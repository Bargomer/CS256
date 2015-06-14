#pragma once
#include "stdafx.h"
#include "SignUp.h"
#include "Welcome.h"
#include "Options.h"
#include <string>
#include <msclr\marshal_cppstd.h>
#include <Vcclr.h>
#include <fstream>

namespace CS256 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;
	using namespace System::Runtime::InteropServices;
	//std::string sha256(std::string input);

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{

	
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  submitButton;
	protected:

	private: System::Windows::Forms::TextBox^  usernameBox;

	private: System::Windows::Forms::TextBox^  passwordBox;
	private: System::Windows::Forms::Label^  usernameLabel;
	private: System::Windows::Forms::Label^  passwordLabel;
	private: System::Windows::Forms::Button^  signupButton;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->submitButton = (gcnew System::Windows::Forms::Button());
			this->usernameBox = (gcnew System::Windows::Forms::TextBox());
			this->passwordBox = (gcnew System::Windows::Forms::TextBox());
			this->usernameLabel = (gcnew System::Windows::Forms::Label());
			this->passwordLabel = (gcnew System::Windows::Forms::Label());
			this->signupButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// submitButton
			// 
			this->submitButton->Location = System::Drawing::Point(102, 136);
			this->submitButton->Name = L"submitButton";
			this->submitButton->Size = System::Drawing::Size(75, 23);
			this->submitButton->TabIndex = 0;
			this->submitButton->Text = L"Submit";
			this->submitButton->UseVisualStyleBackColor = true;
			this->submitButton->Click += gcnew System::EventHandler(this, &MyForm::submitButton_Click);
			// 
			// usernameBox
			// 
			this->usernameBox->Location = System::Drawing::Point(89, 69);
			this->usernameBox->MaxLength = 12;
			this->usernameBox->Multiline = true;
			this->usernameBox->Name = L"usernameBox";
			this->usernameBox->Size = System::Drawing::Size(100, 20);
			this->usernameBox->TabIndex = 1;
			// 
			// passwordBox
			// 
			this->passwordBox->Location = System::Drawing::Point(89, 110);
			this->passwordBox->Name = L"passwordBox";
			this->passwordBox->Size = System::Drawing::Size(100, 20);
			this->passwordBox->TabIndex = 2;
			this->passwordBox->UseSystemPasswordChar = true;
			this->passwordBox->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// usernameLabel
			// 
			this->usernameLabel->AutoSize = true;
			this->usernameLabel->Location = System::Drawing::Point(25, 69);
			this->usernameLabel->Name = L"usernameLabel";
			this->usernameLabel->Size = System::Drawing::Size(55, 13);
			this->usernameLabel->TabIndex = 3;
			this->usernameLabel->Text = L"Username";
			// 
			// passwordLabel
			// 
			this->passwordLabel->AutoSize = true;
			this->passwordLabel->Location = System::Drawing::Point(25, 110);
			this->passwordLabel->Name = L"passwordLabel";
			this->passwordLabel->Size = System::Drawing::Size(53, 13);
			this->passwordLabel->TabIndex = 4;
			this->passwordLabel->Text = L"Password";
			// 
			// signupButton
			// 
			this->signupButton->Location = System::Drawing::Point(90, 178);
			this->signupButton->Name = L"signupButton";
			this->signupButton->Size = System::Drawing::Size(99, 23);
			this->signupButton->TabIndex = 5;
			this->signupButton->Text = L"New Keys";
			this->signupButton->UseVisualStyleBackColor = true;
			this->signupButton->Click += gcnew System::EventHandler(this, &MyForm::signupButton_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->signupButton);
			this->Controls->Add(this->passwordLabel);
			this->Controls->Add(this->usernameLabel);
			this->Controls->Add(this->passwordBox);
			this->Controls->Add(this->usernameBox);
			this->Controls->Add(this->submitButton);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void submitButton_Click(System::Object^  sender, System::EventArgs^  e) {

		string line;
		ifstream myfile("encryption.txt");
		if (myfile.is_open())
		{
			while (getline(myfile, line))
			{
				cout << line << '\n';
			}
			myfile.close();
		}
		Vigenere cipher(line);
		
		String^ username;
		String^ password;
		const char* userName =
			(const char*)(Marshal::StringToHGlobalAnsi(this->usernameBox->Text)).ToPointer();;
		std::string decrypt = cipher.encrypt(userName);
		username = gcnew String(decrypt.c_str());

		const char* passWord =
			(const char*)(Marshal::StringToHGlobalAnsi(this->passwordBox->Text)).ToPointer();;
		decrypt = cipher.encrypt(passWord);
		password = gcnew String(decrypt.c_str());
		
		String^ constring = L"datasource=localhost;port=3306;username=root;password=jl0794362";
		MySqlConnection^ conDatabase = gcnew MySqlConnection(constring);
		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("select * from drillletter.users where username = '" + username + "' and password='" + password + "';", conDatabase);
		MySqlDataReader^ myReader;
		try{
			conDatabase->Open();
			myReader = cmdDataBase->ExecuteReader();

			int count = 0;
			while (myReader->Read()){
				count = count + 1;
			}

			if (count == 1){
				//MessageBox::Show("Username and password exist!");
				
				
				Options^ frm = gcnew Options(this);
				frm->StartPosition = FormStartPosition::Manual;
				frm->Location = this->Location;
				frm->Size = this->Size;
				frm->Show();
				this->usernameBox->Text = "";
				this->passwordBox->Text = "";
				this->Hide();
			}
			else{

				//888888888888888888888888888888888888888888888888888
				//std::string str = sha256("testing this motha");
				//String^ str2 = gcnew String(std::to_string(str.length()).c_str());

				//MessageBox::Show(str2);
			}
		}
		finally{}
	}
	private: System::Void signupButton_Click(System::Object^  sender, System::EventArgs^  e) {

		SignUp^ frm = gcnew SignUp(this);
		frm->StartPosition = FormStartPosition::Manual;
		frm->Location = this->Location;
		frm->Size = this->Size;
		frm->Show();
		this->Hide();
	}
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
}

		 
};


}
