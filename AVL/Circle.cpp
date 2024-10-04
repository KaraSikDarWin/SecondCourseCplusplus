//
// Created by oslon on 31.10.2023.
//
#include <iostream>
#include "Circle.h"
using namespace std;


void Add(Circle* &head, int x){ //Добавление элемента в список который в каждом узле
    Circle* run= head;
    if (head== nullptr){
        head = new Circle(x);
    }else{
        while(run->next!=head){
            run=run->next;
        }
        Circle* beg =new Circle(x);
        run->next=beg;
        beg->next=head;
        head=beg;
    }
}//

void PrintCircle(Circle* head){//напечатать список указатель на который в каждом узле
    if (head!= nullptr) {
        Circle *run = head;
        while (run->next != head) {
            cout << run->data;
            cout << " ";
            run = run->next;
        }
        cout << run->data << endl;
    }else cout<<"List doesn't exist!"<<endl;
}//

void dldl(Circle* &head, int x){ //Удалить элемент из списка, указатель которого находится в каждом узле
    Circle* run =head->next;
    Circle* beg =head;
    while (run!=head){
        if(run->data==x){
            beg->next=run->next;
            delete run;
            run=beg->next;
        }
        beg=beg->next;
        run=run->next;
    }
    if (run->data==x){
        beg->next=run->next;
        delete run;
        head=beg->next;
    }
}//

bool Searching(Circle* head,int x){//Проверка наличия элемента в списке указатель на который находится в каждом узле
    if(head!= nullptr) {
        bool flag = 0;
        Circle *run = head;
        while ((run->next != head)and (flag==0)) {
            if (run->data == x) {
                flag = 1;

            } else run = run->next;
        }
        if (run->data == x) {
            flag = 1;
        }

        if (flag) {
            return flag;
        } else return flag;
    }else cout<<"List doesn't exists!"<<endl;
}//

void DelCircle(Circle* &head){
    Circle* run;
    Circle* beg;
    if (head!= nullptr){
        if (head->next==head){
            delete head;
            head= nullptr;
        }else{
            run=head->next;
            while(run->next!=head){
                beg=run->next;
                delete run;
                run= beg;
            }
            delete run;
            delete head;
            head= nullptr;

        }
    }else cout<<"List doesn't exist!"<<endl;
}//
