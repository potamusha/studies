#include "ProductForm.h"
#include "SupplierForm.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Kursovaja::ProductForm form;
	Kursovaja::SupplierForm form1;
	Application::Run(%form);
	Application::Run(%form1);
}
