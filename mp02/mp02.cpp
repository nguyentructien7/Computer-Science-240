//
//  main.cpp
/* File: mp02
 Name: Kelsey (Tien) Nguyen
 Revised:   9/24/16
 Course: CS 240 - Introduction to Computing III
 Description: The program output the customer name, bank account information and the date. Uses inheritance, pointer, and polymorphism.

 */


#include "Customer.hpp"
#include "CheckingAccount.hpp"
#include "Bank.hpp"
#include <iostream>


int main() {
        Bank bank;
        
        /* Open three accounts to the Bank. */
        bank.openAccount(new CheckingAccount(Customer("Adam", "Apple")));
        bank.openAccount(new CheckingAccount(Customer("Beatrice", "Bagel")));
        bank.openAccount(new CheckingAccount(Customer("Chris", "Cucumber")));
        
        cout << "Customer list:" << endl;
        bank.listCustomers(cout);
        cout << endl;
        
        cout << "Account list:" << endl;
        bank.listAccounts(cout);
        cout << endl;
        
        cout << "Bank record:" << endl;
        cout << bank.toString() << endl;
        
        return 0;
}// end main()
