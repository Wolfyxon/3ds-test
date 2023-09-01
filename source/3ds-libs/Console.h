#pragma once
#include <3ds.h>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Console
{
private:
    vector<string> output;
    PrintConsole printConsole;
public:
    gfxScreen_t screen;

    Console(gfxScreen_t screen_);
    ~Console();
    void print(string text);
    void clear();
    void render();
    void setFont(ConsoleFont font);
    int getRows();
    int getColumns();
};
