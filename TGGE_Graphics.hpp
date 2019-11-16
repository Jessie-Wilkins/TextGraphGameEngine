#pragma once
#ifndef TGGE_Graphics_h
#define TGGE_Graphics_h
#include <iostream>
using namespace std;

class TGGE_Graphics {
    public:
        string generateLetter(char letter, int horizontal_location, int vertical_location, string present_string);
    private:
        string addExtraLines(string str_graph, int vertical_location);
        string addExtraSpaces(string str_graph, int horizontal_location);
};

#endif