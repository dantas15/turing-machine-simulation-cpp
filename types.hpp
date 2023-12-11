#include <iostream>
#include <vector>

#pragma once

struct transition {
    std::string fromState;
    char readSymbol;
    std::string toState;
    char writeSymbol;
    char moveDirection;
};

struct TuringMachine {
    std::vector<std::string> states;
    std::vector<char> alphabet;
    std::vector<char> tape;
    std::vector<transition> transitions;
    std::string initialState;
    std::vector<std::string> finalStates;
};