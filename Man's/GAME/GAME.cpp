#include <iostream>
#include <cstdlib>//библиотека для генераций рандомных чисел
#include <ctime>//библиотека которая генерирование случайных чисел с заданным вам временем

using namespace std;

void playGame(int max_number) {
    int Secretnum = rand() % max_number + 1;//создание секретного числа 
    int gues = 0;//ввод
    int attempts = 0;//всего попыток
    cout << "Угадай число которую я загадал, 1 из " << max_number << "!" << endl;
    while (gues != Secretnum) {
        cout << "Ваш вариант = ";//цикл пока не угадает
        cin >> gues;
        attempts++;


        if (gues > Secretnum) {
            cout << "Неправильно. Твоё число должно быть меньше" << endl; //программа загадала 6, а я написал допустим 1, и он говорит что, введённое число должно быть меньше.
        }
        else if (gues == Secretnum) {
            cout << "УГАДАААЛ" << endl;//угадал
        }
        else if (gues < Secretnum) {
            cout << "Неправильно. Твоё число должно быть больше" << endl;//программа также подсказываем что введённое число должно быть больше.
        }
    }
}

void gameLvl(int max_number) {
    int Secretnum2 = rand() % max_number + 1;//создание секретного числа 
    int gues2 = 0;//ввод
    int attempts2 = 0;//всего попыток
    cout << "Угадай число которую я загадал, 1 из " << max_number << "!" << endl;
    while (gues2 != Secretnum2) {
        cout << "Ваш вариант = ";//цикл пока не угадает
        cin >> gues2;
        attempts2++;


        if (gues2 > Secretnum2) {
            cout << "Неправильно. Твоё число должно быть меньше" << endl; //программа загадала 6, а я написал допустим 1, и он говорит что, введённое число должно быть меньше.
        }
        else if (gues2 == Secretnum2) {
            cout << "УГАДАААЛ" << endl;//угадал
        }
        else if (gues2 < Secretnum2) {
            cout << "Неправильно. Твоё число должно быть больше" << endl;//программа также подсказываем что введённое число должно быть больше.
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int num = 0;
    int numLvl = 0;

    cout << "1 - Начать игру" << endl;
    cout << "2 - Выйти" << endl;
    cin >> num;
    if (num == 1) {
        cout << "Выберите уровень сложности: " << endl;
        cout << "1. Легкий с 10 из 1" << endl;
        cout << "2. Средний с 50 из 1" << endl;
        cout << "3. Сложный с 100 из 1" << endl;
        cin >> numLvl;

        switch (numLvl) {
        case 1:
            cout << " Первая игра начинается" << endl;
            playGame(10); // Легкий уровень
            break;
        case 2:
            cout << "Игра начинается через 1...2...3!" << endl;
            gameLvl(50); // Средний уровень
            break;
        case 3:
            cout << "Игра начинается через 1...2...3!" << endl;
            gameLvl(100); // Сложный уровень
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова." << endl;
            main(); // Рекурсивный вызов main для повторного ввода
        }
    }
    else if (num == 2) {
        cout << "Игра окончена. До свидания!" << endl;
    }
    else {
        cout << "Неверный выбор. Попробуйте снова." << endl;
        main(); // Рекурсивный вызов main для повторного ввода
    }

    return 0;
}
