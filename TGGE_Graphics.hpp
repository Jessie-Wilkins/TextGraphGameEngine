#pragma once
#ifndef TGGE_Graphics_h
#define TGGE_Graphics_h
#include <iostream>
using namespace std;

class TGGE_Graphics {
    public:
        string generateLetter(char letter);
        string generateLetter(char letter, int location);
        string generateLetter(char letter, int horizontal_location, int vertical_location);
    private:
};

#endif