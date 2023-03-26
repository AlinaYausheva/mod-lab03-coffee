//Copyright 2022 GHA Test Team
#pragma once
#include <iostream>
#include <string>
#include <iterator>

class Automata {
 public:
    enum States { OFF, WAIT, ACCEPT, CHECK, COOK };
    Automata(std::string menu[], int price[]);
    void on();
    void off();
    void coin(int monies);
    void getMenu();
    States getState();
    void choice(int choiceNum);
    void check(int choiceNum);
    void cancel();
    void cook(int choiceNum);
    void finish();

 private:
    int cash;
    std::string* menu;
    int* price;
    States state;
};
