/*
 File:           mp04.MaramAlmutairi
 Name:           Maram Almutairi
 Revised:        Oct 21, 2016
 Course:         CS240-Intro to Computing III
 Description:    Program that uses a linked list to process state data, reads from a file,
 and uses pointers along with dynamic memory management.
 
 main.cpp
 mp04.MaramAlmutairi
 Created by Maram Almutairi on 10/21/16.
 Copyright © 2016 Maram Almutairi. All rights reserved.
 */

#ifndef States_hpp
#define States_hpp

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

const int NUMBER_OF_STATES = 50;

/* Fields inside the State object that can server as sorting keys.
 * Each enum constant is given a value starting with 0 and incrementing
 * by 1 for each subsequent constant. Thus, Abbreviation is 0 and
 * OrderInducted is 6. */
enum StateSortField {
    Abbreviation,
    Name,
    Capital,
    Population,
    Area,
    YearInducted,
    OrderInducted
};

/*---------------------------------------------------------------------------------
 * Class: States
 *
 * This class stores an array of NUMBER_OF_STATES state objects. The ordering of
 * the elements are based on one of the seven fields (abbreviation to orderInducted).
 *
 *---------------------------------------------------------------------------------*/
class States {
private:
    
    /*---------------------------------------------------------------------------------*/
    class State {
    public:
        string abbreviation;
        string name;
        string capital;
        int population;
        int area;
        int yearInducted;
        int orderInducted;
        
        /* Initializes the object with empty strings ("") and 0's. */
        State()
        {
            abbreviation = "";
            name = "";
            capital = "";
            population = 0;
            area = 0;
            yearInducted = 0;
            orderInducted = 0;
        }
        
        /* Returns the state object formatted as follows:
         * Abbreviation<spc>Name<spc>Capital<spc>Population<spc>Area<spc>Year Inducted<spc>Order Inducted
         */
        string toString() const
        {
            char * buffer = new char[1024];
            sprintf(buffer, "%-14s %-16s %-15s %10d %10d %15d %17d",
                    abbreviation.c_str(),
                    name.c_str(),
                    capital.c_str(),
                    population,
                    area,
                    yearInducted,
                    orderInducted
                    );
            
            
            string ret(buffer);
            return ret;
        }
    
        /* Equality means each corresponding property is the same. */
        virtual bool operator == (const State& o) const
        {
            if(abbreviation != o.abbreviation)
                return false;
            if(name != o.name)
                return false;
            if(capital != o.capital)
                return false;
            if(population != o.population)
                return false;
            if(area != o.area)
                return false;
            if(yearInducted != o.yearInducted)
                return false;
            if(orderInducted != o.orderInducted)
                return false;
            
            return true;
        }
        
        virtual bool operator != (const State& o) const
        {
            return !(*this == o);
        }
        
        /* Ordering is determined on first corresponding property pair that is different. */
        virtual bool operator <  (const State& o) const
        {
            if(abbreviation < o.abbreviation)
                return true;
            if(name < o.name)
                return true;
            if(capital < o.capital)
                return true;
            if(population < o.population)
                return true;
            if(area < o.area)
                return true;
            if(yearInducted < o.yearInducted)
                return true;
            if(orderInducted < o.orderInducted)
                return true;
            
            return false;
        }
        
        virtual bool operator <= (const State& o) const
        {
            return !(*this > o);
        }
        
        virtual bool operator >  (const State& o) const
        {
            if(abbreviation > o.abbreviation)
                return true;
            if(name > o.name)
                return true;
            if(capital > o.capital)
                return true;
            if(population > o.population)
                return true;
            if(area > o.area)
                return true;
            if(yearInducted > o.yearInducted)
                return true;
            if(orderInducted > o.orderInducted)
                return true;
            
            return false;
        }
        
        virtual bool operator >= (const State& o) const
        {
            return !(*this < o);
        }
        
    }; // end State
    /*---------------------------------------------------------------------------------*/
    
    /* Selection sort supporting methods. */
    
    /* Performs an ascending ordering based on the sortField. */
    int indexOfSmallestElementStartingAt(const int startIndex, const StateSortField sortField) const
    {
        int smallestIndex = startIndex; //assume index 0 has the smallest item & then do research:
        for(int i=startIndex;i<NUMBER_OF_STATES;i++) //go through all other states
        {
            //if the sort field is (something) and states[i] is "less than" the smallestIndex (in that field)
            //then that means that (i) is the new smallestIndex
            if((sortField == Abbreviation)&&( states[i].abbreviation < states[smallestIndex].abbreviation))
                smallestIndex = i;
            else if((sortField == Name)&&( states[i].name < states[smallestIndex].name))
                smallestIndex = i;
            else if((sortField == Capital)&&( states[i].capital < states[smallestIndex].capital))
                smallestIndex = i;
            else if((sortField == Population)&&( states[i].population < states[smallestIndex].population))
                smallestIndex = i;
            else if((sortField == Area)&&( states[i].area < states[smallestIndex].area))
                smallestIndex = i;
            else if((sortField == YearInducted)&&( states[i].yearInducted < states[smallestIndex].yearInducted))
                smallestIndex = i;
            else if((sortField == OrderInducted)&&( states[i].orderInducted < states[smallestIndex].orderInducted))
                smallestIndex = i;
            //otherwise, it wasn't the smallest...
        }
        return smallestIndex;
    }
    
