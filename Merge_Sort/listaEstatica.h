#include <iostream>
#include "rand.h"

using namespace std;

typedef struct{
    string name;
    int key;
}Person;

typedef Person DataType;

class StaticList{
public:

    static constexpr unsigned int MAX = 1000;

    DataType list[MAX];
    unsigned int size;

    /*initizalize an empty list.*/
    StaticList(){

        size = 0;
    }

    /*initialize an list with sz unique elements in a random order.*/
    StaticList(const int sz){
        size = sz;

        /*First we add the elements sequencially.*/
        for(int i=0; i<sz; ++i){

            list[i].key = i;
            list[i].name = rand_name();
        }

        /*A permutation of the elements occurs to randomize the positions.*/
        int elem1, elem2;
        for(int i=0; i<sz; ++i){

            elem1 = rand()%sz;
            elem2 = rand()%sz;
            swap(elem1, elem2);
        }
    }

    /*insert the value on position pos overwriting the element in pos.*/
    void overwrite_position(const unsigned int pos, const DataType value){

        if(pos >= size) return;

        list[pos] = value;
    }

    /*insert value on position pos moving the element in pos one index foward.*/
    void insert_position(const unsigned int pos, const DataType value){

        if(pos >= size) return;
        
        /*the loop starts at the end of the list moving all the elements one index foward opening the index pos to element value.*/
        for(int i=size; i>pos; --i){

            list[i] = list[i-1];
        }

        list[pos] = value;
        size++;
    }

    /*insert x in the end of the list.*/
    void push_back(const DataType x){

        if(size == MAX) return;

        list[size++] = x; 
    }

    //print the elements of a list.
    void print(int l, int r, char color, int mid){
        int cl;
        if(color == 'b') cl = 34;
        else if(color == 'r') cl = 31; 
        for(int i=0; i<size; ++i){
            
            if(i==l) cout << "\e[" << cl << ";10m";
            if(mid == i) cout << "|";
            else cout << " ";
            cout << list[i].key;
            if(i==r) cout << "\e[m";
        }
        cout << "\n";
    }

    /*swap the element on index posA with the element on index posB*/
    void swap(const unsigned int posA, const unsigned int posB){

        DataType aux = list[posA];

        list[posA] = list[posB];
        list[posB] = aux;
    }

    /*delete the element at index pos*/
    void delete_position(const unsigned int pos){

        /*the loop starts on index pos moving the elements one index back and overwriting the element at pos*/
        for(int i=pos; i<size; ++i){
            list[i] = list[i+1];
        }
        size--;
    }

    void mergesort(bool print){

        StaticList auxL(*this);
        rec_mergesort(0, size, &auxL, print);
    }

private:

    void merge(const int left, const int mid, const int right, StaticList* auxL){

        int leftAux = left;
        int midAux = mid;
        
        for(int i=left; i<right; ++i){

            if(leftAux<mid && (!(midAux<right) || list[leftAux].key<list[midAux].key)){

                auxL->overwrite_position(i, list[leftAux++]);
            }else{

                auxL->overwrite_position(i, list[midAux++]);
            }
        }
    }

    void rec_mergesort(const int left, const int right, StaticList* auxL, bool prt){

        if(left < right-1){
            int mid = (left+right)/2;
            auxL->rec_mergesort(left, mid, this, prt);
            auxL->rec_mergesort(mid, right, this, prt);
            if(prt){
                cout << endl;
                auxL->print(left, right-1, 'r', mid);
            }
            auxL->merge(left, mid, right, this);

            if(prt){
                cout << endl;
                print(left, right-1, 'b', -1);
                cout<< endl;
            }
        }
    }
};