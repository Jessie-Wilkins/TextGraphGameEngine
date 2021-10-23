//
//  main.cpp
//  TextGraphGameEngine
//
//  Created by Jessie Wilkins on 11/16/19.
//  Copyright © 2019 Jessie Wilkins. All rights reserved.
//


#define CATCH_CONFIG_RUNNER
#include <iostream>
#include "Graphics/TGGE_Graphics.hpp"
#include "catch.hpp"
using namespace std;


int main(int argc, const char * argv[]) {
    int result = Catch::Session().run( argc, argv );
}


    