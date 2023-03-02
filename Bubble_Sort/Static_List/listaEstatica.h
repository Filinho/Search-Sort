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

    StaticList(){

        size = 0;
    }

    StaticList(const int sz){

        size = sz;

        for(int i=0; i<sz; ++i){

            list[i].key = i;
            list[i].name = rand_name();
        }

        int elem1, elem2;
        for(int i=0; i<sz; ++i){

            elem1 = rand()%sz;
            elem2 = rand()%sz;
            swap(elem1, elem2);
        }
    }

    void overwrite_position(const unsigned int pos, const DataType value){

        if(pos >= size) return;

        list[pos] = value;
    }

    void insert_position(const unsigned int pos, const DataType value){

        if(pos >= size) return;

        for(int i=size; i>pos; --i){

            list[i] = list[i-1];
        }

        list[pos] = value;
        size++;
    }

    void push_back(const DataType x){

        if(size == MAX) return;

        list[size++] = x; 
    }

    void bubblesort(const bool print){

        int swapPos = size-1;
        bool swapped = true;

        if(print){
            this->print();
            cout << endl;
        }

        while(swapped){

            swapped = false;

            int n = swapPos;

            for(int j=0; j<n; ++j){

                if(list[j].key > list[j+1].key){

                    swap(j, j+1);
                    swapPos = j;
                    swapped = true;
                }
            }

            if(print){
                this->print();
                cout << endl;
            }
        }
    }

    int binary_search(const DataType target){

        int left = 0;
        int right = size-1;
        int targetKey = target.key;

        while(left <= right){

            int middle = (right+left)/2;

            if(list[middle].key == targetKey) return middle;

            else if(list[middle].key < targetKey){

                left = middle+1;
            }else{

                right = middle-1;
            }
        }

        return -1;
    }

    void print(){

        for(int i=0; i<size; ++i){

            cout << "(" << list[i].key << ")-Nome: " << list[i].name << endl;
        }
    }

    void swap(const unsigned int posA, const unsigned int posB){

        DataType aux = list[posA];

        list[posA] = list[posB];
        list[posB] = aux;
    }

    void delete_position(const unsigned int pos){

        for(int i=pos; i<size; ++i){

            list[i] = list[i+1];
        }

        size--;
    }

};