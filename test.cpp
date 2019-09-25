#include<iostream>
#include<string>
using namespace std;

int main(){
    string *monk = new string[1];

    for(int i=0; i<5; i++){
        cout << "input?" <<endl;
        cin >> monk[0];
        cout << monk[0] <<endl;
        //after input
        //delete[] monk;
        //0monk = nullptr;
    }
    return 0;
}