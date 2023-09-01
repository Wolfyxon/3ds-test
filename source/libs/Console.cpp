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
    bool clearOnRender = true;
    vector<string> output;
}

void Console::print(string text){
    output.push_back(text);
}

void Console::render(){
    if(clearOnRender) consoleClear();
    consoleInit(screen, NULL);

    for(int i = 0; i<output.size(); i++){
        cout << getPositionPrefix(i) << output[i];
    }
}