#include "TGGE_Graphics.hpp"
#include <iostream>

string TGGE_Graphics::generateLetter(char letter, int horizontal_location, int vertical_location, string present_string) {
    string str_graph = present_string;
    int location_of_line_break;

    if(str_graph != "") {
        str_graph = adjustCurrentStringGraphics(str_graph, location_of_line_break, vertical_location, horizontal_location, letter);
    }

    else {
        str_graph = addNewStringGraphics(str_graph, vertical_location, horizontal_location, letter);
        
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

int TGGE_Graphics::findLocationOfLastLineBreak(int& j, string str_graph, int location_of_line_break, int vertical_location) {
    for(location_of_line_break = 0; location_of_line_break<str_graph.length(); location_of_line_break++) {
        if(str_graph.at(location_of_line_break) == '\n') {
            j++;
            if (j==vertical_location) {
                return location_of_line_break;
            }
        }
    }
}

string TGGE_Graphics::insertCharactersIntoString(int j, string str_graph, int location_of_line_break, int vertical_location, int horizontal_location, char letter) {
    if(j!=vertical_location) {
        str_graph += "\n";
        for(int i = 0; i <horizontal_location; i++) {
            str_graph+=" ";
        }
        str_graph+=string(1,letter);
    }
    else {
        str_graph.insert(location_of_line_break+1+horizontal_location,string(1,letter));
    }
    return str_graph;
}

string TGGE_Graphics::adjustCurrentStringGraphics(string str_graph, int location_of_line_break, int vertical_location, int horizontal_location, char letter) {
    if(vertical_location == 2) {
            int j = 0;
            location_of_line_break = findLocationOfLastLineBreak(j, str_graph, location_of_line_break, vertical_location);
            str_graph = insertCharactersIntoString(j, str_graph, location_of_line_break, vertical_location, horizontal_location, letter);
    }
    else {
        str_graph.insert(horizontal_location+vertical_location,"b");
    }
    return str_graph;
}

string TGGE_Graphics::addNewStringGraphics(string str_graph, int vertical_location, int horizontal_location, char letter){
        str_graph = addExtraLines(str_graph, vertical_location);
        
        str_graph = addExtraSpaces(str_graph, horizontal_location);

        return str_graph+letter;
}