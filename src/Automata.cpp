#include "Automata.h"
        
using namespace std;

Automata::Automata(string Menu[], int Price[]) {
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
    }
    else if (getState() == ACCEPT) {
        cash += monies;
    }
}
void Automata::getMenu() {
    cout << "MENU:" << endl;;
    for (int i = 0; i < menu->size(); i++) {
        cout << to_string(i+1) + ". " + menu[i];
        cout << " ____ " + to_string(price[i]) + "$" << endl;
    }
}
Automata::States Automata::getState() {
    return state;
}
void Automata::choice(int choiceNum) {
    if (getState() == ACCEPT) {
        cout << "Chosen drink: " + menu[choiceNum] << endl;
        state = CHECK;
        check(choiceNum);
    }
}
void Automata::check(int choiceNum) {
    if (getState() == CHECK) {
        if (cash >= price[choiceNum]) {
            cash -= price[choiceNum];
            cout << "Take the change: " + to_string(cash) + "$" << endl;
            state = COOK;
            cook(choiceNum);
        }
        else {
            state = ACCEPT;
            cout << "Not enough money" << endl;
        }
    }
}
void Automata::cancel() {
    if ((getState() == ACCEPT) || (getState() == CHECK)) {
        state = WAIT;
        if (cash > 0) {
            cout << "Ñollect the deposited money: " + to_string(cash) + "$" << endl;
        }
        cash = 0;
    }
}
void Automata::cook(int choiceNum) {
    if (getState() == COOK) {
        cout << "Wait... Your drink " + menu[choiceNum] + " will be ready soon" << endl;
        finish();
    }
}
void Automata::finish() {
    if (getState() == COOK) {
        state = WAIT;
    }
}