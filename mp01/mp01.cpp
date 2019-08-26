/* File: mp01
 Name: Kelsey (Tien) Nguyen
 Revised: 9/5/16
 Course: CS 240 - Introduction to Computing III
 Description: The program read file into struct and class objects and display it.
 */

#include "Student.hpp"
#include <iostream>
#include <fstream>


using namespace std;




/*--------------------------------------------------------------------------------
 *didConnectToInputFile();
 * Returns true if file was opened successfully, false otherwise.
 ---------------------------------------------------------------------------------*/
bool didConnectToInputFile(ifstream& fin, const string& filename){
    
    fin.open (filename);
    return fin.is_open();
    
}//end



/*---------------------------------------------------------------------------------
 *readStudentRecord();
 Reads and returns the single student record read from the file stream.
 ----------------------------------------------------------------------------------*/
Student readStudentRecord(ifstream& fin){
    
    string upcomingLine;
    
    //build student information
    getline(fin, upcomingLine);
    string studentInformation[13];
    
    //storing student infomation in the array
    for(int i=0;i<13;i++)
    {
        int upcomingBreak = (int) upcomingLine.find(",");
        studentInformation[i] = upcomingLine.substr(0, upcomingBreak);
        upcomingLine = upcomingLine.substr (upcomingBreak+1, upcomingLine.length());
    }//end of the for loop
    
    
    //saving information from the array to the correct struct
    const struct Name currentName ={studentInformation[0], studentInformation[1]};
    const struct Address campusAddress ={studentInformation[2],studentInformation[3],studentInformation[4],studentInformation[5],studentInformation[6]};
    const struct  Address homeAddress = {studentInformation[7],studentInformation[8],studentInformation[9],studentInformation[10],studentInformation[11]};
    Student currentStudent (currentName,studentInformation[12], campusAddress);
    currentStudent.setHomeAddress(homeAddress);
    //now student is currentStudent.getName()
    
    
    //build each course information
    while(fin.good()){
        
        getline(fin, upcomingLine);
        string courseInformation[4];
        
        //storing course information to the array
        for ( int i=0; i< 4; i++)
        {
            
            int upcomingBreak = (int) upcomingLine.find(",");
            courseInformation[i] = upcomingLine.substr(0, upcomingBreak);
            upcomingLine = upcomingLine.substr (upcomingBreak+1, upcomingLine.length());
            
        }// end of loops
        
        //saving course information from the array to the correct struct
        const struct Course currentCourse = { courseInformation [0],courseInformation [1],stod(courseInformation [2]),courseInformation [3]};//end
        currentStudent.addCourse(currentCourse);//end
        
        //now course is currentCourse.name;
        
    }
    return currentStudent;
    
}//end




/*--------------------------------------------------------------------------------
 *displaysStudentRecord();
 *Displays the student record to the screen.
 ---------------------------------------------------------------------------------*/
void displayStudentRecord(const Student& o){
    
    //displays name
    cout << "Name: " << " "<< o.getName().last<< ", "<< o.getName().first << endl;
    
    //displays address
    cout <<"Campus address:"<< endl;
    cout << "\t" << o.getCampusAddress().address1 << endl;
    cout << "\t" << o.getCampusAddress().address2 << endl;
    cout << "\t" << o.getCampusAddress().city <<", "<< o.getCampusAddress().state<< " "<<o.getCampusAddress().zipcode << endl;
    
    
    cout<<"Home address:"<< endl;
    if (o.getHomeAddress().address1.length()>0){
        cout<<"\t"<< o.getHomeAddress().address1 << endl;
    }
    if (o.getHomeAddress().address2.length()>0){
        cout<< "\t"<<o.getHomeAddress().address2 << endl;
    }
    
    cout<<"\t"<< o.getHomeAddress().city <<", "<< o.getHomeAddress().state<<" "<<o.getHomeAddress().zipcode<< endl;
    
    
    //displays major
    cout<< "Major: " << o.getMajor()<<endl;
    
    //get the information from each course in the array
    cout<< "Courses Taken:"<< endl;
    for ( int i=0; i<o.getCoursesTakenCount(); i++)
    {
        printf("\t[%d] %s-%s, %.1f: %s\n", (i+1),
               o.getCourse(i).number.c_str(),
               o.getCourse(i).title.c_str(),
               o.getCourse(i).credits,
               o.getCourse(i).grade.c_str());
        
        
        
    }//end if for loop
    
    //displays GPA
    printf( "Cumulative GPA: %.2f\n" ,o.getCumulativeGpa());
    
    
    
}//end




/*--------------------------------------------------------------------------------
 *main()
 *TODO: implement main().
 * Read from the file the student record. Save the record in the variable studentRecord.
 * Display the student record to the screen.
 ---------------------------------------------------------------------------------*/

int main()  {
    
    //create the file stream
    ifstream fileInput;
    
    //try to open file
    if ( !didConnectToInputFile(fileInput, "students.txt") ) {
        cerr << "Error: could not open file." << endl;
        exit(1);
    }
    
    
    //making new student and print
    Student studentFile = readStudentRecord(fileInput);
    fileInput.close();
    displayStudentRecord(studentFile);
    
    
    return 0;

    
    
}//end main

