/*
 Name:           Maram Almutairi
 File:           mp07.MaramAlmutairi
 Name:           Maram Almutairi
 Revised:        Dec 1, 2016
 Course:         CS240-Intro to Computing III
 Objective:      To implement a recursive version of quick sort using an array
                 To time the algorithm
 
 
 */

#include "State.hpp"
#include <iomanip>
#include <sstream>

using namespace std;


/* Initializes the object. */
State::State(string abbreviation,
             string name,
             string capital,
             int population,
             int area,
             int yearInducted,
             int orderInducted)
:  abbreviation(abbreviation), name(name), capital(capital),
population(population), area(area), yearInducted(yearInducted), orderInducted(orderInducted)
{}// end State()
/*---------------------------------------------------------------------------------*/

/* Returns the state object formatted as follows:
 * Abbreviation, name and capital are left aligned, all others are right aligned. Each field should fit
 * in a column wide enough, to offer left or right alignment.
 *
 * <abbreviation><spc><name><spc><capital><spc><population><spc><area><spc><yearInducted><spc><orderInducted>
 */
string State::toString() const {
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
    << setw(14) << orderInducted;
    
    return oss.str();
    
}// end toString()
/*---------------------------------------------------------------------------------*/

/* Equality means each corresponding property is the same. */
bool State::operator == (const State& o) const { return toString() == o.toString(); }// end ==()
bool State::operator != (const State& o) const { return !(*this == o);              }// end !=()

/* Ordering is determined on first corresponding property pair that is different. */
bool State::operator <  (const State& o) const { return toString() < o.toString(); }// end <()
bool State::operator <= (const State& o) const { return !(*this > o);              }// end <=()
bool State::operator >  (const State& o) const { return o < *this;                 }// end >()
bool State::operator >= (const State& o) const { return !(*this < o);              }// end
/*---------------------------------------------------------------------------------*/

/* Operator to display a State object to the screen. Calls the o.toString(). */
ostream& operator <<(ostream& out, const State& o) {
    out << o.toString();
    
    return out;
}// end <<()
/*---------------------------------------------------------------------------------*/



