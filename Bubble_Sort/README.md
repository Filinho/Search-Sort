# Bubble Sort

## Buble Sort is a sorting algorithm, which works by traversing the vector n times, and in each of them the largest element is placed at the end of the list until it is completely sorted.

![BS](https://user-images.githubusercontent.com/115127639/222279089-4cb68992-399b-4465-8aa0-75ced43a20a3.png)

# Static List

```c++
void bubblesort(){

        int swapPos = size-1;
        bool swapped = true;

        while(swapped){

            swapped = false;

            int n = swapPos;

            for(int j=0; j<n; ++j){/*4 7 8 6 4 6 7 3 10 2*/

                if(list[j].key > list[j+1].key){

                    swap(j, j+1);
                    swapPos = j;
                    swapped = true;
                }
            }
        }
    }
```

# Dynamic List

```c++
void bubbleSort(){
        Node * current;
        bool swapped = false; // boolean variable that informs if an swap happened

        /* each time times this for is traversed, the biggest key in the first n-i elements, is placed at the end of the list*/
        for(int i = 0; i <n_element;i++){
            current = StartHeadNode->Next; // set current as the first valid node of the list
            swapped = false; // set swapped false
        /*each time this for is traversdes, the current node is comparede with the next node*/
            for(int j = 0; j< n_element -i -1; j++){
                /*compare if the key of current is bigger than next node key, if it is, current is swapped if next, and swapped become true*/
                if(current->p.key>=current->Next->p.key){
                    SwapFront(current);
                    swapped = true;
                }
                /*if the compared arguments is already ordered, the current node become the next node*/
                else{
                    current = current->Next;
                }
            }
            /*if all the list is traversed, and there is no swap, it means that the list is already ordered*/
            if(swapped == false) break;
        }
    }
```
