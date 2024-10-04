#include <iostream>
#include <fstream>
#include <cstring>
#include <chrono>
#include <vector>
#include <cmath>

#define SHIFT_SIZE 256
#define uichar (int)(unsigned char)
#define prime 1217;
#define db 60;

using namespace std;

int i=0;

struct Number{
    char FB;
    int number;
    string SB;
};

struct Elem{
    Number number;
    string fio;
    string BrandAndName;
    int numberofstring;
};

void Rasdel(Elem &p, string str){
    string helpstr="";
    int i =7;
    int space = 0;
    string sub="";
    p.number.FB=char(str[0]);
    string s= str.substr(1,3);
    p.number.number=stoi(s);
    s= str.substr(4,2);
    p.number.SB=s;

    for(;i<33;i++){

        sub+=str[i];

    }

    p.fio=sub;
    sub="";
    while (i<=str.length()){
        sub+=str[i];
        i++;
    }
    p.BrandAndName=sub;
}


int Read(vector<Elem>&mas, int N){
    cout<<"Reading data started..."<<endl;
    ifstream fin("golTwo.txt");
    string b;

    for (int i=0; i<N;i++){
        getline(fin,b);
        Elem p;
        mas.push_back(p);
        Rasdel(mas[i],b);

        mas[i].numberofstring=i+1;
    }
    cout<<"Reading data finished..."<<endl;
}

void Write(vector <Elem> mas, string fileName){
    ofstream g(fileName);
    string helpstring="";
    for (int i=0;i<mas.size();i++){
        helpstring =mas[i].number.FB + to_string(mas[i].number.number)+mas[i].number.SB+" "+mas[i].fio+" "+mas[i].BrandAndName+" "+to_string(mas[i].numberofstring)+'\n' ;
        g<<helpstring;
    }
    g.close();
}

void getBadShift(int shift[], string& str) {
    int pattern_size = str.size();

    for (int i = 0; i < SHIFT_SIZE; i++) {
        shift[i] = pattern_size;
    }

    for (int i = 0; i < pattern_size - 1; i++) {
        shift[uichar str[i]] = pattern_size - i - 1;
    }
}

inline int max(int a, int b) {
    return (a > b) ? a : b;
}

int getIndexShift(string& str, int str_ind, int count) {
    int n = str.size();
    int i, j;
    while (str_ind >= 0) {
        i = n-1; j = str_ind;
        if (str_ind < count-1) count = str_ind+1;
        while (i >= n - count && str[i] == str[j]) {
            if (n - i == count) return (n - j - count);
            i--;
            j--;
        }
        str_ind--;
    }
    return n;

}

void preprocess_good_suffix(int* shift, string& str) {
    int len = str.size();
    int str_ind = len - 2;

    for (int count = 1; count < len; count++) {
        shift[count] = getIndexShift(str, str_ind, count);
        str_ind = len - shift[count] - 1;
    }

}

bool BoyerMurSearch(string& txt, string& pat, int times, int *g_shift, int b_shift[]) {
    int pat_size = pat.size(), txt_size = txt.size();
    int d1, d2; //для вычисления сдвигов
    //кол-во найденных / кол-во совпавших символов
    int i, j, k, count = 0, match = 0;
    i = j = k = pat_size - 1; // i - тек.позиция откуда начинаем проверку в тексте, j - бегунок в паттерне, k - бегунок в тексте
    while (i <= txt_size - 1) {
        match = 0;
        j = pat_size - 1;
        k = i;
        while (j >= 0 && pat[j] == txt[k]) {
            k--; j--;
            match++;
        }

        //если нашли, то прибавляем к счётчику 1 и сдвигаемся на длину паттерна
        if (k + pat_size == i) {
            count++;
            i += pat_size;
        }
        else {
            d1 = max(b_shift[uichar txt[i]] - match, 1);
            d2 = *(g_shift + match);
            if (count == 0) i += d1;
            else i += max(d1, d2);
        }
    }
    if (count == times) return true; //если паттерн найден в тексте заданное кол-во раз, то ТРУЕ
    else return false;
}





