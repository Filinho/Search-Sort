#include <iostream>
#include <cstdlib>


using namespace std;

class Node{
public:
    int Data;
    Node * Next;
    Node * Prev;
    Node(){
        Data = 0;
        Next = NULL;
        Prev = NULL;
    };

    Node(int x){
        Data = x;
        Next = NULL;
        Prev = NULL;
    };
};

class LinkedList{
public:
    Node * StartHeadNode;

    Node * EndHeadNode;

    void PushFront(const int & data){

        Node * newNode = new Node(data);
        Node * oldStart= StartHeadNode->Next;

        newNode->Prev = StartHeadNode;
        oldStart->Prev = newNode;
        newNode->Next = oldStart;
        StartHeadNode->Next = newNode;
    }

    void PushBack(const int & data){

        Node * newNode = new Node(data);
        Node * oldEnd= EndHeadNode->Prev;

        newNode->Next = EndHeadNode;
        newNode->Prev = oldEnd;

        oldEnd->Next = newNode;
        EndHeadNode->Prev = newNode;
    }

    void TranspFront(Node * node){
        if(node->Next == EndHeadNode) return;
        TranspBack(node->Next);
    }

    void TranspBack(Node * node){

        if(node->Prev == StartHeadNode) return;
        Node * aux = node->Prev;

        node->Prev = aux->Prev;
        aux->Prev->Next = node;
        aux->Prev = node;
        aux->Next = node->Next;
        node->Next->Prev = aux;
        node->Next = aux;
    }
    
    LinkedList(){

        StartHeadNode = new Node(0);
        EndHeadNode = new Node(-1);

        StartHeadNode->Next = EndHeadNode;
        EndHeadNode->Prev = StartHeadNode;
    }
    
    LinkedList(const int & n){
        StartHeadNode = new Node(-1);
        EndHeadNode = new Node(-1);

        StartHeadNode->Next = EndHeadNode;
        EndHeadNode->Prev = StartHeadNode;
        
        for(unsigned int i = 0; i<n;i++){
            int x = rand() % 100;
            this->PushBack(x);
        }
    }

    LinkedList(const int & start, const int & end){
        StartHeadNode = new Node(0);
        EndHeadNode = new Node(-1);

        StartHeadNode->Next = EndHeadNode;
        EndHeadNode->Prev = StartHeadNode;

        for(unsigned int i = 0; i<start;i++){
            int x = rand() % end;
            this->PushBack(x);
        }
    }

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

