#include <iostream>
//#include "Trees.h"
//#include "Access.h"
#include "fstream"
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
}

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
}

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
}

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
}



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
            if (p1->bal==0){ p->bal=1; p1->bal=-1;h=0;}
            else {p->bal=0; p1->bal=0;}
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
            if (p1->bal==0){p->bal=-1; p1->bal=1; h=0;}
            else {p->bal=0;p1->bal=0;}
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

void del(Elem* &r, bool &h, Elem* &q){
    if (r->right != nullptr){
        del(r->right,h, q);
        if (h) balanceR(r,h);
    }else{
        q->data= r->data;
        q=r;
        r=r->left;
        h= true;
    }
}

void deletel(string x, int y, Elem* &p, bool &h) { //Удаление узла в дереве

    Elem* q;
    if (p == nullptr)  cout << "Key doesn't exist!" << endl;
    else if((EXVELENT(p,x))and (Searching(p->head, y))and (p->head!=p->head->next)){
        dldl(p->head,y);

    }else if(DataBigX(p,x)){
        deletel(x,y,p->left,h);
        if (h) balanceL(p,h);
    }else if(DataLowX(p,x)){
        deletel(x,y,p->right,h);
        if (h) balanceR(p,h);
    }else{
        q=p;
        if (q->right== nullptr) {p=q->left; h=1;}
        else if(q->left== nullptr){ p=q->right;h=1;}
        else{
            del(q->left,h,q);
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
    return 1;
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
        Print(t->left,h+3);
        for (int i =1; i<h; i++ ){
            cout<<"  ";
        }
        cout<<Sbor(t)<<" ";
        PrintCircle(t->head);
        Print(t->right,h+3);
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

bool Check(string s){
    if ((s.length()==6) and (100<=stoi(s.substr(1,3)) and 999>stoi(s.substr(1,3))  ) and ((s[0]>=65) and (s[0]<=90)) and ((s[4]>=65) and (s[4]<=90)) and ((s[5]>=65) and (s[5]<=90)) ) return 1;
    return 0;
}

void Read(Elem* &root,bool &h){ //Считывание данных из файла
    string b;
    int i=0;
    ifstream fin("lol.txt");
    while(!fin.eof()){
        i++;
        fin>>b;
        if (Check(b)) Search(b,i,root,h); else cout<<"Incorrect string number "<<i<<" in the file"<<endl;
    }
}

int main(){
    Elem* root;
    bool h =0;
    //Read(root,h);
    Search("A110BC",10,root,h);
    for (int i =12;i<50; i+=2){
        if((i%2)==0){
            Search(("A1"+ to_string(i)+"BC"),i,root,h);
        }
    }

    Print(root,7);
    deletel("A124BC",24,root,h);
    cout<<"------------------------------------------"<<endl;
    Search("A150BC", 80,root,h);
    //Search("A151BC", 80,root,h);
    Print(root,7);


    return 0;
}

