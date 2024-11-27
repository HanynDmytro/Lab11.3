#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <Windows.h>
using namespace std;

struct Info {
    string lastname;
    string initial;
    string position;
    unsigned year;
    double salary;
};


// Функція створення нового файлу або відкриття для додавання записів
void createOrAppendFile(string filename) {
    ofstream file(filename, ios::app);
    if (!file) {
        cerr << "Помилка при створенні/відкритті файлу" << endl;
    }
    file.close();
}

// Функція додавання інформації про потяг до файлу
void addEmployeeInfo(string filename) {
    ofstream file(filename, ios::app);
    if (!file) {
        cerr << "Помилка при відкритті файлу" << endl;
        return;
    }

    Info employee;
    cout << "Введіть прізвище: ";
    getline(cin, employee.lastname);

    cout << "Введіть ініціали:  ";
    cin >> employee.initial;
    cin.ignore(); // Ігноруємо \n після вводу типу

    cout << "Введіть посаду: ";
    cin >> employee.position;
    cin.ignore(); // Ігноруємо \n після вводу часу

    cout << "Введіть рік прийняття на роботу: ";
    cin >> employee.year;
    cin.ignore(); // Ігноруємо \n після вводу часу

    cout << "Введіть оклад: ";
    cin >> employee.salary;
    cin.ignore(); // Ігноруємо \n після вводу часу

    file << employee.lastname << " " << employee.initial << " " << employee.position << " " << employee.year << " " << employee.salary <<  endl;
    file.close();
    cout << "Інформація про службовця додана до файлу." << endl;
}

// Функція виводу інформації про потяги, що відправляються після заданого часу
void displayEmployeeByLastname(string filename, string lastname) {
    ifstream file(filename);
    string s;
    string find;
    if (!file) {
        cerr << "Помилка при відкритті файлу" << endl;
        return;
    }
    while (getline(file, s)) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ') {
                find += s[i];
            }
            else
            {
                break;
            }
        }
        if (find == lastname) {
            int count = 0;
            string show;
            for (int i = 0; i <= s.length(); i++)
            {
                if (s[i] != ' ')
                {
                    show += s[i];
                }
                if (s[i] == ' ' || i == s.length()){
                    count++;
                    switch (count) {
                    case 1:
                        cout << "Прізвище: " << show << endl;
                        show = "";
                        break;
                    case 2:
                        cout << "Ініціали: " << show << endl;
                        show = "";
                        break;
                    case 3:
                        cout << "Посала: " << show << endl;
                        show = "";
                        break;
                    case 4:
                        cout << "Рік прийняття: " << show << endl;
                        show = "";
                        break;
                    case 5:
                        cout << "Оклад: " << show << endl;
                        show = "";
                        break;
                    }
                }
            }
        }
        find = "";

    }
}

// Функція для відображення меню і виконання вибраних дій
void menu(string filename) {
    int option;
    string lastname;
    while (true) {
        cout << "Меню:\n"
            << "[1] Створити/додати інформацію до файлу\n"
            << "[2] Вивести інформацію про службовцю, за прізвищем\n"
            << "[3] Вихід\n: ";
        cin >> option;
        cin.ignore(); // Ігноруємо \n після вводу опції

        switch (option) {
        case 1:
            addEmployeeInfo(filename);
            break;
        case 2:
            cout << "Введіть прізвище: ";
            cin >>lastname;
            cin.ignore(); // Ігноруємо \n після вводу часу
            displayEmployeeByLastname(filename, lastname);
            break;
        case 3:
            return; // Завершити програму
        default:
            cout << "Неправильний ввід!" << endl;
            break;
        }
    }
}

// Головна функція
int main() {
    SetConsoleCP(1251);        // Налаштування кодування для вводу
    SetConsoleOutputCP(1251); // Налаштування кодування для виводу

    string filename;
    cout << "Введіть ім'я файлу: ";
    getline(cin, filename);

    createOrAppendFile(filename); // Створення/відкриття файлу
    menu(filename);              // Відображення меню

    return 0;
}
