#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>  // For output formatting
#include <sstream>  // For string processing
#include <algorithm>  // For remove_if and erase
using namespace std;

#define bac1 1678
#define bac2 1734
#define bac3 2014
#define bac4 2536
#define bac5 2834
#define bac6 2927

// Customer structure to store information
struct Customer {
    string id;                 // Customer ID
    string name;               // Customer Name
    string address;            // Customer Address
    string phoneNumber;        // Customer Phone Number
    double electricityUsage;   // Electricity Usage
};

// Electricity Manager class to manage customers and bills
class ElectricityManager {
    private:
        vector<Customer> customers;  // List of customers

        // Function to calculate electricity bill based on usage
        double calculateBill(double usage) const {
            double billAmount;
            if (usage <= 50) {
                billAmount = usage * bac1;
            } else if (usage <= 100) {
                billAmount = 50 * bac1 + ((usage - 50) * bac2);
            } else if (usage <= 200) {
                billAmount = 50 * bac1 + (50 * bac2) + ((usage - 100) * bac3);
            } else if (usage <= 300) {
                billAmount = 50 * bac1 + (50 * bac2) + (100 * bac3) + ((usage - 200) * bac4);
            } else if (usage <= 400) {
                billAmount = 50 * bac1 + (50 * bac2) + (100 * bac3) + (100 * bac4) + ((usage - 300) * bac5);
            } else {
                billAmount = 50 * bac1 + (50 * bac2) + (100 * bac3) + (100 * bac4) + (100 * bac5) + ((usage - 400) * bac6);
            }
            return billAmount;
        }

        // Function to load customers data from file
        void loadCustomersFromFile(const string& filename) {
            ifstream file(filename);
            if (!file.is_open()) {
                cerr << "Khong ton tai file: " << filename << endl;
                return;
            }
            Customer temp;
            string line;
            while (getline(file, line)) {
                if (line.empty()) {
                    continue;
                }

                stringstream ss(line);
                string token;

                // Read customer ID
                getline(ss, token, '|');
                temp.id = token;

                // Read customer name
                getline(ss, token, '|');
                temp.name = token;

                // Read customer address
                getline(ss, token, '|');
                temp.address = token;

                // Read customer phone number
                getline(ss, token, '|');
                temp.phoneNumber = token;

                // Read electricity usage and validate
                getline(ss, token);
                try {
                    temp.electricityUsage = stod(token);
                    if (temp.electricityUsage < 0) {
                        throw invalid_argument("So dien tieu thu khong duoc am.");
                    }
                } catch (const std::invalid_argument& e) {
                    cerr << "Loi: So dien tieu thu khong hop le cho ma KH " << temp.id
                        << " voi gia tri: '" << token << "'" << endl;
                    continue;  // Skip the customer with invalid electricity usage
                }
                customers.push_back(temp);
            }
            file.close();
        }

        // Function to save customer data to file
        void saveCustomersToFile(const string& filename) const {
            ofstream file(filename);
            if (!file.is_open()) {
                cerr << "Khong the mo file: " << filename << endl;
                return;
            }

            for (const auto& customer : customers) {
                file << customer.id << "|"
                    << customer.name << "|"
                    << customer.address << "|"
                    << customer.phoneNumber << "|"
                    << customer.electricityUsage << endl;
            }
            file.close();
        }

    public:
        // Function to add a new customer
        void addCustomer() {
            Customer newCustomer;
            cout << "Nhap ma khach hang: ";
            cin >> newCustomer.id;
            cin.ignore();

            cout << "Nhap ten khach hang: ";
            getline(cin, newCustomer.name);

            cout << "Nhap dia chi: ";
            getline(cin, newCustomer.address);

            cout << "Nhap so dien thoai: ";
            getline(cin, newCustomer.phoneNumber);

            // Check electricity usage input
            while (true) {
                cout << "Nhap so dien tieu thu: ";
                cin >> newCustomer.electricityUsage;
                if (newCustomer.electricityUsage >= 0) {
                    break;
                } else {
                    cout << "So dien tieu thu khong hop le. Vui long nhap lai.\n";
                }
            }
            cin.ignore();  // Ignore newline character to avoid issues with subsequent inputs

            customers.push_back(newCustomer);
            saveData();  // Save data after adding a new customer
        }

