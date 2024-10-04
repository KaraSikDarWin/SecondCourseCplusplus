#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Level{
public:
  virtual float get_coff(){return 0;};
};

class University: public Level{
private:
    float coff=1.8;
public:
     float  get_coff() {
        return coff;
    }
};

class Citie: public Level{
private:
    float coff=1.4;
public:
    float get_coff(){
        return coff;
    }
};

class Edge: public Level{
private:
    float coff=1.6;
public:
    float get_coff(){
        return coff;
    }
};

class Russia: public Level{
private:
    float coff=1.8;
public:
    float get_coff(){
        return coff;
    }
};

class Multiverse: public Level{
private:
    float coff=2;
public:
    float get_coff(){
        return coff;
    }
};

struct People{
    string name;
    string organization;
    string group;
    string school;
    string email;
    string role;
    People(){};
    People(string name, string organ, string gr, string sch, string ema,string role):name(name),organization(organ),group(gr),school(sch),email(ema),role(role){};
};

struct Event{
    string wisd;
    string name;
    Level* lvl;
    string type;
    int duraction;
    int countofpeaple;
    vector <People*> orgs;
    Event(){};
    Event(string ws, string nam, Level* lv, string ty, int dur, int co, vector <People*> gro):wisd(ws),name(nam), lvl(lv), type(ty),duraction(dur),countofpeaple(co),orgs(gro) {}
};


class Base{
private:
    static Base * p_instance;
    vector <Event*> basa;
    Base() {
        ifstream f("EKO_INPUT.txt");
        string b;
        string supstring;
        int marker;
        int i;
        while ((getline(f,b))){
            marker =0;
            supstring="";
            Event* nw = new Event;
            for ( i =0; b[i]!='[';i++){
                if (b[i]==' ') {
                    switch (marker) {
                        case 0: {nw->wisd=supstring; supstring=""; marker++;
                            break;};
                        case 1: {nw->name=supstring; supstring=""; marker++;
                            break;};
                        case 2: {
                            if(supstring=="University"){
                              Level* lvl = new University;
                              nw->lvl=lvl;
                            };
                            if(supstring=="Citie"){
                                Level* lvl = new Citie;
                                nw->lvl=lvl;
                            };
                            if(supstring=="Edge"){
                                Level* lvl = new Edge;
                                nw->lvl=lvl;
                            };
                            if(supstring=="Russia"){
                                Level* lvl = new Russia;
                                nw->lvl=lvl;
                            };
                            if(supstring=="Multiverse"){
                                Level* lvl = new Multiverse;
                                nw->lvl=lvl;
                            };
                                supstring="";
                                marker++;
                                break;
                        };
                        case 3: {nw->type= supstring; supstring=""; marker++;
                            break;};
                        case 4: {nw->duraction= stoi(supstring); supstring=""; marker++;
                            break;};
                    }
                }else supstring+=b[i];
            }
           nw->countofpeaple= stoi(supstring);
            supstring="";
            marker=0;
            i+=2;
            vector<People*> lol;
            lol.clear();
            while((i<b.length())){
                marker=0;
                supstring="";
                People* ppl =new People();
                for(;b[i]!=')';i++){
                    if(b[i]==' '){
                        switch (marker) {
                            case 0: {
                                ppl->name = supstring;
                                supstring = "";
                                marker++;
                                break;
                            };
                            case 1: {
                                ppl->organization = supstring;
                                supstring = "";
                                marker++;
                                break;
                            };
                            case 2: {
                                ppl->group = supstring;
                                supstring = "";
                                marker++;
                                break;
                            };
                            case 3: {
                                ppl->school = supstring;
                                supstring = "";
                                marker++;
                                break;
                            };

                            case 4: {
                                ppl->email = supstring;
                                supstring = "";
                                marker++;
                                break;
                            };
                        }
                    }else supstring+=b[i];

                }
                ppl->role=supstring;
                lol.push_back(ppl);
                i+=3;
            }
            nw->orgs=lol;
            basa.push_back(nw);
        }
        f.close();

    }
    Base( const Base& );
    Base& operator=( Base& );
public:
    static Base * getInstance() {
        if(!p_instance)
            p_instance = new Base();
        return p_instance;
    }

vector <Event*> GetListEvent(){
        return basa;
    };

    float Calculate(string target_name){
        float Chance=0;
        bool flag=0;
        for (int i=0; i<basa.size();i++){
            float sum=0;
            flag =0;
            Event* nnw=Base::getInstance()->GetListEvent()[i];
            for (int j =0; j<Base::getInstance()->GetListEvent()[i]->orgs.size(); j++ ){
                if (target_name==Base::getInstance()->GetListEvent()[i]->orgs[j]->name){
                    flag=1;
                   // nnw= Base::getInstance()->GetListEvent()[i];
                    if(nnw->orgs[j]->role=="Volonteer") sum=3;
                    else if(nnw->orgs[j]->role=="Worker") sum=6;
                    else if(nnw->orgs[j]->role=="Organaser") sum=9;
                    else if(nnw->orgs[j]->role=="Director") sum=12;
                }
            }

            if (flag){
                sum*=nnw->lvl->get_coff();

                if(nnw->duraction=1) sum*=1.1;
                else if (nnw->duraction<4) sum*=1.2;
                else if (nnw->duraction<8) sum*=1.3;
                else if (nnw->duraction<15) sum*=1.4;
                else if (nnw->duraction<21) sum*=1.6;
                else sum*=1.8;

                if (nnw->countofpeaple<10) sum*=1;
                else if(nnw->countofpeaple<51) sum*=1.3;
                else if(nnw->countofpeaple<101) sum*=1.5;
                else if(nnw->countofpeaple<501) sum*=1.8;
                else sum*=2;
            }
            Chance+=sum;
        }
        return Chance;
    };

    void addEvent(string ws, string nam, Level* lv, string ty, int dur, int co, vector <People*> gro ){
        basa.push_back(new Event(ws,nam,lv,ty,dur,co,gro));
    }

};

Base* Base::p_instance = 0;

int main(){
    Base::getInstance();
    cout<<Base::getInstance()->Calculate("Kirill");
}