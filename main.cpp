#include <iostream>
#include "shaurma.h"
#include "pizza.h"
#include "drink.h"
#include "soup.h"
#include "fries.h"
#include "basket.h"
#include <windows.h>
using namespace std;


int main() {
    SetConsoleOutputCP(CP_UTF8);
    float summ1, summ2;
    string optionInput;
    int option, i = 0,counter_one, counter_two;
    auto *bas = new basket[20];
    auto *bas_double = new basket[20][20];

    shaurma _shaurma = shaurma();
    pizza _pizza = pizza();
    drink _drink = drink();
    soup _soup = soup();
    fries _fries = fries();
    bas[i] = basket(_shaurma, _pizza, _drink, _soup, _fries);

    while (option != 5) {
        puts("\nВвести заказ - 1");
        puts("Вывести все заказы - 2");
        puts("Ввести двумерный массив - 3");
        puts("Вывести двумерный массив - 4");
        puts("Выход - 5");
        /////TRY БЛОК/////
        cin >> optionInput;
        try {
            option = stoi(optionInput);
            if (option > 5 || option < 1)
                throw ("invalid range");
        } catch (invalid_argument e) {
            cout << ("Нужно вводить цифру!!!");
        } catch (char const *s) {
            cout << ("Диапазон 1-5!!!\n");
        }
//        ////////////////

        cin >> option;;
        switch (option) {
            case 1: {
                // ОДНОМЕРНЫЙ МАССИВ ОБЪЕКТОВ //

                bas[i].input();
                bas[i].output();
                summ1 = basket::sum(*bas);
                basket::payment(summ1);
                i++;
                counter_one++;
                break;
            }
            case 2: {
                for (int j = 0; j < counter_one; j++) {
                    bas[j].output();
                    bas[j].sum(*bas);
                    puts("");
                }
                break;
            }
            case 3: {
                for (int k = 0; k < 1; k++)     //ДВУМЕРНЫЙ МАССИВ ОБЪЕКТОВ//
                    for (int j = 0; j < 1; j++) {
                        shaurma _shaurma = shaurma();
                        pizza _pizza = pizza();
                        drink _drink = drink();
                        soup _soup = soup();
                        fries _fries = fries();

                        bas_double[i][j] = basket(_shaurma, _pizza, _drink, _soup, _fries);
                        bas_double[i][j].input();
                        bas_double[i][j].output();
                        summ2 = bas_double[i][j].sum(**bas_double);
                        basket::payment(summ2);
                        counter_two++;
                    }
                break;
            }
            case 4:
                for (int k = 0; k < 1; k++)
                    for (int j = 0; j < 1; j++) {
                        bas_double[i][j].output();
                        bas_double[i][j].sum(**bas_double);
                        puts("");
                    }
                break;
            case (5):
                exit(0);
        }
    }
}