        // Function to display all customer bills
        void displayBills() const {
            cout << setw(10) << left << "Ma KH"
                << setw(20) << "Ten KH"
                << setw(20) << "Dia Chi"
                << setw(15) << "So Dien Thoai"
                << setw(10) << "So Dien"
                << setw(15) << "Tien Dien" << endl;
            cout << string(90, '-') << endl;

            for (const auto& customer : customers) {
                cout << setw(10) << left << customer.id
                    << setw(20) << customer.name
                    << setw(20) << customer.address
                    << setw(15) << customer.phoneNumber
                    << setw(10) << customer.electricityUsage
                    << fixed << setprecision(2) << setw(15) << calculateBill(customer.electricityUsage) << endl;
            }
        }

        // Function to save all data to file
        void saveData() const {
            saveCustomersToFile("customers.txt");
            cout << "Da luu du lieu vao file 'customers.txt'." << endl;
        }

        // Function to load data from file
        void loadData() {
            loadCustomersFromFile("customers.txt");
            if (customers.empty()) {
                cout << "Khong co du lieu trong file.\n";
            } else {
                cout << "Da tai du lieu tu file 'customers.txt'.\n";
            }
        }

        // Function to edit customer details
        void editCustomer(const string& id) {
            bool found = false;
            for (auto& customer : customers) {
                if (customer.id == id) {
                    found = true;
                    cout << "Sua thong tin khach hang: " << customer.id << endl;
                    cout << "Nhap ten moi: ";
                    getline(cin, customer.name);
                    cout << "Nhap dia chi moi: ";
                    getline(cin, customer.address);
                    cout << "Nhap so dien thoai moi: ";
                    getline(cin, customer.phoneNumber);
                    while (true) {
                        cout << "Nhap so dien tieu thu moi: ";
                        cin >> customer.electricityUsage;
                        if (customer.electricityUsage >= 0) {
                            break;
                        } else {
                            cout << "So dien tieu thu khong hop le. Vui long nhap lai.\n";
                        }
                    }
                    cin.ignore();  // Ignore newline character after input
                    saveData();  // Save the updated data to file
                    break;
                }
            }

            if (!found) {
                cout << "Khach hang voi ma " << id << " khong tim thay!\n";
            }
        }

        // Function to delete a customer
        void deleteCustomer(const string& id) {
            auto it = remove_if(customers.begin(), customers.end(), [&id](const Customer& customer) {
                return customer.id == id;
            });

            if (it != customers.end()) {
                customers.erase(it, customers.end());
                saveData();  // Save the updated list to file
                cout << "Da xoa khach hang voi ma " << id << endl;
            } else {
                cout << "Khach hang voi ma " << id << " khong tim thay!\n";
            }
        }
};

int main() {
    ElectricityManager manager;

    // Load data from file
    manager.loadData();

    int choice;
    do {
        cout << "\n========== Quan Ly Tien Dien ==========\n";
        cout << "1. Them khach hang\n";
        cout << "2. Hien thi hoa don\n";
        cout << "3. Sua thong tin khach hang\n";
        cout << "4. Xoa khach hang\n";
        cout << "0. Thoat\n";
        cout << "Lua chon: ";
        cin >> choice;
        cin.ignore();  // Ignore newline character

        string id;
        switch (choice) {
            case 1:
                manager.addCustomer();
                break;
            case 2:
                manager.displayBills();
                break;
            case 3:
                cout << "Nhap ma khach hang can sua: ";
                getline(cin, id);
                manager.editCustomer(id);
                break;
            case 4:
                cout << "Nhap ma khach hang can xoa: ";
                getline(cin, id);
                manager.deleteCustomer(id);
                break;
            case 0:
                cout << "Ket thuc chuong trinh.\n";
                break;
            default:
                cout << "Lua chon khong hop le. Vui long thu lai!\n";
                break;
        }
    } while (choice != 0);

    return 0;
}
