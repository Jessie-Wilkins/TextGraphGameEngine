#include "TGGE_Graphics_Test.hpp"
#include <iostream>
TEST_CASE("TGGE_Graphics_Test") {
    
    string str_print;
    TGGE_Graphics graph;

    SECTION("Test_If_Letter_Can_Be_Generated"){
        str_print = graph.generateLetter('a', 0, 0, "");
        
        REQUIRE(str_print=="a");
    }

    SECTION("Test_If_Letter_Can_Be_Generated_at_Specific_Location_Horizontally(number_of_characters_used_as_unit)"){
        str_print = graph.generateLetter('a', 4, 0, "");
        
        REQUIRE(str_print=="    a");
    }

    SECTION("Test If Letter Can Be Generated at Specific Location Horizontally and Vertically") {
        str_print = graph.generateLetter('a', 4, 1, "");

        REQUIRE(str_print=="\n    a");
    }

    SECTION("Test If Another Letter Can Be Appended On Same String On Same Line") {
        str_print = graph.generateLetter('a', 4, 1, "");
        
        str_print = graph.generateLetter('b', 5, 1, str_print);

        REQUIRE(str_print=="\n    ab");
    }

    SECTION("Test If Another Letter Can Be Generated On Same String on the Next Line") {
        str_print = graph.generateLetter('a', 4, 1, "");
        
        str_print = graph.generateLetter('b', 5, 1, str_print);
        
        str_print = graph.generateLetter('b', 4, 2, str_print);

        REQUIRE(str_print=="\n    ab\n    b");
    }

    SECTION("Test If Another Letter Can Be Inserted Before Existing Characters On Same String on Same Line") {
        str_print = graph.generateLetter('a', 4, 1, "");
        
        str_print = graph.generateLetter('b', 5, 1, str_print);

        str_print = graph.generateLetter('b', 4, 2, str_print);

        str_print = graph.generateLetter('b', 2, 1, str_print);

        REQUIRE(str_print=="\n  b  ab\n    b");
    }

    SECTION("Test If Another Letter Can Be Inserted In Between Characters on Another Line") {
        str_print = graph.generateLetter('a', 4, 1, "");
        
        str_print = graph.generateLetter('b', 5, 1, str_print);

        str_print = graph.generateLetter('b', 4, 2, str_print);

        str_print = graph.generateLetter('b', 2, 1, str_print);

        str_print = graph.generateLetter('c', 2, 2, str_print);

        REQUIRE(str_print=="\n  b  ab\n  c  b");
    }

}