#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

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

struct HashNode{
    Elem* LinkNode;
    bool status;
    HashNode(int =0):LinkNode(nullptr),status(0){};
};

class HashTable{
    float Fully;
    int size;
    int NonEmptyNodes;
    vector<HashNode> Table;

private:

//    void Write(vector <HashNode> mas, string fileName){
//        ofstream g(fileName);
//        string helpstring;
//        for (int i=0;i<mas.size();i++){
//            if (mas[i].status != 0) {
//                helpstring = mas[i].LinkNode->number.FB + to_string(mas[i].LinkNode->number.number) +
//                             mas[i].LinkNode->number.SB + " " + mas[i].LinkNode->fio.Surname + " " +
//                             mas[i].LinkNode->fio.Name + " " + mas[i].LinkNode->fio.SeconName + " " +
//                             mas[i].LinkNode->BrandAndName.Brand + " " + mas[i].LinkNode->BrandAndName.Model + " " +
//                             to_string(mas[i].LinkNode->NumberOfOrder)+" "+
//                             to_string(mas[i].LinkNode->numberofstring) +
//                             "     HASH: "+ to_string(MultHash(mas[i].LinkNode->fio.Surname,mas[i].LinkNode->fio.Name,mas[i].LinkNode->fio.SeconName,mas[i].LinkNode->NumberOfOrder))+'\n';
//
//                g << helpstring;
//            }else{
//                g<<"0 "+ to_string(i)+"\n";
//            }
//        }
//        g.close();
//    }

    void split(string* ms ,string str){
        int space =0;
        string substring="";
        for (int i =0; i<str.size(); i++){
            if (str[i]==' '){
                ms[space] = substring;
                space++;
                substring="";
            }else substring+=str[i];
        }
        ms[space] = substring;
    }

    int ConvertStringToInt(string str){
        int ln = str.length();
        int sum =0;
        for (int i =0; i<ln; i++){
            sum+=str[i];
        }
        return sum;
    }

    int MultHash(string SurName1, string Name1, string SecondName1, int NumberOfOrder1){
        int key = ConvertStringToInt(SurName1)+ConvertStringToInt(Name1)+ConvertStringToInt(SecondName1)+NumberOfOrder1;
        float answ = key * 0.33;
        answ = answ - int(answ);
        return ::floor(size * answ);
    }

    int AntiCollision(int hash, int attempt){
        return (hash + attempt) % size;
    }

    void SizeUp(){
        int newsize =size*2;
        HashNode p(0);
        vector<HashNode> oldMas (newsize, p);
        swap(Table,oldMas);
        size = newsize;
        for (int i = 0; i<oldMas.size();i++){
            if (oldMas[i].LinkNode!= nullptr){
                addHashNode(oldMas[i].LinkNode, false);
            }
        }
    }

    void SizeDown(){
        int newsize =size/2;
        HashNode p(0);
        vector<HashNode> oldMas (newsize, p);
        swap(Table,oldMas);
        size = newsize;
        for (int i = 0; i<oldMas.size();i++){
            if (oldMas[i].status!= 0){
                addHashNode(oldMas[i].LinkNode, false);
            }
        }
    }


public:

    int AddNode(string fio, int NumberOfOrder){
        string mas[3];
        split(mas,fio);
        Elem* p = new Elem();
        p->fio.Surname=mas[0];
        p->fio.Name=mas[1];
        p->fio.SeconName=mas[2];
        p->NumberOfOrder=NumberOfOrder;
        return addHashNode(p);
    }

    int Search(string fio, int NumberOfOrder){
        string mas[3];
        split(mas,fio);
        Elem* p = new Elem();
        p->fio.Surname=mas[0];
        p->fio.Name=mas[1];
        p->fio.SeconName=mas[2];
        p->NumberOfOrder=NumberOfOrder;
        int hash = MultHash(mas[0],mas[1],mas[2],NumberOfOrder);
        int ind;
        bool flag= false;
        bool unique=true;

        ind = IfCollision(hash,mas[0],mas[1],mas[2],NumberOfOrder,flag,unique);
        if(ind >=0 and unique){
            cout<<"This element doesn't exist in this table"<<endl;
                return 0;
        } else if(!unique){
            cout<<"It element exist in table. It's index is "<<to_string(ind)<<endl;
            return 1;
        }
        return 0;
    }

//    int IfCollision(int hash, string SurName1, string Name1, string SecondName1, int NumberOfOrder1, bool &flag, bool &unique){
//        int attempt =0;
//        int ind;
//        while (attempt < size) {
//            ind = AntiCollision(hash,attempt);
//            if (Table[ind].LinkNode!= nullptr and (Table[ind].LinkNode->fio.Surname==SurName1 and Table[ind].LinkNode->fio.Name==Name1 and Table[ind].LinkNode->fio.SeconName==SecondName1 and Table[ind].LinkNode->NumberOfOrder==NumberOfOrder1)) {
//                flag=true;
//                unique= false;
//                return -ind;
//            }
//            if (Table[ind].status == 0) {
//                flag= true;
//                return ind;
//            }
//            //дописать проверку уникальности ключа
//            attempt++;
//        }
//        return 0;
//    }

