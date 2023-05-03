#include <iostream>
#include"Dictionaries.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    HashTable<string> table(20);

    vector<string> list1 {
      "�����",
      "����",
      "�����",
      "�������",
      "����"
    };

    vector<string> list2 {
      "�����",
      "�������",
      "��������",
      "����",
      "�������"
    };

    for (auto element : list1) {
        table.insert(element, "������ �������");
    }
    table.print();
    cout << "====================" << endl;
    for (auto element : list2) {
        if (table.find(element) == -1) {
            table.insert(element, "������ �������");
        }
    }
    table.print();
    table.remove("�����");
    cout << "====================" << endl;
    table.print();

    return 0;
}