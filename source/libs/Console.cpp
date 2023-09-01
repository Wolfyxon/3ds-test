#include "Console.h"
#include <3ds.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

string getPositionPrefix(int row, int column = 0){
    return "\x1b[" + to_string(row) + ";" + to_string(column) + "H";
}

Console::Console(gfxScreen_t screen_){
    gfxScreen_t screen = screen_;
    gfxScreen_t initScreen = screen_;
    vector<string> output;
    PrintConsole printConsole;
}

Console::~Console(){
    clear();
}

void Console::print(string text){
    output.push_back(text);
}

void Console::clear(){
    output.clear();
}

void Console::render(){
    consoleInit(screen, &printConsole);
    //consoleSelect(&printConsole);
    //consoleClear();

    for(int i = 0; i<(int)output.size(); i++){
        cout << getPositionPrefix(i) << output[i];
    }
}