    void swap(const int index1, const int index2)
    {
        State temp = states[index1];
        states[index1] = states[index2];
        states[index2] = temp;
    }
    
    /* Returns true is connection is open. */
    bool didConnectToFile(ifstream& fin, const string& filename)
    {
        fin.open(filename);
        return fin.is_open();
    }
    
    
    /* The property representing the 50 states. */
    State states[NUMBER_OF_STATES];
    
public:
    /* Does no additional initialization. */
    States()
    {
        
    }
    
    /* Reads from the specified file and loads the states array. The delimiter
     * identifies the character delimiting each field in the file.
     */
    void loadFromFile(const string& filename, const char delimiter)
    {
        ifstream in;
        if(didConnectToFile(in, filename))
        {
            string line;
            for(int i=0;i<NUMBER_OF_STATES;i++)
            {
                getline(in, line);
                State nextState;
                stringstream ss;
                ss.str(line);
                for(int i=0;i<7;i++)
                {
                    string item;
                    getline(ss, item, delimiter);
                    if(i == 0)
                        nextState.abbreviation = item;
                    else if(i == 1)
                        nextState.name = item;
                    else if(i == 2)
                        nextState.capital = item;
                    else if(i == 3)
                        nextState.population = stoi(item);
                    else if(i == 4)
                        nextState.area = stoi(item);
                    else if(i == 5)
                        nextState.yearInducted = stoi(item);
                    else if(i == 6)
                        nextState.orderInducted = stoi(item);
                }
                states[i]  = nextState;
            }
        }
    }
    
    /* Returns the state at the specified index. */
    State getAt(const int index)
    {
        return states[index];
    }
    
    /* Sorts the array states by the specified field. */
    void sort(const StateSortField sortField)
    {
        //cout << "Sorting by " << sortField << endl;
        for(int i=0;i<NUMBER_OF_STATES;i++)
        {
            int smallest = indexOfSmallestElementStartingAt(i, sortField);
            //cout << "Smallest: " << smallest << endl;
            if(i != smallest)
            {
                swap(i, smallest);
            }
        }
    }
    
    /* Returns a string will current contents of the array formatted as follows:
     * Abbreviation<spc>Name<spc>Capital<spc>Population<spc>Area<spc>Year Inducted<spc>Order Inducted
     * ----------------------------------------------------------------------------------------------
     * <abbreviation><spc><name><spc><capital><spc><population><spc><area><spc><yearInducted><spc><orderInducted>
     * ...
     *
     * Note: the fields <abbreviation>,<name> and <capital> are left aligned, the others right aligned.
     */
    string toString() const
    {
        char buffer[1024];
        sprintf(buffer, "%12s %20s %18s %12s %12s %13s %13s",
                "Abbreviation",
                "Name",
                "Capital",
                "Population",
                "Area",
                "Year Inducted",
                "Order Inducted");
        
        string output = "";
        for(int i=0;i<NUMBER_OF_STATES;i++)
        {
            output = output + states[i].toString() + "\n";
        }
        return output;
    }
    /*----------------------------------------------------------------------------------*/
    
    /* Equality means each corresponding state element is the same. */
    virtual bool operator == (const States& o) const
    {
        for(int i=0;i<NUMBER_OF_STATES;i++)
        {
            if(states[i] != o.states[i])
            {
                return false;
            }
        }
        
        return true;
    }
    virtual bool operator != (const States& o) const
    {
        return !(*this == o);
    }
    
    /* Ordering is determined on first corresponding state pair that is different. */
    virtual bool operator <  (const States& o) const
    {
        for(int i=0;i<NUMBER_OF_STATES;i++)
        {
            if(states[i] != o.states[i])
            {
                return states[i] < o.states[i];
            }
        }
        return false;
    }
    virtual bool operator <= (const States& o) const
    {
        return !(*this > o);
    }
    virtual bool operator >  (const States& o) const
    {
        for(int i=0;i<NUMBER_OF_STATES;i++)
        {
            if(states[i] != o.states[i])
            {
                return states[i] > o.states[i];
            }
        }
        return false;
    }
    virtual bool operator >= (const States& o) const
    {
        return !(*this < o);
    }
    /*----------------------------------------------------------------------------------*/
    
};

/* Calls the toString() method of the parameter object o. */
ostream& operator <<(ostream& out, const States& o)
{
    return out;
}

#endif /* States_hpp */










