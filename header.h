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
//CONSTRUCTOR
DollarAmount::DollarAmount(int size)
{
    sum = 0.00;
    mean = 0.00;
    input = new string[1];
    listAmount = new string[size];
    listAmountCopy = new string[size];
}

//DECONSTRUCTOR
DollarAmount::~DollarAmount()
{
    //cout << "deconstructor is called" << endl;
    delete[] listAmount;
    delete[] input;
    delete[] calcAmount;
}

string DollarAmount::iO_Pointer(){
    cout << "Enter the expenditure record (ex: 2.54, 1055.79 : -1 to exit )";
            cin >> input[0];
            return input[0];
}

//PLACE VALUES IN POINTER
void DollarAmount::allocateInput(int position, int size)
{

    listAmount[position] = input[0];
    //copy list Amount to listAmountCopy
    for(int i=0; i<=position; i++){
        listAmountCopy[i] = listAmount[i];
    }
    //done with listAmount since input stored in copy
    delete[] listAmount;
    listAmount = nullptr;
    //create new dynamic list amount
    int newSize = size + 1;
    listAmount = new string[newSize];
    //reallocate memory back to listAmount
    for(int i=0; i<=position; i++){
        listAmount[i] = listAmountCopy[i];
    }
    //done with copyPointer, safe to delete and increase size for next allocation round
    delete []listAmountCopy;
    listAmountCopy = nullptr;
    listAmountCopy = new string[newSize];
}

//PRINT POINTER
void DollarAmount::printPoint(int size)
{
    for (int i = 0; i < size; i++)
        cout << listAmount[i] << endl;
}

//PRINT THE MEAN FROM THE FINAL RESULT POINTER
void DollarAmount::printMean(int size)
{
    size--;
    calcAmount = new double[size];
    for(int i = 0; i<size; i++){
        if(size == 1){
            calcAmount[0] = atof(listAmount[0].c_str());
            break;
        }
        calcAmount[i] =  atof(listAmount[i].c_str());}
    
    for (int i = 0; i < size; i++){
        if(size == 1){
            sum = calcAmount[0];
            break;
        }
        sum += calcAmount[i];
    }
    
    mean = sum / size;
    cout << "the mean is " << mean << endl;
}
//START OF FRIEND CLASS AND CLASS MEMBERS============================================================================================================
class SpendingRecord{
    
    private:
        string *expendInput;
        string *listRecord;
        string *listCombined;

    public:
    SpendingRecord(int size);
    ~SpendingRecord();
    void iO_Pointer();
    void allocateStringInput(string input, int position);
    void reInitStringPtr(int size);
    //void printFinalRecord();
    void combineBothInputs(const DollarAmount &, int size);
    void printPoint(int size);
};

SpendingRecord::SpendingRecord(int size){
    listRecord = new string[size];
    listCombined = new string[size];
    expendInput = new string[1];
}

SpendingRecord::~SpendingRecord()
{
    delete[] listRecord;
    delete[] listCombined;
    delete[] expendInput;
}

void SpendingRecord::iO_Pointer(){
    cout<< "the expenditure?";
    cin >> expendInput[0];
    cout << endl;
}
//ALOCATE INPUT TO STRING, DO WE NEEED DOUBLE TO STRING CONVERSION?
void SpendingRecord::allocateStringInput(string input, int position)
{
    listRecord[position] = input;
    cout << "listRecord contents: "<<listRecord[position] << " at position " << position << endl;
}

//RE-INITIALIZE STRING POINTER SIZE
void SpendingRecord::reInitStringPtr(int size)
{
    listRecord = new string[size];
    cout << "list Record has new size of " << size << endl;
}

void SpendingRecord::combineBothInputs(const DollarAmount & da, int finalSize){
    listCombined = new string[finalSize];
    for(int i=0; i<finalSize; i++){
        //convert double value of list Amount to string
        //store string in spending record
    }
}

void SpendingRecord::printPoint(int size)
{
    for (int i = 0; i < size; i++)
        cout << listRecord[i] << endl;
}


//END OF CLASSES AND CLASS FUNCTIONS
//==============================================================================================================================================//
//BEGINING OF NON-CLASS MEMBER FUNCTIONS
//DECIMAL CHECK OF INPUT
bool decimalCheck(string input)
{
    //check decimal character ammount and placement
    int decCount = 0;
    for (int i = 0; i <= input.size(); i++)
    {
        if (input[i] == '.')
        {
            decCount++;
        }

        if (input[i] == '.' && input[i + 3] != '\0')
        {
            cout << "your have too many decimal places being used, only use two!! Try again!" << endl;
            return false;
        }

        if ((input[i] == '.' && input[i + 2] == '\0') || (input[i] == '.' && input[i + 1] == '\0'))
        {
            cout << "you have a decimal, but no complete decimal format after decimal point... Try again!" << endl;
            return false;
        }
    }
    if (decCount == 0)
    {
        cout << "No decimals! Invalid Format! try agian!!" << endl;
        return false;
    }

    else if (decCount >= 2)
    {
        cout << "Too many decimals, Invalid Format! try again!!" << endl;
    }

    return true;
}
//CHARACTER SIZE CHECK OF INPUT
bool sizeCheck(string input)
{
    if (input.size() < 4 && input.size() > 7)
    {
        cout << "you have too many characters!! try again!!" << endl;
        return 0;
    }
    else
        return true;
}
//CHECKS FOR NON-DIGIT INPUT
bool nonNumericCheck(string input)
{
    const int myCharsSize = 26;
    const int specialCharsSize = 24;

    char myChars[myCharsSize] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char specialChars[specialCharsSize] = {'~', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+', '-', '=', '<', '>', '?', '{', '}', '"', ',', ':', ';'};
    for (int i = 0; i < input.size(); i++)
    {
        for (int j = 0; j < myCharsSize; j++)
        {
            if (input[i] == myChars[j])
            {
                cout << "you have alphabetic characters in your ammount, Try Again!!!" << endl;
                return 0;
            }
        }
    }
    for (int i = 0; i < input.size(); i++)
    {
        for (int j = 0; j < specialCharsSize; j++)
        {
            if (input[i] == specialChars[j])
            {
                cout << "you have special alphabetic characters in your ammount, Try Again!!!" << endl;
                return 0;
            }
        }
    }
    return true;
}
//NON CLASS FUNCTION TO CHECK INPUT
double checkChars(string input)
{
    if (sizeCheck(input) == 0)
        return 0;
    //count decimals
    else if (decimalCheck(input) == 0)
        return 0;

    else if (nonNumericCheck(input) == 0)
        return 0;

    //check for all invalid characters
    int myCharSize = 11;
    char myChars[11] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.'};
    string verifiedChar = "00000000";

    for (int i = 0; i < input.size(); i++)
    {
        for (int j = 0; j < myCharSize; j++)
        {
            if (input[i] == myChars[j])
            {
                verifiedChar[i] = input[i];
            }
        }
    }
    //convert string to integer
    double verifiedNum = atof(verifiedChar.c_str());
    double inputNum = atof(input.c_str());
    //special characters after the number will still go through
    if (inputNum < 0.00 || inputNum >= 10000.00)
    {
        cout << "your ammount must be between $10000.00 and $0.00" << endl;
        return 0;
    }
    if (verifiedNum == inputNum)
    {
        return verifiedNum;
    }
    else
        return 0;
}
