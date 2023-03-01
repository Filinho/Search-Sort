#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct{
    string Name;
    int key;
} Person;
class Node{
public:
    Person p;
    Node * Next;
    Node * Prev;
    Node(){
        p.Name ="Dummy";
        p.key = 0;
        Next = NULL;
        Prev = NULL;
    };

    Node(const Person  &  x){
        p = x;
        Next = NULL;
        Prev = NULL;
    };
};

class LinkedList{
public:
    Node * StartHeadNode;

    Node * EndHeadNode;

    int n_element;

    void PushFront(const Person & data){

        Node * newNode = new Node(data);
        Node * oldStart= StartHeadNode->Next;

        newNode->Prev = StartHeadNode;
        oldStart->Prev = newNode;
        newNode->Next = oldStart;
        StartHeadNode->Next = newNode;
        n_element ++;
    }

    void PushBack(const Person & data){

        Node * newNode = new Node(data);
        Node * oldEnd= EndHeadNode->Prev;

        newNode->Next = EndHeadNode;
        newNode->Prev = oldEnd;

        oldEnd->Next = newNode;
        EndHeadNode->Prev = newNode;
        n_element ++;
    }

    void SwapFront(Node * node){
        if(node->Next == EndHeadNode) return;
        SwapBack(node->Next);
    }

    void SwapBack(Node * node){

        if(node->Prev == StartHeadNode) return;
        Node * aux = node->Prev;

        node->Prev = aux->Prev;
        aux->Prev->Next = node;
        aux->Prev = node;
        aux->Next = node->Next;
        node->Next->Prev = aux;
        node->Next = aux;
    }
    
    void BubbleSort(){
        bool Swap = true;
        int aux = n_element -1;
        int n = n_element;

        while(Swap){
            Swap = false;
        }

    }
    // default constructor, that initialize both headnodes, and a empty List
    LinkedList(){

        StartHeadNode = new Node();
        EndHeadNode = new Node();

        StartHeadNode->Next = EndHeadNode;
        EndHeadNode->Prev = StartHeadNode;
        n_element = 0;
    }
    // constructor that initialize a List with n random numbers
    LinkedList(const int & n){
        StartHeadNode = new Node();
        EndHeadNode = new Node();
        n_element = 0;
        StartHeadNode->Next = EndHeadNode;
        EndHeadNode->Prev = StartHeadNode;
        
    }
    // constructor that initializes a list with n values ​​in the defined range
    LinkedList(const Data & n, const int & range){
        StartHeadNode = new Node(0);
        EndHeadNode = new Node(Data);
        n_element = 0;
        StartHeadNode->Next = EndHeadNode;
        EndHeadNode->Prev = StartHeadNode;

        for(unsigned int i = 0; i<n;i++){
            int x = rand() % range;
            this->PushBack(x);
        }
    }
    // delete list
    ~LinkedList(){
        Node * deleted = StartHeadNode->Next;
        while(deleted != EndHeadNode){
            StartHeadNode->Next = deleted->Next;
            delete(deleted);
            deleted = StartHeadNode->Next; 
        }
        delete(StartHeadNode);
        delete(EndHeadNode);
    }
};

