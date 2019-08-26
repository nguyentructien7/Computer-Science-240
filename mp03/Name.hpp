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

#ifndef Name_hpp
#define Name_hpp

#include <string>
using namespace std;

class Name {
private:
    string first;
    string last;
    
public:
    Name(const string& first = "", const string& last = "");
    
    /* Destructor. No dynamic memory at this time, but just in
     * case we need it in the future.
     */
    virtual ~Name();
    
    virtual string getFirst() const final;
    virtual string getLast() const final;
    virtual string getName() const final;
    
    /* Returns the name formatted as: <last><delimiter><first>.
     * This is used for sorting purposes.
     */
    virtual string getSortedNameWithDelimiter(const string& delimiter) const final;
    
    virtual void setFirst(const string& first) final;
    virtual void setLast(const string& last) final;
    
    virtual string toString() const;
    
    /* The sorted name is used for all comparisons */
    
    virtual bool operator == (const Name& o) const;
    virtual bool operator != (const Name& o) const;
    virtual bool operator <  (const Name& o) const;
    virtual bool operator <= (const Name& o) const;
    virtual bool operator >  (const Name& o) const;
    virtual bool operator >= (const Name& o) const;
};

/* This operator function simply calls the toString(). */
ostream& operator <<(ostream& out, const Name& name);

#endif /* Name_hpp */





