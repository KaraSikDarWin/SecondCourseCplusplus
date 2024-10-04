#include <iostream>

using namespace std;

struct Elem{
    int data;
    Elem* next;
    Elem():data(), next(this){};
    Elem(int x):data(x), next(this){};
};

Elem* head= nullptr;
Elem* out = nullptr;
Elem* shead= nullptr;


void Add(Elem* &head, int x){
    Elem* run=head;
    if (head== nullptr){
        head = new Elem(x);
    }else{

        while(run->next!=head){
            run=run->next;
        }
        Elem* beg =new Elem(x);
        run->next=beg;
        beg->next=head;
        head=beg;

    }
}

bool Search(Elem* head,int x){
    if(head!= nullptr) {
        bool flag = 0;
        Elem *run = head;
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

void Print(Elem* head){
    if (head!= nullptr) {
        Elem *run = head;
        while (run->next != head) {
            cout << run->data;
            cout << "  ";
            run = run->next;
        }
        cout << run->data << endl;
    }else cout<<"List doesn't exist!"<<endl;
}

void dldl(Elem* &head, int x){
    Elem* run =head->next;
    Elem* beg =head;
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

//void Del(Elem* &head){
//    if (head!= nullptr) {
//        Elem* run;
//        Elem* bg;
//        run=head;
//    while(run->next!=head){
//            run=run->next;
//        }
//    run->next= nullptr;
//    while(head!=run){
//        bg=head->next;
//        delete head;
//        head=bg;
//
//    }
//    delete head;
//    head= nullptr;
//    beg= nullptr;
//    } else cout<<"List doesn't exist!"<<endl;
//}

void Del(Elem* &head){
    Elem* run;
    Elem* beg;
    if (head!= nullptr){
        if (head->next==head){
            delete head;
            head= nullptr;
        }else{
            run=head->next;
            while(run->next!=head){
                beg=run->next;
                delete run;
                run= beg;
            }
            delete run;
            delete head;
            head= nullptr;

        }
    }else cout<<"List doesn't exist!"<<endl;
}

void DelPred(Elem* &head,  int x){
    Elem* temp= nullptr;
    if (head == nullptr) {
        cout << "List doesn't exit!"<<endl;
    }
    else {
        Elem* left = head;
        Elem* right = head->next->next;
        bool first = head->next->data == x;
        bool last = head->data == x;
        while (right != head) {
            if (right->data == x) {
                temp = left->next->next;
                delete left->next;
                left->next = temp;


            }
            else {left = left->next;

            }

            right = right->next;

        }
        if((temp!= nullptr) and(temp->data==x)and (right->data==x) and (right==head)) {delete temp; }

        if (last) left->next = head;
        if (first) {
            left->next->next = head->next;
            head = head->next;
        }
    }
    
}

void Assimetric(Elem* head, Elem* shead, Elem* &out){
    bool flag;
    Elem* beg;
    Elem* run = head;
    if ((head!= nullptr) and (shead!= nullptr) ) {
        while (run->next != head) {
            beg = shead;
            flag = 1;
            while (beg->next != shead) {
                if (run->data == beg->data) {
                    flag = 0;
                    break;//
                }
                beg = beg->next;
            }

            if (run->data == beg->data) {
                flag = 0;
            }

            if (flag) {
                if (out != nullptr) {
                    Add(out, run->data);
                } else {
                    out = new Elem(run->data);

                }
            }
            run = run->next;
        }
        flag = 1;
        beg = shead;
        while (beg->next != shead) {
            if (run->data == beg->data) {
                flag = 0;
                break;
            }
            beg = beg->next;
        }
        if (run->data == beg->data) {
            flag = 0;
        }
        if (flag) {
            if (out != nullptr) {
                Add(out,  run->data);
            } else {
                out = new Elem(run->data);
            }
        }

        ///////////////////////////////////////////////////////
        run = shead;
        while (run->next != shead) {
            beg = head;
            flag = 1;
            while (beg->next != head) {
                if (run->data == beg->data) {
                    flag = 0;
                    break;//
                }
                beg = beg->next;
            }

            if (run->data == beg->data) {
                flag = 0;
            }

            if (flag) {
                if (out != nullptr) {
                    Add(out,  run->data);
                } else {
                    out = new Elem(run->data);

                }
            }
            run = run->next;
        }
        flag = 1;
        beg = head;
        while (beg->next != head) {
            if (run->data == beg->data) {
                flag = 0;
                break;
            }
            beg = beg->next;
        }
        if (run->data == beg->data) {
            flag = 0;
        }
        if (flag) {
            if (out != nullptr) {
                Add(out,  run->data);
            } else {
                out = new Elem(run->data);
            }
        }
    }else cout<<"List does't exists!"<<endl;
}


int main(){
    // head - указатель на первый список
    // shead - указатель на первый список
    //out - указатель на третий список
//    Add(head,beg,6);
//    Add(head,beg,5);
    Add(head,4);
    Add(head,1);
    Add(head,5);

    Print(head);
    dldl(head,5);
    //Add(head,5);
//    Add(head,beg,8);


    Print(head);
    Del(head);



    return 0;
}

