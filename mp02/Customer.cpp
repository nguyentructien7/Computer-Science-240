/*    File: mp02.MaramAlmutairi
 *    Name: Maram Almutairi
 *    Revised: 9-23-2016
 *    Course: CS240 - Introduction to Computing III
 *
 *    Desc: Creating a checking account with provided information using inheritence,
            polymorphism, pointers, and dynamic memory management.
 */
//
//  Customer.cpp
//  mp02.MaramAlmutairi
//
//  Created by Maram Almutairi on 9/21/16.
//  Copyright © 2016 Maram Almutairi. All rights reserved.
//

#include "Customer.hpp"
#include <sstream>

using namespace std;


        
Customer::Customer(const string& first, const string& last)
{
    setFirst(first);
    setLast(last);
}

//getters
string Customer::getFirst() const
{
    return this->first;
}

string Customer::getLast() const
{
    return this->last;
}

string Customer::getName() const
{
    return "        " + this->last + ", " + this->first;
}

//setters
void Customer::setFirst(const string& first)
{
    this->first = first;
}

void Customer::setLast(const string& last)
{
    this->last = last;
}

string Customer::toString() const
{
    ostringstream oss;
    oss << getName();
    return oss.str();
}




