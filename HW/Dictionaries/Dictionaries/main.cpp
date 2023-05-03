#include <iostream>
#include"Dictionaries.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    HashTable<string> table(20);

    vector<string> list1 {
      "Цветы",
      "Духи",
      "Кошка",
      "Завтрак",
      "Кофе"
    };

    vector<string> list2 {
      "Кошка",
      "Телефон",
      "Осьминог",
      "Кофе",
      "Ноутбук"
    };

    for (auto element : list1) {
        table.insert(element, "Первая таблица");
    }
    table.print();
    cout << "====================" << endl;
    for (auto element : list2) {
        if (table.find(element) == -1) {
            table.insert(element, "Вторая таблица");
        }
    }
    table.print();
    table.remove("Кошка");
    cout << "====================" << endl;
    table.print();

    return 0;
}