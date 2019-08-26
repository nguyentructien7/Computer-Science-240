/*    File: mp02.MaramAlmutairi
 *    Name: Maram Almutairi
 *    Revised: 9-23-2016
 *    Course: CS240 - Introduction to Computing III
 *
 *    Desc: Creating a checking account with provided information using inheritence,
            polymorphism, pointers, and dynamic memory management.
 */
//
//  Bank.cpp
//  mp02.MaramAlmutairi
//
//  Created by Maram Almutairi on 9/21/16.
//  Copyright © 2016 Maram Almutairi. All rights reserved.
//

#include <sstream>
#include "Bank.hpp"

using namespace std;

Bank::Bank()
{
    this->accountCount = 0;
    for(int i=0;i<MAX_ACCOUNTS;i++)
    {
        this->accounts[i] = nullptr;
    }
}

//destructor
Bank::~Bank()
{
    for(int i=0;i<getAccountCount();i++)
    {
        delete this->accounts[i];
        this->accounts[i] = nullptr;
    }
    accountCount = 0;
}


Customer Bank::getCustomerAtIndex(const int index) const
{
    return this->accounts[index]->getOwner();
}

/* Returns the CheckingAccount object at the specified index. */
Account * Bank::getAccountAtIndex(const int index) const
{
    return this->accounts[index];
}

int Bank::getAccountCount() const
{
    return this->accountCount;
}

void Bank::openAccount(Account* const o)
{
    this->accounts[accountCount] = o;
    accountCount++;
}

/* Lists the customer portion of the Account objects. */
void Bank::listCustomers(ostream& out)
{
    for(int i=0;i<accountCount;i++)
    {
        out << getAccountAtIndex(i)->getOwner().toString() << endl;
    }
    
}

/* Lists the Account in its entirety. */
void Bank::listAccounts(ostream& out)
{
    for(int i=0;i<accountCount;i++)
    {
        out << getAccountAtIndex(i)->toString() << endl;
    }
}

//list accounts
string Bank::toString() const
{
    ostringstream oss;
    oss << "Count: " << accountCount << endl;
    for(int i=0;i<accountCount;i++)
    {
        
        oss << "        (" << (i+1) << ")";
        
        
        //account has a bunch of _____ space at the beginning
        //we already put in space before the account (1)(2) etc so we want to skip the extra space
        const char *acct = getAccountAtIndex(i)->toString().c_str();
        int at = 0; //start at the beginning
        while(acct[at] == ' ')
        {
            at++;
        }

        //from now we have skipped all the space & can print until the end of the string
        while(acct[at] != '\0')
        {
            oss << acct[at];
            at++;
        }
        oss << endl;
    }
    return oss.str();

}




