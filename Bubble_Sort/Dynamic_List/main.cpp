#include "DoubleLinkedList.h"

int main(){
    LinkedList * l = new LinkedList(1000);
    l->printList();
    cout << endl;
    l->bubbleSort();
    l->printList();
    delete(l);
}