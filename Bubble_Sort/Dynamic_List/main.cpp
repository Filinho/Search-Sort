#include "DoubleLinkedList.h"

int main(){
    LinkedList * l = new LinkedList(1000);
    l->printList();
    l->bubbleSort();
    cout << endl;
    l->printList();
    delete(l);
}