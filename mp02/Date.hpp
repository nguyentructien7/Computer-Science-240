/*    File: mp02.MaramAlmutairi
 *    Name: Maram Almutairi
 *    Revised: 9-23-2016
 *    Course: CS240 - Introduction to Computing III
 *
 *    Desc: Creating a checking account with provided information using inheritence,
            polymorphism, pointers, and dynamic memory management.
 */
//
//  Date.hpp
//  mp02.MaramAlmutairi
//
//  Created by Maram Almutairi on 9/21/16.
//  Copyright © 2016 Maram Almutairi. All rights reserved.
//


#ifndef __cppProject__Date__
#define __cppProject__Date__


#include <string>

using namespace std;

class Date {
private:
    int year;
    int month;
    int day;
    int hour;
    int min;
    int sec;
    
public:
    Date();
    virtual ~Date();
    virtual string toString() const;
};

#endif /* defined(__cppProject__Date__) */
