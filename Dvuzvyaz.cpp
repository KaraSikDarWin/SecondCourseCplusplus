#include <iostream>
using namespace std;



struct Node{
    int data;
    Node* pred = nullptr;
    Node* next = nullptr;
};

Node* head = nullptr;
Node* tail = nullptr;
void Create(unsigned x){
    head =  new Node();
    head->data=1;
    head->next= nullptr;
    tail=head;
    Node* run ;
    for (int i=2; i<=x;i++ ){
        run = new Node();
        run->data=i;
        run->next=head;
        head->pred=run;
        head=run;
    }

}

void Print(){
    Node* run = head;
    while (run!= nullptr){
        cout<<run->data<<" ";
        run=run->next;
    }

}

void PrintPred(){
    Node* run = tail;
    while (run!= nullptr){
        cout<<run->data<<" ";
        run=run->pred;
    }
}

void DelPast(int x){
     Node* run = head;
     while (run->next->next!= nullptr){

         if (run->data==x){
             auto buf = run->next->next;
             run->next->next->pred=run;
             delete run->next;
             run->next=buf;

         }else  run=run->next;

     }
}

int main(){
    Create(5);
    Print();
    cout<<endl;

    DelPast(3);

    Print();




    return 0;
}
