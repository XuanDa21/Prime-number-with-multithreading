#include <iostream>
#include "PrimeThread.h"
using namespace std;

void start();
int main() { 
    start();
    return 0;
}

void start() {
    int n, m;
    cout << "Enter value of n: ";
    cin >> n;
    cout << "Enter value of m: ";
    cin >> m;
    PrimeThread primeThread(n, m);
    primeThread.countingPrime();
}

