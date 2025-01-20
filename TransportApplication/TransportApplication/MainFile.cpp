#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;

[System::Runtime::InteropServices::DllImport("user32.dll")]
bool SetProcessDPIAware();

[STAThreadAttribute]
void main()
{
	//������� �� ������� ����������� ���������� ���������� ��� ������ � ����� DPI
	if (Environment::OSVersion->Version->Major >= 6)
		SetProcessDPIAware();

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(true);

	//��������� ��'��� ������� ����� �� ��������� ����
	TransportApplication::MainForm form;
	Application::Run(% form);
}
