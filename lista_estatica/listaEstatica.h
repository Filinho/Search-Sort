#include <iostream>
#define MAX_ELEM 100

using namespace std;

typedef struct{

    string name;
    int key;
}Student;

typedef int DataType;

class StaticList{
public:

    DataType* list;
    unsigned int size;
    unsigned int maxSize;

    StaticList(const int sz){

        list = new DataType[sz];
        maxSize = sz;
        size = 0;
    }

    StaticList(const int sz, const int n){
        
        list = new DataType[sz];
        maxSize = sz;
        size = n;

        for(int i=0; i<n; ++i){

            list[i] = rand()%n + 1;
        }
    }

    void overwrite_position(const unsigned int pos, const int value){

        if(pos >= size) return;

        list[pos] = value;
    }

    void insert_position(const unsigned int pos, const int value){

        if(pos >= size) return;

        for(int i=size; i>pos; --i){

            list[i] = list[i-1];
        }

        list[pos] = value;
        size++;
    }

    void push_back(const DataType x){

        if(size == maxSize) return;

        list[size++] = x; 
    }

    void bubblesort(){

        int swapPos = size-1;
        bool swaped = true;

        while(swaped){

            swaped = false;

            int n = swapPos;

            for(int j=0; j<n; ++j){/*4 7 8 6 4 6 7 3 10 2*/

                if(list[j] > list[j+1]){

                    swap(j, j+1);
                    swapPos = j;
                    swaped = true;
                }
            }
        }
    }

    int binary_search(const DataType target){

        int left = 0;
        int right = size-1;

        while(left <= right){

            int middle = (right+left)/2;

            if(list[middle] == target) return middle;

            else if(list[middle] < target){

                left = middle+1;
            }else{

                right = middle-1;
            }
        }

        return -1;
    }

    void print(){

        for(int i=0; i<size; ++i){

            printf("%d; ", list[i]);
        }

        printf("\n");
    }

    void swap(const unsigned int posA, const unsigned int posB){

        unsigned int aux = list[posA];

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

int main(){

    StaticList l1(10);

    l1.push_back(1);
    l1.print();
    l1.push_back(21);
    l1.print();
    l1.push_back(32);
    l1.print();
    l1.push_back(2);
    l1.print();
    l1.push_back(4);
    l1.print();
    l1.push_back(454);
    l1.print();
    l1.push_back(65);
    l1.print();

    l1.bubblesort();

    l1.print();

    int n = l1.binary_search(29);

    if(n > -1){

        printf("\n%d\n", l1.list[n]);
    }else{

        printf("\n29 não está na lista\n");
    }
}