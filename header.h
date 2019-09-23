#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class DollarAmount
{
private:
    double *listAmount;
    double sum;
    double mean;

public:
    DollarAmount(int size);
    ~DollarAmount();
    void allocateInput(double input, int position);
    void printPoint(int size);
    void reInitPtr(int size);
    void printMean(int size);
};

//CONSTRUCTOR
DollarAmount::DollarAmount(int size)
{
    sum = 0.00;
    mean = 0.00;
    listAmount = new double[size];
}

//DECONSTRUCTOR
DollarAmount::~DollarAmount()
{
    cout << "deconstructor is called" << endl;
    delete[] listAmount;
}

//PLACE VALUES IN POINTER
void DollarAmount::allocateInput(double input, int position)
{
    listAmount[position] = input;
}

//PRINT POINTER
void DollarAmount::printPoint(int size)
{
    for (int i = 0; i < size; i++)
        cout << listAmount[i] << endl;
}

//RE-INITIALIZE POINTER SIZE
void DollarAmount::reInitPtr(int size)
{
    listAmount = new double[size];
}

void DollarAmount::printMean(int size)
{
    for (int i = 0; i < size; i++)
    {
        sum += listAmount[i];
    }
    mean = sum / size;
    cout << "the mean is " << mean << endl;
}
//END OF CLASS FUNCTIONS
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

    if (verifiedNum == inputNum)
    {
        return verifiedNum;
    }
    else
        return 0;
}
