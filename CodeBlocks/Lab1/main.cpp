// 1. Реалізувати рекурсивну функцiю множення двох натуральних чисел, використовуючи рекурентне співвідношення
/*
1. Початок.
2. Виведення початкового тексту. Прийняти у юзера а і b.
3. Виведення введених а і b.
4. Пошук a*b:
4.1 Якщо а == 1, то повернути b.
4.2 Якщо а > 1, то:
4.2.1 Зменшити а на одиницю.
4.2.2 Повернути цю саму функцію для (а - 1) та b, додати до результату b
4.2.3 Продовжується поки а не стане 1....
5. Виведення результату a * b
6. Кінець. (пауза)
*/

#include <iostream>

using namespace std;
int a, b;

void init();
int functionAB(int a, int b);
void pause();

int main() {
    init();
    cout << "entered a is " << a << endl;
    cout << "entered b is " << b << endl;
    cout << "base a*b is equal to " << functionAB(a, b) << endl;
    pause();
    return 0;
}

void init() {
    cout << "Enter a and b" << endl;
    cin >> a >> b;
}

int functionAB(int a, int b) {
    if (a == 1) return b;
    if (a > 0)  return functionAB(--a, b) + b;
}

void pause() {
    cin.sync();
    cin.ignore();
}
