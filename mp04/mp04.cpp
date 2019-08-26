/* File: mp04.KelseyNguyen
 Name: Kelsey Nguyen
 Revised: 10/21/16
 Course: CS 240 - Introduction to Computing III
 Description: The program is reading the "state" data into seven instances of the States class. Each instance is corresponding
 to the data sorted by one of the seven fields. Displays the order by the user input*/


#include "States.hpp"
#include "LinkedList.hpp"
#include <iostream>
using namespace std;


/* This program will create 7 copies of the state data. Each copy will be sorted by
 * one of the sort fields, and added to the linked list. The linked list will thus
 * contain 7 nodes, each node pointing to a sorted copy of the state data by one
 * of the sort fields.
 *
 * The node order of the sorted arrays is: abbreviation, name, capital, population, area,
 * yearInducted and orderInducted.
 *
 * Although this duplication of data is wasteful, it is at this point an easier
 * implementation, and the total memory requirements are not all that much to begin with.
 *
 * Later in the course we will see more efficient ways to create indices, without
 * duplicating the data itself.
 */

int main() {
    /* Insert your code after each TODO, in the order listed below. */
    
    /* TODO: declare the 7 States instances, one for each field. */
    States *orderOfAbbreviation = new States();
    States *orderOfName = new States();
    States *orderOfCapital = new States();
    States *orderOfPopulation = new States();
    States *orderOfArea = new States();
    States *orderOfYearInducted = new States();
    States *orderOfOrderInducted = new States();
    
    /* TODO: Populate the states objects with the contents of the input file.
     * You will have to read the file seven times.
     */
    orderOfAbbreviation->loadFromFile("states.txt", ',');
    orderOfName->loadFromFile("states.txt", ',');
    orderOfCapital->loadFromFile("states.txt", ',');
    orderOfPopulation->loadFromFile("states.txt", ',');
    orderOfArea->loadFromFile("states.txt", ',');
    orderOfYearInducted->loadFromFile("states.txt", ',');
    orderOfOrderInducted->loadFromFile("states.txt", ',');
    
    
    /* TODO: Create a LinkedList of States instance. */
    LinkedList<States> categorize;
    
    
    /* TODO: Sort each states object. */
    orderOfAbbreviation->sort(Abbreviation);
    orderOfName->sort(Name);
    orderOfCapital->sort(Capital);
    orderOfPopulation->sort(Population);
    orderOfArea->sort(Area);
    orderOfYearInducted->sort(YearInducted);
    orderOfOrderInducted->sort(OrderInducted);
    
    /* TODO: Insert each sorted states object into the linked list at the appropriate index.
     * Use the StateSortField constants to identify the corresponding index.
     */
    categorize.insertAt(Abbreviation, orderOfAbbreviation);
    categorize.insertAt(Name, orderOfName);
    categorize.insertAt(Capital, orderOfCapital);
    categorize.insertAt(Population, orderOfPopulation);
    categorize.insertAt(Area, orderOfArea);
    categorize.insertAt(YearInducted, orderOfYearInducted);
    categorize.insertAt(OrderInducted, orderOfOrderInducted);
    
    
    
    /* TODO: Ask the user which list of data they would like to display. */
    char option = ' ';
    while((option != 'Q')&&(option != 'q'))
    {
        cout << "Select sort field [A]bbreviation, [N]ame, [C]apital, [P]opulation, A[r]ea, [Y]ear Inducted, [O]rder Inducted, [Q]uit: ";
        cin >> option;
        cout<<endl;
        cout<<"Abbreviation   Name             Capital         Population       Area   Year Inducted    Order Inducted"<<endl;
        cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
        if((option == 'A')||(option == 'a'))
        {
            cout << categorize.getAt(Abbreviation)->toString();
        }
        else if((option == 'N')||(option == 'n'))
        {
            cout << categorize.getAt(Name)->toString();
        }
        else if((option == 'C')||(option == 'c'))
        {
            cout << categorize.getAt(Capital)->toString();
        }
        else if((option == 'P')||(option == 'p'))
        {
            cout << categorize.getAt(Population)->toString();
        }
        else if((option == 'R')||(option == 'r'))
        {
            cout << categorize.getAt(Area)->toString();
        }
        else if((option == 'Y')||(option == 'y'))
        {
            cout << categorize.getAt(YearInducted)->toString();
        }
        else if((option == 'O')||(option == 'o'))
        {
            cout << categorize.getAt(OrderInducted)->toString();
        }
        cout<<endl;
    }
    
    cout << endl;
    return 0;
}


