#pragma once

namespace QuanLiTienDien {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Register : public System::Windows::Forms::Form
	{
	public:
		Register(void)
		{
			InitializeComponent();
		}

	protected:
		~Register()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::Windows::Forms::Label^ lblUsername;
		System::Windows::Forms::Label^ lblPassword;
		System::Windows::Forms::Label^ lblConfirmPassword;
		System::Windows::Forms::TextBox^ txtUsername;
		System::Windows::Forms::TextBox^ txtPassword;
		System::Windows::Forms::TextBox^ txtConfirmPassword;
		System::Windows::Forms::Button^ btnRegister;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->lblUsername = (gcnew System::Windows::Forms::Label());
			this->lblPassword = (gcnew System::Windows::Forms::Label());
			this->lblConfirmPassword = (gcnew System::Windows::Forms::Label());
			this->txtUsername = (gcnew System::Windows::Forms::TextBox());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->txtConfirmPassword = (gcnew System::Windows::Forms::TextBox());
			this->btnRegister = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lblUsername
			// 
			this->lblUsername->Font = (gcnew System::Drawing::Font(L"Arial", 10));
			this->lblUsername->Location = System::Drawing::Point(20, 29);
			this->lblUsername->Name = L"lblUsername";
			this->lblUsername->Size = System::Drawing::Size(120, 20);
			this->lblUsername->TabIndex = 0;
			this->lblUsername->Text = L"Username:";
			// 
			// lblPassword
			// 
			this->lblPassword->Font = (gcnew System::Drawing::Font(L"Arial", 10));
			this->lblPassword->Location = System::Drawing::Point(20, 70);
			this->lblPassword->Name = L"lblPassword";
			this->lblPassword->Size = System::Drawing::Size(120, 20);
			this->lblPassword->TabIndex = 1;
			this->lblPassword->Text = L"Password:";
			// 
			// lblConfirmPassword
			// 
			this->lblConfirmPassword->Font = (gcnew System::Drawing::Font(L"Arial", 10));
			this->lblConfirmPassword->Location = System::Drawing::Point(20, 115);
			this->lblConfirmPassword->Name = L"lblConfirmPassword";
			this->lblConfirmPassword->Size = System::Drawing::Size(150, 20);
			this->lblConfirmPassword->TabIndex = 2;
			this->lblConfirmPassword->Text = L"Confirm Password:";
			// 
			// txtUsername
			// 
			this->txtUsername->Location = System::Drawing::Point(176, 29);
			this->txtUsername->Name = L"txtUsername";
			this->txtUsername->Size = System::Drawing::Size(200, 22);
			this->txtUsername->TabIndex = 3;
			// 
			// txtPassword
			// 
			this->txtPassword->Location = System::Drawing::Point(176, 70);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->Size = System::Drawing::Size(200, 22);
			this->txtPassword->TabIndex = 4;
			this->txtPassword->UseSystemPasswordChar = true;
			// 
			// txtConfirmPassword
			// 
			this->txtConfirmPassword->Location = System::Drawing::Point(176, 113);
			this->txtConfirmPassword->Name = L"txtConfirmPassword";
			this->txtConfirmPassword->Size = System::Drawing::Size(200, 22);
			this->txtConfirmPassword->TabIndex = 5;
			this->txtConfirmPassword->UseSystemPasswordChar = true;
			// 
			// btnRegister
			// 
			this->btnRegister->Location = System::Drawing::Point(155, 170);
			this->btnRegister->Name = L"btnRegister";
			this->btnRegister->Size = System::Drawing::Size(116, 30);
			this->btnRegister->TabIndex = 6;
			this->btnRegister->Text = L"Register";
			this->btnRegister->Click += gcnew System::EventHandler(this, &Register::btnRegister_Click);
			// 
			// Register
			// 
			this->ClientSize = System::Drawing::Size(432, 233);
			this->Controls->Add(this->lblUsername);
			this->Controls->Add(this->lblPassword);
			this->Controls->Add(this->lblConfirmPassword);
			this->Controls->Add(this->txtUsername);
			this->Controls->Add(this->txtPassword);
			this->Controls->Add(this->txtConfirmPassword);
			this->Controls->Add(this->btnRegister);
			this->Name = L"Register";
			this->Text = L"Register";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		// Event handler for Register button
	private: System::Void btnRegister_Click(System::Object^ sender, System::EventArgs^ e) {
		if (txtPassword->Text != txtConfirmPassword->Text) {
			MessageBox::Show("Passwords do not match.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		try {
			System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter("users.txt", true);
			sw->WriteLine(txtUsername->Text + ":" + txtPassword->Text);
			sw->Close();

			MessageBox::Show("Registration successful!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
			this->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error registering user: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	};
}
