#ifndef C___MAINTREE_H
#include <iostream>
#include "Structures.h"
#include "SupportFunctions.h"
#include "Circle.h"
#include <cstring>
#include <vector>
using namespace std;
#define C___MAINTREE_H

inline int DataBigX( PhoneNumber& datanum, int FirstNum, int SecNum, string ThirdNumber){
//    if(datanum.CodeOfCountry != FirstNum) {
//        if (datanum.CodeOfCountry > FirstNum) return true; else return false;}
    if (datanum.CodeOfRegion != SecNum)
        { if (datanum.CodeOfRegion > SecNum) return true; else return false; }
    if (datanum.Numbers != ThirdNumber) {
        if (stoi(datanum.Numbers) > stoi(ThirdNumber)) return true;
        else return false;
    }
    return -1;
}

//bool EqvNumbAndMB(Number* &Num, BrandName* &BM, vector<string> &mas, string Brand, string Model){
//    return (Num->FB == stoi(mas[0]) and Num->number == stoi(mas[1]) and Num->SB==mas[2] and BM->Brand==Brand and BM->Model==Model);
//}
//
//bool EqDateAndDate(Date* &ate , int day, string month, int year){
//
//}

class AVL{
    bool h= false;
    Node* r = nullptr;
    Node* q= nullptr;
public:
    void AddAVLNode(Elem* &linkElem){
        AddNode(linkElem,r);
    }

    int DeleteNode(vector<string> &mas, string BRAND, string MODEL, int day, string month, int year){
        bool flag = true;
        deletel(mas,r,BRAND,MODEL,day,month,year,flag);
        if(flag){
            cout<<"Node was deleted"<<endl;
            return 1;
        }else {
            cout<<"Node wasn't deleted"<<endl;
            return 0;
        }
    }

    bool IsThisElement(int FirstNum , int SecNum, string ThirdNum){
        return Is(r,  FirstNum ,  SecNum,  ThirdNum);
    }

    string FindDateAVL(vector<string> &mas, string Brand, string Model){
        string out;
        if(FindDate(r, mas,Brand,Model,out)){
            return out;
        } else return "";

    }

    bool UniqueKeyPublic(int FB, string NUM, string SB, string Brand, string Model){
        bool flag=true;
        vector<string> mas= {to_string(FB), NUM,SB};
        UniquKey(r,mas,Brand,Model,flag);
        if (!flag){
            return false;
        } else return true;
    }

    bool PrintTree(){
        PrintTr(r,20);
        return true;
    }


private:

    bool UniquKey(Node* p, vector <string> &mas, string Brand, string Model, bool &flag){
        if (p== nullptr){
            return true;
        }else
        if (!flag){
            return false;
        }
        else  {
            UniquKey(p->left, mas, Brand, Model, flag);
            UniquKey(p->right,mas, Brand, Model, flag);

            if(SearchingNumbAndMB(p->data, mas,Brand,Model)) {
                flag= false;
                return false;
            }
        }

    }

    void AddNode(Elem* &linkElem, Node* &p){ //Вставка элемента в дереве
        Node* p1;
        Node* p2;
        if (p== nullptr){
            p= new Node();
            Add(p->data,linkElem);
            h= true;
        }else if(DataBigX(p->data->Circledata->phoneNumber, linkElem->phoneNumber.CodeOfCountry, linkElem->phoneNumber.CodeOfRegion, linkElem->phoneNumber.Numbers)==1){
            AddNode(linkElem,p->left);
            if (h) {
                if (p->bal == 1) {
                    p->bal = 0;
                    h = false;
                } else if (p->bal == 0) {
                    p->bal =-1;
                } else {
                    p1 = p->left;
                    if (p1->bal == -1) {
                        p->left = p1->right;
                        p1->right = p;
                        p->bal = 0;
                        p = p1;
                    } else {
                        p2 = p1->right;
                        p1->right = p2->left;
                        p2->left = p1;
                        p->left = p2->right;
                        p2->right = p;
                        if (p2->bal == -1) p->bal = 1; else p->bal = 0;
                        if (p2->bal ==1) p->bal = -1; else p1->bal = 0;
                        p = p2;
                    }
                    p->bal = 0;
                    h = false;
                }
            }
        }else if (DataBigX(p->data->Circledata->phoneNumber, linkElem->phoneNumber.CodeOfCountry, linkElem->phoneNumber.CodeOfRegion, linkElem->phoneNumber.Numbers)==0){
            AddNode(linkElem,p->right);
            if (h){
                if (p->bal==-1){
                    p->bal=0;
                    h=0;
                }else if (p->bal==0) p->bal=1;
                else{
                    p1=p->right;
                    if (p1->bal==1){
                        p->right=p1->left;
                        p1->left=p;
                        p->bal=0;
                        p=p1;
                    }else {
                        p2=p1->left;
                        p1->left=p2->right;
                        p2->right=p1;
                        p->right=p2->left;
                        p2->left=p;
                        if (p2->bal==1) p->bal=-1; else p->bal=0;
                        if (p2->bal==-1) p->bal=1; else p1 ->bal=0;
                        p=p2;
                    }
                    p->bal=0;
                    h= false;
                }
            }
        }else{
            Add(p->data,linkElem);
            h= false;
        }
    }

