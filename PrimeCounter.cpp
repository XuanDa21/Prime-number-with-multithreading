#include "PrimeCounter.h"

PrimeCounter::PrimeCounter(int start, int end) {
    this -> start = start;
    this -> end = end;
    this -> count = 0;
}

int PrimeCounter::getStart() {
    return this -> start;
}

int PrimeCounter::getEnd() {
    return this -> end;
}

void PrimeCounter::countPrimes() {
    for(int i = start; i <= end; ++i) {
        bool isPrime = true;
        for(int j = 2; j < i; ++j) {
            if(i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if(isPrime) {
            count++;
            valuePrimes.push_back(i);
        }
    }
}

vector<int> PrimeCounter::getValuePrimes(){
    return valuePrimes;
}

int PrimeCounter::getCount() {
    return count;
}
