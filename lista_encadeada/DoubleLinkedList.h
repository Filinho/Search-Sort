#include "rand.h"
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


    void bubbleSort(){
        Node * current;
        bool swapped = false;
        for(int i = 0; i <n_element;i++){
            current = StartHeadNode->Next;
            swapped = false;
            for(int j = 0; j< n_element -i -1; j++){
                if(current->p.key>=current->Next->p.key){
                    SwapFront(current);
                    swapped = true;
                }
                else{
                    current = current->Next;
                }
            }
            if(swapped == false) break;
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
            for(unsigned int i = 0; i<n;i++){
            Person x;
            x.key = rand() % n;
            x.Name = rand_name((i*x.key)/n);
            PushBack(x);
        }

    }
    // constructor that initializes a list with n values ​​in the defined range
    LinkedList(const int & n, const int & range){
        StartHeadNode = new Node();
        EndHeadNode = new Node();
        n_element = 0;
        StartHeadNode->Next = EndHeadNode;
        EndHeadNode->Prev = StartHeadNode;

        for(unsigned int i = 0; i<n;i++){
            Person x;
            x.key = rand() % n;
            x.Name = rand_name(i*x.key/range);
            PushBack(x);
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

