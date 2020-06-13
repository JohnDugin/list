#include "list.h"
#include <cassert>


// PRIVATE методы ----------------------------------------------------
list::Node::Node(const ValueType& value, Node* next){
    this->value = value;
    this->next = next;
}

void list::Node::insertNext(const ValueType& value){
    Node* newNode = new Node(value, this->next);
    this->next = newNode;

}

void list::Node::removeNext(){
    Node* removeNode = this->next;
    Node* newNext = removeNode->next;
    delete removeNode;
    this->next = newNext;
}

list::Node::~Node(){}



// PUBLIC методы ---- КОНСТРУКТОРЫ И ДИСТРУКТОР ---------------------
list::list(){
    _head = nullptr;
    _size= 0;
}

list::list(const list& _copyList){
    this->_head = nullptr;
    Node* currentNode = _copyList._head;
    while (currentNode)
    {
        this->pushBack(currentNode->value);
        currentNode = currentNode->next;
    }
}

list::list(list&& copyLList) {
    this->_head = copyLList._head;
    copyLList._head = nullptr;
}

list& list::operator+=(const list& copyList){
    int size = _size;
    for(int i = _size, j = 0; i < copyList.size() + size; i++, j++){
        this->pushBack(copyList[j]);
    }
    return *this;
}

list::~list(){
    Node* delNode = nullptr;
    for (delNode = _head; _head; delNode = _head)
    {
        _head = _head->next;
        delete delNode;
        delNode = nullptr;
    }
}



//-------------------------------------------------------------------
ValueType& list::operator[](const size_t pos) const{
    return getNode(pos)->value;
}

list::Node* list::getNode(const size_t pos) const{
    if (pos < 0) {
        assert(pos < 0);
    }
    else if (pos >= this->_size) {
        assert(pos >= this->_size);
    }

    Node* bufNode = this->_head;
    for (int i = 0; i < pos; ++i) {
        bufNode = bufNode->next;
    }

    return bufNode;
}



void list::insert(const size_t pos, const ValueType& value){

    if (pos < 0) {
        assert(pos < 0);
    }
    else if (pos > this->_size) {
        assert(pos > this->_size);
    }

    if (pos == 0) {
        pushFront(value);
    }
    else {
        Node* bufNode = this->_head;
        for (size_t i = 0; i < pos-1; ++i) {
            bufNode = bufNode->next;
        }
        bufNode->insertNext(value);
        ++_size;
    }
}

void list::pushBack(const ValueType& value)
{
    if (_size == 0) {
        pushFront(value);
        return;
    }
    insert(_size, value);
}

void list::pushFront(const ValueType& value){
    _head = new Node(value, _head);
    ++_size;
}



void list::pop(const size_t pos){
    if (pos < 0) {
        assert(pos < 0);
    }
    else if (pos > this->_size) {
        assert(pos > this->_size);
    }

    else if (pos == 0) {
        popFront();
    }
    else if(pos == _size - 1)
    {
        popBack();
    }
    else {

        Node *deleteNode = getNode(pos);
        Node *bufNode = getNode(pos + 1);
        getNode(pos - 1)->next = bufNode;
        delete deleteNode;
        --_size;
    }

}

void list::popNode(Node* node){
    int index = findIndex(node->value);

    if(index == -1)
    {
        assert(index == -1);
    }

    else if (index == 0) {
        popFront();
    }
    else if(index == _size - 1)
    {
        popBack();
    }
    else {


        pop(index);
        --_size;
    }

}

void list::popBack(){

    Node *deleteNode = getNode(_size - 1);
    getNode(_size - 2)->next = nullptr;
    delete deleteNode;
    --_size;
}

void list::popFront(){
    Node *deleteBuf = getNode(0);
    this->_head = getNode(1);
    delete deleteBuf;
    --_size;
}



long long int list::findIndex(const ValueType& value) const
{
    Node *node = this->_head;

    for(int i = 0; i < _size; ++i)
    {
        if(node->value == value){
            return i;
        }
        node = node->next;
    }
    return -1;
}

list::Node* list::findNode(const ValueType& value) const{
    int index = findIndex(value);
    assert(index != -1);
    return getNode(index);
}



void list::reverse()
{
    int index = _size-1;
    long double n;
    for(int i = 0; i <= int((_size-1)/2); ++i){
        n = getNode(i)->value;
        getNode(i)->value = getNode(_size - 1 - i)->value;
        getNode(_size - 1 - i)->value = n;
    }

}


size_t list::size() const
{
    return _size;
}
