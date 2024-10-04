//
// Created by oslon on 31.10.2023.
//

#ifndef C___TREES_H
#define C___TREES_H
#include <iostream>
#include "Circle.h"
using namespace std;
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

bool DataLowX(Elem* est, string vst);
bool DataBigX(Elem* est, string vst);
bool EXVELENT(Elem* est, string vst);
void Search(string x, int y, Elem* &p, bool &h);
void balanceL(Elem* &p, bool &h );
void balanceR(Elem* &p, bool &h);
void del(Elem* &r, bool &h);
void deletel(string x, int y, Elem* &p, bool &h);
bool Is(Elem* p, string x);
string Sbor(Elem* p);
void Print(Elem* t, int h);
void PreOrder(Elem* p);
void FullDel(Elem* &p);

#endif //C___TREES_H
