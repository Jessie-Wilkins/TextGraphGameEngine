#include "TGGE_Graphics_Test.hpp"
#include <iostream>
TEST_CASE("TGGE_Graphics_Test") {
    
    SECTION("Test_If_Letter_Can_Be_Generated"){
        TGGE_Graphics graph;
        string letter = graph.generateLetter('a', 0, 0);
        
        REQUIRE(letter=="a");
    }

    SECTION("Test_If_Letter_Can_Be_Generated_at_Specific_Location_Horizontally(number_of_characters_used_as_unit)"){
        TGGE_Graphics graph;
        string str_print = graph.generateLetter('a', 4, 0);
        
        REQUIRE(str_print=="    a");
    }

    SECTION("Test If Letter Can Be Generated at Specific Location Horizontally and Vertically") {
        TGGE_Graphics graph;
        string str_print = graph.generateLetter('a', 4, 1);

        REQUIRE(str_print=="\n    a");
    }

}