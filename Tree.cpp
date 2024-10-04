#include <iostream>
#include <set>
#include <string>
#include "Types.cpp"
#include "CircleHead.cpp"
using namespace std;


Elem* q;
bool DataLowX(Elem* est, string vst){//Нод-дата меньше x
    if(est->data->FB>vst[0]) return true;
    else if(est->data->number>stoi(vst.substr(1,3))) return true;
    else if(est->data->SB[0]>vst[4]) return true;
    else if(est->data->SB[1]>vst[5]) return true;
    return 0;
}


bool DataBigX(Elem* est, string vst){//Нод-дата больше x

    if(est->data->FB<vst[0]) return true;
    else if(est->data->number<stoi(vst.substr(1,3))) return true;
    else if(est->data->SB[0]<vst[4]) return true;
    else if(est->data->SB[1]<vst[5]) return true;
    return 0;
}

bool EXVELENT(Elem* est, string vst){//Нод-дата равно x
    if((est->data->FB==vst[0])and(est->data->number ==stoi(vst.substr(1,3))) and (est->data->SB[0]==vst[4]) and (est->data->SB[1]==vst[5])) return true;
    return 0;
}

void Search(string x, int y, Elem* &p, bool &h){ //Вставка элемента в дереве
    Elem* p1;
    Elem* p2;
    if (p== nullptr){
        string s= x.substr(1,3);
        p= new Elem();
        p->data=new Data();
        p->data->FB=char(x[0]);
        p->data->number=stoi(s);
        s= x.substr(4,5);
        p->data->SB=s;
        Add(p->head, y);
        //PrintCircle(p->head);
        h= 1;
    }else if(DataBigX(p,x)){
        Search(x,y,p->left,h);

        if (h) {
            if (p->bal == 1) {
                p->bal = 0;
                h = 0;
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
                h = 0;
            }
        }
    }else if (DataLowX(p,x)){
        Search(x,y,p->right,h);

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
                h=0;
            }
        }
    }else if(EXVELENT(p,x)){
        if (!Searching(p->head, y)) Add(p->head,y); else cout<<"Pitaetes dobavit tot zhe kluc"<<endl;
        //PrintCircle(p->head);
        h=0;
    }
}

void balanceL(Elem* &p, bool &h ){ //Левая балансировка
    Elem* p1;
    Elem* p2;
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
            if (p2->bal==-1) p->bal=1; else p->bal=0;
            p=p2;
            p2->bal=0;
        }
    }
}

void balanceR(Elem* &p, bool &h){ //Правая балансировка
    Elem* p1;
    Elem* p2;
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
            if (p2->bal==1) p->bal=-1; else p->bal=0;
            p=p2;
            p2->bal=0;
        }
    }
}

void del(Elem* &r, bool &h){
    if (r->right != nullptr){
        del(r->right,h);
        if (h) balanceR(r,h);
    }else{
        q->data= r->data;
        q=r;
        r=r->left;
        h=1;
    }
}

void deletel(string x, int y, Elem* &p, bool &h){ //Удаление узла в дереве
    if (p== nullptr){cout<<"Key doesn't exist!"<<endl;}
    else if((EXVELENT(p,x))and (Searching(p->head, y))and (p->head!=p->head->next)){
        dldl(p->head,y);

    }else if(DataBigX(p,x)){
        deletel(x,y,p,h);
        if (h) balanceL(p,h);
    }else if(DataLowX(p,x)){
        deletel(x,y,p->right,h);
        if (h) balanceR(p,h);
    }else{
        q=p;
        if (q->right== nullptr) {p=q->left; h=1;}
        else if(q->left== nullptr){ p=q->right;h=1;}
        else{
            del(q->left,h);
            if (h) balanceL(p,h);
        }
    }
}

bool Is(Elem* p, string x){//Проверка наличия узла в дереве с таким значением
    if (p== nullptr){
        return 0;
    } else if (DataBigX(p,x)){
        Is(p->left,x);
    }else if (DataLowX(p,x)){
        Is(p->right,x);
    }else if(EXVELENT(p,x)){
        PrintCircle(p->head);
    }
}

string Sbor(Elem* p){
    string s;
    s+=p->data->FB;
    s+= to_string(p->data->number);
    s+=p->data->SB;
    return s;
}

void Print(Elem* t, int h){ //Распечатать дерево
    if (t!= nullptr){
        Print(t->left,h+1);
        for (int i =1; i<h; i++ ){
            cout<<"  ";
        }
        cout<<Sbor(t)<<" ";
        PrintCircle(t->head);
        Print(t->right,h+1);
    }
}

void PreOrder(Elem* p){ //Обратный проход
    if (p!=nullptr){
        PreOrder(p->left);
        PreOrder(p->right);
        cout<<Sbor(p)<<"  ";
        PrintCircle(p->head);
    }
}
