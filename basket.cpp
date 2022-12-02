#include <iostream>
#include "basket.h"

basket::basket(shaurma _shaurma, pizza _pizza, drink _drink, soup _soup, fries _fries) {
    this->_shaurma = _shaurma;
    this->_pizza = _pizza;
    this->_drink = _drink;
    this->_soup = _soup;
    this->_fries = _fries;
}

basket::basket() {

}

basket::~basket() {

}

void basket::input() {
    _shaurma.input();
    _pizza.input();
    _drink.input();
    _soup.input();
    _fries.input();
}

void basket::output() {
    _shaurma.output();
    _pizza.output();
    _drink.output();
    _soup.output();
    _fries.output();
}

float basket::sum(const basket& p) {
    float sum;
    sum = p._shaurma.sh_price + p._pizza.pizza_price + p._drink.drink_price + p._soup.soup_price + p._fries.fries_price;
    return sum;
}

void basket::payment(float sum){
    float money, change;
    cout <<"Введите полученную от покупателя сумму" << endl;
    cin >> money;
    change = money - sum;
    if (change > 0)
        cout << "Сдача: " << change << endl;
    if (change < 0)
        cout << "Нужно добавить: " << abs(change) << endl;
    if (change == 0)
        cout << "Без сдачи";
}
