#include "DoubleLinkedList.h"

void timerBubble(LinkedList &l){
    using namespace std::chrono;
    using namespace std::chrono;
    steady_clock::time_point t1 = steady_clock::now();
    l.bubbleSort();
    steady_clock::time_point t2 = steady_clock::now();
    cout<< duration_cast<nanoseconds>(t2-t1).count() <<endl;
}
int main(){
    int menu;
    scanf("%d",&menu);
    LinkedList * l;
    switch(menu){
        case 1:{
            int x;
            l = new LinkedList;
            while(scanf("%d",&x) > 0){
                l->PushBack(Person{rand_name(x%30),x});
            }
            l->printList();
            cout<<endl;
            timerBubble(*l);
            l->printList();
            delete(l);
        }break;
        case 2:{
            int tamanho;
            scanf("%d",&tamanho);
            for(int i=0;i<tamanho;i++){
                l = new LinkedList(i);
                timerBubble(*l);
                delete(l);   
            }
        }break;
    }
}