#pragma once

#include <iostream>
#include <windows.h>

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

    // Fill the console with char '' with the length of x on line y and point to the num of chars written https://docs.microsoft.com/en-us/windows/console/fillconsoleoutputcharacter
    FillConsoleOutputCharacterA(
        console, ' ', length, line, &written
    );

    //Get rid of colours in background
    FillConsoleOutputAttribute(
        console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
        length, line, &written
    );

    SetConsoleCursorPosition(console, topLeft); //Set the cursor position
}