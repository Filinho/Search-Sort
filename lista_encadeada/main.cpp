#include "DoubleLinkedList.h"

int main(){
    LinkedList * l = new LinkedList(20);

    for(Node * current = l->StartHeadNode->Next; current != l->EndHeadNode;current = current->Next){
       cout << current->p.Name<< " "; 
    }
    cout << endl;
    
    for(Node * current = l->StartHeadNode->Next; current != l->EndHeadNode;current = current->Next){
    cout << current->p.Name<< " "; 
    }

    delete(l);
}