#pragma once
#include "Customer.h"

namespace QuanLiTienDien {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class TienDienApp : public System::Windows::Forms::Form
    {
    public:
        TienDienApp(void)
        {
            InitializeComponent();
            customers = gcnew System::Collections::Generic::List<Customer^>();
        }

    protected:
        ~TienDienApp()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::DataGridView^ dataGridView1;
        System::Windows::Forms::Button^ buttonAdd;
        System::Windows::Forms::Button^ buttonEdit;
        System::Windows::Forms::Button^ buttonDelete;
        System::Windows::Forms::TextBox^ txtID;
        System::Windows::Forms::TextBox^ txtName;
        System::Windows::Forms::TextBox^ txtAddress;
        System::Windows::Forms::TextBox^ txtPhone;
        System::Windows::Forms::TextBox^ txtElecUsage;
        System::Windows::Forms::Label^ lblID;
        System::Windows::Forms::Label^ lblName;
        System::Windows::Forms::Label^ lblAddress;
        System::Windows::Forms::Label^ lblPhone;
        System::Windows::Forms::Label^ lblElecUsage;
        System::Windows::Forms::GroupBox^ groupCustomerInfo;
        System::Windows::Forms::GroupBox^ groupActions;

    private:
        System::ComponentModel::Container^ components;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn2;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn3;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn4;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn5;
           System::Collections::Generic::List<Customer^>^ customers;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
            this->buttonAdd = (gcnew System::Windows::Forms::Button());
            this->buttonEdit = (gcnew System::Windows::Forms::Button());
            this->buttonDelete = (gcnew System::Windows::Forms::Button());
            this->txtID = (gcnew System::Windows::Forms::TextBox());
            this->txtName = (gcnew System::Windows::Forms::TextBox());
            this->txtAddress = (gcnew System::Windows::Forms::TextBox());
            this->txtPhone = (gcnew System::Windows::Forms::TextBox());
            this->txtElecUsage = (gcnew System::Windows::Forms::TextBox());
            this->lblID = (gcnew System::Windows::Forms::Label());
            this->lblName = (gcnew System::Windows::Forms::Label());
            this->lblAddress = (gcnew System::Windows::Forms::Label());
            this->lblPhone = (gcnew System::Windows::Forms::Label());
            this->lblElecUsage = (gcnew System::Windows::Forms::Label());
            this->groupCustomerInfo = (gcnew System::Windows::Forms::GroupBox());
            this->groupActions = (gcnew System::Windows::Forms::GroupBox());
            this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->dataGridViewTextBoxColumn4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->dataGridViewTextBoxColumn5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
            this->groupCustomerInfo->SuspendLayout();
            this->groupActions->SuspendLayout();
            this->SuspendLayout();
            // 
            // dataGridView1
            // 
            this->dataGridView1->ColumnHeadersHeight = 29;
            this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
                this->dataGridViewTextBoxColumn1,
                    this->dataGridViewTextBoxColumn2, this->dataGridViewTextBoxColumn3, this->dataGridViewTextBoxColumn4, this->dataGridViewTextBoxColumn5
            });
            this->dataGridView1->Location = System::Drawing::Point(86, 31);
            this->dataGridView1->Name = L"dataGridView1";
            this->dataGridView1->RowHeadersWidth = 51;
            this->dataGridView1->Size = System::Drawing::Size(678, 286);
            this->dataGridView1->TabIndex = 0;
            // 
            // buttonAdd
            // 
            this->buttonAdd->Location = System::Drawing::Point(10, 30);
            this->buttonAdd->Name = L"buttonAdd";
            this->buttonAdd->Size = System::Drawing::Size(180, 40);
            this->buttonAdd->TabIndex = 0;
            this->buttonAdd->Text = L"Add";
            this->buttonAdd->Click += gcnew System::EventHandler(this, &TienDienApp::buttonAdd_Click);
            // 
            // buttonEdit
            // 
            this->buttonEdit->Location = System::Drawing::Point(10, 80);
            this->buttonEdit->Name = L"buttonEdit";
            this->buttonEdit->Size = System::Drawing::Size(180, 40);
            this->buttonEdit->TabIndex = 1;
            this->buttonEdit->Text = L"Edit";
            this->buttonEdit->Click += gcnew System::EventHandler(this, &TienDienApp::buttonEdit_Click);
            // 
            // buttonDelete
            // 
            this->buttonDelete->Location = System::Drawing::Point(10, 130);
            this->buttonDelete->Name = L"buttonDelete";
            this->buttonDelete->Size = System::Drawing::Size(180, 40);
            this->buttonDelete->TabIndex = 2;
            this->buttonDelete->Text = L"Delete";
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
            // lblID
            // 
            this->lblID->Location = System::Drawing::Point(6, 30);
            this->lblID->Name = L"lblID";
            this->lblID->Size = System::Drawing::Size(100, 23);
            this->lblID->TabIndex = 0;
            this->lblID->Text = L"ID";
            // 
            // lblName
            // 
            this->lblName->Location = System::Drawing::Point(6, 60);
            this->lblName->Name = L"lblName";
            this->lblName->Size = System::Drawing::Size(100, 23);
            this->lblName->TabIndex = 2;
            this->lblName->Text = L"Name";
            // 
            // lblAddress
            // 
            this->lblAddress->Location = System::Drawing::Point(6, 90);
            this->lblAddress->Name = L"lblAddress";
            this->lblAddress->Size = System::Drawing::Size(100, 23);
            this->lblAddress->TabIndex = 4;
            this->lblAddress->Text = L"Address";
            // 
            // lblPhone
            // 
            this->lblPhone->Location = System::Drawing::Point(6, 120);
            this->lblPhone->Name = L"lblPhone";
            this->lblPhone->Size = System::Drawing::Size(100, 23);
            this->lblPhone->TabIndex = 6;
            this->lblPhone->Text = L"Phone";
            // 
            // lblElecUsage
            // 
            this->lblElecUsage->Location = System::Drawing::Point(6, 150);
            this->lblElecUsage->Name = L"lblElecUsage";
            this->lblElecUsage->Size = System::Drawing::Size(100, 23);
            this->lblElecUsage->TabIndex = 8;
            this->lblElecUsage->Text = L"Electricity Usage";
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
            this->groupCustomerInfo->Location = System::Drawing::Point(86, 345);
            this->groupCustomerInfo->Name = L"groupCustomerInfo";
            this->groupCustomerInfo->Size = System::Drawing::Size(430, 180);
            this->groupCustomerInfo->TabIndex = 1;
            this->groupCustomerInfo->TabStop = false;
            this->groupCustomerInfo->Text = L"Customer Information";
            // 
            // groupActions
            // 
            this->groupActions->Controls->Add(this->buttonAdd);
            this->groupActions->Controls->Add(this->buttonEdit);
            this->groupActions->Controls->Add(this->buttonDelete);
            this->groupActions->Location = System::Drawing::Point(545, 345);
            this->groupActions->Name = L"groupActions";
            this->groupActions->Size = System::Drawing::Size(200, 180);
            this->groupActions->TabIndex = 2;
            this->groupActions->TabStop = false;
            this->groupActions->Text = L"Actions";
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
            this->dataGridViewTextBoxColumn2->HeaderText = L"Name";
            this->dataGridViewTextBoxColumn2->MinimumWidth = 6;
            this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
            this->dataGridViewTextBoxColumn2->Width = 125;
            // 
            // dataGridViewTextBoxColumn3
            // 
            this->dataGridViewTextBoxColumn3->HeaderText = L"Address";
            this->dataGridViewTextBoxColumn3->MinimumWidth = 6;
            this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
            this->dataGridViewTextBoxColumn3->Width = 125;
            // 
            // dataGridViewTextBoxColumn4
            // 
            this->dataGridViewTextBoxColumn4->HeaderText = L"Phone Number";
            this->dataGridViewTextBoxColumn4->MinimumWidth = 6;
            this->dataGridViewTextBoxColumn4->Name = L"dataGridViewTextBoxColumn4";
            this->dataGridViewTextBoxColumn4->Width = 125;
            // 
            // dataGridViewTextBoxColumn5
            // 
            this->dataGridViewTextBoxColumn5->HeaderText = L"Electricity Usage";
            this->dataGridViewTextBoxColumn5->MinimumWidth = 6;
            this->dataGridViewTextBoxColumn5->Name = L"dataGridViewTextBoxColumn5";
            this->dataGridViewTextBoxColumn5->Width = 125;
            // 
            // TienDienApp
            // 
            this->ClientSize = System::Drawing::Size(945, 537);
            this->Controls->Add(this->dataGridView1);
            this->Controls->Add(this->groupCustomerInfo);
            this->Controls->Add(this->groupActions);
            this->Name = L"TienDienApp";
            this->Text = L"TienDienApp";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
            this->groupCustomerInfo->ResumeLayout(false);
            this->groupCustomerInfo->PerformLayout();
            this->groupActions->ResumeLayout(false);
            this->ResumeLayout(false);

        }
