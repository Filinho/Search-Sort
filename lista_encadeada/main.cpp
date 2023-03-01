#include "DoubleLinkedList.h"

int main(){
    LinkedList * l = new LinkedList(10);
    l->printList();
    l->bubbleSort();
    cout << endl;
    l->printList();
    delete(l);
}