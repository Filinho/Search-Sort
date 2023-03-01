#include "DoubleLinkedList.h"

int main(){
    LinkedList * l = new LinkedList(20);

    for(Node * current = l->StartHeadNode->Next; current != l->EndHeadNode;current = current->Next){
       cout<<"Name: " << current->p.Name<< ", Key: "<< current->p.key << endl; 
    }
    cout << endl;
    delete(l);
}