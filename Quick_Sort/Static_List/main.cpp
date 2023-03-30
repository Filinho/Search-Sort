#include "listaEstatica.h"
#include <chrono>

/* Executa e computa o tempo de execução do bubblesort na lista l. Caso print seja true, printa o estado da lista a cada iteração, caso print seja false apenas printa o tempo de execução do bubblesort.*/
void timerBubble(StaticList &l, bool print){
    using namespace std::chrono;
    using namespace std::chrono;
    steady_clock::time_point t1 = steady_clock::now();
    l.quickSort(print);
    steady_clock::time_point t2 = steady_clock::now();
    cout<< duration_cast<nanoseconds>(t2 - t1).count() <<endl;
}

int main(){

    using namespace std::chrono;
    
    StaticList* l1;
    int menu;
    scanf("%d", &menu);

    /*O switch possui dois casos correspondentes aos casos de teste*/
    /*No caso 1, uma lista com chaves recebidas da entrada padrão é criada e ordenada pelo bubblesort sendo que o estado da lista é printado a cada iteração.*/
    /*No caso 2, dentro de um loop que repete 1000 vezes, uma lista de tamanho i é criada e ordenada pelo bubblesort e o tempo gasto é printado na saida padrão possibilitando que o tempo gasto em cada tamanho de lista seja observado.*/
    switch(menu){
        case 1:

            int val;
            l1 = new StaticList;

            while(scanf("%d", &val) > 0){
                l1->push_back(DataType{rand_name(), val});
            }
            l1->print(-1);
            timerBubble(*l1, true);
            l1->print(-1);
            delete(l1);
            break;
        case 2:
            int n;
            scanf("%d", &n);
            for(int i=0; i<n; ++i){
                l1 = new StaticList(i);
                timerBubble(*l1, false);
                delete(l1);
            }
    }
}