#pragma once
#include<vector>
#include<list>
using namespace std;


template<class T>
class HashTable {
public:
    list<pair<string, T>>* Array_of_Lists;

    int array_size;
    int objects_count;
    int array_list_index;

    HashTable() {
        array_size = 10;
        Array_of_Lists = new list<pair<string, T>>[array_size];
        objects_count = NULL;
        array_list_index = NULL;
    }

    HashTable(int size) {
        if (size < 1)
            throw logic_error("��������� ������ ������ ������������, ������ � ������������.");
        else if (size > 1000)
            throw logic_error("��������� ������ ������ �������������, ������ � ������������.");
        else
            array_size = size;
        Array_of_Lists = new list<pair<string, T>>[array_size];
        objects_count = NULL;
        array_list_index = NULL;
    }

    ~HashTable() {}

    bool isEmpty() { // �������� �� �������
        return objects_count == NULL;
    }

    bool isFull() { // �������� �� �������
        return objects_count >= 10000000;
    }

    int get_size() { // ��������� �������
        return array_size;
    }

    int get_objects_count() { // ��������� ���������� �������� � �������
        return objects_count;
    }

    int HashFunction(string value) { // ��� �������
        int final_pos = NULL;
        for (const auto element : value) 
            final_pos += abs(element);
        return final_pos % array_size;
    }

    T get_table_object(int index) {  // ��������� ������� �� �������
        int i = 0;
        for (auto iterator = Array_of_Lists[array_list_index].begin(); iterator != Array_of_Lists[array_list_index].end(); iterator++) {
            if (i == index)
                return (*iterator).second;
            else
                i++;
        }
        return NULL;
    }

    void TableEntry(string value, T table_object, int index) { // ������ � �������
        if (index == -1)
            Array_of_Lists[array_list_index].push_back(pair<string, T>(value, table_object));
        else {
            int i = 0;
            for (auto iterator = Array_of_Lists[array_list_index].begin(); iterator != Array_of_Lists[array_list_index].end(); iterator++) {
                if (i == index) 
                    *iterator = pair<string, T>(value, table_object);
                else 
                    i++;
            }
        }
    }
    
    int find(string value) {  // ����� ������� ������� � �������
        array_list_index = HashFunction(value);
        int i = NULL;
        if (!Array_of_Lists[array_list_index].empty())
            for (auto iterator = Array_of_Lists[array_list_index].begin(); iterator != Array_of_Lists[array_list_index].end(); iterator++) {
                if (value == (*iterator).first) 
                    return i;
                else 
                    i++;
            }
        return -1;
    }

    void insert(string value, T table_object) { // ������ � �������
        if (isFull())
            throw logic_error("������� ���������, ������ � ������ �������");
        int index = find(value);
        if (index != -1)
            throw logic_error("� ������� ��� ���� ��������� � ����� �� ������, ������ � ������ ������");
        TableEntry(value, table_object, -1);
        objects_count++;
    }

    void update(string value, T table_object) { // ���������� ��������� �������
        int index = find(value);
        if (index == -1) 
            throw logic_error("��������� ������� �� ������, ������ � ������ ����������");
        TableEntry(value, table_object, index);
    }

    void remove(string value) { // �������� �������� �� �������
        if (isEmpty()) 
            throw logic_error("������� �����, ������ � ������ ��������");
        int index = find(value);
        if (index == -1) 
            throw logic_error("��������� ������� �� ������, ������ � ������ ��������");
        Array_of_Lists[array_list_index].remove({ value, get_table_object(index) });
    }

    void print() { // ����� �� �����
        for (int i = 0; i < array_size; i++) 
            if (!Array_of_Lists[i].empty())
                for (auto iterator = Array_of_Lists[i].begin(); iterator != Array_of_Lists[i].end(); iterator++) 
                    cout << (*iterator).first << " | " << (*iterator).second << endl;
    }

    int get_array_list_index() { // ��������� ������� ������� ������
        return array_list_index;
    }

    void set_array_list_index(int value) { // ��������� �������
        if (value > array_size)
            throw logic_error("������� ������� ��������, ����������� ������ ������� �������");
        if (value < 1)
            throw logic_error("������� ����� ��������");
        array_list_index = value;
    }
};