/*
 File:           mp06.MaramAlmutairi
 Name:           Maram Almutairi
 Revised:        Nov 18, 2016
 Course:         CS240-Intro to Computing III
 Objective:      To implement a recursive version of quick sort using an array
 To time the algorithm
 */

#include "States.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;

const int NUMBER_OF_STATES = 50;
/* Initializes the object with empty strings ("") and 0's. */
States::State::State(string abbreviation, string name, string capital,
                     int population, int area, int yearInducted, int orderInducted)
: abbreviation(abbreviation), name(name), capital(capital),
population(population), area(area), yearInducted(yearInducted), orderInducted(orderInducted)
{}// end State()
/*---------------------------------------------------------------------------------*/

/* Returns the state object formatted as follows:
 * Abbreviation, name and capital are left aligned, all others are right aligned. Each field should fit
 * in a column wide enough, to offer left or right alignment.
 *
 * <abbreviation><spc><name><spc><capital><spc><population><spc><area><spc><yearInducted><spc><orderInducted>
 */
string States::State::toString() const {
    ostringstream oss;
    int colSpace = 3;
    
    oss   << left
    << setw(12) << abbreviation
    << setw(colSpace) << " "
    << setw(14) << name
    << setw(colSpace) << " "
    << setw(14) << capital
    << setw(colSpace) << " "
    << right
    << setw(12) << population
    << setw(colSpace) << " "
    << setw(8) << area
    << setw(colSpace) << " "
    << setw(13) << yearInducted
    << setw(colSpace) << " "
    << setw(14) << orderInducted
    << endl;
    
    return oss.str();
    
}// end toString()
/*---------------------------------------------------------------------------------*/

/* Equality means each corresponding property is the same. */
bool States::State::operator == (const State& o) const { return toString() == o.toString(); }// end ==()
bool States::State::operator != (const State& o) const { return !(*this == o);              }// end !=()

/* Ordering is determined on first corresponding property pair that is different. */
bool States::State::operator <  (const State& o) const { return toString() < o.toString(); }// end <()
bool States::State::operator <= (const State& o) const { return !(*this > o);              }// end <=()
bool States::State::operator >  (const State& o) const { return o < *this;                 }// end >()
bool States::State::operator >= (const State& o) const { return !(*this < o);              }// end
/*---------------------------------------------------------------------------------*/


/* Reads from the specified file and loads the states linked list. The delimiter
 * identifies the character delimiting each field in the file.
 */
