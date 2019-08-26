/*    File: mp02.MaramAlmutairi
 *    Name: Maram Almutairi
 *    Revised: 9-23-2016
 *    Course: CS240 - Introduction to Computing III
 *
 *    Desc: Creating a checking account with provided information using inheritence,
            polymorphism, pointers, and dynamic memory management.
 */
//
//  Account.cpp
//  mp02.MaramAlmutairi
//
//  Created by Maram Almutairi on 9/21/16.
//  Copyright © 2016 Maram Almutairi. All rights reserved.
//

#include "Account.hpp"
#include "Date.hpp"


Account::Account(const Customer& owner)
{
    this->owner = owner;
    Date rightNow;
    this->dateOpened = rightNow.toString();
}

Account::~Account() {}// end ~Name()


//getters
Customer Account::getOwner() const
{
    return this->owner;
}

string Account::getDateOpened() const
{
    return this->dateOpened;
}


