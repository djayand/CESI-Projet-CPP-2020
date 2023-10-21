// WinMain.cpp
// Fichier qui permet de lancement de l'application

#include "Menu.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

int __clrcall WinMain(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	PooProject::menu Application;
	Application::Run(% Application);
}