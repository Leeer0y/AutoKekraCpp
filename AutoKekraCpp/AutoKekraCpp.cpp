// AutoKekraCpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Very usefull tutorial : https://www.youtube.com/watch?v=j4VFo4acorQ

#include <iostream>
#include <Windows.h>
#include <thread>

#include "defines.h"

double cpsMin = 12.0;
double cpsMax = 16.0;
double randomCps;

bool infoVisable = true;

double dRandRange(double min, double max)
{
    double f = (double)rand() / RAND_MAX;
    return min + f * (max - min);
}

void clearLine(COORD line, int length) {
    COORD topLeft = { 0, 0 }; //Coord to top left
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); //Get a handle on the console
    CONSOLE_SCREEN_BUFFER_INFO screen; //Buffer info variable
    DWORD written; // Type DWORD (32bit variable)

    GetConsoleScreenBufferInfo(console, &screen); //Get the buffer info
    FillConsoleOutputCharacterA(
        console, ' ', length, line, &written
    ); // Fill the console with char '' with the length of x on line y and point to the num of chars written https://docs.microsoft.com/en-us/windows/console/fillconsoleoutputcharacter
    FillConsoleOutputAttribute(
        console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
        length, line, &written
    ); //Get rid of colours in background
    SetConsoleCursorPosition(console, topLeft); //Set the cursor position
}

void keyThread()
{
    while (true) {
        if (GetAsyncKeyState(EXITBUTTON)) {
            std::cout << "exiting...\n";
            exit(EXIT_SUCCESS); // exit
        }
        if (GetAsyncKeyState(HOLDBUTTON))
        {
            INPUT iNPUT = { 0 };
            iNPUT.type = INPUT_MOUSE;
            iNPUT.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
            SendInput(1, &iNPUT, sizeof(iNPUT));
            ZeroMemory(&iNPUT, sizeof(iNPUT));
            iNPUT.type = INPUT_MOUSE;
            iNPUT.mi.dwFlags = MOUSEEVENTF_LEFTUP;
            SendInput(1, &iNPUT, sizeof(iNPUT));
            //std::cout << "The side mouse button was pressed!\n";
            randomCps = dRandRange(cpsMin, cpsMax);
            //std::cout << randomCps << std::endl;
            Sleep(1000 / randomCps);
        }
    }
}

void updateInfoThread()
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    double* randCpsAddr = &randomCps;

    while (true)
    {
        if (infoVisable == true) {
            clearLine({ 6, 11 }, 32);
            SetConsoleCursorPosition(console, { 0, 11 });
            std::cout << "CPS: " << *randCpsAddr << std::endl;
        }
        SetConsoleCursorPosition(console, { 0, 0 });
        Sleep(1000);
    }
}

int main()
{
    std::cout << "AUTO KEKRA CPP!\n";

    std::thread thread(keyThread);

    std::cout << " ____  __.      __                   " <<
        "\n |    |/ _|____ |  | ______________   " <<
        "\n |      <_/ __ \u005c|  |/ /\u005c_  __ \u005c__  \u005c  " <<
        "\n |    |  \u005c  ___/|    <  |  | \u005c// __ \u005c_" <<
        "\n |____|__ \u005c___  >__|_ \u005c |__|  (____  /" <<
        "\n         \u005c/   \u005c/     \u005c/            \u005c/ " << std::endl;
    
    std::cout << "-----Binds-----\n";
    std::cout << "Activate: " << HOLDBUTTON << std::endl;
    std::cout << "Exit: " << EXITBUTTON << std::endl;
    std::thread infoThread(updateInfoThread);
    thread.join();
    return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file0