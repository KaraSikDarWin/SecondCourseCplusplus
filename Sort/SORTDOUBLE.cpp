#include <iostream>
#include <fstream>
#include <cstring>
#include <chrono>
#include <vector>
using namespace std;

struct Number{
    char FB;
    int number;
    string SB;
};
struct FIO{
    string Surname;
    string Name;
    string SecondName;
};

struct Elem{
    Number number;
    FIO fio;
    int numberofstring;
};

void Rasdel(Elem &p, string str){
    string helpstr="";
    int i =7;
    p.number.FB=char(str[0]);
    string s= str.substr(1,3);
    p.number.number=stoi(s);
    s= str.substr(4,2);
    p.number.SB=s;

    while (i<=str.length()){
       if ((i<str.length())and (str[i]!=' ')){
             helpstr+=str[i];
       } else if(p.fio.Surname=="") {p.fio.Surname=helpstr; helpstr=""; }
       else if(p.fio.Name=="") {p.fio.Name=helpstr; helpstr=""; } else  if(p.fio.SecondName=="") {p.fio.SecondName=helpstr; helpstr=""; }
        i++;
    }
}

int Read(vector<Elem>&mas, int N){
    cout<<"Reading data started..."<<endl;
    //ifstream fin("gol.txt");
    ifstream fin("test.txt");
    string b;

    for (int i=0; i<N;i++){
        getline(fin,b);
        Elem p;
        mas.push_back(p);
        Rasdel(mas[i],b);

        //Rasdel(mas2[i],b);
        mas[i].numberofstring=i+1;
       // mas2[i].numberofstring=i+1;
    }
    cout<<"Reading data finished..."<<endl;
}

void Write(vector<Elem> mas, int count,string fileName){
    ofstream g(fileName);
    string helpstring="";
    for (int i=0;i<count;i++){
        helpstring =mas[i].number.FB + to_string(mas[i].number.number)+mas[i].number.SB+" "+mas[i].fio.Surname+" "+mas[i].fio.Name+" "+mas[i].fio.SecondName+" "+to_string(mas[i].numberofstring)+"\n" ;
        g<<helpstring;
    }
    g.close();
}

void Print(vector<Elem> mas, int count){
    for (int i=0;i<count;i++){
        cout<<mas[i].number.FB<<mas[i].number.number<<mas[i].number.SB<<" ";

    }
    cout<<endl;
    for (int i=0;i<count;i++){
        cout<<mas[i].fio.Surname<<" "<<mas[i].fio.Name<<" "<<mas[i].fio.SecondName<<" /// ";
    }

    cout<<endl;
    for (int i=0;i<count;i++){
        cout<<mas[i].numberofstring<<" ";
    }

}

bool DataBigX(Elem est, Elem vst){//Нод-дата больше x

    if (est.number.FB!=vst.number.FB){
        if ((est.number.FB > vst.number.FB))  return true; else return false;
    }

    if (est.number.number!=vst.number.number) {
        if (est.number.number > vst.number.number)
            return true;
        else return false;
    }

        if (est.number.SB[0]!=vst.number.SB[0]){
            if (est.number.SB[0] > vst.number.SB[0]) return true; else return false;
        }

        if (est.number.SB[1]!=vst.number.SB[1]){
            if (est.number.SB[1] > vst.number.SB[1]) return true;  else return false;
        }


        char* estStr;
        char* vstStr;


        if (est.fio.Surname!=vst.fio.Surname){
             estStr = new char[est.fio.Surname.length()];
             vstStr = new char[vst.fio.Surname.length()];

            strcpy(estStr,est.fio.Surname.c_str());
            strcpy(vstStr,vst.fio.Surname.c_str());
            if (strcmp(estStr,vstStr)>0)return true; else return false;
        }

    if (est.fio.Name!=vst.fio.Name){
        estStr = new char[est.fio.Name.length()];
        vstStr = new char[vst.fio.Name.length()];

        strcpy(estStr,est.fio.Name.c_str());
        strcpy(vstStr,vst.fio.Name.c_str());
        if (strcmp(estStr,vstStr)>0)return true; else return false;


    }

    if (est.fio.SecondName!=vst.fio.SecondName){
        estStr = new char[est.fio.SecondName.length()];
        vstStr = new char[vst.fio.SecondName.length()];
        strcpy(estStr,est.fio.SecondName.c_str());
        strcpy(vstStr,vst.fio.SecondName.c_str());
        if (strcmp(estStr,vstStr)>0)return true; else return false;

    }
        return 0;
}



