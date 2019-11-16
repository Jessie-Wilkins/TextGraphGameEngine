#include "TGGE_Graphics.hpp"
#include <iostream>

string TGGE_Graphics::generateLetter(char letter, int horizontal_location, int vertical_location) {
    string str_graph = "";
    
    for(int i = 0; i<vertical_location; i++) {
        str_graph =str_graph+"\n";
    }

    for(int i = 0; i<horizontal_location; i++) {
        str_graph =str_graph+" ";
    }
    str_graph=str_graph+letter;
    return str_graph;;
}