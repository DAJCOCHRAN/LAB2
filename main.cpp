#include "header.h"


//INITIAL POINTER ASSIGNMENT TO BE GIVEN

int main()
{
    //expendRecord();
    double inputNum = 0;
    string input = " ";
    int size = 5;
    int sizeFlag = 0;
    DollarAmount a(size);
    DollarAmount b(size);
    for (int i = 0; i < size; i++)
    {
        sizeFlag = size - 1;
        cout << "WELCOME!" << endl;
        cout << "Please enter an ammount less than $10000.00 and larger than 0.00" << endl;
        cout << "Make sure to include the dollar ammount and cent ammount even if it is 0, for example $25.01" << endl;
        bool verified = false;
        while(verified == false){
        cout << "Enter the expenditure record (ex: 2.54, 1055.79 : )" << endl;
        cin >> input;
        cout << " " << endl;
        //try catch for input validation
        inputNum = checkChars(input);
        if(inputNum > 0 && inputNum<10000.00) verified = true;
        else cout<<"your ammount must be between $10000.00 and $0.00"<<endl;
        }
        a.allocateInput(inputNum, i);
        b = a;
        size = size++;
        a.reInitPtr(size);
        a = b;
        b.reInitPtr(size);

        if (i == 4)
        {
            break;
        }
        }
    cout << "this is the list of all entered ammounts" << endl;
    a.printPoint(size);
    a.printMean(size);

    return 0;
}
