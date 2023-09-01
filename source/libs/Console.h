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
    gfxScreen_t screen;
    PrintConsole printConsole;
public:
    bool clearOnRender;

    Console(gfxScreen_t screen_);
    ~Console();
    void print(string text);
    void clear();
    void render();
};
