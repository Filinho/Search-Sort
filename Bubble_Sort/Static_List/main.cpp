#include "listaEstatica.h"
#include <chrono>

int main(){

    using namespace std::chrono;
    using namespace std::chrono;
    steady_clock::time_point t1 = steady_clock::now();
    
    StaticList l1(1000);

    l1.bubblesort();

    l1.print();

    steady_clock::time_point t2 = steady_clock::now();

    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

    cout << time_span.count();
}