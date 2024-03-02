#include "PrimeThread.h"
#include <iostream>

PrimeThread::PrimeThread(int rangeToCount, int numberThread){
    this -> rangeToCount = rangeToCount;
    this -> numberThread = numberThread;
    int range = rangeToCount/numberThread;
    int start = 1;
    int end = range;
    if(numberThread <= 2) {
        start = 1;
        end = rangeToCount;
        primeCounters.push_back(PrimeCounter(start, end));
    }
    else {
        for(int i = 1; i <= (numberThread - 1); ++i) {
            if (i == (numberThread - 1)) {
                end = rangeToCount;
            }
            primeCounters.push_back(PrimeCounter(start, end));
            start = end + 1;
            end += range;
        }
    }
}

void PrimeThread::countingPrime() {
    vector<thread> threads;
    for (int i = 0; i < (numberThread - 1); ++i) {
        //first parameter is the reference to the function
        //second parameter is the reference to the object of the class
        //at last we have arguments
        threads.push_back(std::thread(&PrimeCounter::countPrimes, &primeCounters[i]));
    }

    for (int i = 0; i < (numberThread - 1); ++i) {
        threads[i].join();
    }
    
    int totalCount = 0;
    auto f = [](int totalCount) { 
        cout << "Total prime number is: " << totalCount << endl;    
    };

    for (int i = 0; i < (numberThread - 1); ++i) {
        totalCount += primeCounters[i].getCount();
        vector<int> valuePrimes = primeCounters[i].getValuePrimes();
        cout << primeCounters[i].getStart() << " to " << primeCounters[i].getEnd() << " have ";
        for(int i = 0; i < valuePrimes.size(); ++i) {
            cout << valuePrimes[i] << " "; 
        }
        cout << endl;
    }

    thread lastThread(f, totalCount);
    lastThread.join();
}