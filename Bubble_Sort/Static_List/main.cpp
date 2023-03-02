#include "listaEstatica.h"
#include <chrono>

void timerBubble(StaticList &l, bool print){
    using namespace std::chrono;
    using namespace std::chrono;
    steady_clock::time_point t1 = steady_clock::now();
    l.bubblesort(print);
    steady_clock::time_point t2 = steady_clock::now();
    cout<< duration_cast<nanoseconds>(t2 - t1).count() <<endl;
}

int main(){

    using namespace std::chrono;
    
    StaticList* l1;
    int menu;
    scanf("%d", &menu);

    switch(menu){
        case 1:

            int val;
            l1 = new StaticList;

            while(scanf("%d", &val) > 0){
                l1->push_back(DataType{rand_name(), val});
            }

            timerBubble(*l1, true);
            delete(l1);
            break;
        case 2:

            for(int i=0; i<1000; ++i){
                l1 = new StaticList(i);
                timerBubble(*l1, false);
                delete(l1);
            }
    }
}