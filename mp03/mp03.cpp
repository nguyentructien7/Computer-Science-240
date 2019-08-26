/* File: mp03
 Name: Kelsey (Tien) Nguyen
 Revised: 10/5/16
 Course: CS 240 - Introduction to Computing III
 Description: Rewrite the ArrayList then change Name * elements to Name elements. Then convert ArrayList class to a template and implement the <<() function as a template. The project requirement is to complete the implementation of the Name class, Update the interface file for the ArrayList class, Implement the class inline, Remove the ArrayList implementation file from the project, then make the ArrayList class into a template.
 */

#include <iostream>
#include "ArrayList.hpp"
#include "Name.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    ArrayList<Name> list;
    
    list.insert(Name("Johny", "Appleseed"));
    list.insert(Name("Tobby", "Appleseed"));
    list.insert(Name("Mary", "Appleseed"));
    
    list[0] = Name("John", "Smith");
    
    cout << "Original list: " << list << endl;
    
    Name name = list.get();
    
    cout << "First name: " << name << endl;
    
    cout  << "Is John Smith before Tobby Appleseed alphabetically? "
    << ( list.getAt(0) < list.getAt(1)? "Yes" : "No" )
    << endl
    << endl;
    

    ArrayList<Name> copyList(list);
    copyList[0] = Name("Mary", "Poppins");
    
    cout  << "Copy list: " << copyList << endl << endl
    << "Original list: "  <<list << endl << endl;
    return 0;
    
}// end main()
