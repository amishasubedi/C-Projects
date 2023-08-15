#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <time.h>
#include <windows.h>

int t, speed = 40;

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void delay(int milliseconds)
{
    Sleep(milliseconds);
}

void ds(int jump = 0)
{
    static int a = 1; // leg animations of dinosaur controller

    if (jump == 0)
    {
        t = 0;
    }
    else if (jump == 2)
    {
        t--;
    }
    else
    {
        t++;
    }

    gotoxy(2, 15 - t);
    printf("                  ");
    gotoxy(2, 16 - t);
    printf("        $$$$$$$ \n");
    gotoxy(2, 17 - t);
    printf("       $$ $$$$$$\n");
    gotoxy(2, 18 - t);
    printf("       $$$$$$$$$\n");
    gotoxy(2, 19 - t);
    printf("$      $$$      \n");
    gotoxy(2, 20 - t);
    printf("$$     $$$$$$$  \n");
    gotoxy(2, 21 - t);
    printf("$$$   $$$$$     \n");
    gotoxy(2, 22 - t);
    printf(" $$  $$$$$$$$$$ \n");
    gotoxy(2, 23 - t);
    printf(" $$$$$$$$$$$    \n");
    gotoxy(2, 24 - t);
    printf("  $$$$$$$$$$    \n");
    gotoxy(2, 25 - t);
    printf("    $$$$$$$$    \n");
    gotoxy(2, 26 - t);
    printf("     $$$$$$     \n");
    gotoxy(2, 27 - t);

    if (jump == 1 || jump == 2)
    {
        printf("     $$$ $$   ");
        gotoxy(2, 28 - t);
        printf("   $$     $$  ");
    }
    else if (a == 1)
    {
        printf("   $$$$   $$$ ");
        gotoxy(2, 29 - t);
        printf("     $$       ");
        a = 2;
    }
    else if (a == 2)
    {
        printf("    $$$ $$    ");
        gotoxy(2, 30 - t);
        printf("     $$       ");
        a = 1;
    }

    gotoxy(2, 31 - t);

    if (jump != 0)
    {
        printf("              ");
    }
    else
    {
        printf("$$$$$$$$$$$$$$");
    }

    delay(speed);
}

void obj()
{
    static int x = 0, src = 0;
    if (x == 56 && t < 4)
    {
        src = 0;
        speed = 40;
        gotoxy(36, 8);
        printf("Game over");
        _getch();
        gotoxy(36, 8);
        printf("               ");
    }

    gotoxy(74 - x, 20);
    printf("$               $  ");
    gotoxy(74 - x, 21);
    printf("$               $  ");
    gotoxy(74 - x, 22);
    printf("$$$$$$$$$$$$$$$$$  ");
    gotoxy(74 - x, 23);
    printf("   $               ");
    gotoxy(74 - x, 24);
    printf("   $               ");
    x++;

    if (x == 73)
    {
        x = 0;
        src++;
        gotoxy(70, 2);
        printf("                ");
        gotoxy(70, 2);
        printf(" %d", src);

        if (speed > 20)
        {
            speed--;
        }
    }
}

void getup()
{
    system("cls");
    gotoxy(10, 2);
    printf("Press X to Exit, Press Space to jump");
}

int main()
{
    // define height and width of console
    system("mode con: lines = 29 cols = 82");
    char ch;
    int i;

    /// initialization
    getup();

    while (true)
    {
        while (!kbhit())
        {
            ds();
            obj();
        }

        ch = _getch(); // take input from user

        if (ch == ' ')
        {
            for (int i = 0; i < 10; i++)
            {
                ds(1); // press 1 for jump
                obj();
            }

            for (int i = 0; i < 10; i++)
            {
                ds(2); // press 2 for land
                obj();
            }
        }
        else if (ch == 'x')
        {
            return (0);
        }
    }
}
