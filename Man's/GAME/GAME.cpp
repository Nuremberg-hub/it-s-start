#include <iostream>
#include <cstdlib> // библиотека для генераций рандомных чисел
#include <ctime>   // библиотека которая генерирует случайные числа с заданным временем
#include <variant> // библиотека для прощего массива
#include <string>  // Для работы с строками
#include <SFML/Graphics.hpp> // библитека для выведений изображений на экран, графика

using namespace std;
using namespace sf;

void playGame(int max_number) {
    int Secretnum = rand() % max_number + 1; // создание секретного числа 
    int gues = 0; // ввод
    int attempts = 0; // всего попыток
    cout << "Угадай число которое я загадал, 1 из " << max_number << "!" << endl;

    while (gues != Secretnum) {
        cout << "Ваш вариант = "; // цикл пока не угадает
        string input;
        cin >> input;

        // Если введено "STOP", завершаем игру
        if (input == "STOP") {
            cout << "Игра окончена. До свидания!" << endl;
            return; // Выход из функции
        }

        // Преобразуем введённую строку в число
        gues = stoi(input);
        attempts++;

        if (gues > Secretnum) {
            cout << "Неправильно. Твоё число должно быть меньше" << endl;
        }
        else if (gues == Secretnum) {
            cout << "УГАДАААЛ" << endl;
        }
        else if (gues < Secretnum) {
            cout << "Неправильно. Твоё число должно быть больше" << endl;
        }
    }
}

void gameLvl(int max_number) {
    int Secretnum2 = rand() % max_number + 1; // создание секретного числа 
    int gues2 = 0; // ввод
    int attempts2 = 0; // всего попыток
    cout << "Угадай число которое я загадал, 1 из " << max_number << "!" << endl;

    while (gues2 != Secretnum2) {
        cout << "Ваш вариант = "; // цикл пока не угадает
        string input;
        cin >> input;

        // Если введено "STOP", завершаем игру
        if (input == "STOP") {
            cout << "Игра окончена. До свидания!" << endl;
            return; // Выход из функции
        }

        // Преобразуем введённую строку в число
        gues2 = stoi(input);
        attempts2++;

        if (gues2 > Secretnum2) {
            cout << "Неправильно. Твоё число должно быть меньше" << endl;
        }
        else if (gues2 == Secretnum2) {
            cout << "УГАДАААЛ" << endl;
        }
        else if (gues2 < Secretnum2) {
            cout << "Неправильно. Твоё число должно быть больше" << endl;
        }
    }
}

double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}

double CelsiusToKelvin(double celsius) {
    return celsius + 273.15;
}
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

double fahrenheitToKelvin(double fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0 + 273.15;
}

double kelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}

double kelvinToFahrenheit(double kelvin) {
    return (kelvin - 273.15) * 9.0 / 5.0 + 32;
}

int main() {
    setlocale(LC_ALL, "Russian");
    string input;  // Используем строковый тип для ввода
    int numLvl = 0;
    int choice;
    double value;

    while (true) {
        cout << "1 - Начать игру" << endl;
        cout << "2 - Выйти" << endl;
        cout << "3 - Конвертер температур" << endl;
        cout << "4 - Изображение" << endl;
        cin >> input;

        if (input == "4") {
            cout << "Выведение изображенние пока что в разработке, спасибо за внимание :) !!!" << endl;
        }

        if (input == "1") {
            cout << "Выберите уровень сложности: " << endl;
            cout << "1. Легкий с 10 из 1" << endl;
            cout << "2. Средний с 50 из 1" << endl;
            cout << "3. Сложный с 100 из 1" << endl;
            cin >> numLvl;

            switch (numLvl) {
            case 1:
                cout << "Первая игра начинается" << endl;
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
                break;
            }
        }
        else if (input == "2") {
            cout << "Игра окончена. До свидания!" << endl;
            break;
        }
        else if (input == "3") {
            cout << "Выбери как конвертировать: \n";
            cout << "1. Цельсий в Фаренгейт\n";
            cout << "2. Цельсий в Кельвин\n";
            cout << "3. Фаренгейт в Цельсий\n";
            cout << "4. Фаренгейт в Кельвин\n";
            cout << "5. Кельвин в Цельсий\n";
            cout << "6. Кельвин в Фаренгейт\n";
            cout << "Ваш выбор: ";
            cin >> choice;

            cout << "Введите значение температуры: " << endl;
            cin >> value;

            switch (choice) {
            case 1:
                cout << "Результат: " << celsiusToFahrenheit(value) << "'F" << endl;
                break;
            case 2:
                cout << "Результат: " << CelsiusToKelvin(value) << " K" << endl;
                break;
            case 3:
                cout << "Результат: " << fahrenheitToCelsius(value) << " 'C" << endl;
                break;
            case 4:
                cout << "Результат: " << fahrenheitToKelvin(value) << " K" << endl;
                break;
            case 5:
                cout << "Результат: " << kelvinToCelsius(value) << " 'C" << endl;
                break;
            case 6:
                cout << "Результат: " << kelvinToFahrenheit(value) << " K" << endl;
                break;
            default:
                cout << "Это неверный выбор!" << endl;
                break;
            }
        }
        //else if (input == "4") {
        //    // Создание окна и его размера
        //    RenderWindow window(VideoMode(800, 600), "Отображение изображения");

        //    // Загружаем текстуру из файла
        //    Texture texture;
        //    if (!texture.loadFromFile("image.jpg")) {
        //        // Если не удалось загрузить, выводим ошибку          // Изображение пока в разработке
        //        return -1;
        //    }

        //    // Создаём спрайт и устанавливаем текстуру
        //    Sprite sprite;
        //    sprite.setTexture(texture);

        //    // Основной цикл программы
        //    while (window.isOpen()) {
        //        Event event;
        //        while (window.pollEvent(event)) {
        //            if (event.type == Event::Closed)
        //                window.close();
        //        }

        //        // Отображаем спрайт
        //        window.clear();       // Очищаем окно
        //        window.draw(sprite);  // Рисуем спрайт
        //        window.display();     // Отображаем содержимое окна
        //    }
        //}
        else {
            cout << "Неверный выбор. Попробуйте снова." << endl;
        }
    }

    return 0;
}