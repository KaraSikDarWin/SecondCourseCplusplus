#include <iostream>
using namespace std;
struct Circle{//Описание элемента списка в котором будет хранится информация о тех строках в которых встречается этот элемент
    int data;
    Circle* next;
    Circle():data(), next(this){};
    Circle(int x):data(x), next(this){};
};

struct Data{
    char FB;
    int number;
    string SB;
};

struct Elem{//Описание узла дерева
    Data* data;
    //string data;
    Circle* head;
    int bal;
    Elem* right;
    Elem* left;
    Elem():data(), right(nullptr), left(nullptr), bal(0),head(nullptr){};
};
