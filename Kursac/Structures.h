#ifndef C___STRUCTURES_H
#include <iostream>
using namespace std;
#define C___STRUCTURES_H
class AVL;
struct Number{
    char FB;
    string number;
    string SB;
    Number(){};
    Number(int fb, string number, string sb):FB(fb),number(number),SB(sb){};
};

struct PhoneNumber{
    int CodeOfCountry=8;
    int CodeOfRegion;
    string Numbers;
    PhoneNumber(){};
    PhoneNumber(int regioncode, string phonenumbers):CodeOfRegion(regioncode), Numbers(phonenumbers){};
};

struct BrandName{
    string Brand;
    string Model;
    BrandName(){};
    BrandName(string brand, string model):Brand(brand), Model(model){};
};

struct Date{
    int Day;
    string Month;
    int Year;
    Date(){};
    Date(int day, string month, int year):Day(day), Month(month), Year(year){};
};

struct Elem{
    Number number;
    PhoneNumber phoneNumber;
    BrandName brandName;
    Date date;
    int NumberOfString;
    Elem(){};
    Elem(int FB, string number, string SB, int regioncode, string phonenumbers, string brand, string model, int day, string month, int year):
    number(Number(FB,number,SB)), phoneNumber(regioncode,phonenumbers), brandName(brand,model), date(Date(day,month,year)){};
};

//Добавить круг
struct Circle{//Описание элемента списка в котором будет хранится информация о тех строках в которых встречается этот элемент
    Elem* Circledata;
    Circle* next;
    Circle():Circledata(), next(this){};
    Circle(Elem* x):Circledata(x), next(this){};
};

struct Node{//Описание узла дерева
    Circle* data;
    int bal;
    Node* right;
    Node* left;
    Node():right(nullptr), left(nullptr), bal(0), data(nullptr){};
};//

struct HashNode{
    AVL* LinkNode;
    HashNode(int =0):LinkNode(nullptr){};
};
#endif //C___STRUCTURES_H