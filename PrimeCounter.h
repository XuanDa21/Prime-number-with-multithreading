#ifndef PrimeCounter_h
#define PrimeCounter_h
#include <vector>
using namespace std;
class PrimeCounter{
    private: 
        int start, end, count;
    public:

        vector<int> valuePrimes;

        explicit PrimeCounter(int start, int end);

        void countPrimes();

        vector<int> getValuePrimes();

        int getCount();

        int getStart();

        int getEnd();

};

#endif