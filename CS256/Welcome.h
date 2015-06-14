#pragma once
#include <msclr\marshal_cppstd.h>
#include <Vcclr.h>
#include <fstream>
#include <string>
#include "encryptoo.cpp"

namespace CS256 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace MySql::Data::MySqlClient;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

	/// <summary>
	/// Summary for Welcome
	/// </summary>
	public ref class Welcome : public System::Windows::Forms::Form
	{

	private: System::Windows::Forms::Form ^ otherform;
	private: String^ getinfo;
	public:
		Welcome(System::Windows::Forms::Form ^ o)
		{
			
			//comboBox1->Items->Add(" ");
			otherform = o;
			InitializeComponent();
	
			Fillcombo();

			//
			//TODO: Add the constructor code here
			//
		}
	public:
		Welcome(void)
		{
			
			InitializeComponent();
			Fillcombo();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Welcome()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  submitQuery;
	protected:

	private: System::Windows::Forms::TextBox^  showSSN;
	private: System::Windows::Forms::TextBox^  showFirst;
	private: System::Windows::Forms::TextBox^  showLast;
	protected:



	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Button^  rtnWelcomeBtn;

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
			this->submitQuery = (gcnew System::Windows::Forms::Button());
			this->showSSN = (gcnew System::Windows::Forms::TextBox());
			this->showFirst = (gcnew System::Windows::Forms::TextBox());
			this->showLast = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->rtnWelcomeBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// submitQuery
			// 
			this->submitQuery->Location = System::Drawing::Point(186, 188);
			this->submitQuery->Name = L"submitQuery";
			this->submitQuery->Size = System::Drawing::Size(75, 23);
			this->submitQuery->TabIndex = 0;
			this->submitQuery->Text = L"Query";
			this->submitQuery->UseVisualStyleBackColor = true;
			this->submitQuery->Click += gcnew System::EventHandler(this, &Welcome::submitQuery_Click);
			// 
			// showSSN
			// 
			this->showSSN->Location = System::Drawing::Point(79, 24);
			this->showSSN->Name = L"showSSN";
			this->showSSN->Size = System::Drawing::Size(100, 20);
			this->showSSN->TabIndex = 1;
			// 
			// showFirst
			// 
			this->showFirst->Location = System::Drawing::Point(79, 70);
			this->showFirst->Name = L"showFirst";
			this->showFirst->Size = System::Drawing::Size(100, 20);
			this->showFirst->TabIndex = 2;
			// 
			// showLast
			// 
			this->showLast->Location = System::Drawing::Point(79, 117);
			this->showLast->Name = L"showLast";
			this->showLast->Size = System::Drawing::Size(100, 20);
			this->showLast->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(55, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Username";
			this->label1->Click += gcnew System::EventHandler(this, &Welcome::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 70);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(53, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Password";
			this->label2->Click += gcnew System::EventHandler(this, &Welcome::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 124);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(29, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"SSN";
			this->label3->Click += gcnew System::EventHandler(this, &Welcome::label3_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(16, 176);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 7;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Welcome::comboBox1_SelectedIndexChanged);
			// 
			// rtnWelcomeBtn
			// 
			this->rtnWelcomeBtn->Location = System::Drawing::Point(186, 226);
			this->rtnWelcomeBtn->Name = L"rtnWelcomeBtn";
			this->rtnWelcomeBtn->Size = System::Drawing::Size(75, 23);
			this->rtnWelcomeBtn->TabIndex = 8;
			this->rtnWelcomeBtn->Text = L"Done";
			this->rtnWelcomeBtn->UseVisualStyleBackColor = true;
			this->rtnWelcomeBtn->Click += gcnew System::EventHandler(this, &Welcome::rtnWelcomeBtn_Click);
			// 
			// Welcome
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->rtnWelcomeBtn);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->showLast);
			this->Controls->Add(this->showFirst);
			this->Controls->Add(this->showSSN);
			this->Controls->Add(this->submitQuery);
			this->Name = L"Welcome";
			this->Text = L"Welcome";
			this->Load += gcnew System::EventHandler(this, &Welcome::Welcome_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Welcome_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: void Fillcombo(void){
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


	
			 String^ constring = L"datasource=localhost;port=3306;username=root;password=jl0794362";
			 MySqlConnection^ conDatabase = gcnew MySqlConnection(constring);
			 MySqlCommand^ cmdDataBase = gcnew MySqlCommand("select * from drillletter.users;", conDatabase);
			 MySqlDataReader^ myReader;
			 try{
				 conDatabase->Open();
				 myReader = cmdDataBase->ExecuteReader();

				 while (myReader->Read()){
					 String^ readName;
					 readName = myReader->GetString("username");
					 const char* userName =
						 (const char*)(Marshal::StringToHGlobalAnsi(readName)).ToPointer();;
					 std::string decrypt = cipher.decrypt(userName);
					 readName = gcnew String(decrypt.c_str());
					 CS256::Welcome::comboBox1->Items->Add(readName);
				 }

			 }
			 finally{}
		 }
private: System::Void rtnWelcomeBtn_Click(System::Object^  sender, System::EventArgs^  e) {

	this->Hide();
	otherform->Show();
}
private: System::Void submitQuery_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {

	String^ comboValue = comboBox1->Text;

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

	const char* userName =
		(const char*)(Marshal::StringToHGlobalAnsi(comboValue)).ToPointer();;
	std::string decrypt = cipher.encrypt(userName);
	comboValue = gcnew String(decrypt.c_str());

	String^ temp = "434d51c5183af28";
	String^ constring = L"datasource=localhost;port=3306;username=root;password=jl0794362";
	MySqlConnection^ conDatabase = gcnew MySqlConnection(constring);
	MySqlCommand^ cmdDataBase = gcnew MySqlCommand("select * from drillletter.users where username='"+comboValue+"';", conDatabase);
	MySqlDataReader^ myReader;
	try{
		conDatabase->Open();
		myReader = cmdDataBase->ExecuteReader();

		if(myReader->Read()){
			String^ username = myReader->GetString("username");
			const char* userName =
				(const char*)(Marshal::StringToHGlobalAnsi(username)).ToPointer();;
			std::string decrypt = cipher.decrypt(userName);
			username = gcnew String(decrypt.c_str());
			showSSN->Text = username;

			String^ password = myReader->GetString("password");
			const char* passWord =
				(const char*)(Marshal::StringToHGlobalAnsi(password)).ToPointer();;
			decrypt = cipher.decrypt(passWord);
			password = gcnew String(decrypt.c_str());
			showFirst->Text = password;

			String^ SSN = myReader->GetString("SSN");
			const char* SSNN =
				(const char*)(Marshal::StringToHGlobalAnsi(SSN)).ToPointer();;
			decrypt = cipher.decrypt(SSNN);
			SSN = gcnew String(decrypt.c_str());
			showLast->Text = SSN;
		}

	}
	finally{}
}
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
