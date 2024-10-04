#pragma once
#include <iostream>
using namespace std;
template <typename T>
struct Node {
    T data;
    Node<T>* next;

    Node() : next(nullptr) {};
    Node(T x) : data(x), next(nullptr) {};
    Node(T x, Node<T>* nextlink) : data(x), next(nextlink) {};

};





