#include <iostream>
using namespace std;

const int MAX_ARRAY_SIZE = 100;

void inputArray(int arr[], int &n) {
    cout << "Введіть розмір масиву: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }
}

void outputArray(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

//                  ARRAY 3 
// Формування перших N членів арифм. прогресії з A та D

void makeArray3(int arr[], int n, int A, int D) {
    for (int i = 0; i < n; i++) {
        arr[i] = A + i * D;
    }
}

//                ARRAY 24 
// Перевірити, чи утворюють елементи масиву арифметичну прогресію.
// Якщо так — вивести різницю D, інакше 0.
int checkArray24(int arr[], int n) {
    if (n < 2) return 0;

    int D = arr[1] - arr[0];

    for (int i = 2; i < n; i++) {
        if (arr[i] - arr[i - 1] != D) return 0;
    }

    return D;
}

void taskArray24() {
    int arr[MAX_ARRAY_SIZE], n;
    inputArray(arr, n);

    cout << "Ваш масив: ";
    outputArray(arr, n);

    int D = checkArray24(arr, n);
    cout << "Результат: " << D << endl;
}

//          ARRAY 77 
// Звести у квадрат локальні мінімуми
// (елементи менші за ЛІВИЙ і ПРАВИЙ сусід).

void modifyArray77(int arr[], int n) {
    for (int i = 1; i < n - 1; i++) {
        if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
            arr[i] = arr[i] * arr[i];
        }
    }
}

void taskArray77() {
    int arr[MAX_ARRAY_SIZE], n;
    inputArray(arr, n);

    cout << "Початковий масив: ";
    outputArray(arr, n);

    modifyArray77(arr, n);

    cout << "Масив після змін: ";
    outputArray(arr, n);
}

//          ГОЛОВНЕ МЕНЮ

int main() {
    int choice;

    do {
        cout << "\n МЕНЮ \n";
        cout << "1 — Array24 (перевірка арифметичної прогресії)\n";
        cout << "2 — Array77 (квадрат локальних мінімумів)\n";
        cout << "0 — Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
            case 1:
                taskArray24();
                break;

            case 2:
                taskArray77();
                break;

            case 0:
                cout << "Вихід...\n";
                break;

            default:
                cout << "Невірний вибір!\n";
        }

    } while (choice != 0);

    return 0;
}
