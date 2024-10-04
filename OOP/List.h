#pragma once

#include "ListNode.h"
#include "Iterator.h"
#include <utility>
#include <vector>

#define MAX_SIZE 1000
using namespace std;
template <typename T>
class Container {
private:
    Node<T>* head;
    Node<T>* tail;
    size_t size_;

public:
    using ValType = T;
    using NodeType = Node<ValType>;
    using Iterator = ConIterator<Container<ValType>>;

public:
    Container() {
//        this->head = nullptr;
//        this->tail = nullptr;
//        this->size_ = 0;

        this->head= new Node<T>();
        this->tail = head;
        this->size_=0;
    }

    Container(Container&& other){
        head = exchange(other.head, nullptr);
        tail = exchange(other.tail, nullptr);
        size_ = std::exchange(other.size_, 0);
    }

    Container(vector <T> mas){
        this->head= new Node<T>();
        this->tail = head;
        this->size_=0;
        for (int i =0; i<mas.size();i++){
            push_back(mas[i]);
        }
    }

//    Container operator=(Container&& other) noexcept
//    {
//        if (this == &other)
//            return *this;
//
//        head = std::exchange(other.head, nullptr);
//        tail = std::exchange(other.tail, nullptr);
//        size_= std::exchange(other.size_, 0);
//        return *this;
//    }

    Container& operator = ( Container& other) {
        Node<T>* cache = other.head;
        clear();
        push_front(other.head->data);
        cache=cache->next;
        while(cache->next!=tail){
            push_back(cache->data);
            cache=cache->next;
        }
    }

//    bool operator==(Container& first){
//        if (size_==first.size_){
//            Node<T>* cache = first.head;
//            Node<T>* cache1 = head;
//            for (int i =0; i< size_;i++){
//                if(*cache!=*cache1) return false;
//                cache1=cache1->next;
//                cache=cache->next;
//            }
//            return true;
//        } else return false;
//    }

    ~Container() {
        clear();
    }

    Iterator begin() {
        return Iterator(head);
    }
    Iterator end() {
        return Iterator(tail);
    }

    const Iterator cbegin() const{
        return Iterator(head);
    }

    const Iterator cend() const {
        return Iterator(tail);
    }

    bool operator == (const Container& other) const{
        return bool(size_ == other.size_) && equals(cbegin(), cend(), other.cbegin());
    }

    bool operator!=(const Container& other) const {
        return *this != other;
    }

    void swap(Container<T> &ls){
        Node<T>* p1 =ls.head;
        long c = ls.size_;
        ls.head =  head;
        head = p1;
        p1 = ls.tail;
        ls.tail = tail;
        tail =p1;
        ls.size_ = size_;
        size_ = c;
    }

    size_t max_size() const {
        return MAX_SIZE;
    }
    size_t size() const {
        return size_;
    }

    bool empty(){
        if (size_>0) return 1; else return 0;
    }

    void push_front(T a){
        if (this->head == nullptr) {
            this->head = new Node<T>(a);
            this->tail = this->head->next;
            size_++;
        }
        else {
            Node<T> *p = new Node<T>(a);
            p->next =this->head;
            this->head = p;
            size_++;
        }
    };


    void push_back(T a){
        if(size_>=1) {
            Node<T> *run = head;
            Node<T> *p = new Node(a);
            while (run->next != tail) {
                run = run->next;
            }
            run->next = p;
            p->next = tail;
            size_++;
        }else{
            Node<T>* p = new Node<T>(a);
            p->next= tail;
            head=p;
            size_++;
        }
    }



    void pop_front(){
        if (size_>=1) {
            Node<T> *p = head;
            head = p->next;
            delete p;
            size_--;
        }
    }

    void pop_back(){
        if (size_>=1) {
            if (head->next == tail) {
                delete head;
                head = tail;
                size_--;
            } else {
                Node<T> *p = head;
                Node<T> *run = p->next;
                while ((run->next != tail)) {
                    run = run->next;
                    p = p->next;
                }
                p->next = tail;
                delete run;
                size_--;
            }
        }
    }

    void print() {
        if (this->head == nullptr) cout << "List is empty!\n";
        else {
            Node<T>* cache = this->head;
            while (cache->next != tail) {
                cout << cache->data << ' ';
                cache = cache->next;
            }
            std::cout << cache->data << '\n';
        }
    }

    void clear() {
        if (this->head == nullptr) cout;
        else {
           Node<T>* cache = this->head->next;
            while (this->head != nullptr) {
                delete this->head;
                this->head = cache;
                if (cache) cache = cache->next;
            }
            this->head = nullptr;
            this->size_ = 0;
        }
    }
};
