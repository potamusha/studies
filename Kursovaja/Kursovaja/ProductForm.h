
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


	struct Product {
		char code[6];
		char name[50];
		char unit[5];
		double price;
		int quantity;
		char supplierCode[6];
	};

	/// <summary>
	/// Summary for ProductForm
	/// </summary>
	public ref class ProductForm : public System::Windows::Forms::Form
	{
	public:
		ProductForm(void)
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
		~ProductForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  txtCode;
	protected:
	private: System::Windows::Forms::TextBox^  txtName;
	private: System::Windows::Forms::TextBox^  txtUnit;
	private: System::Windows::Forms::TextBox^  txtPrice;
	private: System::Windows::Forms::Label^  labelCode;
	private: System::Windows::Forms::Label^  labelName;
	private: System::Windows::Forms::Label^  labelUnit;
	private: System::Windows::Forms::Label^  labelPrice;





	private: System::Windows::Forms::TextBox^  txtQuantity;
	private: System::Windows::Forms::TextBox^  txtSupplierCode;

	private: System::Windows::Forms::Label^  labelQuantity;
	private: System::Windows::Forms::Label^  labelSupplierCode;


	private: System::Windows::Forms::Button^  buttonAdd;

	private: System::Windows::Forms::Label^  label5;

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
			this->txtName = (gcnew System::Windows::Forms::TextBox());
			this->txtUnit = (gcnew System::Windows::Forms::TextBox());
			this->txtPrice = (gcnew System::Windows::Forms::TextBox());
			this->labelCode = (gcnew System::Windows::Forms::Label());
			this->labelName = (gcnew System::Windows::Forms::Label());
			this->labelUnit = (gcnew System::Windows::Forms::Label());
			this->labelPrice = (gcnew System::Windows::Forms::Label());
			this->txtQuantity = (gcnew System::Windows::Forms::TextBox());
			this->txtSupplierCode = (gcnew System::Windows::Forms::TextBox());
			this->labelQuantity = (gcnew System::Windows::Forms::Label());
			this->labelSupplierCode = (gcnew System::Windows::Forms::Label());
			this->buttonAdd = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// txtCode
			// 
			this->txtCode->Location = System::Drawing::Point(207, 27);
			this->txtCode->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->txtCode->Name = L"txtCode";
			this->txtCode->Size = System::Drawing::Size(68, 20);
			this->txtCode->TabIndex = 0;
			// 
			// txtName
			// 
			this->txtName->Location = System::Drawing::Point(207, 62);
			this->txtName->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->txtName->Name = L"txtName";
			this->txtName->Size = System::Drawing::Size(68, 20);
			this->txtName->TabIndex = 1;
			// 
			// txtUnit
			// 
			this->txtUnit->Location = System::Drawing::Point(207, 97);
			this->txtUnit->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->txtUnit->Name = L"txtUnit";
			this->txtUnit->Size = System::Drawing::Size(68, 20);
			this->txtUnit->TabIndex = 2;
			// 
			// txtPrice
			// 
			this->txtPrice->Location = System::Drawing::Point(207, 131);
			this->txtPrice->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->txtPrice->Name = L"txtPrice";
			this->txtPrice->Size = System::Drawing::Size(68, 20);
			this->txtPrice->TabIndex = 3;
			// 
			// labelCode
			// 
			this->labelCode->AutoSize = true;
			this->labelCode->Location = System::Drawing::Point(69, 27);
			this->labelCode->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->labelCode->Name = L"labelCode";
			this->labelCode->Size = System::Drawing::Size(32, 13);
			this->labelCode->TabIndex = 4;
			this->labelCode->Text = L"Code";
			// 
			// labelName
			// 
			this->labelName->AutoSize = true;
			this->labelName->Location = System::Drawing::Point(72, 62);
			this->labelName->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->labelName->Name = L"labelName";
			this->labelName->Size = System::Drawing::Size(35, 13);
			this->labelName->TabIndex = 5;
			this->labelName->Text = L"Name";
			// 
			// labelUnit
			// 
			this->labelUnit->AutoSize = true;
			this->labelUnit->Location = System::Drawing::Point(72, 101);
			this->labelUnit->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->labelUnit->Name = L"labelUnit";
			this->labelUnit->Size = System::Drawing::Size(26, 13);
			this->labelUnit->TabIndex = 6;
			this->labelUnit->Text = L"Unit";
			// 
			// labelPrice
			// 
			this->labelPrice->AutoSize = true;
			this->labelPrice->Location = System::Drawing::Point(72, 135);
			this->labelPrice->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->labelPrice->Name = L"labelPrice";
			this->labelPrice->Size = System::Drawing::Size(31, 13);
			this->labelPrice->TabIndex = 7;
			this->labelPrice->Text = L"Price";
			// 
			// txtQuantity
			// 
			this->txtQuantity->Location = System::Drawing::Point(207, 167);
			this->txtQuantity->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->txtQuantity->Name = L"txtQuantity";
			this->txtQuantity->Size = System::Drawing::Size(68, 20);
			this->txtQuantity->TabIndex = 8;
			// 
			// txtSupplierCode
			// 
			this->txtSupplierCode->Location = System::Drawing::Point(207, 205);
			this->txtSupplierCode->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->txtSupplierCode->Name = L"txtSupplierCode";
			this->txtSupplierCode->Size = System::Drawing::Size(68, 20);
			this->txtSupplierCode->TabIndex = 9;
			// 
			// labelQuantity
			// 
			this->labelQuantity->AutoSize = true;
			this->labelQuantity->Location = System::Drawing::Point(72, 167);
			this->labelQuantity->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->labelQuantity->Name = L"labelQuantity";
			this->labelQuantity->Size = System::Drawing::Size(46, 13);
			this->labelQuantity->TabIndex = 12;
			this->labelQuantity->Text = L"Quantity";
			// 
			// labelSupplierCode
			// 
			this->labelSupplierCode->AutoSize = true;
			this->labelSupplierCode->Location = System::Drawing::Point(69, 205);
			this->labelSupplierCode->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->labelSupplierCode->Name = L"labelSupplierCode";
			this->labelSupplierCode->Size = System::Drawing::Size(72, 13);
			this->labelSupplierCode->TabIndex = 13;
			this->labelSupplierCode->Text = L"Supplier code";
			// 
			// buttonAdd
			// 
			this->buttonAdd->Location = System::Drawing::Point(195, 253);
			this->buttonAdd->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->buttonAdd->Name = L"buttonAdd";
			this->buttonAdd->Size = System::Drawing::Size(89, 19);
			this->buttonAdd->TabIndex = 14;
			this->buttonAdd->Text = L"Add";
			this->buttonAdd->UseVisualStyleBackColor = true;
			this->buttonAdd->Click += gcnew System::EventHandler(this, &ProductForm::button1_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(69, 297);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(35, 13);
			this->label5->TabIndex = 15;
			this->label5->Text = L"label5";
			// 
			// ProductForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(508, 438);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->buttonAdd);
			this->Controls->Add(this->labelSupplierCode);
			this->Controls->Add(this->labelQuantity);
			this->Controls->Add(this->txtSupplierCode);
			this->Controls->Add(this->txtQuantity);
			this->Controls->Add(this->labelPrice);
			this->Controls->Add(this->labelUnit);
			this->Controls->Add(this->labelName);
			this->Controls->Add(this->labelCode);
			this->Controls->Add(this->txtPrice);
			this->Controls->Add(this->txtUnit);
			this->Controls->Add(this->txtName);
			this->Controls->Add(this->txtCode);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"ProductForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Product";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion



private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

	
	
	Product newProduct;

	//addAsCharArray(newProduct.code, txtCode->Text);
	
	strcpy(newProduct.code, marshal_as<std::string>(txtCode->Text).c_str());
	newProduct.code[sizeof(newProduct.code)] = '\0';
		
	strcpy(newProduct.name, marshal_as<std::string>(txtName->Text).c_str());
	newProduct.name[sizeof(newProduct.name)] = '\0';

	strcpy(newProduct.unit, marshal_as<std::string>(txtUnit->Text).c_str());
	newProduct.unit[sizeof(newProduct.unit)] = '\0';

	newProduct.price = Convert::ToDouble(txtPrice->Text);
	newProduct.quantity = Convert::ToInt32(txtQuantity->Text);

	strcpy(newProduct.supplierCode, marshal_as<std::string>(txtSupplierCode->Text).c_str());
	newProduct.unit[sizeof(newProduct.supplierCode)] = '\0';

	
	FILE *fp = fopen("products.dat", "wb");
	fwrite(&newProduct, sizeof(Product), 1, fp);
	fclose(fp);

	
	Product loadedProduct;
	
	FILE *fpread= fopen("products.dat", "rb");
	fread(&loadedProduct, sizeof(Product), 1, fpread);
	fclose(fpread);

	
	label5->Text = "Created product: \n"
		+ marshal_as <String^>(loadedProduct.code) + "\n"
			+ marshal_as <String^>(loadedProduct.name) + "\n"
			+ marshal_as <String^>(loadedProduct.unit) + "\n"
		+ loadedProduct.price.ToString("n") + "\n"
		+ loadedProduct.quantity.ToString("n") + "\n"
		+ marshal_as <String^>(loadedProduct.supplierCode);

	
}


		 


};
}