    bool Is(Node* p, int &FirstNum , int &SecNum, string ThirdNum){//Проверка наличия узла в дереве с таким значением
        if (p== nullptr){
            return 0;
        } else if (DataBigX(p->data->Circledata->phoneNumber, FirstNum, SecNum, ThirdNum)==1){
            Is(p->left, FirstNum,SecNum, ThirdNum);
        }else if (DataBigX(p->data->Circledata->phoneNumber,FirstNum,SecNum, ThirdNum)==0) {
            Is(p->right, FirstNum,SecNum, ThirdNum);
        }else {
            return 1;
        }
    }

    void balanceL(Node* &p){ //Левая балансировка
        Node* p1;
        Node* p2;
        if (p->bal==-1) p->bal=0;
        else if (p->bal==0) { p->bal = 1; h= false; }
        else {
            p1=p->right;
            if (p1->bal>=0){
                p->right=p1->left;
                p1->left=p;
                if (p1->bal==0){ p->bal=1; p1->bal=-1;h=0;} else {p->bal=0; p1->bal=0;}
                p=p1;
            }
            else{
                p2=p1->left;
                p1->left=p2->right;
                p2->right=p1;
                p->right=p2->left;
                p2->left=p;
                if (p2->bal==1) p->bal=-1; else p->bal=0;
                if (p2->bal==-1) p1->bal=1; else p1->bal=0;
                p=p2;
                p2->bal=0;
            }
        }
    }

    void balanceR(Node* &p){ //Правая балансировка
        Node* p1;
        Node* p2;
        if (p->bal==1) p->bal=0;
        else if (p->bal==0) {p->bal=-1; h=0;}
        else{
            p1=p->left;
            if (p1->bal<=0){
                p->left=p1->right;
                p1->right=p;
                if (p1->bal==0){p->bal=-1; p1->bal=1; h=0;} else {p->bal=0;p1->bal=0;}
                p=p1;
            }
            else{
                p2=p1->right;
                p1->right=p2->left;
                p2->left=p1;
                p->left=p2->right;
                p2->right=p;
                if (p2->bal==-1) p->bal=1; else p->bal=0;
                if (p2->bal==1) p1->bal=-1; else p1->bal=0;
                p=p2;
                p2->bal=0;
            }
        }
    }

    void del(Node* &r){
        if (r->left != nullptr){
            del(r->left);
            if (h) balanceL(r);
        }else{
            q->data= r->data;
            q=r;
            r=r->right;
            h = true;
        }
    }//

    void deletel(vector<string> &mas, Node* &p, string &BRAND, string &MODEL, int day, string month, int year, bool &flag){ //Удаление узла в дереве
        if (p == nullptr){cout<<"Key doesn't exist!"<<endl; flag = false;}
        else if((DataBigX(p->data->Circledata->phoneNumber, stoi(mas[3]), stoi(mas[4]), mas[5])==-1) and SearchingDate(p->data,day,month,year) and
                SearchingNumbAndMB(p->data, mas,BRAND,MODEL) and (p->data!=p->data->next)){
            DeleteCircleNode(p->data, mas, BRAND,MODEL,day,month,year );
        }
        else if(DataBigX(p->data->Circledata->phoneNumber, stoi(mas[3]), stoi(mas[4]), mas[5])==1){
            deletel(mas,p->left, BRAND, MODEL, day,month,year, flag);
            if (h) balanceL(p);
        }else if(DataBigX(p->data->Circledata->phoneNumber, stoi(mas[3]), stoi(mas[4]), mas[5])==0){
            deletel(mas,p->right, BRAND, MODEL, day,month,year, flag);
            if (h) balanceR(p);
        }else{
            q=p;
            if (q->right== nullptr) {p=q->left; h=1;}
            else if(q->left== nullptr){ p=q->right;h=1;}
            else{
                del(q->right);
                if (h) balanceR(p);
            }
        }
    }

    void PrintTr(Node* t, int n){ //Распечатать дерево
        if (t!= nullptr){
            PrintTr(t->left,n+20);
            for (int i =1; i<n; i++ ){
                cout<<"  ";
            }
            cout<<SborPhoneNumber(t->data->Circledata->phoneNumber)<<"      ";
            PrintCircle(t->data);
            PrintTr(t->right,n+20);
        }
    }

    bool FindDate(Node* p, vector<string> &mas, string Brand, string Model, string &out){
        if (p== nullptr){
            return 0;
        } else if (DataBigX(p->data->Circledata->phoneNumber, 8, stoi(mas[4]), mas[5])==1){
            FindDate(p->left, mas, Brand, Model,out);
        }else if (DataBigX(p->data->Circledata->phoneNumber,8, stoi(mas[4]), mas[5])==0) {
            FindDate(p->right, mas, Brand, Model, out);
        }else {
            if(SearchingDateFIND(p->data,mas, Brand, Model,out)) return 1;
            else return 0;
        }
    }
};
#endif //C___MAINTREE_H