    int addHashNode(Elem *p, bool Ftor = true){ //УЫЕЛИЧИТЬ ПОСЛЕ ДОБАВЛЕНИ\ УМЕНЬШИТЬ ПОСЛЕ УДАЛЕНИЯ\ ДОПИСАТЬ ОТДЕЛЬНЫЙ МЕТОД ДОБАВЛЕНИЯ НОДА ДЛЯ ПОЛЬЗОВАТЕЛЯ
        int flag;
        bool unique=true;
        bool done = false;

        int hash=MultHash(p->fio.Surname,p->fio.Name,p->fio.SeconName,p->NumberOfOrder);

        if (Table[hash].status==0){
            if (Ftor) NonEmptyNodes++;
            Table[hash].LinkNode = p;
            Table[hash].status = true;
            Fully = float(NonEmptyNodes)/float(size);
            if (IsFull() == 1) {
                SizeUp();
            }
            return 1;
        }else {
            flag = IfCollision(hash, p->fio.Surname,p->fio.Name,p->fio.SeconName,p->NumberOfOrder, done, unique);

            if (!unique) {
                cout << "ID isn't unique" << endl;
                return -1;
            }

            if (flag == 0 and !done) {
                SizeUp();
                addHashNode(p);
            }

            if (flag >= 0 and done) {
                if (Ftor) NonEmptyNodes++;
                Table[flag].LinkNode = p;
                Table[flag].status = true;
                Fully = float(NonEmptyNodes) / float(size);
                if (IsFull() == 1) {
                   // SizeUp();
                }
                return 1;
            }
        }//ДОПИСАТЬ РАСШИРЕНИЕ ТАБЛИЦЫ ЕСЛИ КОЛИЧЕСТВО ПОПЫТОК ПРЕВЫСИЛО РАЗМЕР
    }



    int DelHashNode(string FIO, int OrderNumber){
        bool unique = true;
        string mas[3];
        bool flag = false;
        split(mas,FIO);

        int hash = MultHash(mas[0],mas[1],mas[2],OrderNumber);
        int ind = IfCollision(hash,mas[0],mas[1],mas[2],OrderNumber,flag,unique);
        if (ind>=0 and unique){
            cout<<"This isn't exist in this table"<<endl;
            return -1;
        }else if(ind<=0 and !unique) {
            ind = abs(ind);
            Table[ind].status= false;
            NonEmptyNodes--;
        }

            Fully = (float(NonEmptyNodes) / size);
            if (IsFull() == -1) SizeDown();
            return 1;

    }

    void Print(){
        string helpstring;
        for (int i=0;i<Table.size();i++){
            if (Table[i].status != 0) {
                helpstring = "INDEX: "+to_string(i)+"  "+Table[i].LinkNode->number.FB + to_string(Table[i].LinkNode->number.number) +
                             Table[i].LinkNode->number.SB + " " + Table[i].LinkNode->fio.Surname + " " +
                             Table[i].LinkNode->fio.Name + " " + Table[i].LinkNode->fio.SeconName + " " +
                             Table[i].LinkNode->BrandAndName.Brand + " " + Table[i].LinkNode->BrandAndName.Model + " " +
                             to_string(Table[i].LinkNode->NumberOfOrder)+" "+
                             to_string(Table[i].LinkNode->numberofstring) +
                             "     HASH: "+ to_string(MultHash(Table[i].LinkNode->fio.Surname,Table[i].LinkNode->fio.Name,Table[i].LinkNode->fio.SeconName,Table[i].LinkNode->NumberOfOrder))+'\n';

                cout<< helpstring;
            }else{
                cout<<"INDEX: "+to_string(i)+"  "+"0 "+ to_string(i)+"\n";
            }
        }
        cout<<"\n";
        cout<<"\n";
        cout<<"\n";
    }

    void SelfWrite(){
        Write(Table,"HashOut.txt");
    }

    HashTable(int size):Fully(0),size(size),NonEmptyNodes(0){
        HashNode p(0);
        Table= vector<HashNode> (size, p);
    }

    int IsFull(){
        if(Fully>=0.80){
            return 1;
        }else if (Fully<=0.2000100){
            return -1;
        }else return 0;
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
    vector<Elem> arr;
    int N=5;
    Read(arr,N);

    HashTable table(10);
    table.Create(N,arr);




    table.Print();
    table.SelfWrite();

}