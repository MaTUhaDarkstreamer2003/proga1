#include <iostream>
#include <ctime>

using namespace std;

int main () {

    std::clock_t start, finish;
    double duration1;
    double duration2;
    int k = 1;
    int g = 234765;

    start = clock();
    for (long long int i=0; i<=10000000000; i++) {
        if (i & 1) {
            k=1;
        }
        else {
            k=1;
        }
    } 

    duration1 = (double) ( clock() - start );
    cout << "Vremya1: " << duration1 << " milisekund" << endl;

    k=1;

    start = clock();
    for (long long int i=0; i<=10000000000; i++) {
        if (i % 2 == 1) {
            k=1;
        }
        else {
            k=1;
        }
    } 

    duration2 = (double) ( clock() - start );
    cout << "Vremya2: " << duration2 << " milisekund" << endl;


    cout <<100 * (duration1/duration2-1) << "%";
    return 0;
}