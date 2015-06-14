#pragma once
//#include "cryptoPPP.h"
#include "MyForm.h"
#include "stdafx.h"
#include "SignUp.h"
#include "Welcome.h"
#include "encryptoo.cpp"
#include "md5.cpp"
#include <msclr\marshal_cppstd.h>
#include <Vcclr.h>
#include <string>
#include <fstream>



namespace CS256 {

	using namespace System;
	using namespace System::Runtime::InteropServices;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;
	

	/// <summary>
	/// Summary for SignUp
	/// </summary>
	public ref class SignUp : public System::Windows::Forms::Form
	{
	private: System::Windows::Forms::Form ^ otherform;
	public:
		SignUp(System::Windows::Forms::Form ^ o)
		{
			otherform = o;
			InitializeComponent();

			//
			//TODO: Add the constructor code here
			//
		}

	public:
		SignUp(void)
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
		~SignUp()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  plainTextOne;
	protected:



	private: System::Windows::Forms::Button^  generateButton;


	protected:

	protected:






	private: System::Windows::Forms::Label^  label2;



	private: System::Windows::Forms::Button^  signUpSubmit;
	private: System::Windows::Forms::Label^  labelSSN;
	private: System::Windows::Forms::TextBox^  plainTextTwo;


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
			this->plainTextOne = (gcnew System::Windows::Forms::TextBox());
			this->generateButton = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->signUpSubmit = (gcnew System::Windows::Forms::Button());
			this->labelSSN = (gcnew System::Windows::Forms::Label());
			this->plainTextTwo = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// plainTextOne
			// 
			this->plainTextOne->Location = System::Drawing::Point(151, 61);
			this->plainTextOne->Name = L"plainTextOne";
			this->plainTextOne->Size = System::Drawing::Size(100, 20);
			this->plainTextOne->TabIndex = 1;
			// 
			// generateButton
			// 
			this->generateButton->Location = System::Drawing::Point(94, 149);
			this->generateButton->Name = L"generateButton";
			this->generateButton->Size = System::Drawing::Size(136, 23);
			this->generateButton->TabIndex = 3;
			this->generateButton->Text = L"Generate Keys";
			this->generateButton->UseVisualStyleBackColor = true;
			this->generateButton->Click += gcnew System::EventHandler(this, &SignUp::generateButton_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 68);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(84, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Fist Action Code";
			this->label2->Click += gcnew System::EventHandler(this, &SignUp::label2_Click);
			// 
			// signUpSubmit
			// 
			this->signUpSubmit->Location = System::Drawing::Point(225, 222);
			this->signUpSubmit->Name = L"signUpSubmit";
			this->signUpSubmit->Size = System::Drawing::Size(52, 25);
			this->signUpSubmit->TabIndex = 11;
			this->signUpSubmit->Text = L"Submit";
			this->signUpSubmit->UseVisualStyleBackColor = true;
			this->signUpSubmit->Click += gcnew System::EventHandler(this, &SignUp::signUpSubmit_Click);
			// 
			// labelSSN
			// 
			this->labelSSN->AutoSize = true;
			this->labelSSN->Location = System::Drawing::Point(14, 95);
			this->labelSSN->Name = L"labelSSN";
			this->labelSSN->Size = System::Drawing::Size(110, 13);
			this->labelSSN->TabIndex = 12;
			this->labelSSN->Text = L"Second Access Code";
			this->labelSSN->Click += gcnew System::EventHandler(this, &SignUp::labelSSN_Click);
			// 
			// plainTextTwo
			// 
			this->plainTextTwo->Location = System::Drawing::Point(151, 92);
			this->plainTextTwo->Name = L"plainTextTwo";
			this->plainTextTwo->Size = System::Drawing::Size(100, 20);
			this->plainTextTwo->TabIndex = 13;
			// 
			// SignUp
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(289, 261);
			this->Controls->Add(this->plainTextTwo);
			this->Controls->Add(this->labelSSN);
			this->Controls->Add(this->signUpSubmit);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->generateButton);
			this->Controls->Add(this->plainTextOne);
			this->Name = L"SignUp";
			this->Text = L"SignUp";
			this->Load += gcnew System::EventHandler(this, &SignUp::SignUp_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void SignUp_Load(System::Object^  sender, System::EventArgs^  e) {

		
	}
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void generateButton_Click(System::Object^  sender, System::EventArgs^  e) {

	//get first part of plaintext
	const char* chars = 
      (const char*)(Marshal::StringToHGlobalAnsi(this->plainTextOne->Text)).ToPointer();
	
	//get second part of plaintext
	const char* chars2 =
		(const char*)(Marshal::StringToHGlobalAnsi(this->plainTextTwo->Text)).ToPointer();

	string plainText = chars;
	plainText += chars2;
	//String^ test = gcnew String(plainText.c_str());
	std::string str = md5(plainText);
	Vigenere cipher(str);
	
	string temp = cipher.encrypt(plainText);

	
	 //cipher.encrypt("testing");
	string hello = "hello world";
	std::string encrypt = cipher.encrypt(hello);
	std::string decrypt = cipher.decrypt(encrypt);
	String^ keytwo = gcnew String(str.c_str());
	ofstream myfile;
	myfile.open("encryption.txt");
	myfile << str;
	myfile.close();
	//MessageBox::Show(keytwo);
	//std::string key1 = plainText.substr(0, 15);
	//std::string key2 = plainText.substr(16, 31);

	//String^ keytwo = gcnew String(key2.c_str());
	//String^ keyone = gcnew String(key1.c_str());
}
private: System::Void signUpSubmit_Click(System::Object^  sender, System::EventArgs^  e) {
	/*
	String^ constring = L"datasource=localhost;port=3306;username=root;password=jl0794362";
	MySqlConnection^ conDatabase = gcnew MySqlConnection(constring);
	MySqlCommand^ cmdDataBase = gcnew MySqlCommand("insert into drillletter.users (username,password,SSN,key1,key2) values('" + this->usernameSU->Text + "','" + this->passwordSU->Text + "','" + this->SSNSU->Text + "','" + this->firstKey->Text + "', '" + this->secondKey->Text + "');", conDatabase);
	MySqlDataReader^ myReader;
	try{
		conDatabase->Open();
		myReader = cmdDataBase->ExecuteReader();

		while (myReader->Read()){
			
		}

	}
	finally{}*/
	this->Hide();
	otherform->Show();

	
}
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void labelSSN_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
