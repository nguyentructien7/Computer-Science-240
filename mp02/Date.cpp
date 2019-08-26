/*    File: mp02.MaramAlmutairi
 *    Name: Maram Almutairi
 *    Revised: 9-23-2016
 *    Course: CS240 - Introduction to Computing III
 *
 *    Desc: Creating a checking account with provided information using inheritence,
            polymorphism, pointers, and dynamic memory management.
 */
//
//  Date.cpp
//  mp02.MaramAlmutairi
//
//  Created by Maram Almutairi on 9/21/16.
//  Copyright © 2016 Maram Almutairi. All rights reserved.
//

#include "Date.hpp"
#include <ctime>
#include <sstream>
#include <iostream>

using namespace std;

/* Uses the tm structure that represents date/time information. It queries
 * the local system for the time.
 */
Date::Date() {
    time_t now = time(0);
    tm * dt = localtime(&now);
    
    year = 1900 + dt->tm_year;
    month = 1 + dt->tm_mon;
    day = dt->tm_mday;
    
    hour = dt->tm_hour;
    min = dt->tm_min;
    sec = dt->tm_sec;
}// end Date()

Date::~Date() {}// end ~Date()

/* Returns a date/time string in the format yyyy.mm.dd, hh:mm:ss */
string Date::toString() const {
    ostringstream oss;
    
    oss << year << "."
    << month << "."
    << day << ", "
    << hour << ":"
    << min << ":"
    << sec;
    
    return oss.str();
}// end toString()




