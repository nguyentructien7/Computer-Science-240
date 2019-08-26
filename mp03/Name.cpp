/*
 File:           mp03.MaramAlmutairi
 Name:           Maram Almutairi
 Revised:        Oct 6, 2016
 Course:         CS240-Intro to Computing III
 Description:    Program that makes use of class and function templates, while
                 also using pointers and dynamic memory management.
 Project Requirements:
                 Implement the relational operator methods and <<() function.
                 Update the ArrayList's declaration to reflect the new element type (Name object)
                 Inline implementation.
                 Removal of .cpp file from the project
                 Turn the ArrayList into a template.
 main.cpp
 mp03.MaramAlmutairi
 Created by Maram Almutairi on 10/2/16.
 Copyright © 2016 Maram Almutairi. All rights reserved.
 */

#include "Name.hpp"
#include <sstream>
using namespace std;

Name::Name(const string& first, const string& last) {
    setFirst(first);
    setLast(last);
}// end Name()

/* Destructor. No dynamic memory at this time, but just in
 * case we need it in the future.
 */
Name::~Name() {}// end ~Name()

string Name::getFirst() const { return first;              }// end getFirst()
string Name::getLast() const  { return last;               }// end getLast()
string Name::getName() const  { return first + " " + last; }// end getName()

/* Returns the name formatted as: last delimiter first.
 * This is used for sorting purposes.
 */
string Name::getSortedNameWithDelimiter(const string& delimiter) const { return last + delimiter + first; }// end getSortedNameWithDelimiter()

void Name::setFirst(const string& first) { this->first = first; }// end setFirst()
void Name::setLast(const string& last)   { this->last = last;   }// end setLast()

string Name::toString() const {
    ostringstream oss;
    
    oss << getName();
    
    return oss.str();
}// end toString()

/* the following boolean operations aid in ordering the list of names in alphabetical order
 */

bool Name::operator == (const Name& o) const
{
    return getName() == o.getName() ;
}

bool Name::operator != (const Name& o) const
{
    return getName() != o.getName() ;
}

bool Name::operator <  (const Name& o) const
{
    if(getLast() == o.getLast())
    {
        return (getFirst() < o.getFirst());
    }
    
    return getLast() < o.getLast() ;
}

bool Name::operator <= (const Name& o) const
{
    if(getLast() == o.getLast())
    {
        return (getFirst() <= o.getFirst());
    }
    
    return getLast() <= o.getLast() ;
}

bool Name::operator >  (const Name& o) const
{
    if(getLast() == o.getLast())
    {
        return (getFirst() > o.getFirst());
    }

    return getLast() > o.getLast() ;
}

bool Name::operator >= (const Name& o) const
{
    if(getLast() == o.getLast())
    {
        return (getFirst() >= o.getFirst());
    }

    return getLast() >= o.getLast() ;
}


ostream& operator <<(ostream& out, const Name& o) {
    out << o.toString();
    
    return out;
}// end <<()









