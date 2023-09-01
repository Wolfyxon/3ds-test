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
public:
    bool clearOnRender;

    Console(gfxScreen_t screen_, bool clearOnRender_ = true);
    ~Console();
    void print(string text);
    void render();
};
