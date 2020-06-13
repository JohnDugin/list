#include <iostream>
#include "list.h"

using namespace std;

void dump(const list& l){
    for(size_t i = 0; i < l.size(); ++i, cout << " ")
        cout << l[i];
}

int main(){
    list l;
    l.pushBack(1);
    l.pushFront(0);
    l.pushBack(2);

    cout << "Stage 1: ";
    dump(l);
    cout << endl;

    l.insert(1, 10);
    cout << "Stage 2: ";
    dump(l);
    cout << endl;

    l.pop(1);
    cout << "Stage 3: ";
    dump(l);
    cout << endl;

    l.reverse();
    cout << "Stage 4: ";
    dump(l);
    cout << endl;

    return 0;
}