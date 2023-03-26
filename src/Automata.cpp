//Copyright 2022 GHA Test Team
#include "Automata.h"

Automata::Automata(std::string Menu[], int Price[]) {
    cash = 0;
    menu = Menu;
    price = Price;
    state = OFF;
}
void Automata::on() {
    if (getState() == OFF) {
        state = WAIT;
    }
}
void Automata::off() {
    if (getState() == WAIT) {
        state = OFF;
    }
}
void Automata::coin(int monies) {
    if (getState() == WAIT) {
        state = ACCEPT;
        cash += monies;
    } else if (getState() == ACCEPT) {
        cash += monies;
    }
}
void Automata::getMenu() {
    std::cout << "MENU:" << std::endl;;
    for (int i = 0; i < menu->size(); i++) {
        std::cout << std::to_string(i+1) + ". " + menu[i];
        std::cout << " ____ " + std::to_string(price[i]) + "$" << std::endl;
    }
}
Automata::States Automata::getState() {
    return state;
}
void Automata::choice(int choiceNum) {
    if (getState() == ACCEPT) {
        std::cout << "Chosen drink: " + menu[choiceNum] << std::endl;
        state = CHECK;
    }
}
void Automata::check(int choiceNum) {
    if (getState() == CHECK) {
        if (cash >= price[choiceNum]) {
            cash -= price[choiceNum];
            std::cout << "Take the change: " + std::to_string(cash) + "$" << std::endl;
            state = COOK;
        } else {
            state = ACCEPT;
            std::cout << "Not enough money" << std::endl;
        }
    }
}
void Automata::cancel() {
    if ((getState() == ACCEPT) || (getState() == CHECK)) {
        state = WAIT;
        if (cash > 0) {
            std::cout << "Сollect the deposited money: "
                + std::to_string(cash) + "$" << std::endl;
        }
        cash = 0;
    }
}
void Automata::cook(int choiceNum) {
    if (getState() == COOK) {
        std::cout << "Wait... Your drink " + menu[choiceNum]
            + " will be ready soon" << std::endl;
    }
}
void Automata::finish() {
    if (getState() == COOK) {
        state = WAIT;
    }
}
