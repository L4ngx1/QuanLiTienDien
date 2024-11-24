#pragma once
#include "Customer.h"
namespace QuanLiTienDien {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class TienDienApp : public System::Windows::Forms::Form {
    public:
        TienDienApp(void) {
            InitializeComponent();
            customers = gcnew System::Collections::Generic::List<Customer^>();
            dataGridView1->AutoGenerateColumns = false;
            dataGridView1->Columns->Add("ID", "ID");
            dataGridView1->Columns->Add("Name", "Name");
            dataGridView1->Columns->Add("Address", "Address");
            dataGridView1->Columns->Add("Phone", "Phone Number");
            dataGridView1->Columns->Add("ElecUsage", "Electricity Usage");
        }
    protected:
        ~TienDienApp() {
            if (components)
            {
                delete components;
            }
        }
    private:
        System::Collections::Generic::List<Customer^>^ customers;
        System::Windows::Forms::DataGridView^ dataGridView1;
        System::Windows::Forms::Button^ buttonAdd;
        System::Windows::Forms::Button^ buttonEdit;
        System::Windows::Forms::Button^ buttonDelete;
        System::Windows::Forms::TextBox^ txtID;
        System::Windows::Forms::TextBox^ txtName;
        System::Windows::Forms::TextBox^ txtAddress;
        System::Windows::Forms::TextBox^ txtPhone;
        System::Windows::Forms::TextBox^ txtElecUsage;
        System::Windows::Forms::Label^ lblName;
        System::Windows::Forms::Label^ lblAddress;
        System::Windows::Forms::Label^ lblPhone;
        System::Windows::Forms::Label^ lblElecUsage;
        System::Windows::Forms::GroupBox^ groupCustomerInfo;
        System::Windows::Forms::GroupBox^ groupActions;
        System::ComponentModel::Container^ components;
        System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;
        System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn2;
        System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn3;
        System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn4;
        System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn5;
        System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn6;
    private: System::Windows::Forms::TextBox^ txtSearch;

