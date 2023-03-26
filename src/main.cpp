//Copyright 2022 GHA Test Team
#include <iostream>
#include <string>
#include "Automata.h"
    
int main() {
    std::string menu[] = { "Tea", "Milk", "Americano", "Espresso", "Latte", "Cappuccino", "Hot chocolate" };
    int price[] = { 3, 2, 4, 3, 4, 5, 3 };
    Automata automat(menu, price);
    automat.on();
    automat.getMenu();
    automat.coin(4);
    automat.choice(6);   
}
