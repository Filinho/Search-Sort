 #include <iostream>
#define MAX_ELEM 100

using namespace std;

typedef struct{

    string name;
    int key;
}Person;

typedef Person DataType;

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

            list[i].key = rand()%n + 1;
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

                if(list[j].key > list[j+1].key){

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

            cout << "Nome: " << list[i].name << "Key: " << list[i].key << endl;
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