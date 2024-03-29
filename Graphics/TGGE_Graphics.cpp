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

string TGGE_Graphics::addNewLineAfterSpecifiedLine(int line_number, string present_string) {
    int line_number_presently = 0;
    string part_string1 = "";
    int char_number = 0;
    for(int i = 0; i<present_string.length(); i++) {
        if(present_string.at(i) == '\n') {
            line_number_presently++;
           
        }
        if(line_number_presently == line_number) {
            part_string1 = present_string.substr(0,i);
            part_string1+="\n";
            present_string = part_string1+present_string.substr(i, present_string.length()-1);
            break;
        }
    }
    return present_string;
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
            else if(j>vertical_location) {
                break;
            }
            
        }
        
    }
    return location_of_line_break;
}

string TGGE_Graphics::insertCharactersIntoString(int j, string str_graph, int location_of_line_break, int vertical_location, int horizontal_location, char letter) {
    if(vertical_location == 0) {
        str_graph = addCharacterToFirstLine(str_graph, location_of_line_break, horizontal_location, letter);
    }
    
    else if(j!=vertical_location) {
        str_graph = addCharacterToNewLine(str_graph, horizontal_location, letter);
    }

    else {
        str_graph = addCharacterBetweenFirstAndLastLine(str_graph, vertical_location, letter, location_of_line_break, horizontal_location);
    }
    return str_graph;
}

string TGGE_Graphics::adjustCurrentStringGraphics(string str_graph, int location_of_line_break, int vertical_location, int horizontal_location, char letter) {
    int j = 0;
    location_of_line_break = findLocationOfLastLineBreak(j, str_graph, location_of_line_break, vertical_location);
    str_graph = insertCharactersIntoString(j, str_graph, location_of_line_break, vertical_location, horizontal_location, letter);
    return str_graph;
}

string TGGE_Graphics::addNewStringGraphics(string str_graph, int vertical_location, int horizontal_location, char letter){
        str_graph = addExtraLines(str_graph, vertical_location);
        
        str_graph = addExtraSpaces(str_graph, horizontal_location);

        return str_graph+letter;
}

bool TGGE_Graphics::ifDifferentLocation(int location_of_line_break, int horizontal_location, int next_location_of_line_break) {
    return location_of_line_break+1+horizontal_location>=next_location_of_line_break && location_of_line_break!=next_location_of_line_break && next_location_of_line_break!=0;
}

string TGGE_Graphics::changeStringStructure(string str_graph, int location_of_line_break, int next_location_of_line_break, int horizontal_location) {
    string temp_str = str_graph.substr(0, next_location_of_line_break);
    while(temp_str.length()<horizontal_location+1+location_of_line_break){
        temp_str+=" ";
    }
    return temp_str+str_graph.substr(next_location_of_line_break, str_graph.length());
}

string TGGE_Graphics::addNewLineToBeginning(string str_print) {
    string temp_string = str_print;
    str_print = "\n";
    str_print = str_print+temp_string;
    return str_print;
}

string TGGE_Graphics::addCharacterToFirstLine(string str_graph, int location_of_line_break, int horizontal_location, char letter) {
    string tempString1 = str_graph.substr(0, location_of_line_break);
    string tempString2 = str_graph.substr(location_of_line_break, str_graph.size());
    while(tempString1.size() < horizontal_location) {
        tempString1+=" ";
    }
    str_graph = tempString1+tempString2;

    str_graph.insert(horizontal_location,string(1,letter));

    return str_graph;
}

string TGGE_Graphics::addCharacterToNewLine(string str_graph, int horizontal_location, char letter) {
    str_graph += "\n";
    for(int i = 0; i <horizontal_location; i++) {
        str_graph+=" ";
    }
    str_graph+=string(1,letter);

    return str_graph;
}

string TGGE_Graphics::addCharacterBetweenFirstAndLastLine(string str_graph, int vertical_location, char letter, int location_of_line_break, int horizontal_location) {
    int next_line_break = 0;
    int next_vertical_location = vertical_location+1;
    int next_location_of_line_break = 0;
    next_location_of_line_break = findLocationOfLastLineBreak(next_line_break, str_graph, next_location_of_line_break, next_vertical_location);
    if(ifDifferentLocation(location_of_line_break, horizontal_location, next_location_of_line_break)) {
        str_graph = changeStringStructure(str_graph, location_of_line_break, next_location_of_line_break, horizontal_location);
    }
    str_graph.insert(location_of_line_break+1+horizontal_location,string(1,letter));

    return str_graph;
}

string TGGE_Graphics::moveLetterByReference(string char_reference, int horizontal_location, int vertical_location, string str_print) {
    char existing_character = char_reference.at(0);
    int occurance_number = char_reference.at(1)-'0';
    occurance_number = occurance_number+1;
    int current_char_occurance = 0;
    int character_location = 0;

    for(int i=0; i<str_print.length(); i++) {
        if(str_print.at(i) == existing_character) {
            current_char_occurance++;
            if(current_char_occurance == occurance_number) {
                character_location = i;
                break;
            }
        }
    }

    string new_str_print = generateLetter(existing_character, horizontal_location, vertical_location, str_print);

    new_str_print = new_str_print.erase(character_location+1, 1);

    new_str_print = new_str_print.insert(character_location+1, " ");

    return new_str_print;
}