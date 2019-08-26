/*
 Name:           Maram Almutairi
 File:           mp07.MaramAlmutairi
 Name:           Maram Almutairi
 Revised:        Dec 1, 2016
 Course:         CS240-Intro to Computing III
 Objective:      To implement a recursive version of quick sort using an array
                 To time the algorithm
 
 
 */

#ifndef State_hpp
#define State_hpp

#include <string>
#include <sstream>
using namespace std;


/*---------------------------------------------------------------------------------*/
/* Class: State
 * This class stores information on a State.
 * Only the constructor is used, so properties remain private. Simplification
 * is the reason for that.
 */
class State {
private:
    string abbreviation;
    string name;
    string capital;
    int population;
    int area;
    int yearInducted;
    int orderInducted;
    
public:
    
    /* Initializes the object. */
    State(string abbreviation = "",
          string name = "",
          string capital = "",
          int population = 0,
          int area = 0,
          int yearInducted = 0,
          int orderInducted = 0);
    
    /* Returns the state object formatted as follows:
     * Abbreviation, name and capital are left aligned, all others are right aligned. Each field should fit
     * in a column wide enough, to offer left or right alignment.
     *
     * <abbreviation><spc><name><spc><capital><spc><population><spc><area><spc><yearInducted><spc><orderInducted>
     */
    string toString() const;
    
    /* Equality means each corresponding property is the same. */
    virtual bool operator == (const State& o) const;
    virtual bool operator != (const State& o) const;
    
    /* Ordering is determined on first corresponding property pair that is different. */
    virtual bool operator <  (const State& o) const;
    virtual bool operator <= (const State& o) const;
    virtual bool operator >  (const State& o) const;
    virtual bool operator >= (const State& o) const;
    
}; // end State
/*---------------------------------------------------------------------------------*/

/* Operator to display a State object to the screen. Calls the o.toString(). */
ostream& operator <<(ostream& out, const State& o);

#endif /* State_hpp */
