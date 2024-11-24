#pragma once
#include "Register.h"
#include "TienDienApp.h"
namespace QuanLiTienDien {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Login : public System::Windows::Forms::Form
	{
	public:
		Login(void)
		{
			InitializeComponent();
		}

	protected:
		~Login()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::Windows::Forms::Label^ lblUsername;
		System::Windows::Forms::Label^ lblPassword;
		System::Windows::Forms::TextBox^ txtUsername;
		System::Windows::Forms::TextBox^ txtPassword;
		System::Windows::Forms::Button^ btnLogin;
		System::Windows::Forms::Button^ btnRegister;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->lblUsername = (gcnew System::Windows::Forms::Label());
			this->lblPassword = (gcnew System::Windows::Forms::Label());
			this->txtUsername = (gcnew System::Windows::Forms::TextBox());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->btnLogin = (gcnew System::Windows::Forms::Button());
			this->btnRegister = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lblUsername
			// 
			this->lblUsername->Font = (gcnew System::Drawing::Font(L"Arial", 10));
			this->lblUsername->Location = System::Drawing::Point(50, 50);
			this->lblUsername->Name = L"lblUsername";
			this->lblUsername->Size = System::Drawing::Size(100, 20);
			this->lblUsername->TabIndex = 0;
			this->lblUsername->Text = L"Username:";
			// 
			// lblPassword
			// 
			this->lblPassword->Font = (gcnew System::Drawing::Font(L"Arial", 10));
			this->lblPassword->Location = System::Drawing::Point(50, 100);
			this->lblPassword->Name = L"lblPassword";
			this->lblPassword->Size = System::Drawing::Size(100, 20);
			this->lblPassword->TabIndex = 1;
			this->lblPassword->Text = L"Password:";
			// 
			// txtUsername
			// 
			this->txtUsername->Location = System::Drawing::Point(150, 50);
			this->txtUsername->Name = L"txtUsername";
			this->txtUsername->Size = System::Drawing::Size(200, 22);
			this->txtUsername->TabIndex = 2;
			// 
			// txtPassword
			// 
			this->txtPassword->Location = System::Drawing::Point(150, 100);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->Size = System::Drawing::Size(200, 22);
			this->txtPassword->TabIndex = 3;
			this->txtPassword->UseSystemPasswordChar = true;
			// 
			// btnLogin
			// 
			this->btnLogin->Location = System::Drawing::Point(109, 150);
			this->btnLogin->Name = L"btnLogin";
			this->btnLogin->Size = System::Drawing::Size(80, 30);
			this->btnLogin->TabIndex = 4;
			this->btnLogin->Text = L"Login";
			this->btnLogin->Click += gcnew System::EventHandler(this, &Login::btnLogin_Click);
			// 
			// btnRegister
			// 
			this->btnRegister->Location = System::Drawing::Point(232, 150);
			this->btnRegister->Name = L"btnRegister";
			this->btnRegister->Size = System::Drawing::Size(80, 30);
			this->btnRegister->TabIndex = 5;
			this->btnRegister->Text = L"Register";
			this->btnRegister->Click += gcnew System::EventHandler(this, &Login::btnRegister_Click);
			// 
			// Login
			// 
			this->ClientSize = System::Drawing::Size(432, 233);
			this->Controls->Add(this->lblUsername);
			this->Controls->Add(this->lblPassword);
			this->Controls->Add(this->txtUsername);
			this->Controls->Add(this->txtPassword);
			this->Controls->Add(this->btnLogin);
			this->Controls->Add(this->btnRegister);
			this->Name = L"Login";
			this->Text = L"Login";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		// Event handler for Login button
	private: System::Void btnLogin_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			array<String^>^ lines = System::IO::File::ReadAllLines("users.txt");
			for each (String ^ line in lines) {
				array<String^>^ parts = line->Split(':');
				if (parts->Length == 2 && parts[0] == txtUsername->Text && parts[1] == txtPassword->Text) {
					MessageBox::Show("Login successful!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
					TienDienApp^ app = gcnew TienDienApp();
					app->ShowDialog(); // Show the Register form
					return;
				}
			}
			MessageBox::Show("Invalid username or password.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error reading user data: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

		   // Event handler for Register button
	private: System::Void btnRegister_Click(System::Object^ sender, System::EventArgs^ e) {
		Register^ registerForm = gcnew Register();
		registerForm->ShowDialog(); // Show the Register form
	}
	};
}
