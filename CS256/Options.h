#pragma once
#include "Insert.h"
#include "Welcome.h"

namespace CS256 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Options
	/// </summary>
	public ref class Options : public System::Windows::Forms::Form
	{

	private: System::Windows::Forms::Form ^ otherform;
	public:
		Options(System::Windows::Forms::Form ^ o)
		{
			otherform = o;
			InitializeComponent();

			//
			//TODO: Add the constructor code here
			//
		}
	public:
		Options(void)
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
		~Options()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  viewDatabase;
	protected:

	private: System::Windows::Forms::Button^  insertDatabase;

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
			this->viewDatabase = (gcnew System::Windows::Forms::Button());
			this->insertDatabase = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// viewDatabase
			// 
			this->viewDatabase->Location = System::Drawing::Point(93, 84);
			this->viewDatabase->Name = L"viewDatabase";
			this->viewDatabase->Size = System::Drawing::Size(104, 23);
			this->viewDatabase->TabIndex = 0;
			this->viewDatabase->Text = L"View Database";
			this->viewDatabase->UseVisualStyleBackColor = true;
			this->viewDatabase->Click += gcnew System::EventHandler(this, &Options::button1_Click);
			// 
			// insertDatabase
			// 
			this->insertDatabase->Location = System::Drawing::Point(93, 150);
			this->insertDatabase->Name = L"insertDatabase";
			this->insertDatabase->Size = System::Drawing::Size(104, 23);
			this->insertDatabase->TabIndex = 1;
			this->insertDatabase->Text = L"Insert to Database";
			this->insertDatabase->UseVisualStyleBackColor = true;
			this->insertDatabase->Click += gcnew System::EventHandler(this, &Options::insertDatabase_Click);
			// 
			// Options
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->insertDatabase);
			this->Controls->Add(this->viewDatabase);
			this->Name = L"Options";
			this->Text = L"Options";
			this->Load += gcnew System::EventHandler(this, &Options::Options_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Options_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		Welcome^ frm = gcnew Welcome(this);
		frm->StartPosition = FormStartPosition::Manual;
		frm->Location = this->Location;
		frm->Size = this->Size;
		frm->Show();
		this->Hide();
	}
	private: System::Void insertDatabase_Click(System::Object^  sender, System::EventArgs^  e) {
		Insert^ frm = gcnew Insert(this);
		frm->StartPosition = FormStartPosition::Manual;
		frm->Location = this->Location;
		frm->Size = this->Size;
		frm->Show();
		this->Hide();
	}
};
}
