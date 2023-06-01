# Bubble Sort

## Buble Sort is a sorting algorithm, which works by traversing the vector n times, and in each of them the largest element is placed at the end of the list until it is completely sorted.


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

