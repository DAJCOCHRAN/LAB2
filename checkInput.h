//MAIN FUNCTION IS AT THE BOTTOM OF THE PROGRAM
#include"header.h"

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

        if (input[i] == '.' && input[i+3] != '\0'){
            cout << "your have too many decimal places being used, only use two!! Try again!" << endl;
            return false;
        }

        if ((input[i] == '.' && input[i+2] == '\0') || (input[i] == '.' && input[i+1] == '\0')){
            cout << "you have a decimal, but no decimal number after decimal point... Try again!" << endl;
            return false;
        }
    }
    if (decCount == 0)
    {
        cout << "No decimals! Invalid Format! try agian!!" << endl;
        return false;
    }

    else if(decCount >= 2){
        cout << "Too many decimals, Invalid Format! try again!!" << endl;
    }
    else
        return true;
}

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

string sayHundredThousandOnes(int integer){
    switch(integer){
        case 1: return "One";
        case 2: return "Two";
        case 3: return "Three";
        case 4:  return "Four";
        case 5: return "Five";
        case 6: return "Six";
        case 7: return "Seven";
        case 8: return "Eight";
        case 9: return "Nine";
    }
}
//DOES NOT WORK FOR 11 --> 
string sayTens(int integer){
    switch(integer){
        case 2: return "Twenty";
        case 3: return "Thirty";
        case 4: return "Fourty";
        case 5: return "Fifty";
        case 6: return "Sixty";
        case 7: return "Seventy";
        case 8: return "Eighty";
        case 9: return "Ninety";
    }
}
//ensure entire integer is pulled for remaining dollar ammount
string sayTeens(int integer){
    switch(integer){
        case 10: return "Ten";
        case 11: return "Eleven";
        case 12: return "Twelve";
        case 13: return "Thirteen";
        case 14:  return "Fourteen";
        case 15: return "Fifteen";
        case 16: return "Sixteen";
        case 17: return "Seventeen";
        case 18: return "Eighteen";
        case 19: return "Nineteen";
    }
}

double checkChars(string input)
{
    if (sizeCheck(input) == 0)
        return 0;
    //count decimals
    else if (decimalCheck(input) == 0)
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
    else return 0;
}

string sayDollar(int dollar)
{
    string saidNumber = "";
    int removePlace = 0;
    string dollarAmount = "";

    if(dollar == 0){
        dollarAmount.append("Zero Dollars");
        return dollarAmount;
    }
    
    if ((dollar/1000) >= 1){
        removePlace = (dollar/1000);
        saidNumber = sayHundredThousandOnes(removePlace);
        dollarAmount.append(saidNumber + " Thousand");
        removePlace *= 1000;
        dollar -= removePlace;
        if(dollar == 0){
            return (dollarAmount + " Dollars");
        }
    }

    if ((dollar/100) >= 1){
        removePlace = (dollar/100);
        saidNumber = sayHundredThousandOnes(removePlace);
        dollarAmount.append(" " + saidNumber + " Hundred");
        removePlace *= 100;
        dollar -= removePlace;
        if(dollar == 0){
            return (dollarAmount + " Dollars");
        }
    }
    if (dollar >= 20){
        removePlace = (dollar/10);
        saidNumber = sayTens(removePlace);
        removePlace *= 10;
        dollarAmount.append(" " + saidNumber);
        dollar -= removePlace;
        if(dollar == 0){
            return (dollarAmount + " Dollars");
        }
    }

    if (dollar >= 10 && dollar <=19 ){
        saidNumber = sayTeens(dollar);
        dollarAmount.append(" " + saidNumber);
        return (dollarAmount + " Dollars");
    }

    if (dollar <=9 ){
        saidNumber = sayHundredThousandOnes(dollar);
        dollarAmount.append(" " + saidNumber);
        dollar = 0;
    }

    if(dollar == 0){
        dollarAmount.append(" Dollars");
        return dollarAmount;
    }
}

string sayCent(int cent){
    string saidCent = "", centAmount = "";
    int removePlace = 0;
    //if cents is initialy zero
    if (cent == 0){
        saidCent.append(" Zero Cents");
        return saidCent;
    }
    if(cent >= 20){
        removePlace = (cent/10);
        saidCent = sayTens(removePlace);
        centAmount.append(" " + saidCent);
        removePlace *= 10;
        cent -= removePlace;
        if(cent == 0){
            return (centAmount + " Cents");
        }
    }
    if(cent <= 19 && cent >= 10){
        saidCent = sayTeens(cent);
        centAmount.append(" " + saidCent);
        return (centAmount + " Cents");
    }
    if(cent <= 9){
        saidCent = sayHundredThousandOnes(cent);
        centAmount.append(" " + saidCent);
        return (centAmount + " Cents");
    }
    if(cent == 0){
        centAmount.append(" Cents");
        return centAmount;
    }
}

int main()
{
    double verifiedInput = 0;
    string input;

     
    while (verifiedInput == 0)
    {
        cout << "what is the number?" << endl << "$ ";
        cin >> input;
        verifiedInput = checkChars(input);
    }
    //get only the dollar ammount
    int verifiedDollars = verifiedInput;
    //take away dollar amount to get cent amount
    double verifiedCents = verifiedInput - verifiedDollars;
    verifiedCents *= 100;

    //get the dollars and the cents seperated
    //verifiedCents = modf(verifiedInput, &verifiedDollars);
    //verifiedCents *= 100;

    //say the word!!
    string saidDollars = sayDollar(verifiedDollars);
    string saidCent = sayCent(verifiedCents);
    cout << saidCent << endl;
    cout << "The ammount is " << saidDollars << " and" << saidCent <<endl;
    //divisible game to say what it is
    

    return 0;
}
