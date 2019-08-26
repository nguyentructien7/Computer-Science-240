/*
 File: mp01.MaramAlmutairi
 Name: Maram Almutairi
 Revised: Friday, September 9, 2016
 Course: CS240 - Intro to Computing III
 
 Description: Program reads from a text file and stores this information into appropriate struct and class objects
 and displays it to the screen.
 */


#include "Student.hpp"
#include <sstream>
using namespace std;

//getter functions
Name Student::getName() const{return name;}
Address Student::getCampusAddress() const{return campusAddress;}
Address Student::getHomeAddress() const{return homeAddress;}
string Student::getMajor() const{return major;}

/* Assume index is valid (0 <= index <= coursesTakenCount - 1) */
Course Student::getCourse(const int index) const{return courseTaken[index];}
int Student::getCoursesTakenCount() const{return coursesTakenCount;}

//setter functions
void Student::setName(const Name& name){this->name=name;}
void Student::setCampusAddress(const Address& campusAddress){this->campusAddress=campusAddress;}
void Student::setHomeAddress(const Address& homeAddress){this->homeAddress=homeAddress;}
void Student::setMajor(const string& major){this->major=major;}

//student constructor
Student::Student(const Name& name, const string& major, const Address& campusAddress)
{
    this->name = name;
    this->major = major;
    this->campusAddress = campusAddress;
    coursesTakenCount = 0;

}

/* Adds the course to the end of the array. */
void Student::addCourse(const Course& course)
{
    courseTaken[coursesTakenCount] = course;
    coursesTakenCount++;
}

/* Returns the gpa of all the courses taken. */
double Student::getCumulativeGpa() const
{
    
    double gpaSum=0;
    double creditSum = 0;
    for(int i=0;i<coursesTakenCount; i++)
    {
        //store credits to courseCredits
        double courseCredits = courseTaken[i].credits;
        creditSum = creditSum + courseCredits;
        
        double gradeValue = 0;
        if(courseTaken[i].grade == "A")
        {
            gradeValue = 4.0;
        }
        else if(courseTaken[i].grade == "B")
        {
            gradeValue = 3.0;
        }
        else if(courseTaken[i].grade == "C")
        {
            gradeValue = 2.0;
        }
        else if(courseTaken[i].grade == "D")
        {
            gradeValue = 1.0;
        }
        //quality points calculation
        gpaSum = gpaSum+courseCredits*gradeValue;
    }
    //return gpa calculation
    return gpaSum / creditSum;
}








