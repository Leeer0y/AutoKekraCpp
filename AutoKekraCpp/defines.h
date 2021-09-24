#pragma once
#include <string>

/*
This header file defines in the main code what button does what.
Feel free to change the keybinds but DO NOT CHANGE THE NAMES as it will break the program.

The values used for input is Virtual Keyboard from winuser.h, You can use the constant value or the hex value.
Here is a link to the Virtual-Key Codes https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes

*/

int holdBTN = VK_XBUTTON2;
int exitBTN = VK_NUMPAD0;

double cpsMin = 12.0;
double cpsMax = 16.0;

void settingsInit() {
	bool isValid = true;
	std::string words[22];

	std::ifstream is;
	is.open("settings.txt");
	if (is)
	{
		for (int i = 0; i < 22; i++)
		{
			is >> words[i];
			//std::cout << lines[i] << std::endl;

		}
		is.close();
	}
	else
	{
		int msgboxID = MessageBox(
			NULL,
			(LPCWSTR)L"Settings file does not exist, would you like to create it?",
			(LPCWSTR)L"Alert",
			MB_ICONWARNING | MB_YESNO | MB_DEFBUTTON2
		);
		if (msgboxID == 6)
		{
			std::ofstream sf("settings.txt");
			sf << "Binds for auto kekra! \nuse https://docs.microsoft.com/en-us/dotnet/api/system.windows.forms.keys?view=net-5.0 for list of key codes.\n\nHOLDBUTTON: 6 \nEXITBUTTON: 96 \n\nCpsMin: 12.0\nCpsMax: 16.0";
			sf.close();
			std::ifstream insf;
			insf.open("settings.txt");
			for (int i = 0; i < 22; i++)
			{
				insf >> words[i];
				//std::cout << lines[i] << std::endl;
			}
			insf.close();
		}
		else if (msgboxID == 7)
		{
			int msgboxDBN = MessageBox(
				NULL,
				(LPCWSTR)L"Ok, reverting to defult binds.",
				(LPCWSTR)L"Alert",
				MB_ICONWARNING | MB_OK | MB_DEFBUTTON2
			);
			return;
		}
	}

	for (int i = 0; i < 22; i++)
	{
		//std::cout << words[i];
		if (std::strcmp(words[i].c_str(), "HOLDBUTTON:") == 0)
		{
			for (int x = 0; x < words[i + 1].length(); x++)
			{
				if (!isdigit(words[i + 1][x]))
				{
					int msgboxID = MessageBox(
						NULL,
						(LPCWSTR)L"Invalid option for HOLDBUTTON, please use a key code. Reverting to defult..",
						(LPCWSTR)L"Alert",
						MB_ICONWARNING | MB_OK | MB_DEFBUTTON2
					);
					isValid = false;
					return;
				}
			}
			holdBTN = std::stoi(words[i + 1]);
		}
		
		if (std::strcmp(words[i].c_str(), "EXITBUTTON:") == 0)
		{
			for (int x = 0; x < words[i + 1].length(); x++)
			{
				if (!isdigit(words[i + 1][x]))
				{
					int msgboxID = MessageBox(
						NULL,
						(LPCWSTR)L"Invalid option for EXITBUTTON, please use a key code. Reverting to defult..",
						(LPCWSTR)L"Alert",
						MB_ICONWARNING | MB_OK | MB_DEFBUTTON2
					);
					isValid = false;
					return;
				}
			}
			exitBTN = std::stoi(words[i + 1]);
		}

		if (std::strcmp(words[i].c_str(), "CpsMin:") == 0)
		{
			for (int x = 0; x < words[i + 1].length(); x++)
			{
				if (!isdigit(words[i + 1][x]) && words[i + 1][x] != '.')
				{
					int msgboxID = MessageBox(
						NULL,
						(LPCWSTR)L"Invalid option for CpsMin, please use a number. Reverting to defult..",
						(LPCWSTR)L"Alert",
						MB_ICONWARNING | MB_OK | MB_DEFBUTTON2
					);
					isValid = false;
					return;
				}
			}
			cpsMin = std::stod(words[i + 1]);
		}

		if (std::strcmp(words[i].c_str(), "CpsMax:") == 0)
		{
			for (int x = 0; x < words[i + 1].length(); x++)
			{
				if (!isdigit(words[i + 1][x]) && words[i + 1][x] != '.')
				{
					int msgboxID = MessageBox(
						NULL,
						(LPCWSTR)L"Invalid option for CpsMax, please use a number. Reverting to defult..",
						(LPCWSTR)L"Alert",
						MB_ICONWARNING | MB_OK | MB_DEFBUTTON2
					);
					isValid = false;
					return;
				}
			}
			cpsMax = std::stod(words[i + 1]);
		}
		
	}
}


