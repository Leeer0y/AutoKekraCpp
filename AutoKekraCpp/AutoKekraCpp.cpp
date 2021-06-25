// AutoKekraCpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Very usefull tutorial : https://www.youtube.com/watch?v=j4VFo4acorQ

#include <iostream>
#include <Windows.h>
#include <thread>

#include "defines.h"

double cpsMin = 12.0;
double cpsMax = 16.0;
double randomCps;

double dRandRange(double min, double max)
{
    double f = (double)rand() / RAND_MAX;
    return min + f * (max - min);
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
