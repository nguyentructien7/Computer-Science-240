/*
File:           mp04
Name:           Kelsey (Tien) Nguyen
Revised:        Nov. 5, 2016
Course:         CS240-Intro to Computing III
Description: to implement a recursive version of quick sort using an array and to implement the algorithm

*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int ARRAY_SIZE = 100;

/* TODO: Recursive quick sort implementation. Refer to both the book's solution and the
 * one presented in class to implement the quicksort algorithm.
 */
void qsort(int * list[], const int first, const int last);

/* TODO: Partition method of recursive quicksort algorithm. */
int partition(int * list[], const int first, const int last);

/* TODO: Swap the elements at the given indices. */
void swap(int * list[], const int index1, const int index2);

/* TODO: <<() for an array of pointers to int. */
ostream& operator <<(ostream& out, int * list[]);




int main() {
    /* Declare a dynamic array, list, of integer pointers. */
    int **integerPtrs;
    
    /* TODO: Allocate an array of ARRAY_SIZE + 1 int pointers. The extra element will contain
     * a nullptr. This nullptr will be used by the overloaded <<() function to determine the end.
     */
    integerPtrs=new int*[ARRAY_SIZE+1];
    
    /* TODO: Randomly generate ARRAY_SIZE integer values in the range 1-1000 and add to the array. */
    for (int x=0;x<ARRAY_SIZE;x++){
        int * newInt=new int;
        *newInt=rand()%1000+1;
        integerPtrs[x]=newInt;
    }
    
    /* TODO: Add a nullptr to the last element so the <<() knows when to stop. */
    integerPtrs[ARRAY_SIZE]=nullptr;
    
    /* TODO: List the original unsorted array. */
    cout<<"Original List: "<<endl;
    cout<<"["<<endl<<integerPtrs<<"]"<<endl;
    
    /* TODO: sort the array using qsort(). */
    qsort(integerPtrs,0,ARRAY_SIZE-1);
    
    /* TODO: List the sorted list. */
    cout<<endl<<"Sorted List: "<<endl;
    cout<<"["<<endl<<integerPtrs<<"]"<<endl;
    
    /* TODO: Release all the memory allocated to the array. */
    
    for (int x=0;x<ARRAY_SIZE;x++){
        delete integerPtrs[x];
    } delete []integerPtrs;
    
    
    
    
    /* TODO: Randomly generate 10,000 integer values in the range 1-1000 and add to the array. */
    
    int size=10000;
    integerPtrs=new int*[size];
    for (int x=0;x<size;x++){
        int * newInt=new int;
        *newInt=rand()%1000+1;
        integerPtrs[x]=newInt;
    }
    
    /* TODO: Display the total amount of time it takes to sort a list
     * of 10000 random numbers. Use the clock() function for this. Make sure you look up
     * how to use it and see what library you need to include.
     */
    clock_t time=clock();
    qsort(integerPtrs,0,size-1);
    cout<<"Time to sort 10,000: "<< ((float)(clock()-time)/CLOCKS_PER_SEC)<<" seconds "<<endl;
    
    /* TODO: Release all the memory allocated to the array. */
    
    for (int x=0;x<size;x++){
        delete integerPtrs[x];
    } delete [] integerPtrs;
    return 0;
}

/* TODO: Recursive quick sort implementation. Refer to both the book's solution and the
 * one presented in class to implement the quicksort algorithm.
 */
void qsort(int * list[], const int first, const int last) {
    if(first < last)
    {
        int part = partition(list, first, last);
        qsort(list, first, part-1);
        qsort(list, part+1, last);
    }
    
}// end qsort()
/*----------------------------------------------------------------------------------*/

/* TODO: Partition method of recursive quicksort algorithm. */
int partition(int * list[], const int first, const int last) {
    int part = *list[first];
    int lastNum = first;
    int firstNum = first+1;
    while (firstNum<=last)
    {
        if(*list[firstNum] <= part){
            lastNum++;
            swap(list, firstNum, lastNum);
        }
        
        firstNum++;
    }
    swap(list, first, lastNum);
    return lastNum;
    
}// end partition()
/*----------------------------------------------------------------------------------*/

/* TODO: Swap the elements at the given indices. */
void swap(int * list[], const int index1, const int index2) {
    int *temporary=list[index1];
    list[index1]=list[index2];
    list[index2]=temporary;
}// end swap()
/*----------------------------------------------------------------------------------*/


/* TODO: <<() for an array of pointers to int. */
ostream& operator <<(ostream& out, int * list[]) {
    int x=0;
    while (list[x]!=nullptr){
        if (list[x]!=nullptr){
            cout<<*list[x]<<endl;
        } x++;
    } return out;
}



