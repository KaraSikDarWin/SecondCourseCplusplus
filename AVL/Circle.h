//
// Created by oslon on 31.10.2023.
//
#pragma once
//#ifndef C___CIRCLE_H
//#define C___CIRCLE_H

    struct Circle{//Описание элемента списка в котором будет хранится информация о тех строках в которых встречается этот элемент
        int data;
        Circle* next;
        Circle():data(), next(this){};
        Circle(int x):data(x), next(this){};
    };//
    void Add(Circle* &head, int x);
    void PrintCircle(Circle* head);
    void dldl(Circle* &head, int x);
    bool Searching(Circle* head,int x);
    void DelCircle(Circle* &head);



//#endif //C___CIRCLE_H
