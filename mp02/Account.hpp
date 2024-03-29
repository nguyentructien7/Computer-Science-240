/*    File: mp02.MaramAlmutairi
 *    Name: Maram Almutairi
 *    Revised: 9-23-2016
 *    Course: CS240 - Introduction to Computing III
 *
 *    Desc: Creating a checking account with provided information using inheritence,
            polymorphism, pointers, and dynamic memory management.
 */
//
//  Account.hpp
//  mp02.MaramAlmutairi
//
//  Created by Maram Almutairi on 9/21/16.
//  Copyright © 2016 Maram Almutairi. All rights reserved.
//

#ifndef __cppProject__Account__
#define __cppProject__Account__

#include "Customer.hpp"
#include <string>

using namespace std;


class Account {
private:
    string dateOpened;
    Customer owner;
    
public:
    /* The ctor assigns the owner and sets the date to the current
     * date. You will use the Date() class for this.
     */
    Account(const Customer& owner);
    
    /* The dtor does nothing for the Account. However, since the class is abstract it
     * must be virtual so subclass objects can be deleted automatically.
     */
    virtual ~Account();
    
    virtual string getDateOpened() const final;
    virtual Customer getOwner() const final;
    
    /* Do not provide an implementation in Account. This is a true abstract method. */
    virtual string toString() const =0;
};

#endif /* defined(__cppProject__Account__) */
