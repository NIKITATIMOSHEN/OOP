#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;

[System::Runtime::InteropServices::DllImport("user32.dll")]
bool SetProcessDPIAware();

[STAThreadAttribute]
void main()
{
	//Функція що покращує відображення графічного інтерфейсу для екранів з різним DPI
	if (Environment::OSVersion->Version->Major >= 6)
		SetProcessDPIAware();

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(true);

	//Створюємо об'єкт головної форми на запускаємо його
	TransportApplication::MainForm form;
	Application::Run(% form);
}