        System::Windows::Forms::Button^ btnSearch;
        System::Windows::Forms::Label^ lblSearch;
    private: System::Windows::Forms::Label^ lblID;
    private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
#pragma region
    void InitializeComponent(void) {
        this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
        this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->dataGridViewTextBoxColumn4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->dataGridViewTextBoxColumn5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->dataGridViewTextBoxColumn6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->buttonAdd = (gcnew System::Windows::Forms::Button());
        this->buttonEdit = (gcnew System::Windows::Forms::Button());
        this->buttonDelete = (gcnew System::Windows::Forms::Button());
        this->txtID = (gcnew System::Windows::Forms::TextBox());
        this->txtName = (gcnew System::Windows::Forms::TextBox());
        this->txtAddress = (gcnew System::Windows::Forms::TextBox());
        this->txtPhone = (gcnew System::Windows::Forms::TextBox());
        this->txtElecUsage = (gcnew System::Windows::Forms::TextBox());
        this->lblName = (gcnew System::Windows::Forms::Label());
        this->lblAddress = (gcnew System::Windows::Forms::Label());
        this->lblPhone = (gcnew System::Windows::Forms::Label());
        this->lblElecUsage = (gcnew System::Windows::Forms::Label());
        this->groupCustomerInfo = (gcnew System::Windows::Forms::GroupBox());
        this->lblID = (gcnew System::Windows::Forms::Label());
        this->groupActions = (gcnew System::Windows::Forms::GroupBox());
        this->txtSearch = (gcnew System::Windows::Forms::TextBox());
        this->btnSearch = (gcnew System::Windows::Forms::Button());
        this->lblSearch = (gcnew System::Windows::Forms::Label());
        this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
        this->groupCustomerInfo->SuspendLayout();
        this->groupActions->SuspendLayout();
        this->SuspendLayout();
        // 
        // dataGridView1
        // 
        this->dataGridView1->ColumnHeadersHeight = 29;
        this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
            this->dataGridViewTextBoxColumn1,
                this->dataGridViewTextBoxColumn2, this->dataGridViewTextBoxColumn3, this->dataGridViewTextBoxColumn4, this->dataGridViewTextBoxColumn5,
                this->dataGridViewTextBoxColumn6
        });
        this->dataGridView1->Location = System::Drawing::Point(52, 247);
        this->dataGridView1->Name = L"dataGridView1";
        this->dataGridView1->RowHeadersWidth = 51;
        this->dataGridView1->Size = System::Drawing::Size(816, 284);
        this->dataGridView1->TabIndex = 0;
        this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &TienDienApp::dataGridView1_CellContentClick);
        // 
        // dataGridViewTextBoxColumn1
        // 
        this->dataGridViewTextBoxColumn1->HeaderText = L"ID";
        this->dataGridViewTextBoxColumn1->MinimumWidth = 6;
        this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
        this->dataGridViewTextBoxColumn1->Width = 125;
        // 
        // dataGridViewTextBoxColumn2
        // 
        this->dataGridViewTextBoxColumn2->HeaderText = L"Họ Tên";
        this->dataGridViewTextBoxColumn2->MinimumWidth = 6;
        this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
        this->dataGridViewTextBoxColumn2->Width = 125;
        // 
        // dataGridViewTextBoxColumn3
        // 
        this->dataGridViewTextBoxColumn3->HeaderText = L"Địa Chỉ";
        this->dataGridViewTextBoxColumn3->MinimumWidth = 6;
        this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
        this->dataGridViewTextBoxColumn3->Width = 125;
        // 
        // dataGridViewTextBoxColumn4
        // 
        this->dataGridViewTextBoxColumn4->HeaderText = L"Số Điện Thoại";
        this->dataGridViewTextBoxColumn4->MinimumWidth = 6;
        this->dataGridViewTextBoxColumn4->Name = L"dataGridViewTextBoxColumn4";
        this->dataGridViewTextBoxColumn4->Width = 125;
        // 
        // dataGridViewTextBoxColumn5
        // 
        this->dataGridViewTextBoxColumn5->HeaderText = L"Số Điện Tiêu Thụ (kWh)";
        this->dataGridViewTextBoxColumn5->MinimumWidth = 6;
        this->dataGridViewTextBoxColumn5->Name = L"dataGridViewTextBoxColumn5";
        this->dataGridViewTextBoxColumn5->Width = 132;
        // 
        // dataGridViewTextBoxColumn6
        // 
        this->dataGridViewTextBoxColumn6->HeaderText = L"Số Tiền (VND)";
        this->dataGridViewTextBoxColumn6->MinimumWidth = 6;
        this->dataGridViewTextBoxColumn6->Name = L"dataGridViewTextBoxColumn6";
        this->dataGridViewTextBoxColumn6->Width = 132;
        // 
        // buttonAdd
        // 
        this->buttonAdd->Location = System::Drawing::Point(10, 30);
        this->buttonAdd->Name = L"buttonAdd";
        this->buttonAdd->Size = System::Drawing::Size(180, 40);
        this->buttonAdd->TabIndex = 0;
        this->buttonAdd->Text = L"Thêm";
        this->buttonAdd->Click += gcnew System::EventHandler(this, &TienDienApp::buttonAdd_Click);
        // 
        // buttonEdit
        // 
        this->buttonEdit->Location = System::Drawing::Point(10, 80);
        this->buttonEdit->Name = L"buttonEdit";
        this->buttonEdit->Size = System::Drawing::Size(180, 40);
        this->buttonEdit->TabIndex = 1;
        this->buttonEdit->Text = L"Sửa";
        this->buttonEdit->Click += gcnew System::EventHandler(this, &TienDienApp::buttonEdit_Click);
        // 
        // buttonDelete
        // 
        this->buttonDelete->Location = System::Drawing::Point(10, 130);
        this->buttonDelete->Name = L"buttonDelete";
        this->buttonDelete->Size = System::Drawing::Size(180, 40);
        this->buttonDelete->TabIndex = 2;
        this->buttonDelete->Text = L"Xóa";
        this->buttonDelete->Click += gcnew System::EventHandler(this, &TienDienApp::buttonDelete_Click);
        // 
        // txtID
        // 
        this->txtID->Location = System::Drawing::Point(112, 30);
        this->txtID->Name = L"txtID";
        this->txtID->Size = System::Drawing::Size(280, 22);
        this->txtID->TabIndex = 1;
        // 
        // txtName
        // 
        this->txtName->Location = System::Drawing::Point(112, 60);
        this->txtName->Name = L"txtName";
        this->txtName->Size = System::Drawing::Size(280, 22);
        this->txtName->TabIndex = 3;
        // 
        // txtAddress
        // 
        this->txtAddress->Location = System::Drawing::Point(112, 90);
        this->txtAddress->Name = L"txtAddress";
        this->txtAddress->Size = System::Drawing::Size(280, 22);
        this->txtAddress->TabIndex = 5;
        // 
        // txtPhone
        // 
        this->txtPhone->Location = System::Drawing::Point(112, 120);
        this->txtPhone->Name = L"txtPhone";
        this->txtPhone->Size = System::Drawing::Size(280, 22);
        this->txtPhone->TabIndex = 7;
        // 
        // txtElecUsage
        // 
        this->txtElecUsage->Location = System::Drawing::Point(112, 150);
        this->txtElecUsage->Name = L"txtElecUsage";
        this->txtElecUsage->Size = System::Drawing::Size(280, 22);
        this->txtElecUsage->TabIndex = 9;
        // 
        // lblName
        // 
        this->lblName->Location = System::Drawing::Point(6, 60);
        this->lblName->Name = L"lblName";
        this->lblName->Size = System::Drawing::Size(100, 23);
        this->lblName->TabIndex = 2;
        this->lblName->Text = L"Họ Tên";
        // 
        // lblAddress
        // 
        this->lblAddress->Location = System::Drawing::Point(6, 90);
        this->lblAddress->Name = L"lblAddress";
        this->lblAddress->Size = System::Drawing::Size(100, 23);
        this->lblAddress->TabIndex = 4;
        this->lblAddress->Text = L"Địa Chỉ";
        // 
        // lblPhone
        // 
        this->lblPhone->Location = System::Drawing::Point(6, 120);
        this->lblPhone->Name = L"lblPhone";
        this->lblPhone->Size = System::Drawing::Size(100, 23);
        this->lblPhone->TabIndex = 6;
        this->lblPhone->Text = L"Số Điện Thoại";
        // 
        // lblElecUsage
        // 
        this->lblElecUsage->Location = System::Drawing::Point(6, 150);
        this->lblElecUsage->Name = L"lblElecUsage";
        this->lblElecUsage->Size = System::Drawing::Size(100, 23);
        this->lblElecUsage->TabIndex = 8;
        this->lblElecUsage->Text = L"Số Điện (kWh)";
        this->lblElecUsage->Click += gcnew System::EventHandler(this, &TienDienApp::lblElecUsage_Click);
        // 
        // groupCustomerInfo
        // 
        this->groupCustomerInfo->Controls->Add(this->lblID);
        this->groupCustomerInfo->Controls->Add(this->txtID);
        this->groupCustomerInfo->Controls->Add(this->lblName);
        this->groupCustomerInfo->Controls->Add(this->txtName);
        this->groupCustomerInfo->Controls->Add(this->lblAddress);
        this->groupCustomerInfo->Controls->Add(this->txtAddress);
        this->groupCustomerInfo->Controls->Add(this->lblPhone);
        this->groupCustomerInfo->Controls->Add(this->txtPhone);
        this->groupCustomerInfo->Controls->Add(this->lblElecUsage);
        this->groupCustomerInfo->Controls->Add(this->txtElecUsage);
        this->groupCustomerInfo->Location = System::Drawing::Point(52, 22);
        this->groupCustomerInfo->Name = L"groupCustomerInfo";
        this->groupCustomerInfo->Size = System::Drawing::Size(430, 180);
        this->groupCustomerInfo->TabIndex = 1;
        this->groupCustomerInfo->TabStop = false;
        this->groupCustomerInfo->Text = L"Thông Tin Khách Hàng";
        // 
        // lblID
        // 
        this->lblID->Location = System::Drawing::Point(6, 29);
        this->lblID->Name = L"lblID";
        this->lblID->Size = System::Drawing::Size(100, 23);
        this->lblID->TabIndex = 0;
        this->lblID->Text = L"ID";
        this->lblID->Click += gcnew System::EventHandler(this, &TienDienApp::lblSearch_Click);
        // 
        // groupActions
        // 
        this->groupActions->Controls->Add(this->buttonAdd);
        this->groupActions->Controls->Add(this->buttonEdit);
        this->groupActions->Controls->Add(this->buttonDelete);
        this->groupActions->Location = System::Drawing::Point(519, 22);
        this->groupActions->Name = L"groupActions";
        this->groupActions->Size = System::Drawing::Size(200, 180);
        this->groupActions->TabIndex = 2;
        this->groupActions->TabStop = false;
        this->groupActions->Text = L"Chức Năng";
        // 
        // txtSearch
        // 
        this->txtSearch->Location = System::Drawing::Point(627, 222);
        this->txtSearch->Name = L"txtSearch";
        this->txtSearch->Size = System::Drawing::Size(145, 22);
        this->txtSearch->TabIndex = 3;
        this->txtSearch->TextChanged += gcnew System::EventHandler(this, &TienDienApp::txtSearch_TextChanged);
        // 
        // btnSearch
        // 
        this->btnSearch->Location = System::Drawing::Point(778, 222);
        this->btnSearch->Name = L"btnSearch";
        this->btnSearch->Size = System::Drawing::Size(90, 22);
        this->btnSearch->TabIndex = 4;
        this->btnSearch->Text = L"Search";
        this->btnSearch->UseVisualStyleBackColor = true;
        this->btnSearch->Click += gcnew System::EventHandler(this, &TienDienApp::btnSearch_Click);
        // 
        // lblSearch
        // 
        this->lblSearch->Location = System::Drawing::Point(444, 225);
        this->lblSearch->Name = L"lblSearch";
        this->lblSearch->Size = System::Drawing::Size(177, 19);
        this->lblSearch->TabIndex = 9;
        this->lblSearch->Text = L"Nhập ID khách hàng cần tìm:";
        this->lblSearch->Click += gcnew System::EventHandler(this, &TienDienApp::lblSearch_Click);
        // 
        // TienDienApp
        // 
        this->ClientSize = System::Drawing::Size(972, 551);
        this->Controls->Add(this->lblSearch);
        this->Controls->Add(this->btnSearch);
        this->Controls->Add(this->txtSearch);
        this->Controls->Add(this->dataGridView1);
        this->Controls->Add(this->groupCustomerInfo);
        this->Controls->Add(this->groupActions);
        this->Name = L"TienDienApp";
        this->Text = L"TienDienApp";
        this->Load += gcnew System::EventHandler(this, &TienDienApp::TienDienApp_Load);
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
        this->groupCustomerInfo->ResumeLayout(false);
        this->groupCustomerInfo->PerformLayout();
        this->groupActions->ResumeLayout(false);
        this->ResumeLayout(false);
        this->PerformLayout();

    }
