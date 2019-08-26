/*
 Name:           Maram Almutairi
 File:           mp07.MaramAlmutairi
 Name:           Maram Almutairi
 Revised:        Dec 1, 2016
 Course:         CS240-Intro to Computing III
 Objective:      To implement a recursive version of quick sort using an array
                 To time the algorithm
 
 
 */

#ifndef Heap_hpp
#define Heap_hpp

#include <iostream>
#include <string>
#include <sstream>

using namespace std;


/* We are going to implement this Heap very specifically to only handle the 50 States.
 * Normally, this is not a good idea, since it limits the use of the heap, but let's
 * not worry about that little detail this time around.
 *
 * Better solution: A better implementation would be to make the items a dynamic
 * array, its size based on the number of nodes the Heap is to handle.
 */
const int HEAP_SIZE = 50;


/* Class: Heap
 * Use the implementation algorithm shown in the notes.
 * The Heap class represents a Heap, offering sorting capability.
 */
template <typename E>
class Heap {
private:
    /*---------------------------------------------------------------------------------*/
    E items[HEAP_SIZE];
    int size;
    
    /* Rebuilds the heap. */
    void rebuild(int rootIndex, const int n) {
        // TODO: implement
        int max = rootIndex;
        if( rootIndex*2+1 < n)
        {
            max = 2 * rootIndex + 1;
            if(rootIndex*2+2 < n)
            {
                if(items[max+1] > items[max])
                {
                    max = max+1;
                }
            }
        }
        
        if( items[rootIndex] < items[max] ) //parent has changed
        {
            E temp = items[rootIndex];
            items[rootIndex] = items[max];
            items[max] = temp;
            rebuild(max, n);
        }
        
    } // end rebuild()
    /*---------------------------------------------------------------------------------*/
    
public:
    /* Sets the size to 0. */
    Heap()
    {// TODO: implement
        size = 0;
    } // end Heap()
        
    /* Does nothing this time. */
    virtual ~Heap()
    {
            // TODO: implement
    } // end ~Heap()
            
    
    /* Returns true if the heap is empty. */
    virtual bool isEmpty() const {
        // TODO: implement
        return (size == 0);
    } // end isEmpty()
    /*---------------------------------------------------------------------------------*/
    
    /* Inserts the object to the heap and reinstates the hep.
     * If the array is full, give the message "Heap is full. Object not added.", but do
     * not exit the program.
     */
    virtual void insert(const E& o) {
        // TODO: implement
        if(size == HEAP_SIZE)
        {
            cout << "Heap is full.  Object not added" << endl;
            return;
        }
        
        items[size] = o;
        int child = size;
        int parent = (child-1)/2;
        while( child > 0 && items[parent] < items[child])
        {
            E temp = items[parent];
            items[parent] = items[child];
            items[child] = temp;
            child = parent;
            parent = (child-1)/2;
        }
        
        size++;
    } // end insert()
    /*---------------------------------------------------------------------------------*/
    
    /* Removes the object from the heap and rebuilds the heap.
     * If the heap is empty give the message "Heap is empty. No object removed.", but
     * do not exit the program.
     */
    virtual void remove() {
        // TODO: implement
        if(isEmpty())
        {
            cout << "Heap is empty.  No object removed." << endl;
            return;
        }
        
        items[0] = items[size-1];
        int parent = 0;
        while(true)
        {
            int child1 = (parent*2)+1; // 0 -> 1/2
            int child2 = (parent*2)+2; // 1 -> 3->4 / 2->5 6
            if(child2 >= size)
                child2 = child1;
            if(child1 >= size)
                break; //bottom leaf
            
            if(items[parent] < items[child1]) //child1 is bigger than parent
            {
                if(items[child1] > items[child2]) //child1 is biggest child
                {
                    E temp = items[parent];
                    items[parent] = items[child1];
                    items[child1] = temp;
                    parent = child1;
                }
                else //child2 is the biggest child
                {
                    E temp = items[parent];
                    items[parent] = items[child2];
                    items[child2] = temp;
                    parent = child2;
                }
            }
            else if(child2 < size && items[parent] < items[child2]) //child2 bigger than parent, parent bigger than child1
            {
                E temp = items[parent];
                items[parent] = items[child2];
                items[child2] = temp;
                parent = child2;
            }
            else //else parent is bigger than both children
            {
                break;
            }
        }
        
        
        size--;
        //int trickleDownIndex = 0;
        
        
    }// end remove()
    /*---------------------------------------------------------------------------------*/
    
    /* Performs a heap sort. */
    virtual void sort() {
        // TODO: implement
        //cout << "SORTING" << endl;
        for(int i=size-1;i>=0;i--)
        {
            rebuild(i, size);
        }
        
        int last = size-1;
        for(int i=1;i<size;i++)
        {
            E temp = items[0];
            items[0] = items[last];
            items[last] = temp;
            last--;
            
            rebuild(0, last);
        }
    } // end sort()
    /*---------------------------------------------------------------------------------*/
    
    /* Returns the objects in the array formatted as:
     * items[0]
     * items[1]
     * ...
     * items[size -1]
     */
    virtual string toString() const {
        // TODO: implement
        string output = "";
        stringstream outs;
        for(int i=0;i<size;i++)
        {
            outs << items[i] << endl;
        }
        return outs.str();
    } // end toString()
    /*---------------------------------------------------------------------------------*/
    
};// end Heap

/* Displays the heap to the screen. Calls the o.toString(). */
template <typename E>
ostream& operator <<(ostream& out, const Heap<E>& o) {
    // TODO: implement
    out << o.toString() << endl;
    return out;
}// end <<()




#endif
