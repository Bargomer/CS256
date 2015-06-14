#pragma once
#include "stdafx.h"
#include <fstream>
#include "encryptoo.cpp"
#include <string>
#include <msclr\marshal_cppstd.h>
#include <Vcclr.h>

namespace CS256 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;
	using namespace System::Runtime::InteropServices;

	/// <summary>
	/// Summary for Insert
	/// </summary>
	public ref class Insert : public System::Windows::Forms::Form
	{
	private: System::Windows::Forms::Form ^ otherform;
	public:
		Insert(System::Windows::Forms::Form ^ o)
		{

			//comboBox1->Items->Add(" ");
			otherform = o;
			InitializeComponent();

			//
			//TODO: Add the constructor code here
			//
		}

	public:
		Insert(void)
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
		~Insert()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  insertUsername;
	protected:

	private: System::Windows::Forms::Label^  label43243;
	private: System::Windows::Forms::Label^  labelw;
	private: System::Windows::Forms::TextBox^  insertPassword;
	protected:



	private: System::Windows::Forms::Label^  label555;
	private: System::Windows::Forms::TextBox^  insertSSN;



	private: System::Windows::Forms::Button^  submitInsert;

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
			this->insertUsername = (gcnew System::Windows::Forms::TextBox());
			this->label43243 = (gcnew System::Windows::Forms::Label());
			this->labelw = (gcnew System::Windows::Forms::Label());
			this->insertPassword = (gcnew System::Windows::Forms::TextBox());
			this->label555 = (gcnew System::Windows::Forms::Label());
			this->insertSSN = (gcnew System::Windows::Forms::TextBox());
			this->submitInsert = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// insertUsername
			// 
			this->insertUsername->Location = System::Drawing::Point(135, 47);
			this->insertUsername->Name = L"insertUsername";
			this->insertUsername->Size = System::Drawing::Size(100, 20);
			this->insertUsername->TabIndex = 0;
			// 
			// label43243
			// 
			this->label43243->AutoSize = true;
			this->label43243->Location = System::Drawing::Point(37, 53);
			this->label43243->Name = L"label43243";
			this->label43243->Size = System::Drawing::Size(55, 13);
			this->label43243->TabIndex = 1;
			this->label43243->Text = L"Username";
			// 
			// labelw
			// 
			this->labelw->AutoSize = true;
			this->labelw->Location = System::Drawing::Point(37, 95);
			this->labelw->Name = L"labelw";
			this->labelw->Size = System::Drawing::Size(53, 13);
			this->labelw->TabIndex = 3;
			this->labelw->Text = L"Password";
			// 
			// insertPassword
			// 
			this->insertPassword->Location = System::Drawing::Point(135, 89);
			this->insertPassword->Name = L"insertPassword";
			this->insertPassword->Size = System::Drawing::Size(100, 20);
			this->insertPassword->TabIndex = 2;
			// 
			// label555
			// 
			this->label555->AutoSize = true;
			this->label555->Location = System::Drawing::Point(37, 134);
			this->label555->Name = L"label555";
			this->label555->Size = System::Drawing::Size(29, 13);
			this->label555->TabIndex = 5;
			this->label555->Text = L"SSN";
			// 
			// insertSSN
			// 
			this->insertSSN->Location = System::Drawing::Point(135, 128);
			this->insertSSN->Name = L"insertSSN";
			this->insertSSN->Size = System::Drawing::Size(100, 20);
			this->insertSSN->TabIndex = 4;
			// 
			// submitInsert
			// 
			this->submitInsert->Location = System::Drawing::Point(184, 216);
			this->submitInsert->Name = L"submitInsert";
			this->submitInsert->Size = System::Drawing::Size(75, 23);
			this->submitInsert->TabIndex = 6;
			this->submitInsert->Text = L"Submit";
			this->submitInsert->UseVisualStyleBackColor = true;
			this->submitInsert->Click += gcnew System::EventHandler(this, &Insert::submitInsert_Click);
			// 
			// Insert
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->submitInsert);
			this->Controls->Add(this->label555);
			this->Controls->Add(this->insertSSN);
			this->Controls->Add(this->labelw);
			this->Controls->Add(this->insertPassword);
			this->Controls->Add(this->label43243);
			this->Controls->Add(this->insertUsername);
			this->Name = L"Insert";
			this->Text = L"Insert";
			this->Load += gcnew System::EventHandler(this, &Insert::Insert_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Insert_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void submitInsert_Click(System::Object^  sender, System::EventArgs^  e) {
		
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
		string plainText = "Hello world";

		string temp = cipher.encrypt(plainText);
		//get first part of plaintext
		const char* userName =
			(const char*)(Marshal::StringToHGlobalAnsi(this->insertUsername->Text)).ToPointer();;
		const char* password =
			(const char*)(Marshal::StringToHGlobalAnsi(this->insertPassword->Text)).ToPointer();
		const char* SSN =
			(const char*)(Marshal::StringToHGlobalAnsi(this->insertSSN->Text)).ToPointer();
		
		//encrypt username
		std::string encrypt = cipher.encrypt(userName);
		String^ user = gcnew String(encrypt.c_str());
		//encrypt password
		encrypt = cipher.encrypt(password);
		String^ pass = gcnew String(encrypt.c_str());
		//encrypt ssn
		encrypt = cipher.encrypt(SSN);
		String^ SSNN = gcnew String(encrypt.c_str());
		
		
		String^ constring = L"datasource=localhost;port=3306;username=root;password=jl0794362";
		MySqlConnection^ conDatabase = gcnew MySqlConnection(constring);
		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("insert into drillletter.users (username,password,SSN) values('" + user + "','" + pass + "','" + SSNN + "');", conDatabase);
		MySqlDataReader^ myReader;
		try{
		conDatabase->Open();
		myReader = cmdDataBase->ExecuteReader();

		while (myReader->Read()){

		}

		}
		finally{}
		this->Hide();
		otherform->Show();
	}
};
}
