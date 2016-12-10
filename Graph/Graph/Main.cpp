#include "GraphForm.h"
#include <iostream>
using namespace GraphProject;
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(cli::array<System::String^, 1>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	GraphForm ^form = gcnew GraphForm;
	Application::Run(form);

	return 0;
}