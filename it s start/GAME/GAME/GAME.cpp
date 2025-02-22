#include <iostream> // Для ввода/вывода.
#include <cstdlib> // Библиотека для генераций рандомных чисел.
#include <ctime>   // Библиотека которая генерирует случайные числа с заданным временем.
#include <variant> // Библиотека для прощего массива.
#include <string>  // Строчная преременная.
#include <SFML/Graphics.hpp> // Библиотека для работы с графиком, вывод изображение, анимаций, аудио и т.д.
#include <Windows.h> // Заголовочный файл который даёт доступ к Windows API.

using namespace std; // Используем для того что бы не писать std::
using namespace sf; // Используем для того что бы не писать sf:;

void setColor(int color) { // Цвет текста
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void SecrGAME() {   // Функций которая выводит действий который ты выбрал.
    RenderWindow window(VideoMode(1300, 700), "SFML Window"); // Окно вывода 1300 на 700 (1300 ширина, 700 высота).

    // Игрок (персонаж).
    Texture playerTexture; // Создание текстурки игрока.
    if (!playerTexture.loadFromFile("C:/Users/Айдана/OneDrive/Рабочий стол/image.jpg")) { // Путь к изображению игрока.
        cout << "Ошибка загрузки текстуры игрока!" << endl; // Срабатывание условий если не смог загрузить.
    }
    Sprite player(playerTexture); // Создание спрайта (о игроке, то есть его начальная позиция и размер и т.д).
    player.setScale(0.1f, 0.1f); // Размер игрока (Изображение).
    player.setPosition(100, 100);  // Начальная позиций игрока.

    // Опасные блоки.
    RectangleShape dangerBlock(Vector2f(1000, 10)); // Создание Блока и размера (1000 ширина, 10 длинна).
    dangerBlock.setFillColor(Color::Red); // Цвет опасного блока.
    dangerBlock.setPosition(400, 300); // Начальная позиция опасного блока.

    // Второй Опасный Блок.
    RectangleShape SecondDangerBlock(Vector2f(1000, 10));
    SecondDangerBlock.setFillColor(Color::Red);
    SecondDangerBlock.setPosition(400, 250);

    // Выигрышный блок
    RectangleShape winBlock(Vector2f(100, 100)); // Создание Блока.
    winBlock.setFillColor(Color::Green); // Даём цвет выигрышныму блоку.
    winBlock.setPosition(1250, 225.50); // Установение победного места (Начальная позиция).

    while (window.isOpen()) { // Бесконесный цикл.
        Event event; // Создание событий.
        while (window.pollEvent(event)) { // Цикл в котором процесс будет продолжать пока не выйдут (нажатие крестика).
            if (event.type == Event::Closed) // События которое закрываем программу.
                window.close(); // Закрытие
        }

        // Управление персонажем
        if (Keyboard::isKeyPressed(Keyboard::A)) { // Нажатие клавиши А влево.
            player.move(-4.5, 0); // Скорость игрока.
        }
        if (Keyboard::isKeyPressed(Keyboard::D)) { // Нажатие клавиши D вправо.
            player.move(4.5, 0); // Скорость игрока.
        }
        if (Keyboard::isKeyPressed(Keyboard::W)) { // Нажатие клавиши W вверх.
            player.move(0, -4.5); // Скорость игрока.
        }
        if (Keyboard::isKeyPressed(Keyboard::S)) { // Нажатие клавиши S вниз
            player.move(0, 4.5); // Скорость игрока
        }

        // Проверка столкновения с опасными блоками
        if (player.getGlobalBounds().intersects(dangerBlock.getGlobalBounds()) || // Условие при столкновений с блоков проигрыша
            player.getGlobalBounds().intersects(SecondDangerBlock.getGlobalBounds())) {
            setColor(5);
            cout << "Ты проиграл\n";
            Sleep(1000); // закрытие только через 1 секунды (1000 миллисекунд).
            setColor(7);
            window.close(); // Закрытие программы.
        }

        // Проверка столкновения с победным блоком
        if (player.getGlobalBounds().intersects(winBlock.getGlobalBounds())) { // Условие при столкновений с блоков выигрыша
            setColor(10);
            cout << "Ты выиграл! Поздравляю!\n";
            Sleep(1000); // Закрытие только через ё секунды (1000 миллисекунд).
            setColor(7);
            window.close(); // Закрытие программы.
        }

        // Отрисовка
        window.clear();
        window.draw(player); // Игрок
        window.draw(dangerBlock); // Опасный Блок
        window.draw(SecondDangerBlock); // Опасный Блок 2.
        window.draw(winBlock); // Победный блок.
        window.display(); // Дисплей.
        window.setFramerateLimit(60); // Ограничений фпс что бы много не жрал.
    }
}

void playGame(int max_number) { // Функция игры Угадай Число
    int Secretnum = rand() % max_number + 1; // Создание секретного числа.
    int gues = 0; // ввод
    int attempts = 0; // всего попыток
    cout << "Угадай число которое я загадал, 1 из " << max_number << "!" << endl;

    while (gues != Secretnum) { // Цикл пока игрок не отгадает число.
        cout << "Ваш вариант = ";
        string input;
        cin >> input;

        // Если введено "STOP", завершаем игру
        if (input == "STOP") {
            cout << "Игра окончена. До свидания!" << endl;
            return; // Выход из функции
        }
        
        // Преобразуем введённую строку в число.
        gues = stoi(input);
        attempts++; // 1+

        // Подсказки.
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

void gameLvl(int max_number) { // Фнукция уровней игры Угадай число
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

double celsiusToFahrenheit(double celsius) { // Цельсий в Фаренгейт.
    return (celsius * 9.0 / 5.0) + 32;
}

double CelsiusToKelvin(double celsius) { // Цельсий в Келвин.
    return celsius + 273.15;
}
double fahrenheitToCelsius(double fahrenheit) { // Фаренгейт в Цельсий.
    return (fahrenheit - 32) * 5.0 / 9.0;
}

double fahrenheitToKelvin(double fahrenheit) { // Фаренгейт в Келвин.
    return (fahrenheit - 32) * 5.0 / 9.0 + 273.15;
}

double kelvinToCelsius(double kelvin) { // Келвин в Цельсий.
    return kelvin - 273.15;
}

double kelvinToFahrenheit(double kelvin) { // Келвин в Фаренгейт.
    return (kelvin - 273.15) * 9.0 / 5.0 + 32;
}

int main() {
    setlocale(LC_ALL, "Russian"); // Что бы символы были русскийми а не каря маряка.
    string input;  // Используем строковый тип для ввода.
    int numLvl = 0;
    int choice;
    double value;

    while (true) { // Бесконечный цикл.
        // Меню.
        cout << "1 - Начать игру" << endl;
        cout << "2 - Выйти" << endl;
        cout << "3 - Конвертер температур" << endl;
        cout << "4 - Изображение" << endl;
        cin >> input;


        if (input == "1") {
            cout << "Выберите уровень сложности: " << endl;
            cout << "1. Легкий с 10 из 1" << endl;
            cout << "2. Средний с 50 из 1" << endl;
            cout << "3. Сложный с 100 из 1" << endl;
            cin >> numLvl;

            switch (numLvl) { // Игра Угадай число.
            case 1:
                cout << "Первая игра начинается" << endl;
                playGame(10); // Легкий уровень.
                break;
            case 2:
                cout << "Игра начинается через 1...2...3!" << endl;
                gameLvl(50); // Средний уровень.
                break;
            case 3:
                cout << "Игра начинается через 1...2...3!" << endl;
                gameLvl(100); // Сложный уровень.
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
            // Конвертер температур.
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
        else if (input == "4") { // Изображение
            SecrGAME();
        }
     }
    return 0;
}
