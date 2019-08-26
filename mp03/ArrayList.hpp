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

#ifndef ArrayList_hpp
#define ArrayList_hpp

#include <string>
#include <sstream>
#include <iostream>
#include "Name.hpp"

using namespace std;

template <class T>
class ArrayList {
private:
    /*----------------------------------------------------------------------------------*/
    T * array;      // Dynamic array of Name * elements.
    int size;
    /*----------------------------------------------------------------------------------*/
    
    /* Resizes the array by 1. */
    void resize(){
        
        try {
            // 1) allocate new array
            T * temp = createArray(size + 1);
            
            // 2) preserve old
            for (int i = 0; i <= size - 1; i += 1) {
                temp[i] = array[i];
            }
            
            // 3) release old
            delete [] array;
            
            // 4) reassign
            array = temp;
            
            // 5) reset
            temp = nullptr;
            size += 1;
            
        } catch (bad_alloc ba) {
            cerr << ba.what() << endl;
            exit(1);
        }
        
    }// end resize()
    
    /* Duplicates all the elements of the parameter object to the newly created one. */
    void duplicateElements(const ArrayList& o){
        size = o.size;
        array = createArray(size);
        
        for(int i = 0; i <= size - 1; i += 1) {
            array[i] = T(o.array[i]);
        }
    }// end copyElements()
    
    /* Releases all the elements of the array first, then the array itself. */
    void releaseElements(){
        
        /* Release the array. */
        delete [] array;
        
        /* Clean up */
        array = nullptr;
        size = 0;
    }// end releaseElements()

    
    /* Returns a dynamically allocated Name * * object. Throws a bad_alloc exception
     * if it fails to allocate the needed memory.
     */
    T * createArray(const int newSize) {
        return new Name [newSize];
    }// end createArray()
    /*----------------------------------------------------------------------------------*/
    
public:
    /* Sets the size to 0 and items to nullptr. */
    ArrayList() : size(0), array(nullptr) {
    }// end ArrayList()
    
    /* The structural requirements of any class using dynamic memory allocation.
     * 1) destructor - avoids memory leaks
     * 2) copy constructor - makes a deep copy of the object
     * 3) assignment operator =() - makes a deep copy of assigned object
     */
    
    /* 1) Destructor
     * Releases all the dynamically allocated elements, then the array itself.
     */
    virtual ~ArrayList(){
        releaseElements();
    }// end ~ArrayList()

    
    /* 2) Copy constructor
     * Makes a duplicate of the parameter object o.
     */
    ArrayList(const ArrayList& o){
        duplicateElements(o);
    }// end ArrayList()
    
    /* 3) Overload =()
     * Makes a duplicate of the assigned object o
     */
    virtual const ArrayList& operator =(const ArrayList& o) final {
        if (this != &o) {
            releaseElements();
            duplicateElements(o);
        }
        
        return *this;
    }// end =()
    /*----------------------------------------------------------------------------------*/
    
    /* Returns the size of the array list. */
    virtual int getSize() const final{
        return size;
    }// end getSize()
    
    /* Returns the item at the specified index. */
    virtual T getAt(const int index) const final{
        
        if (index >= 0 && index <= size - 1) {
            return array[index];
            
        } else if (array == nullptr) {
            throw logic_error("Error: Empty array");
            
        } else {
            throw logic_error("Error: index out of bounds");
        }
    }// end getAt()
    
    /* Returns the item at index 0. */
    virtual T get() const final{
        if (array == nullptr) {
            throw logic_error("Error: Empty array");
        }
        
        return array[0];
    }// end get()
    
    /* Inserts the name at the specified index.
     * The array is first resized by 1 to accommodate the new value.
     */
    virtual void insertAt(const int index, T const name) final{
        resize();
        
        for (int i = size - 2; i >= index; i -= 1) {
            array[i + 1] = array[i];
        }
        
        array[index] = name;
    }// end insertAt()
    
    /* Inserts the name at the end of the array.
     * The array is first resized by 1 to accommodate the new value.
     */
    virtual void insert(T const name) final{
        resize();
        
        array[size - 1] = name;
        
    }// end insert()
    
    /* Will return the object formatted as:
     * [
     *  name1
     *  name2
     *  ...
     *  nameN
     * ]
     */
    virtual string toString() const{
        ostringstream oss;
        
        oss << "[" << endl;
        
        for (int i = 0; i <= size - 1; i += 1) {
            oss<<"       ";
            oss << array[i].getName() << endl;
        }
        
        oss << "]";
        
        return oss.str();
    }// end toString()

    /*----------------------------------------------------------------------------------*/
    
    /* Overloaded operators */
    
    /* Returns the address of the element at the specified index. The operator will
     * validate the index for proper range and return a logic_error exception if
     * the index is out of bounds.
     *
     * The return type is always a reference to the array element type.
     */
    virtual T & operator [] (const int index) const final{
        if (index >= 0 && index <= size - 1) {
            return array[index];
            
        } else {
            throw logic_error("Error: index out of bounds");
        }
    }// end []()
    
    
    /* Equality means the size is the same, and eah corresponding element is the same. */
    virtual bool operator == (const ArrayList& o) const{
        bool equal = size == o.size;
        
        if (equal) {
            string thisName;
            string thatName;
            
            int i = 0;
            //      for (int i = 0; i <= size - 1; i += 1) {
            while (equal) {
                thisName = array[i].getName();
                thatName = o.array[i].getName();
                
                equal = equal &&  thisName == thatName;
                i += 1;
            }
        }
        return equal;
    }// end ==()
    
    virtual bool operator != (const ArrayList& o) const { return !(*this == o); }// end !=();
    
    /* The ordering opearators are based on size alone. */
    virtual bool operator <  (const ArrayList& o) const{ return size < o.size ; }// end <()

    virtual bool operator <= (const ArrayList& o) const{ return size <= o.size ; }// end <=()

    virtual bool operator >  (const ArrayList& o) const{ return size > o.size ; }// end >()

    virtual bool operator >= (const ArrayList& o) const{ return size >= o.size ; }// end >=()

    /*----------------------------------------------------------------------------------*/

    
    friend ostream& operator <<(ostream& out, const ArrayList& o)
    {
        out << o.toString();
        
        return out;
    }// end <<();

}; // end ArrayList

#endif /* ArrayList_hpp */