#pragma endregion
    bool ValidateFields(){
        array<TextBox^>^ fields = { txtID, txtName, txtAddress, txtPhone, txtElecUsage };
        array<String^>^ fieldNames = { "ID", "Name", "Address", "Phone", "Electricity Usage" };
        for (int i = 0; i < fields->Length; i++) {
            if (String::IsNullOrEmpty(fields[i]->Text)) {
                MessageBox::Show(fieldNames[i] + " cannot be empty.");
                fields[i]->Focus();
                return false;
            }
        }
        double usage;
        if (!Double::TryParse(txtElecUsage->Text, usage) || usage <= 0) {
            MessageBox::Show("Electricity usage must be a valid positive number.");
            txtElecUsage->Focus();
            return false;
        }
        return true;
    }
    bool IsIDUnique(String^ id) {
        for each (Customer ^ customer in customers) {
            if (customer->ID == id) {
                return false; // ID đã tồn tại
            }
        }
        return true;
    }
    private: System::Void buttonAdd_Click(System::Object^ sender, System::EventArgs^ e) {
        // Check if all fields are filled
        if (String::IsNullOrEmpty(txtID->Text) || String::IsNullOrEmpty(txtName->Text) ||
            String::IsNullOrEmpty(txtAddress->Text) || String::IsNullOrEmpty(txtPhone->Text) ||
            String::IsNullOrEmpty(txtElecUsage->Text)) {
            MessageBox::Show("Please fill in all fields.");
            return;
        }
        // Check if the ID already exists
        if (!IsIDUnique(txtID->Text)) {
            MessageBox::Show("ID already exists. Please use a different ID.");
            return;
        }
        // Convert electricity usage to double
        double usage = 0;
        if (!Double::TryParse(txtElecUsage->Text, usage) || usage <= 0) {
            MessageBox::Show("Please enter a valid electricity usage.");
            return;
        }
        // Add new customer with the usage as a double
        Customer^ newCustomer = gcnew Customer(txtID->Text, txtName->Text, txtAddress->Text, txtPhone->Text, usage);
        customers->Add(newCustomer);
        // Update the grid view
        UpdateGridView();
        // Clear the input fields after adding the customer
        txtID->Clear();
        txtName->Clear();
        txtAddress->Clear();
        txtPhone->Clear();
        txtElecUsage->Clear();
    }
    private:System::Void buttonEdit_Click(System::Object^ sender, System::EventArgs^ e) {
        // Check if any row is selected
        if (dataGridView1->SelectedRows->Count == 0) {
            MessageBox::Show("Please select a customer to edit.");
            return;
        }
        // Get the index of the selected row
        int index = dataGridView1->SelectedRows[0]->Index;
        if (index < 0 || index >= customers->Count) {
            MessageBox::Show("Invalid selection.");
            return;
        }
        // Validate the fields before proceeding
        if (!ValidateFields()) return;
        // Update the customer details based on the form inputs
        Customer^ selectedCustomer = customers[index];
        selectedCustomer->ID = txtID->Text;
        selectedCustomer->Name = txtName->Text;
        selectedCustomer->Address = txtAddress->Text;
        selectedCustomer->PhoneNumber = txtPhone->Text;
        // Convert the electricity usage to double and update the customer
        double usage;
        if (Double::TryParse(txtElecUsage->Text, usage) && usage > 0) {
            selectedCustomer->ElecUsage = usage;
        }
        else {
            MessageBox::Show("Please enter a valid electricity usage.");
            return;
        }
        // Refresh the data grid view to reflect changes
        UpdateGridView();
        // Clear the input fields after updating
        txtID->Clear();
        txtName->Clear();
        txtAddress->Clear();
        txtPhone->Clear();
        txtElecUsage->Clear();
    }
    private: System::Void buttonDelete_Click(System::Object^ sender, System::EventArgs^ e) {
        // Check if any row is selected
        if (dataGridView1->SelectedRows->Count == 0) {
            MessageBox::Show("Please select a customer to delete.");
            return;
        }
        // Get the index of the selected row
        DataGridViewRow^ selectedRow = dataGridView1->SelectedRows[0];
        int index = selectedRow->Index;
        // Make sure the index is valid
        if (index >= 0 && index < customers->Count) {
            // Remove the customer from the list
            customers->RemoveAt(index);
            // Update the data grid view
            UpdateGridView();
            MessageBox::Show("Customer deleted successfully.");
        }
        else {
            MessageBox::Show("Invalid selection.");
        }
    }
        void UpdateGridView() {
            dataGridView1->Rows->Clear();
            for each (Customer ^ customer in customers) {
                // Add the row with customer information and calculated bill
                array<String^>^ row = {
                    customer->ID,
                    customer->Name,
                    customer->Address,
                    customer->PhoneNumber,
                    customer->ElecUsage.ToString(),
                    customer->CalculateBill().ToString() // Display the calculated bill
                };
                dataGridView1->Rows->Add(row);
            }
        }

    private: System::Void TienDienApp_Load(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void lblSearch_Click(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
    }
    private: System::Void btnSearch_Click(System::Object^ sender, System::EventArgs^ e) {
        String^ searchTerm = txtSearch->Text;
        if (String::IsNullOrEmpty(searchTerm)) {
            MessageBox::Show("Please enter an ID to search.");
            return;
        }
        // Find the customer by ID
        Customer^ foundCustomer = nullptr;
        for each (Customer ^ customer in customers) {
            if (customer->ID == searchTerm) {
                foundCustomer = customer;
                break;
            }
        }
        if (foundCustomer != nullptr) {
            // Display the found customer's information
            txtID->Text = foundCustomer->ID;
            txtName->Text = foundCustomer->Name;
            txtAddress->Text = foundCustomer->Address;
            txtPhone->Text = foundCustomer->PhoneNumber;
            txtElecUsage->Text = foundCustomer->ElecUsage.ToString();
        }
        else {
            MessageBox::Show("Customer not found.");
        }
    }
    private: System::Void txtSearch_TextChanged(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void lblElecUsage_Click(System::Object^ sender, System::EventArgs^ e) {
    }
};
}