#pragma endregion

        // Event Handlers
    private: System::Void buttonAdd_Click(System::Object^ sender, System::EventArgs^ e) {
        // Check if all fields are filled
        if (String::IsNullOrEmpty(txtID->Text) || String::IsNullOrEmpty(txtName->Text) ||
            String::IsNullOrEmpty(txtAddress->Text) || String::IsNullOrEmpty(txtPhone->Text) ||
            String::IsNullOrEmpty(txtElecUsage->Text))
        {
            MessageBox::Show("Please fill in all fields.");
            return;
        }

        // Convert electricity usage to double
        double usage = 0;
        if (!Double::TryParse(txtElecUsage->Text, usage) || usage <= 0)
        {
            MessageBox::Show("Please enter a valid electricity usage.");
            return;
        }

        // Add new customer with the usage as a double
        Customer^ newCustomer = gcnew Customer(txtID->Text, txtName->Text, txtAddress->Text, txtPhone->Text, usage);
        customers->Add(newCustomer);
        UpdateGridView();
    }

    private: System::Void buttonEdit_Click(System::Object^ sender, System::EventArgs^ e) {
        // Assuming we edit the first customer (can be expanded for better selection)
        if (customers->Count > 0) {
            customers[0]->Name = "Updated Name";
            UpdateGridView();
        }
    }

    private: System::Void buttonDelete_Click(System::Object^ sender, System::EventArgs^ e) {
        // Assuming we delete the first customer (can be expanded for better selection)
        if (customers->Count > 0) {
            customers->RemoveAt(0);
            UpdateGridView();
        }
    }

    private: System::Void UpdateGridView() {
        dataGridView1->Rows->Clear();
        for (int i = 0; i < customers->Count; i++) {
            Customer^ customer = customers[i];
            array<String^>^ row = { customer->ID, customer->Name, customer->Address, customer->PhoneNumber, customer->GetElecUsageString() };
            dataGridView1->Rows->Add(row);
        }
    }

    };
}
