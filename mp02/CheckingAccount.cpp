/*    File: mp02.MaramAlmutairi
 *    Name: Maram Almutairi
 *    Revised: 9-23-2016
 *    Course: CS240 - Introduction to Computing III
 *
 *    Desc: Creating a checking account with provided information using inheritence,
            polymorphism, pointers, and dynamic memory management.
 */
//
//  CheckingAccount.cpp
//  mp02.MaramAlmutairi
//
//  Created by Maram Almutairi on 9/21/16.
//  Copyright © 2016 Maram Almutairi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <sstream>

#include "CheckingAccount.hpp"

CheckingAccount::CheckingAccount(const Customer& owner) : Account(owner)
{
    this->accountNumber = 90000 + (int)(rand()%10000);
    
}

int CheckingAccount::getAccountNumber() const
{
    return this->accountNumber;
}


string CheckingAccount::toString() const
{
    ostringstream oss;
    oss << "        [" << getAccountNumber() << "][" << getDateOpened() << "][";
    
    const char *owner = this->getOwner().getName().c_str();
    int at = 0; //start at the beginning
    while(owner[at] == ' ')
    {
        at++;
    }
    
    //from now we have skipped all the space & can print until the end of the string
    while(owner[at] != '\0')
    {
        oss << owner[at];
        at++;
    }
    
    oss << "]";
    return oss.str();
}
