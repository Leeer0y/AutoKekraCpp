#pragma once
#include <string>

/*
This header file defines in the main code what button does what.
Feel free to change the keybinds but DO NOT CHANGE THE NAMES as it will break the program.

The values used for input is Virtual Keyboard from winuser.h, You can use the constant value or the hex value.
Here is a link to the Virtual-Key Codes https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes

*/

int HOLDBUTTON = VK_XBUTTON2;
int EXITBUTTON = VK_NUMPAD0;

double cpsMin = 12.0;
double cpsMax = 16.0;

void settingsInit() {
	bool isValid = true;
	std::string lines[22];

	std::ifstream is;
	is.open("settings.txt");
	for (int i = 0; i < 22; i++)
	{
		is >> lines[i];
		//std::cout << lines[i] << std::endl;
	}

	for (int i = 0; i < lines[12].length(); i++)
	{
		if (!isdigit(lines[12][i]))
		{
			int msgboxID = MessageBox(
				NULL,
				(LPCWSTR)L"Invalid option for HOLDBUTTON, please use a key code. Reverting to defult..",
				(LPCWSTR)L"Account Details",
				MB_ICONWARNING | MB_OK | MB_DEFBUTTON2
			);
			isValid = false;
			return;
		}
	}

		HOLDBUTTON = std::stoi(lines[12]);

	for (int i = 0; i < lines[12].length(); i++)
	{
		if (!isdigit(lines[15][i]))
		{
			int msgboxID = MessageBox(
				NULL,
				(LPCWSTR)L"Invalid option for EXITBUTTON, please use a key code. Reverting to defult.",
				(LPCWSTR)L"Account Details",
				MB_ICONWARNING | MB_OK | MB_DEFBUTTON2
			);
			isValid = false;
			return;
		}
	}

	EXITBUTTON = std::stoi(lines[15]);

	for (int i = 0; i < lines[18].length(); i++)
	{
		if (!isdigit(lines[18][i]) && lines[18][i] != '.')
		{
			int msgboxID = MessageBox(
				NULL,
				(LPCWSTR)L"Invalid option for cpsMin, please use a key code. Reverting to defult.",
				(LPCWSTR)L"Account Details",
				MB_ICONWARNING | MB_OK | MB_DEFBUTTON2
			);
			isValid = false;
			return;

		}
	}

	cpsMin = std::stod(lines[18]);

	for (int i = 0; i < lines[21].length(); i++)
	{
		if (!isdigit(lines[21][i]) && lines[21][i] != '.')
		{
			int msgboxID = MessageBox(
				NULL,
				(LPCWSTR)L"Invalid option for cpsMin, please use a key code. Reverting to defult.",
				(LPCWSTR)L"Account Details",
				MB_ICONWARNING | MB_OK | MB_DEFBUTTON2
			);
			isValid = false;
			return;
		}
	}

	cpsMax = std::stod(lines[21]);
}


