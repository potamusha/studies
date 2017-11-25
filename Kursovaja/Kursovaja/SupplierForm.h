#include <msclr\marshal_cppstd.h>

#pragma once

namespace Kursovaja {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;


	struct Supplier {
		char code[6];
		char name[25];
		char address[25];
	};


	/// <summary>
	/// Summary for SupplierForm
	/// </summary>
	public ref class SupplierForm : public System::Windows::Forms::Form
	{
	public:
		SupplierForm(void)
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
		~SupplierForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  txtCode;
	protected:

	protected:

	protected:
	private: System::Windows::Forms::Label^  labelSupplierCode;
	private: System::Windows::Forms::Button^  buttonAdd;
	private: System::Windows::Forms::Label^  labelAddress;
	private: System::Windows::Forms::Label^  labelName;
	private: System::Windows::Forms::TextBox^  txtAddress;
	private: System::Windows::Forms::TextBox^  txtName;
	private: System::Windows::Forms::Label^  label1;


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
			this->txtCode = (gcnew System::Windows::Forms::TextBox());
			this->labelSupplierCode = (gcnew System::Windows::Forms::Label());
			this->buttonAdd = (gcnew System::Windows::Forms::Button());
			this->labelAddress = (gcnew System::Windows::Forms::Label());
			this->labelName = (gcnew System::Windows::Forms::Label());
			this->txtAddress = (gcnew System::Windows::Forms::TextBox());
			this->txtName = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// txtCode
			// 
			this->txtCode->Location = System::Drawing::Point(221, 54);
			this->txtCode->Name = L"txtCode";
			this->txtCode->Size = System::Drawing::Size(100, 20);
			this->txtCode->TabIndex = 0;
			// 
			// labelSupplierCode
			// 
			this->labelSupplierCode->AutoSize = true;
			this->labelSupplierCode->Enabled = false;
			this->labelSupplierCode->Location = System::Drawing::Point(72, 54);
			this->labelSupplierCode->Name = L"labelSupplierCode";
			this->labelSupplierCode->Size = System::Drawing::Size(32, 13);
			this->labelSupplierCode->TabIndex = 1;
			this->labelSupplierCode->Text = L"Code";
			// 
			// buttonAdd
			// 
			this->buttonAdd->Location = System::Drawing::Point(221, 252);
			this->buttonAdd->Name = L"buttonAdd";
			this->buttonAdd->Size = System::Drawing::Size(75, 23);
			this->buttonAdd->TabIndex = 2;
			this->buttonAdd->Text = L"Add";
			this->buttonAdd->UseVisualStyleBackColor = true;
			this->buttonAdd->Click += gcnew System::EventHandler(this, &SupplierForm::buttonAdd_Click);
			// 
			// labelAddress
			// 
			this->labelAddress->AutoSize = true;
			this->labelAddress->Enabled = false;
			this->labelAddress->Location = System::Drawing::Point(72, 171);
			this->labelAddress->Name = L"labelAddress";
			this->labelAddress->Size = System::Drawing::Size(45, 13);
			this->labelAddress->TabIndex = 3;
			this->labelAddress->Text = L"Address";
			// 
			// labelName
			// 
			this->labelName->AutoSize = true;
			this->labelName->Enabled = false;
			this->labelName->Location = System::Drawing::Point(72, 109);
			this->labelName->Name = L"labelName";
			this->labelName->Size = System::Drawing::Size(35, 13);
			this->labelName->TabIndex = 4;
			this->labelName->Text = L"Name";
			// 
			// txtAddress
			// 
			this->txtAddress->Location = System::Drawing::Point(221, 171);
			this->txtAddress->Name = L"txtAddress";
			this->txtAddress->Size = System::Drawing::Size(100, 20);
			this->txtAddress->TabIndex = 5;
			// 
			// txtName
			// 
			this->txtName->Location = System::Drawing::Point(221, 109);
			this->txtName->Name = L"txtName";
			this->txtName->Size = System::Drawing::Size(100, 20);
			this->txtName->TabIndex = 6;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(72, 380);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 7;
			this->label1->Text = L"label1";
			
			// 
			// SupplierForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(511, 471);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtName);
			this->Controls->Add(this->txtAddress);
			this->Controls->Add(this->labelName);
			this->Controls->Add(this->labelAddress);
			this->Controls->Add(this->buttonAdd);
			this->Controls->Add(this->labelSupplierCode);
			this->Controls->Add(this->txtCode);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"SupplierForm";
			this->Text = L"SupplierForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonAdd_Click(System::Object^  sender, System::EventArgs^  e) {


		Supplier newSupplier;

		strcpy(newSupplier.code, marshal_as<std::string>(txtCode->Text).c_str());
		newSupplier.code[sizeof(newSupplier.code)] = '\0';


		newSupplier.code = marshal_as< std::string >(txtCode->Text);
		newSupplier.name = marshal_as< std::string >(txtName->Text);
		newSupplier.address = marshal_as< std::string >(txtAddress->Text);
		
		label1->Text = "Created supplier: \n"
			+ marshal_as <String^>(newSupplier.code) + "\n"
			+ marshal_as <String^>(newSupplier.name) + "\n"
			+ marshal_as <String^>(newSupplier.address);
			

	}

};
}