bool RabinKarpSearch(string txt, string pat, int CountEqual, int d, int &h, int &p, int q)
{
    int M = pat.length();
    int N = txt.length();
    int i, j;
    int t = 0;
    int CountScore=0;

    for (i = 0; i < M; i++) {
       // p = ( p + pat[i]);
        t = ( d*t + txt[i])%q;
    }

    for (i = 0; i <= N - M; i++) {

        if (p == t) {

            for (j = 0; j < M; j++) {
                if (txt[i + j] != pat[j]) {
                    break;
                }
            }

            if (j == M) {
                CountScore++;
                if (CountScore==CountEqual) return true;
            }

        }

        if (i < N - M) {
            t = (d*(t - txt[i]*h)  + txt[i + M])%q ;
//            if (t<0) t = (t+q);
        }
    }
    return false;
}

void RabinKarp(vector<Elem> mas,string patternOne, int NOne, string patternTwo, int NTwo){
    auto start = chrono::steady_clock::now();
    vector <Elem> out;
    int hash_p1=0, hash_p2=0 ;
    int h1=0,h2=0 ;
    int q =1117;
    int d = 100;



    for (int i =0; i<patternOne.length();i++) hash_p1= (patternOne[i]+d*hash_p1)%q;


    for (int i=0; i<mas.size();i++) {
        if (RabinKarpSearch(mas[i].fio, patternOne, NOne,d,h1,hash_p1,q)) {
            for (int j =0;j<patternTwo.length()-1;j++) h2 = (h2*d)%q;
            for (int j =0; j<patternTwo.length();j++) hash_p2= (patternTwo[j]+d*hash_p2)%q;
            if(RabinKarpSearch(mas[i].BrandAndName, patternTwo, NTwo, d,h2,hash_p2,q)) {
                out.push_back(mas[i]);
            };
        };

    }
    Write(out,"RabinKarpOut.txt");
    auto stop = chrono::steady_clock::now();
    auto diff = stop-start;
    ofstream g("RabinKarpOut.txt",ios::app);
    g<<chrono::duration<double, milli>(diff).count()/1000<<"sec";
    g.close();
}

void BoyerMur(vector<Elem> mas, string patternOne, int NOne, string patternTwo, int NTwo){
    auto start = chrono::steady_clock::now();
    vector <Elem> out;
    int m1 = patternOne.length();
    int m2 = patternTwo.length();
    int bpos1[SHIFT_SIZE], shift1[m1];
    shift1[0]=1;
    int bpos2[SHIFT_SIZE], shift2[m2];
    shift2[0]=1;


    preprocess_good_suffix(shift1, patternOne);
    getBadShift(bpos1, patternOne);

    preprocess_good_suffix(shift2, patternTwo);
    getBadShift(bpos2,patternTwo);



    for (int i = 0; i<mas.size(); i++){
        if (BoyerMurSearch(mas[i].fio, patternOne,NOne, shift1, bpos1) and BoyerMurSearch(mas[i].BrandAndName, patternTwo, NTwo, shift2,bpos2)){
            out.push_back(mas[i]);
        }
    }
    Write(out,"BoyerMurOut.txt");
    auto stop = chrono::steady_clock::now();
    auto diff = stop-start;
    ofstream g("BoyerMurOut.txt",ios::app);
    g<<chrono::duration<double, milli>(diff).count()/1000<<"sec";
    g.close();
}

int main(){
    //Paul Waker  Nissan/Toyota
    //Kirill OSlonov  Nissan/Toyota
    //Vin Diesel Dodge/Chevrolet
    int N;
    vector<Elem> mas;
    N=100;
    Read(mas,N);
    RabinKarp(mas, "MUR", 1, "MUR",1);
    BoyerMur(mas, "MURMUR", 1, "MURMUR",1);
}