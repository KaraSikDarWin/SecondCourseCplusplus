#include <iostream>
#include <vector>
#include <utility>
#include <set>
using namespace std;

class list{
    struct Node;
public:
    class Iterator{
        friend class list;

        Node* the_elem;
    public:
        Iterator():the_elem(0){};
        Iterator(Node* &el):the_elem(el){};

        bool operator == (const Iterator &it) const{ return (the_elem==it.the_elem);};

        bool operator != (const Iterator &it) const {
                return !(it==*this);
        };

        Node& operator++(int a)
        {   if ((the_elem!=0)&&(the_elem->next!=0))
                the_elem = the_elem->next;
            return *the_elem;
        }

        Node& operator++()
        {
            int cn = 0;
            if ((the_elem!=0)&&(the_elem->next!=0))
            {
                set<char> t;
                string data= to_string(int(the_elem->data));
                for (int i =0;i<data.length();i++ ){
                    if ( (data[i])!='.' and !(t.contains(data[i]))  ){
                        t.insert(data[i]);
                        cn++;
                    }
                }
            }

            the_elem->data-=cn;
            the_elem= the_elem->next;
            return *the_elem;
        }

        double& operator*() const
        { if (the_elem != 0) return the_elem->data;
            else { cout << "Null iterator!" << endl; exit(1); }
        }
    };

public:
    list():head(new Node()), tail(head),  count(0){
        Head = Iterator(head);
        Tail =Iterator(tail);
    }

    list(const double& a):head(new Node()), tail(head), Tail(Head), count(0)
    {
        Head = Iterator(head);
        Tail = Iterator(tail);
        push_front(a);
    }

    list(list&& other){
        head = exchange(other.head, nullptr);
        tail = exchange(other.tail, nullptr);
        count = std::exchange(other.count, 0);
        Head = Iterator(head);
        Tail = Iterator(tail);
    }

    list ( list& other){

    }

    Iterator begin(){return head;};
    Iterator end(){return tail;};

    list& operator=(list&& other) noexcept
    {

        if (this == &other)
            return *this;

        head = std::exchange(other.head, nullptr);
        tail = std::exchange(other.tail, nullptr);
        Head = Iterator(head);
        Tail= Iterator(tail);
        count = std::exchange(other.count, 0);
        return *this;
    }

    void push_front(vector <double> mas){
        for(int i =0; i<mas.size(); i++){
            Node* p= new Node(mas[i]);
            p->next=head;
            head=p;
            Head =Iterator(head);
            count++;
        }
    }

    void push_front(const double &a){
        Node* p= new Node(a);
        p->next=head;
        head=p;
        Head =Iterator(head);
        count++;
    };

    void push_back(const double &a){
        if(count>=1) {
            Node *run = head;
            Node *p = new Node(a);
            while (run->next != tail) {
                run = run->next;
            }
            run->next = p;
            p->next = tail;
            count++;
        }else{
            Node* p = new Node(a);
            p->next= tail;
            head=p;
            Head=Iterator(head);
            count++;
        }
    }

    void push_back(vector <double> mas){
        if((count==0) and (mas.size()>0)){
            Node* p = new Node(mas[0]);
            p->next= tail;
            head=p;
            Head=Iterator(head);
            count++;
            if (mas.size()>1){
                for (int i = 1; i<mas.size();i++) {
                    Node *run = head;
                    Node *p = new Node(mas[i]);
                    while (run->next != tail) {
                        run = run->next;
                    }
                    run->next = p;
                    p->next = tail;
                    count++;
                }
            }
        } else if(mas.size()>0){
            for (int i = 0; i<mas.size();i++) {
                Node *run = head;
                Node *p = new Node(mas[i]);
                while (run->next != tail) {
                    run = run->next;
                }
                run->next = p;
                p->next = tail;
                count++;
            }
        }
    }

    void pop_front(){
        if (count>=1) {
            Node *p = head;
            head = p->next;
            Head = Iterator(head);
            delete p;
            count--;
        }
    }

    void pop_back(){
        if (count>=1) {
            if (head->next == tail) {
                delete head;
                head = tail;
                Head = Iterator(head);
                count--;
            } else {
                Node *p = head;
                Node *run = p->next;
                while ((run->next != tail)) {
                    run = run->next;
                    p = p->next;
                }
                p->next = tail;
                delete run;
                count--;
            }
        }
    }

    void swap(list &ls){
        Node* p1 =ls.head;
        long c = ls.count;
        ls.head =  head;
        head = p1;
        p1 = ls.tail;
        ls.tail = tail;
        tail =p1;
        ls.count = count;
        count = c;
    }

    long Size(){
        return count;
    }

    bool empty(){
        if (count>0) return 1; else return 0;
    }

    void clear(){
        Node* run = head;
        while (head!=tail){
            head= head->next;
            delete run;
            run = head;
        }
        delete head;
        head = nullptr;
        tail= nullptr;
        count=0;
    }

    ~list(){

    }

private:
    struct Node {
        double data;
        Node *next;
        Node(){};
        Node(const int &data_) : data(data_), next(nullptr){};

    };

    long count;
    Node* head;
    Node* tail;

    Iterator Head;
    Iterator Tail;

};

int main(){
    vector <double> la= {3,4,67,8};
    list l;
    list g;

//l.push_front(89);
//cout<<*l.begin()<<endl;
    l.push_front(78);
    l.push_back(la);
    l.push_back(999);

    g.push_front(678);
    g.push_front(566);


//cout<<*l.end()<<endl;

list::Iterator j(l.begin());
//auto i =l.begin();


for (auto i = g.begin(); i!=g.end();++i){
    //++j;
    cout << *i << endl;
}
    //конструкто нулевой и принимающий один, деструктор, заполнение, добавление элемента, удаление, итератор
    // оператор =  глубокое копирование a=b a - чистится а b -
    //swap
    //advance(2, it) - передвинуть итератор на 2 позиции
    //= через му семантику и конструктор перемещения X& operator=(X&& x)
};