#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class DollarAmount
{
private:
    string *input;
    string *listAmount;
    string *listAmountCopy;
    double *calcAmount;
    double sum;
    double mean;

public:
    DollarAmount(int size);
    DollarAmount(const DollarAmount & da, int position);
    ~DollarAmount();
    void allocateInput(int position, int size);
    void printPoint(int size);
    void printMean(int size);
    //restructure where input is with direct pointer

    string iO_Pointer();

    friend class SpendingRecord;
};

class SpendingRecord{
    
    private:
        string *expendInput;
        string *listRecord;
        string *listRecordCopy;
        string *listCombined;

    public:
    SpendingRecord(int size);
    ~SpendingRecord();
    void iO_Pointer();
    void allocateExpend(int position, int size);
    void printExpend(int size);
    //void printFinalRecord();
    void combineBothInputs(const DollarAmount &, int size);
    void printPoint(int size);
};

//==============================================================================================================================================//
//BEGINING OF NON-CLASS MEMBER FUNCTIONS
//DECIMAL CHECK OF INPUT
