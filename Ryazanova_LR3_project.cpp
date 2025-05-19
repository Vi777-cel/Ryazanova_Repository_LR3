#include <iostream>
#include <limits> // Для std::numeric_limits
using namespace std;

void inputBytes(unsigned long long& B) {
     cout << "Введите количество байтов: ";
    while (!(cin >> B)) {
        cout << "Ошибка ввода! Пожалуйста, введите целое число: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void toMegabytes(unsigned long long B) {
    if (B == 0) {
        cout << "Сначала введите объем данных (пункт 1).\n";
        return;
    }
    double MB = static_cast<double>(B) / (1024 * 1024);
    cout << B << " байт = " << MB << " мегабайт (MB)\n";
}

void toGigabytes(unsigned long long B) {
    if (B == 0) {
        cout << "Сначала введите объем данных (пункт 1).\n";
        return;
    }
    double GB = static_cast<double>(B) / (1024 * 1024 * 1024);//
    cout << B << " байт = " << GB << " гигабайт (GB)\n";
}

int main() {
    unsigned long long B = 0;
    int choice;
    
    do {
        cout << "\nМеню:\n";
        cout << "1. Ввести объем информации в байтах (B)\n";
        cout << "2. Выразить объем B в мегабайтах\n";
        cout << "3. Выразить объем B в гигабайтах\n";
        cout << "0. Выход\n";
        cout << "Выберите пункт меню: ";
        
        while (!(cin >> choice)) {
            cout << "Ошибка ввода! Введите число: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        switch(choice) {
            case 1:
                inputBytes(B);
                break;
            case 2:
                toMegabytes(B);
                break;
            case 3:
                toGigabytes(B);
                break;
            case 0:
                cout << "Выход из программы.\n";
                break;
            default:
                cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while(choice != 0);
    
    return 0;
}