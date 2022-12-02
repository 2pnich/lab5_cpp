#ifndef LAB_2_2_BASKET_H
#define LAB_2_2_BASKET_H
#include <iostream>
#include "shaurma.h"
#include "pizza.h"
#include "drink.h"
#include "soup.h"
#include "fries.h"

class basket {
private:
    shaurma _shaurma;
    pizza _pizza;
    drink _drink;
    soup _soup;
    fries _fries;
public:
    basket(shaurma _shaurma, pizza _pizza, drink _drink, soup _soup, fries _fries);
    basket();
    ~basket();
    void input();
    void output();
    static void payment(float sum);
    static float sum(const basket& p);
};


#endif //LAB_2_2_BASKET_H
