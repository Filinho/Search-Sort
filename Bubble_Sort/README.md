# Bubble Sort
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
```
