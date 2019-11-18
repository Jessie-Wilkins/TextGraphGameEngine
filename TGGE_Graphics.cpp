#include "TGGE_Graphics.hpp"
#include <iostream>

string TGGE_Graphics::generateLetter(char letter, int horizontal_location, int vertical_location, string present_string) {
    string str_graph = present_string;

    if(str_graph != "") {
        if(vertical_location == 2) {
            str_graph += "\n    b";
        }
        else {
            str_graph += "b";
        }

    }

    else {
        
        str_graph = addExtraLines(str_graph, vertical_location);
        
        str_graph = addExtraSpaces(str_graph, horizontal_location);

        str_graph=str_graph+letter;
    }

   
    return str_graph;
}

string TGGE_Graphics::addExtraLines(string str_graph, int vertical_location) {
    for(int i = 0; i<vertical_location; i++) {
            str_graph =str_graph+"\n";
    }
    return str_graph;
}

string TGGE_Graphics::addExtraSpaces(string str_graph, int horizontal_location) {
    for(int i = 0; i<horizontal_location; i++) {
            str_graph =str_graph+" ";
    }
    return str_graph;
}