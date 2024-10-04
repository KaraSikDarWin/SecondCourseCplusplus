#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

struct Number{
    char FB;
    int number;
    string SB;
};

struct Elem{
    Number number;
    string fio;
    string BrandAndName;
    int NumberOfOrder;
    int numberofstring;
};

string Sbor(Elem p){
    return p.number.FB+ to_string(p.number.number)+p.number.SB;
}

void Rasdel(Elem &p, string str){
    int i =7;
    string sub="";
    int space=0;
    p.number.FB=char(str[0]);
    string s= str.substr(1,3);
    p.number.number=stoi(s);
    s= str.substr(4,2);
    p.number.SB=s;

    while(space!=3){
        if (str[i]!=' ')
        {
            sub+=str[i];
            i++;
        }else {
            space++;
            if(space<=2) {
                sub += str[i];
                i++;
            }else i++;
        };
    }
    p.fio=sub;
    i =33;
    sub="";
    space=0;
    while(space!=2){
        if (str[i]!=' ')
        {
            sub+=str[i];
            i++;
        }else {
            space++;
            if(space<=1) {
                sub += str[i];
                i++;
            }else i++;
        };
    }
    p.BrandAndName=sub;
    i=49;
    sub="";
    while (i<=str.length()-1){
         sub+=str[i];
         i++;
    }
    p.NumberOfOrder = stoi(sub);
}

void Read(vector<Elem>&mas, int N){
    cout<<"Reading data started..."<<endl;
    ifstream fin("golOne.txt");
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

void shekerSort(vector<Elem> &mass, int count) {
    int left = 0, right = count - 1;
    int flag = 1;
    while ((left < right) && flag > 0) {
        flag = 0;
        for (int i = left; i < right; i++)
        {

            if (mass[i].NumberOfOrder > mass[i + 1].NumberOfOrder)
            {             // меняем их местами
                Elem t = mass[i];
                mass[i] = mass[i + 1];
                mass[i + 1] = t;
                flag = 1;      // перемещения в этом цикле были
            }
        }
        right--; // сдвигаем правую границу на предыдущий элемент
        for (int i = right; i > left; i--)  //двигаемся справа налево
        {
            if (mass[i - 1].NumberOfOrder > mass[i].NumberOfOrder) {
                Elem t = mass[i];
                mass[i] = mass[i - 1];
                mass[i - 1] = t;
                flag = 1;
            }
        }
        left++;
    }
}

void print(vector<Elem> arr, int size){
    for (int i =0 ; i<size; i++) cout<<arr[i].NumberOfOrder<<" ";
    cout<<endl;
}

pair<int,int> Inter(vector<Elem> arr, int size, int keyOfSearch){
    shekerSort(arr, size);
    print(arr,size);
    int K=0;
    int low = 0;
    int high = size - 1;
    int mid;
    while ((arr[low].NumberOfOrder < keyOfSearch) && (arr[high].NumberOfOrder >= keyOfSearch)) {
        K++;
        mid = low + ((keyOfSearch - arr[low].NumberOfOrder) * (high - low)) / (arr[high].NumberOfOrder - arr[low].NumberOfOrder);

        if (arr[mid].NumberOfOrder < keyOfSearch) {
            low = mid + 1;
        }

        else {
            if (arr[mid].NumberOfOrder > keyOfSearch) {
                high = mid - 1;
            } else return pair<int,int> (arr[mid].numberofstring, K);
        }
    }
    //если цикл while не вернул индекс искомого значения,
    //то проверяем не находится ли оно в ячейке массива с индексом low,
    //иначе возвращаем -1 (значение не найдено)
    if (arr[low].NumberOfOrder == keyOfSearch)
        return pair<int,int> (arr[low].numberofstring, K++);

    return pair<int,int> (-1, K);
}

pair<int,int> LenearWithBarrier(vector<Elem> arr, int size, int value){
    int K=0;
    if (size != 0) {
        Elem val;
        val.NumberOfOrder=value;
        arr.push_back(val);

        //Есть гарантия того, что элемент есть в массиве, значит индекс можно не проверять
        int i = 0;
        while (K++,arr[i].NumberOfOrder != value) {//Одно условие в цикле
       i++;
        }

        if ( i<size) {//Не уткнулись в барьер или последний элемент был искомым
            return pair<int,int> (arr[i].numberofstring,K);
        }
    }
    return pair<int,int>( -1, K);
}

int main(){
    vector <Elem> lol;
    int N = 12;
    int KEY = 1000;
    Read(lol, N);

    cout<<"LinearWithBarrier"<<endl;
    auto [AnswerLiner, permLiner] = LenearWithBarrier(lol, N, KEY);
    cout<<"INDEX V FILE: "<<AnswerLiner<<" Kolvoa operaciy: "<<permLiner<<endl;
    cout<<endl;
    cout<<"Interpolation"<<endl;
    auto [AnswerITER,permITER] = Inter(lol, N, KEY);
    cout<<"INDEX V FILE: "<<AnswerITER<< " Kolvo operaciy "<<permITER;
}
