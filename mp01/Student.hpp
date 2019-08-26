/*
 File: mp01.MaramAlmutairi
 Name: Maram Almutairi
 Revised: Friday, September 9, 2016
 Course: CS240 - Intro to Computing III
 
 Description: Program reads from a text file and stores this information into appropriate struct and class objects
              and displays it to the screen.
 */

#ifndef Student_hpp
#define Student_hpp

#include <string>
using namespace std;


/*-----------------------------------------------------------------------------
 * struct: Name
 * Represents a name
 *---------------------------------------------------------------------------*/
struct Name {
   string first;
   string last;
};

/*-----------------------------------------------------------------------------
 * struct: Address
 * Represents an address
 *---------------------------------------------------------------------------*/
struct Address {
   string address1;
   string address2;
   string city;
   string state;
   string zipcode;
};

/*-----------------------------------------------------------------------------
 * struct: Course
 * Represents a course
 *---------------------------------------------------------------------------*/
struct Course {
   string number;
   string title;
   double credits;
   string grade;
};


/*-----------------------------------------------------------------------------
 * class: Student
 * Represents a student
 *---------------------------------------------------------------------------*/
class Student {
private:
   Name name;
   Address campusAddress;
   Address homeAddress;
   string major;
   Course courseTaken[100];
   int coursesTakenCount;
   
public:
    Student(const Name& name, const string& major, const Address& campusAddress);
    Student();
    
   Name getName() const;
   Address getCampusAddress() const;
   Address getHomeAddress() const;
   string getMajor() const;
   
   /* Assume index is valid (0 <= index <= coursesTakenCount - 1) */
   Course getCourse(const int index) const;
   int getCoursesTakenCount() const;
   
   
   void setName(const Name& name);
   void setCampusAddress(const Address& campusAddress);
   void setHomeAddress(const Address& homeAddress);
   void setMajor(const string& major);
   
   string toString() const;
   
   /* Adds the course to the end of the array. */
   void addCourse(const Course& course);
   
   /* Returns the gpa of all the courses taken. */
   double getCumulativeGpa() const;
};

#endif /* Student_hpp */
