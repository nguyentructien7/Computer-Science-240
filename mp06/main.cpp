/*
 File:           mp06
 Name:           Kelsey (Tien) Nguyen
 Revised:        Nov 18, 2016
 Course:         CS240-Intro to Computing III
 Objective:      To implement a recursive version of quick sort using an array
 To time the algorithm
 */

#include "States.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

/*--------------------------------------------------------------------------------------------------*/
int main() {
    States states("states.txt", ',');
    
    char key;
    
    cout << "Choose option [A]bbreviation, [N]ame, [C]apital, [P]opulation, A[r]ea, [Y]ear Inducted, [O]rder Inducted, [Q]uit: ";
    
    cin >> key;
    key = toupper(key);

    //displays requested information based on user input
    while (key != 'Q') {
        
        cout<<"Abbreviation   Name             Capital            Population       Area   Year Inducted   Order Inducted"<<endl;
        cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
        switch (key) {
            case 'A':   states.listByAbbreviation();  break;
            case 'N':   states.listByName();          break;
            case 'C':   states.listByCapital();       break;
            case 'P':   states.listByPopulation();    break;
            case 'R':   states.listByArea();          break;
            case 'Y':   states.listByYearInducted();  break;
            case 'O':   states.listByOrderInducted(); break;
        }
        
        cout << endl << endl;
        cout << "Choose option [A]bbreviation, [N]ame, [C]apital, [P]opulation, A[r]ea, [Y]ear Inducted, [O]rder Inducted, [Q]uit: ";
        cin >> key;
        key = toupper(key);
    }
    
    cout << "Program ended successfully." << endl << endl;
    return 0;
}// end main()