void States::loadFromFile(const string& filename, const char delimiter) {
    // TODO: Implement
     ifstream in;
     if(didConnectToFile(in, filename))
     {
         string line;
         for(int i=0;i<NUMBER_OF_STATES;i++)
         {
            getline(in, line);
             State *nextState = new State();
             stringstream ss;
             ss.str(line);
             for(int i=0;i<7;i++)
             {
                string item;
                 getline(ss, item, delimiter);
                 if(i == 0)
                     nextState->abbreviation = item;
                 else if(i == 1)
                     nextState->name = item;
                 else if(i == 2)
                     nextState->capital = item;
                 else if(i == 3)
                     nextState->population = stoi(item);
                 else if(i == 4)
                     nextState->area = stoi(item);
                 else if(i == 5)
                     nextState->yearInducted = stoi(item);
                 else if(i == 6)
                     nextState->orderInducted = stoi(item);
             }

            states.insert(nextState);
            // cout << "Loaded " << nextState->name << endl;
        }
     }
     else{
         cout << "FILE NOT FOUND" << endl;
     }
}// loadFromFile()
     /*----------------------------------------------------------------------------------*/
    
    bool States::didConnectToFile(ifstream& fin, const string& filename) {
        fin.open(filename);
        
        return ( fin.is_open() );
    }// end didConnectToFile()
    /*----------------------------------------------------------------------------------*/
    
    /* The constructor loads the linked list from the file, and builds the seven
     * binary search tree objects, by traversing the linked list only once.
     */
    States::States(const string& filename, const char delimiter) {
        /* TODO: Implement */
        //cout << "LOADING" << endl;
        loadFromFile(filename, delimiter);
        
        
        for(int i=0;i<NUMBER_OF_STATES;i++)
        {
            State *next = states.getAt(i);
            
            StateIndex<string> nextAbbIndex(next->abbreviation, next);
            abbreviationBst.insert(nextAbbIndex);
            
            StateIndex<string> *nextNameIndex = new StateIndex<string>(next->name, next);
            nameBst.insert(*nextNameIndex);

            
            StateIndex<string> *nextCapitalIndex = new StateIndex<string>(next->capital, next);
            capitalBst.insert(*nextCapitalIndex);

            
            StateIndex<int> *nextPopIndex = new StateIndex<int>(next->population, next);
            populationBst.insert(*nextPopIndex);
            

            StateIndex<int> *nextAreaIndex = new StateIndex<int>(next->area, next);
            areaBst.insert(*nextAreaIndex);


            StateIndex<int>nextInductedBst(next->yearInducted, next);
            yearInductedBst.insert(nextInductedBst);
            

            StateIndex<int>nextOrderBst(next->orderInducted, next);
            orderInductedBst.insert(nextOrderBst);
        }
        
        
    }//end States()
    /*----------------------------------------------------------------------------------*/
    
    
    /*----------------------------------------------------------------------------------*/
    
    /* Returns the state at the specified index. */
    States::State * States::getAt(const int index) {
        return states.getAt(index);
    }// end getAt()
    /*----------------------------------------------------------------------------------*/
    
    /* Returns a string with the current contents of the array formatted as follows:
     * Abbreviation<spc>Name<spc>Capital<spc>Population<spc>Area<spc>Year Inducted<spc>Order Inducted
     * ----------------------------------------------------------------------------------------------
     * <abbreviation><spc><name><spc><capital><spc><population><spc><area><spc><yearInducted><spc><orderInducted>
     * ...
     *
     * Note: the fields <abbreviation>,<name> and <capital> are left aligned, the others right aligned.
     */
    string States::toString() const {
        ostringstream oss;
        int colSpace = 3;
        
        oss   << left
        << setw(12) << "Abbreviation"
        << setw(colSpace) << " "
        << setw(14) << "Name"
        << setw(colSpace) << " "
        << setw(14) << "Capital"
        << setw(colSpace) << " "
        << right
        << setw(12) << "Population"
        << setw(colSpace) << " "
        << setw(8) << "Area"
        << setw(colSpace) << " "
        << setw(13) << "Year Inducted"
        << setw(colSpace) << " "
        << setw(14) << "Order Inducted"
        << endl
        << setfill('-')
        << setw(105) << "-"
        << setfill(' ')
        << endl;
        
        /* TODO: list each state by calling each State's toString() method. */
        
        return oss.str();
    }// end toString()
    /*----------------------------------------------------------------------------------*/
    
    /* Equality means each corresponding state element is the same. */
    bool States::operator == (const States& o) const {
        
        return false;
    }// end ==()
    /*----------------------------------------------------------------------------------*/
    
    bool States::operator != (const States& o) const { return !(*this == o); }// end !=()
    /*----------------------------------------------------------------------------------*/
    
    /* Ordering is determined on first corresponding state pair that is different. */
    bool States::operator <  (const States& o) const {
        
        return false;
    }// end <()
    /*----------------------------------------------------------------------------------*/
    
    bool States::operator <= (const States& o) const { return !(*this > o); }// end <=()
    bool States::operator >  (const States& o) const { return o < *this;    }// end >()
    bool States::operator >= (const States& o) const { return !(*this < o); }// end >=()
    /*----------------------------------------------------------------------------------*/
    
    /* Methods that list the states in the specified order. Each method uses the corresponding
     * index tree to access the states in the linked list in order.
     */
    void States::listByAbbreviation() const {
        abbreviationBst.inorder(&display);
    }// end listByAbbreviation()
    
    void States::listByName() const {
        nameBst.inorder(&display);
    }// end listByName()
    
    void States::listByCapital() const {
        capitalBst.inorder(&display);
    }// end listByCapital()
    
    void States::listByPopulation() const {
        populationBst.inorder(&display);
        
    }// end listByPopulation()
    
    void States::listByArea() const {
        areaBst.inorder(&display);
    }// end listByArea()
    
    void States::listByYearInducted() const {
        yearInductedBst.inorder(&display);
    }// listByYearInducted()
    
    void States::listByOrderInducted() const {
        orderInductedBst.inorder(&display);
    }// end listByOrderInducted()
    /*---------------------------------------------------------------------------------*/
    
    ostream& operator <<(ostream& out, const States::State& o) {
        out << o.toString();
        
        return out;
    }// end <<()
    /*---------------------------------------------------------------------------------*/
    
    ostream& operator <<(ostream& out, const States& o) {
        out << o.toString();
        
        return out;
    }// end <<()
    /*---------------------------------------------------------------------------------*/
