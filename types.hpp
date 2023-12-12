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

void copyTransition(const transition& src, transition& dest) {
    dest.fromState = src.fromState;
    dest.readSymbol = src.readSymbol;
    dest.toState = src.toState;
    dest.writeSymbol = src.writeSymbol;
    dest.moveDirection = src.moveDirection;
}