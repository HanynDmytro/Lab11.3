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


// ������� ��������� ������ ����� ��� �������� ��� ��������� ������
void createOrAppendFile(string filename) {
    ofstream file(filename, ios::app);
    if (!file) {
        cerr << "������� ��� ��������/������� �����" << endl;
    }
    file.close();
}

// ������� ��������� ���������� ��� ����� �� �����
void addEmployeeInfo(string filename) {
    ofstream file(filename, ios::app);
    if (!file) {
        cerr << "������� ��� ������� �����" << endl;
        return;
    }

    Info employee;
    cout << "������ �������: ";
    getline(cin, employee.lastname);

    cout << "������ �������:  ";
    cin >> employee.initial;
    cin.ignore(); // �������� \n ���� ����� ����

    cout << "������ ������: ";
    cin >> employee.position;
    cin.ignore(); // �������� \n ���� ����� ����

    cout << "������ �� ��������� �� ������: ";
    cin >> employee.year;
    cin.ignore(); // �������� \n ���� ����� ����

    cout << "������ �����: ";
    cin >> employee.salary;
    cin.ignore(); // �������� \n ���� ����� ����

    file << employee.lastname << " " << employee.initial << " " << employee.position << " " << employee.year << " " << employee.salary <<  endl;
    file.close();
    cout << "���������� ��� ��������� ������ �� �����." << endl;
}

// ������� ������ ���������� ��� ������, �� ������������� ���� �������� ����
void displayEmployeeByLastname(string filename, string lastname) {
    ifstream file(filename);
    string s;
    string find;
    if (!file) {
        cerr << "������� ��� ������� �����" << endl;
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
                        cout << "�������: " << show << endl;
                        show = "";
                        break;
                    case 2:
                        cout << "�������: " << show << endl;
                        show = "";
                        break;
                    case 3:
                        cout << "������: " << show << endl;
                        show = "";
                        break;
                    case 4:
                        cout << "г� ���������: " << show << endl;
                        show = "";
                        break;
                    case 5:
                        cout << "�����: " << show << endl;
                        show = "";
                        break;
                    }
                }
            }
        }
        find = "";

    }
}

// ������� ��� ����������� ���� � ��������� �������� ��
void menu(string filename) {
    int option;
    string lastname;
    while (true) {
        cout << "����:\n"
            << "[1] ��������/������ ���������� �� �����\n"
            << "[2] ������� ���������� ��� ���������, �� ��������\n"
            << "[3] �����\n: ";
        cin >> option;
        cin.ignore(); // �������� \n ���� ����� �����

        switch (option) {
        case 1:
            addEmployeeInfo(filename);
            break;
        case 2:
            cout << "������ �������: ";
            cin >>lastname;
            cin.ignore(); // �������� \n ���� ����� ����
            displayEmployeeByLastname(filename, lastname);
            break;
        case 3:
            return; // ��������� ��������
        default:
            cout << "������������ ���!" << endl;
            break;
        }
    }
}

// ������� �������
int main() {
    SetConsoleCP(1251);        // ������������ ��������� ��� �����
    SetConsoleOutputCP(1251); // ������������ ��������� ��� ������

    string filename;
    cout << "������ ��'� �����: ";
    getline(cin, filename);

    createOrAppendFile(filename); // ���������/�������� �����
    menu(filename);              // ³���������� ����

    return 0;
}
