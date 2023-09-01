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

gfxScreen_t screen;
Console::Console(gfxScreen_t screen_){
    screen = screen_;
}

Console::~Console(){
    clear();
}

void Console::print(string text){
    if((int)output.size() > 30){
        output.erase(output.begin());
    }
    output.push_back(text);
}

void Console::clear(){
    output.clear();
}

void Console::setFont(ConsoleFont font){
    consoleSetFont(&printConsole, &font);
}

int Console::getRows(){
    return 30;
}

int Console::getColumns(){
    if(screen == GFX_TOP) return 50;
    if(screen == GFX_BOTTOM) return 40;
}

void Console::render(){
    consoleInit(screen, &printConsole);
    consoleSelect(&printConsole);
    //consoleClear();
    
    for(int i = 0; i<(int)output.size(); i++){
        int topOffset = i+1;
        cout << getPositionPrefix(topOffset) << output[i];
    }
}