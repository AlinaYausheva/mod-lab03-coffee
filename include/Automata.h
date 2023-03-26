#pragma once
#include <iostream>
#include <string>
#include <iterator>

using namespace std;

class Automata {
public:
    enum States { OFF, WAIT, ACCEPT, CHECK, COOK };
    Automata(string menu[], int price[]);
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
    string* menu;
    int* price;
    States state;
};
