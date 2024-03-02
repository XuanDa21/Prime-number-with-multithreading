#ifndef PrimeThread_h
#define PrimeThread_h
#include "PrimeCounter.h"
#include <thread>
#include <mutex>
#include <vector>
using namespace std;
class PrimeThread{
    private: 
            int rangeToCount, numberThread, primeThread;
            vector<PrimeCounter> primeCounters;
            mutex varMutex;
    public:

            PrimeThread(int, int);

            void countingPrime();
};

#endif