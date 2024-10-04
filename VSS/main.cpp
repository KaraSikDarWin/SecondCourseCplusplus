#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;
class AVL;

struct Number{
    char FB;
    int number;
    string SB;
};

struct PhoneNumber{
    int CodeOfCountry;
    int CodeOfRegion;
    string Numbers;
};

struct BrandName{
    string Brand;
    string Model;
};

struct Date{
    string Day;
    string Month;
    string Year;
};

struct Elem{
    Number number;
    PhoneNumber phoneNumber;
    BrandName brandName;
    Date date;
    int NumberOfString;
};

struct Node{//Описание узла дерева
    Elem* data;
    int bal;
    Node* right;
    Node* left;
    Node():right(nullptr), left(nullptr), bal(0){};
};//

struct HashNode{
    Node* LinkNode;
    bool status;
    bool h= false;
    HashNode(int =0):LinkNode(nullptr),status(0),h(0){};
};

Node* q;

int DataBigX(char FB1, int NUM1, string SB1, string BR1, string MOD1, char FB2, int NUM2, string SB2, string BR2, string MOD2) {//Нод-дата меньше x

    char *estStr;
    char *vstStr;

    if (FB1 != FB2) {
        if ((FB1 < FB2)) return true; else return false;
    }

    if (NUM1 != NUM2) {
        if (NUM1 < NUM2)
            return true;
        else return false;
    }

    if (SB1[0] != SB2[0]) {
        if (SB1[0] < SB2[0]) return true; else return false;
    }

    if (SB1[1] != SB2[1]) {
        if (SB1[1] < SB2[1]) return true; else return false;
    }

    if (BR1 != BR2) {
        estStr = new char[BR1.length()];
        vstStr = new char[BR2.length()];
        strcpy(estStr, BR1.c_str());
        strcpy(vstStr, BR2.c_str());
        if (strcmp(estStr, vstStr) > 0)return true; else return false;

    }
    if (MOD1 != MOD2) {
        estStr = new char[MOD1.length()];
        vstStr = new char[MOD2.length()];

        strcpy(estStr, MOD1.c_str());
        strcpy(vstStr, MOD2.c_str());
        if (strcmp(estStr, vstStr) > 0)return true; else return false;
        }

        return -1;

};

class AVL{
    bool h=0;
    Node* r = nullptr;
    Node* q;

    void AddAVLNode(Elem* &linkElem){
        AVL::AddNode(linkElem,r,h);
    }

private:
    void AddNode(Elem* &linkElem, Node* &p, bool &h){ //Вставка элемента в дереве
        Node* p1;
        Node* p2;
        if (p== nullptr){
            p= new Node();
            p->data=linkElem;
            h= 1;
        }else if(!DataBigX(p->data->number.FB,p->data->number.number,p->data->number.SB, p->data->brandName.Brand, p->data->brandName.Model, linkElem->number.FB, linkElem->number.number, linkElem->number.SB, linkElem->brandName.Brand, linkElem->brandName.Model)){
            AddNode(linkElem,p->left,h);
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
        }else if (DataBigX(p->data->number.FB,p->data->number.number,p->data->number.SB, p->data->brandName.Brand, p->data->brandName.Model, linkElem->number.FB, linkElem->number.number, linkElem->number.SB, linkElem->brandName.Brand, linkElem->brandName.Model)){
            AddNode(linkElem,p->right,h);
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
        }
    }
};
bool Is(Node* p, vector<string> &mas){//Проверка наличия узла в дереве с таким значением
    if (p== nullptr){
        return 0;
    } else if (DataBigX(p->data->number.FB,p->data->number.number,p->data->number.SB, p->data->brandName.Brand, p->data->brandName.Model, stoi(mas[0]),stoi(mas[1]),mas[2],mas[3],mas[4])==1){
        Is(p->left,mas);
    }else if (!DataBigX(p->data->number.FB,p->data->number.number,p->data->number.SB, p->data->brandName.Brand, p->data->brandName.Model,
                        stoi(mas[0]),stoi(mas[1]),mas[2],mas[3],mas[4])==1) {
        Is(p->right, mas);
    }else {
        return 1;
    }
    }


void AddNode(Elem* &linkElem, Node* &p, bool &h){ //Вставка элемента в дереве
    Node* p1;
    Node* p2;
    if (p== nullptr){
        p= new Node();
        p->data=linkElem;
        h= 1;
    }else if(!DataBigX(p->data->number.FB,p->data->number.number,p->data->number.SB, p->data->brandName.Brand, p->data->brandName.Model, linkElem->number.FB, linkElem->number.number, linkElem->number.SB, linkElem->brandName.Brand, linkElem->brandName.Model)){
        AddNode(linkElem,p->left,h);
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
    }else if (DataBigX(p->data->number.FB,p->data->number.number,p->data->number.SB, p->data->brandName.Brand, p->data->brandName.Model, linkElem->number.FB, linkElem->number.number, linkElem->number.SB, linkElem->brandName.Brand, linkElem->brandName.Model)){
        AddNode(linkElem,p->right,h);
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
    }
}

void balanceL(Node* &p, bool &h ){ //Левая балансировка
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
            if (p2->bal==-1) p->bal=1; else p->bal=0;
            p=p2;
            p2->bal=0;
        }
    }
}

void balanceR(Node* &p, bool &h){ //Правая балансировка
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
            if (p2->bal==1) p->bal=-1; else p->bal=0;
            p=p2;
            p2->bal=0;
        }
    }
}

