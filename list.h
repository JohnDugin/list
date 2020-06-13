#pragma once
#include <iostream>

using ValueType = double;

class list{
    struct Node {
        Node(const ValueType& value, Node* next = nullptr);
        ~Node();

        void insertNext(const ValueType& value);
        void removeNext();

        ValueType value;
        Node* next;
    };

public:
    ////
    list();
    list(const list& _copyLList);
    list(list&& copyLList);
    list& operator+=(const list& copyList);
    ~list();
    ////

    // доступ к значению элемента по индексу
    ValueType& operator[](const size_t pos) const;
    // доступ к узлу по индексу
    list::Node* getNode(const size_t pos) const;

    // вставка элемента по индексу, сначала ищем, куда вставлять (О(n)), потом вставляем (O(1))
    void insert(const size_t pos, const ValueType& value);
    // вставка в конец (О(n))
    void pushBack(const ValueType& value);
    // вставка в начало (О(1))
    void pushFront(const ValueType& value);


    //удаление элементов
    void pop(const size_t pos);
    void popNode(Node* node);
    void popFront();
    void popBack();


    long long int findIndex(const ValueType& value) const;
    Node* findNode(const ValueType& value) const;


    void reverse();


    size_t size() const;

private:
    Node*	_head;
    size_t	_size;
};
