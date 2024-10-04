#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
using namespace std;

int NumberOfOperation=0;

class Account;


struct Date{
    int year=0;
    int month =0;
    int day=0;
    int hour=0;
    int min=0;
    int sec=0;
    Date(){};
    Date(int year, int month, int day, int hour, int min, int sec):year(year), month(month),day(day),hour(hour),min(min),sec(sec){};
};

struct Transaction{
    string TransactionID;
    string ReceiverID;
    string SenderID;
    int Amount;
    Date date;

    Transaction(){};
    Transaction(string TransactionId, string ReceiverId,string SenderID,double Amount,int year, int month, int day, int hour, int min, int sec):TransactionID(TransactionId),ReceiverID(ReceiverId),SenderID(SenderID),Amount(Amount),
                                                                                       date(year,  month,  day,  hour,  min,  sec){}
};


ostream& operator<<(ostream& os, const Transaction& r) {
    os << r.TransactionID << ' ' << r.SenderID << ' ' << r.ReceiverID << ' ' << r.Amount << ' ' << r.date.year << ' '
       << r.date.month << ' ' << r.date.day << ' ' << r.date.hour << ' ' << r.date.min << ' ' << r.date.sec << endl;
    NumberOfOperation++;
    return os;
}


vector<Account> Accs;

class Singleton{
private:
    static Singleton * p_instance;
    std::vector<Transaction> Base;

    Singleton() {
        ifstream f("Base.txt");
        string b;
        string supstring="";
        int marker;
        while ((getline(f,b))){
            NumberOfOperation++;
            marker =0;
            supstring="";
            Transaction nw;
            for (int i =0; i<=b.length();i++){
                if (b[i]==' ') {
                    switch (marker) {
                        case 0: {nw.TransactionID=supstring; supstring=""; marker++;
                            break; };
                        case 1: {nw.ReceiverID=supstring; supstring=""; marker++;
                            break;};
                        case 2: {nw.SenderID=supstring; supstring=""; marker++;
                            break;};
                        case 3: {nw.Amount= stoi(supstring); supstring=""; marker++;
                            break;};
                        case 4: {nw.date.year= stoi(supstring); supstring=""; marker++;
                            break;};
                        case 5: {nw.date.month= stoi(supstring); supstring=""; marker++;
                            break;};
                        case 6: {nw.date.day= stoi(supstring); supstring=""; marker++;
                            break;};
                        case 7: {nw.date.hour= stoi(supstring); supstring=""; marker++;
                            break;};
                        case 8: {nw.date.min= stoi(supstring); supstring=""; marker++;
                            break;};
                    }
                }else supstring+=b[i];
            }
            nw.date.sec= stoi(supstring);
            Base.push_back(nw);
        }
        f.close();



    }
    Singleton( const Singleton& );
    Singleton& operator=( Singleton& );

public:
    static Singleton * getInstance() {
        if(!p_instance)
            p_instance = new Singleton();
        return p_instance;
    }

    int addTransaction(string TransactionId, string SenderID,string ReceiverId,double Amount,int year, int month, int day, int hour, int min, int sec){
        Transaction nw(TransactionId, ReceiverId, SenderID,Amount, year, month,day,hour,min,sec);
        Base.push_back(nw);
        ofstream os("Base.txt",ios::app);
        os<<nw;
        os.close();
    }


    vector <Transaction> getBase(){
        return Base;
    }

    vector <Account> getAccs(){
        return Accs;
    }
};



class Account{
private:
    string AccountID;
    double Balance;

public:
    void IncreaseBalance(double Count){
        if (Count>=0){
            Balance+=Count;
            time_t t = time(nullptr);
            tm* now = localtime(&t);
            Singleton::getInstance()->addTransaction(to_string(NumberOfOperation), AccountID, "-",Count, now->tm_year+1900, now->tm_mon,now->tm_mday,now->tm_hour,now->tm_min,now->tm_sec);
        }
    }

    void Decrease(int Count){
        if (Count<=0){
            Balance-=Count;
            time_t t = time(nullptr);
            tm* now = localtime(&t);
            Singleton::getInstance()->addTransaction(to_string(NumberOfOperation), AccountID, "-",Count, now->tm_year+1900, now->tm_mon,now->tm_mday,now->tm_hour,now->tm_min,now->tm_sec);
        }
    }

    string Transfer(string Reciever, int Count){
         Balance-=Count;
         for(int i =0; i<Singleton::getInstance()->getAccs().size();i++){
             if (Singleton::getInstance()->getAccs()[i].AccountID==Reciever){
                 Singleton::getInstance()->getAccs()[i].Balance+=Count;
                 time_t t = time(nullptr);
                 tm* now = localtime(&t);
                 Singleton::getInstance()->addTransaction(to_string(NumberOfOperation), AccountID, Reciever,Count, now->tm_year+1900, now->tm_mon,now->tm_mday,now->tm_hour,now->tm_min,now->tm_sec);
                 break;
             }
         }
         return "0";
    }

    int getBalacne(){
        return Balance;
    }

    string getID(){
        return AccountID;
    }

    vector <Transaction> ListOfTransaction(){
        vector <Transaction> out;
        for(int i =0; i<Singleton::getInstance()->getAccs().size();i++){
            if (Singleton::getInstance()->getBase()[i].ReceiverID==AccountID){
            out.push_back(Singleton::getInstance()->getBase()[i]);
            }
        }
        return out;
    }
    Account(){};
    Account(string AccountID, double Balance):AccountID(AccountID),Balance(Balance) {};
};

Singleton* Singleton::p_instance = 0;
int main(){
Singleton::getInstance();
//    Account p("344",384);
//    Accs.push_back(p);
//    p.IncreaseBalance(10000);
//    Account p2("700",800);
//    Accs.push_back(p2);
//    p2.Transfer("344",500);
//    cout<<p2.getBalacne();

}