void shekerSort(vector<Elem> &mass, int count)
{
    cout<<"Shaker sort started..."<<endl;
    auto start = chrono::steady_clock::now();
    int left = 0, right = count - 1;
    int flag = 1;  // флаг наличия перемещений
    // Выполнение цикла пока левая граница не сомкнётся с правой
    // и пока в массиве имеются перемещения
    while ((left < right) && flag > 0)
    {
        flag = 0;
        for (int i = left; i<right; i++)  //двигаемся слева направо
        {

            if (DataBigX(mass[i],mass[i+1]) ) // если следующий элемент меньше текущего,
            {             // меняем их местами
                Elem t = mass[i];
                mass[i] = mass[i + 1];
                mass[i + 1] = t;
                flag = 1;      // перемещения в этом цикле были
            }
        }
        right--; // сдвигаем правую границу на предыдущий элемент
        for (int i = right; i>left; i--)  //двигаемся справа налево
        {
            if (DataBigX(mass[i - 1],mass[i]) )
            {
                Elem t = mass[i];
                mass[i] = mass[i - 1];
                mass[i-1] = t;
                flag = 1;
            }
        }
        left++;
    }

    auto stop = chrono::steady_clock::now();
    auto diff = stop-start;

    cout<<"        "<<chrono::duration<double, milli>(diff).count()/1000<<"sec"<<endl;
    Write(mass,count,"ShakerOut.txt");
    ofstream g("ShakerOut.txt",ios::app);
   g<<chrono::duration<double, milli>(diff).count()/1000<<"sec";
    g.close();
    cout<<"Shaker sort finished..."<<endl;
}

// Функция "просеивания" через кучу - формирование кучи
void siftDown(vector<Elem> &numbers, int root, int bottom)
{

    int maxChild; // индекс максимального потомка
    int done = 0; // флаг того, что куча сформирована
    // Пока не дошли до последнего ряда
    while ((root * 2 <= bottom) && (!done))
    {

        if (root * 2 == bottom)    // если мы в последнем ряду,
            maxChild = root * 2;    // запоминаем левый потомок
            // иначе запоминаем больший потомок из двух
        else if (DataBigX(numbers[root*2], numbers[root*2+1]))
            maxChild = root * 2;
        else
            maxChild = root * 2 + 1;
        // если элемент вершины меньше максимального потомка
            if (DataBigX(numbers[maxChild],numbers[root]))
        {
            Elem temp = numbers[root]; // меняем их местами
            numbers[root] = numbers[maxChild];
            numbers[maxChild] = temp;
            root = maxChild;
        }
        else // иначе
            done = 1; // пирамида сформирована
    }
}
// Функция сортировки на куче
void heapSort(vector<Elem> &numbers, int array_size)
{
    cout<<"Heap sort started..."<<endl;
    auto start = chrono::steady_clock::now();
    // Формируем нижний ряд пирамиды
    for (int i = (array_size / 2); i >= 0; i--)
        siftDown(numbers, i, array_size - 1);
    // Просеиваем через пирамиду остальные элементы
    for (int i = array_size - 1; i >= 1; i--)
    {
        Elem temp = numbers[0];
        numbers[0] = numbers[i];
        numbers[i] = temp;
        siftDown(numbers, 0, i - 1);
    }
    auto stop = chrono::steady_clock::now();
    auto diff = stop-start;
    cout<<"        "<<chrono::duration<double, milli>(diff).count()/1000<<"sec"<<endl;
    Write(numbers,array_size,"HeapOut.txt");
    ofstream g("HeapOut.txt",ios::app);
    g<<chrono::duration<double, milli>(diff).count()/1000<<"sec";
    g.close();
    cout<<"Heap sort finished..."<<endl;
}

int main(){
    int N=0;
    //cin>>N;
vector<Elem> mas;
   // Elem masHeap[N];
   N=9;
    Read(mas,N);
   //heapSort(mas,N);
   shekerSort(mas,N);
    return 0;
}