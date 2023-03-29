#include <iostream>

using namespace std;

typedef struct{

    string name;
    int key;
}Student;

typedef int DataType;

class Node{
public:

    DataType elem;
    Node* next;
    Node* prev;

    Node(){
        next = NULL;
        prev = NULL;
    }

    Node(const DataType newElem){

        elem = newElem;
    }

    void print(){

        cout << elem << ":" << elem << endl;
    }
};

class DoublyLinkedList{
public:

    Node* head;
    Node* tail;
    unsigned int size;

    DoublyLinkedList(){

        head = NULL;
        tail = NULL;
        size = 0;
    }

    DoublyLinkedList(const int sz, const int n){

        size = sz;
        /*DataType dummy;

        dummy.name = "dummy";*/

        for(int i=0; i<sz; ++i){

            push_back(rand()%n);
        }
    }

    ~DoublyLinkedList(){

        while(head){

            Node* aux = head->next;

            delete(head);

            head = aux;
        }
    }

    void print(){

        Node* auxPtr = head;

        for(int i=0; i<size; ++i){

            auxPtr->print();

            auxPtr = auxPtr->next;
        }
    }

    void push_front(const DataType x){

        Node* newNode = new Node(x);
        Node* auxPtr = head;

        head = newNode;

        if(!auxPtr){

            tail = newNode;

            return;
        }

        head->next = auxPtr;
        auxPtr->prev = head;
    }

    void push_back(const DataType x){

        Node* newNode = new Node(x);
        Node* auxPtr = tail;

        tail = newNode;

        if(!auxPtr){

            head = newNode;

            return;
        }

        tail->prev = auxPtr;
        auxPtr->next = tail;
    }

    void bubblesort(){

        
    }

private:

    void swap(Node* nodeA, Node* nodeB){

        Node* newNextA = nodeB->next;
        Node* newPrevA = nodeB->prev;

        
        if(nodeA->next == nodeB){

            nodeA->next = nodeA;
            newPrevA = nodeB;
        }else if(nodeA->prev = nodeB){

            nodeA->prev = nodeA;
            newNextA = nodeB;
        }

        nodeB->next = nodeA->next;
        nodeB->prev = nodeB->prev;
        nodeA->next = newNextA;
        nodeA->prev = newPrevA;

        nodeB->next->prev = nodeB;
        nodeB->prev->next = nodeB;
        nodeA->next->prev = nodeA;
        nodeA->prev->next = nodeA;
    }

    void transpose_front(Node* nodeA){

        swap(nodeA, nodeA->next);
    }

    void transpose_back(Node* nodeA){

        swap(nodeA, nodeA->prev);
    }

    

};

int main(){


}