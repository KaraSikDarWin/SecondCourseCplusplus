#pragma once
#include "List.h"
#include <vector>
using namespace std;

struct Room{
    int NumberOfRoom;
    vector <string> Students;
    Room(){};
    Room(int num, vector<string> stu):NumberOfRoom(num){
        for (int i = 0;i<stu.size();i++){
            Students.push_back(stu[i]);
        }
    };


};
class Dormetery {
    Container<Room> Dom;

public:
    int AddRoom(int NumberOfRoom, vector<string> stu){
        Room GG (NumberOfRoom, stu);
        Dom.push_back(GG);
    }

    int FindFreeRoom(){
        for (auto i = Dom.begin(); i!=Dom.end(); i++){
            if (((*i).Students.empty())){
                return (*i).NumberOfRoom;
            }
        }
        return -1;
    }

    void AddInFreeRoom(string Name){
        for (auto i = Dom.begin(); i!=Dom.end(); i++){
            if (((*i).Students.size()<2)){
                (*i).Students.push_back(Name);
            }
        }
    }

    void Print(){
        for (auto i = Dom.begin(); i!=Dom.end(); i++){
            cout<<"Room: "<<(*i).NumberOfRoom<<"\n";
            for (auto j =0; j!=(*i).Students.size();j++){
                cout<<((*i).Students[j])<<" ";
            }
            cout<<"\n";
            cout<<endl;
        }
    }

    ~Dormetery(){
        Dom.clear();
    }
};