void del(Node* &r, bool &h){
    if (r->left != nullptr){
        del(r->left,h);
        if (h) balanceL(r,h);
    }else{
        q->data= r->data;
        q=r;
        r=r->right;
        h=1;
    }
}//

void deletel(vector<string> &mas, Node* &p, bool &h){ //Удаление узла в дереве
    if (p== nullptr){cout<<"Key doesn't exist!"<<endl;

    }else if((DataBigX(p->data->number.FB,p->data->number.number,p->data->number.SB, p->data->brandName.Brand,p->data->brandName.Model,
                       stoi(mas[0]), stoi(mas[1]), mas[2],mas[3],mas[4]))==1){
        deletel(mas,p->left,h);
        if (h) balanceL(p,h);
    }else if((DataBigX(p->data->number.FB,p->data->number.number,p->data->number.SB, p->data->brandName.Brand,p->data->brandName.Model,
                        stoi(mas[0]), stoi(mas[1]), mas[2],mas[3],mas[4])==0)){
        deletel(mas,p->right,h);
        if (h) balanceR(p,h);
    }else{
        q=p;
        if (q->right== nullptr) {p=q->left; h=1;}
        else if(q->left== nullptr){ p=q->right;h=1;}
        else{
            del(q->right,h);
            if (h) balanceR(p,h);
        }
    }
}


void Rasdel(Elem &p, string str){
    int i;
    string sub;
    p.number.FB=char(str[0]);
    string s= str.substr(1,3);
    p.number.number=stoi(s);
    s= str.substr(4,2);
    p.number.SB=s;

    sub = str[7];
    p.phoneNumber.CodeOfCountry= stoi(sub);
    sub = str.substr(8,3);
    p.phoneNumber.CodeOfRegion= stoi(sub);
    sub = str.substr(11,7);
    p.phoneNumber.Numbers=sub;

    i=19;
    sub="";
    while (str[i]!=','){
        sub+=str[i];
        i++;
    }

    p.brandName.Brand=sub;
    i+=1;
    sub ="";
    while (str[i]!=';'){
        sub+=str[i];
        i++;
    }
    p.brandName.Model=sub;

    i++;
    sub = str.substr(i,2);
    p.date.Day=sub;
    i+=3;
    sub= str.substr(i,2);
    p.date.Month=sub;
    i+=3;
    sub=str.substr(i,4);
    p.date.Year=sub;
}

void Read(vector<Elem>&mas, int N){
    cout<<"Reading data started..."<<endl;
    ifstream fin("KursaCInput.txt");
    string b;

    for (int i=0; i<N;i++){
        getline(fin,b);
        Elem p;
        mas.push_back(p);
        Rasdel(mas[i],b);

        mas[i].NumberOfString=i+1;
    }
    cout<<"Reading data finished..."<<endl;
}

int ConvertStringToInt(string str) {
    int ln = str.length();
    int sum = 0;
    for (int i = 0; i < ln; i++) {
        sum += str[i];
    }
    return sum;
};

void SplitNum(string str, vector<string> &mas){
    mas.push_back(to_string(str[0]));
    string s= str.substr(1,3);
    mas.push_back(s);
    s = str.substr(4,2);
    mas.push_back(s);
}

void SplitBM(string str, vector<string> &mas){
    int i =0;
    string sub="";

    while (str[i]!=' '){
        sub+=str[i];
        i++;
    }

    mas.push_back(sub);
    sub="";

    while (str[i]==' '){
        i++;
    }

    for(;i<str.length();i++){
        sub+=str[i];
    }
    mas.push_back(sub);
}

class HashTable{
    float Fully;
    int size;
    int NonEmptyNodes;
    vector<HashNode> Table;

public:
    int MultHash(string Brand, string Model, char FB, int Numb, string SecNum){
        int key = ConvertStringToInt(Brand)+ConvertStringToInt(Model)+ConvertStringToInt(SecNum)+FB+Numb;
        float answ = key * 0.618033;
        answ = answ - int(answ);
        return ::floor(size * answ);
    }

    int addHashNode(Elem *p, bool Ftor = true){
        bool unique=true;
        bool done = false;

        int hash = MultHash(p->brandName.Brand,p->brandName.Model,p->number.FB,p->number.number,p->number.SB);
        AddNode(p, Table[hash].LinkNode, done);
        NonEmptyNodes++;
        Table[hash].status=1;
        return 1;
    };

    void Find(string NUM, string BRAND, string MODEl){
        vector<string> mas;
        SplitNum(NUM,mas);
        mas.push_back(BRAND);
        mas.push_back(MODEl);
        int hash = MultHash(BRAND,MODEl,stoi(mas[0]), stoi(mas[1]),mas[2]);
        cout<<Is(Table[hash].LinkNode,mas);

    }

    int Delete(string NUM, string BRAND, string MODEL){
        vector <string> mas;
        SplitNum(NUM,mas);
        mas.push_back(BRAND);
        mas.push_back(MODEL);
        int hash = MultHash(BRAND,MODEL,stoi(mas[0]), stoi(mas[1]),mas[2]);
//        deletel(mas,Table[hash].LinkNode,)
    }

    HashTable(int size):Fully(0),size(size),NonEmptyNodes(0){
        HashNode p(0);
        Table= vector<HashNode> (size, p);
    }

    void Create(int N, vector<Elem> &arr1){
        for (int i =0; i<N;i++){
            addHashNode(&arr1[i]);
        }
    }

    ~HashTable(){
        Table.clear();
    }

};

int main(){
    int N = 10;
    vector <Elem> mas;
    Read(mas,N);
    HashTable table(10);
    table.Create(N,mas);
    table.Find("A567BC", "A","B");

}