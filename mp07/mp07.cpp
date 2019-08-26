/* File: mp07
 Name: Kelsey (Tien) Nguyen
 Revised: 1/3/16
 Course: CS 240 - Introduction to Computing III
 Description:The program is the same as project, mp04 and mp06 but using heap to sort.*/

#include <fstream>
#include <string>
#include <iostream>
#include "Heap.hpp"
#include "State.hpp"

using namespace std;


/* Loads the states heap from the file. */
void loadFromFile(Heap<State>& states, const string& filename, const char delimiter);
bool didConnectToFile(ifstream& fin, const string& filename);


 
int main() {
    
    Heap<State> states;
    
    /* Load the data into the heap. */
    loadFromFile(states, "states.txt", ',');
    
    /* List the original heap. */
    cout  << "Original heap:"
    << endl
    << states
    << endl;
    
    /* Sort the heap. */
    states.sort();
    
    /* List the sorted heap. */
    cout  << "Sorted heap:"
    << endl
    << states
    << endl;
    
    return 0;
}// end main()

/* Reads from the specified file and loads the states linked list. The delimiter
 * identifies the character delimiting each field in the file.
 */
void loadFromFile(Heap<State>& states, const string& filename, const char delimiter) {
    ifstream fin;
    
    if ( !didConnectToFile(fin, filename) ) {
        cerr << "Error: Unable to open file." << endl;
        exit(1);
    }
    
    string abbreviation;
    string name;
    string capital;
    
    string populationString;
    string areaString;
    string yearInductedString;
    string orderInductedString;
    
    getline(fin, abbreviation, delimiter);
    while ( !fin.eof() ) {
        
        getline(fin, name, delimiter);
        getline(fin, capital, delimiter);
        getline(fin, populationString, delimiter);
        getline(fin, areaString, delimiter);
        getline(fin, yearInductedString, delimiter);
        getline(fin, orderInductedString);
        
        /* Insert into the heap at this point */
        states.insert( State(abbreviation,
                             name,
                             capital,
                             stoi(populationString),
                             stoi(areaString),
                             stoi(yearInductedString),
                             stoi(orderInductedString)
                             )
                      );
        
        getline(fin, abbreviation, delimiter);
    }
    
    fin.close();
    
}// loadFromFile()
/*----------------------------------------------------------------------------------*/

/* Returns true if file was connected to. */
bool didConnectToFile(ifstream& fin, const string& filename) {
    fin.open(filename);
    
    return ( fin.is_open() );
}// end didConnectToFile()
/*----------------------------------------------------------------------------------*/


