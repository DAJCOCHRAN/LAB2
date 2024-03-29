#include "class.h"
bool decimalCheck(string input);
bool sizeCheck(string input);
bool nonNumericCheck(string input);
double checkChars(string input);

int main()
{
    double inputNum = 0.00;
    string input = "";
    string inputTwo = ""; //useless but needed 
    int size = 1;
    DollarAmount a(size);             //INITIAL AND FINAL OBJECT USAGE             //STORING OBJECT TO STORE A
   SpendingRecord r(size); //uses friend functions
    //SpendingRecord copyRecord(size);
    cout << "Welcome to the expenditure program" << endl;
    cout << "The amount entered should be between $0.00 and $10000.00 in the exact format" << endl;
    for (int i = 0; i < size; i++)
    {
        while (true) //LOOP FOR CHECKING INPUT
        {
            input = a.iO_Pointer();
            if (input == "-1")
                break;
            inputNum = checkChars(input);
            if (inputNum != 0){
                r.iO_Pointer();
                break;
            }
        }
    
        //once validated...
        if(input == "-1")
            break;
        a.allocateInput(i, size); 
        r.allocateExpend(i, size);
        size++;
    }
    cout << "this is the list of all entered ammounts" << endl;
    a.printPoint(size);
    r.printExpend(size);
    r.combineBothInputs(a, size);
    a.printMean(size);

    
    return 0;
}