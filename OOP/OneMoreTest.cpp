#include <iostream>
using namespace std;
//class TDeque
//{   class Elem;                     // опережающее объявление
//public:
//    class iterator {
//        friend class TDeque;
//        iterator(Elem *el):the_elem(el){}
//    public:
//        // конструкторы
//        iterator():the_elem(0){}
//        iterator(const iterator &it):the_elem(it.the_elem){}
//        // присваивание итераторов – генерируется по умочанию
//        // сравнение итераторов
//        bool operator==(const iterator &it) const
//        { return (the_elem == it.the_elem); }
//        bool operator!=(const iterator &it) const
//        { return !(it == *this); }
//        // продвижение к следующему элементу – только префиксная форма
//        iterator& operator++()
//        {   if ((the_elem!=0)&&(the_elem->next!=0))
//                the_elem = the_elem->next;
//            return *this;
//        }
//        // продвижение к предыдущему элементу – только префиксная форма
//        iterator& operator--()
//        {   if ((the_elem!=0)&&(the_elem->prev!=0))
//                the_elem = the_elem->prev;
//            return *this;
//        }
//        // получить ссылку на информационную часть
//        // работает справа и слева от знака присваивания
//        double& operator*() const
//        { if (the_elem != 0) return the_elem->item;
//            else { cout << "Null iterator!" << endl; exit(1); }
//        }
//    private:
//        Elem *the_elem;
//    };
//    public:
//        // создаем пустой дек – с фиктивным запредельным элементом
//        TDeque():Head(new Elem()), Tail(Head), count(0)
//        { Tail->next=Tail->prev=0;
//            head = iterator(Head);            // инициализация для итератора
//            tail = iterator(Tail);            // приватным конструктором
//        }
//        // создаем дек с единственным элементом
//        TDeque(const double& a):Head(new Elem()), Tail(Head), count(0)
//        { Tail->next=Tail->prev=0;
//            head = iterator(Head);
//            tail = iterator(Tail);
//            push_front(a);
//        }
//        ~TDeque();
//        bool isEmpty() const                    // есть ли элементы в деке
//        { bool t = (Head == Tail); return t; }
//        long size() const { return count; }     // количество элементов в деке
//        // методы доступа
//        iterator begin() { return head; }       // первый элемент
//        iterator end()   { return tail; }       // запредельный элемент
//        // методы вставки и удаления на концах дека
//        void push_front(const double &a);
//        void push_back(const double &a);
//        void pop_front();
//        void pop_back();
//    private:
//    class Elem                          // элемент дека
//    {   friend class TDeque;
//        friend class iterator;
//        Elem(const int &a):item(a){ }
//        Elem(){}
//        ~Elem(){}               // объявлять необязательно
//        double item;            // информационная часть элемента
//        Elem *next;             // следующий элемент
//        Elem *prev;             // предыдущий элемент
//    };
//    // запрещаем копировать и присваивать деки
//    TDeque& operator=(const TDeque &);
//    TDeque(const TDeque &);
//    long count;                 // количество элементов
//    Elem *Head;                 // Начало дека
//    Elem *Tail;                 // указатель на запредельный элемент
//    // для итератора
//    iterator head;
//    iterator tail;
//
//    };

int main(){
    double a = 1.2;
    cout<< to_string(a);
}