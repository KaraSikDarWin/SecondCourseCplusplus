//
// Created by oslon on 03.06.2024.
//

#ifndef C___HASHTABLEBAZA_H
#define C___HASHTABLEBAZA_H
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <cmath>
#include <iomanip>
#include "mainTree.h"
#include "SupportFunctions.h"

using namespace std;

class HashTable{
    int size;
    int NonEmptyNodes;
    vector<HashNode> Table;

private:

    int addHashNode(Elem *p){
        int hash = MultHash(p->brandName.Brand,p->brandName.Model,p->number.FB, stoi(p->number.number),p->number.SB);
        if (CheckUnique(p,hash)) {
            Table[hash].LinkNode->AddAVLNode(p);
            NonEmptyNodes++;
            return 1;
        } else {cout<<"Same Element"<<"\n"; return 0; }

    };

    bool CheckUnique(Elem* p, int hash){
        if(!Table[hash].LinkNode->UniqueKeyPublic(int(p->number.FB), p->number.number,p->number.SB, p->brandName.Brand, p->brandName.Model)){
            return false;
        }else return true;
    }

    int MultHash(string Brand, string Model, char FB, int Numb, string SecNum){
        int key = ConvertStringToInt(Brand)+ConvertStringToInt(Model)+ConvertStringToInt(SecNum)+FB+Numb;
        float answ = key * 0.618033;
        answ = answ - int(answ);
        return ::floor(size * answ);
    }

public:


    bool Find(string NUM, string PhoneNumber, string BRAND, string MODEl){
        vector<string> mas;
        SplitNum(NUM,mas);
        SplitPhone(PhoneNumber,mas);
        mas.push_back(BRAND);
        mas.push_back(MODEl);
        int hash = MultHash(BRAND,MODEl,stoi(mas[0]), stoi(mas[1]),mas[2]);
        return Table[hash].LinkNode->IsThisElement(stoi(mas[3]), stoi(mas[4]), mas[5]);

    }

    string FindDateHash(string NUM, string PhoneNumber, string BRAND, string MODEl){
        vector<string> mas;
        SplitNum(NUM,mas);
        SplitPhone(PhoneNumber,mas);
        int hash = MultHash(BRAND,MODEl,stoi(mas[0]), stoi(mas[1]),mas[2]);
        string out =Table[hash].LinkNode->FindDateAVL(mas, BRAND,MODEl);
        if (!out.empty()){
            return out;
        } else return "";

    }

    int PublicAddHashNode(string NUM ,string PhoneNumberIn, string BRAND, string MODEL, int day, string month, int year){
        vector <string> mas;
        SplitNum(NUM,mas);
        SplitPhone(PhoneNumberIn, mas);
        Elem *p = new Elem(stoi(mas[0]), mas[1], mas[2], stoi(mas[4]), mas[5], BRAND, MODEL, day, month, year);
        addHashNode(p);

    }

    int Delete(string NUM, string PhoneNumberIn, string BRAND, string MODEL, int day, string month, int year){
        vector <string> mas;
        SplitNum(NUM,mas);
        SplitPhone(PhoneNumberIn, mas);
        int hash = MultHash(BRAND,MODEL,stoi(mas[0]), stoi(mas[1]),mas[2]);
        Table[hash].LinkNode->DeleteNode(mas, BRAND, MODEL,day,month,year);
    }

    void PrintHashTable(){
        for (int i = 0; i<size;i++){
            cout<<to_string(i)+":"<<"\n";
            Table[i].LinkNode->PrintTree();
            cout<<"---------------------------------------------------"<<'\n';
        }
    }

    HashTable(int size):size(size),NonEmptyNodes(0){
        HashNode p(0);
        Table= vector<HashNode> (size, p);
        for (int i=0;i<size;i++){
            Table[i].LinkNode= new AVL();
        }
    }
    HashTable():size(0),NonEmptyNodes(0){};

    void Create(int N, string Name){
        cout<<"Reading data started..."<<endl;
        ifstream fin("D:/Kursac/untitled/KursaCInput.txt");
        string b;

        for (int i=0; i<N;i++){
            getline(fin,b);
            Elem* p = new Elem();
            Rasdel(*p,b);
            p->NumberOfString=i+1;
            addHashNode(p);
        }
        cout<<"Reading data finished..."<<endl;
    }

    ~HashTable(){
        Table.clear();
    }

};
#endif //C___HASHTABLEBAZA_H
