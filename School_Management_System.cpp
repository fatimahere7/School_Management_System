//----------------*******School Management System******----------------
//-----------------*******Header files*******------------------
#include <iostream>
#include <fstream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>
#include <dos.h>
#include <iomanip>

using namespace std;

//--------*****Global var*****-------------

const int MAX_STUDENTS = 100;
const int MAX_TEACHERS = 100;
const int MAX_COURSES = 5;
const int MAX_NAME_LENGTH = 50;
const int MAX_SUBJECT_LENGTH = 100;
const int MAX_SCHEDULE_LENGTH = 100;

//----------***Student***------------

struct Student {
        char id[10];
        char name[MAX_NAME_LENGTH];
        int grade;
        char courses[MAX_SUBJECT_LENGTH];
        int numCourses;
        float marks, per;
};
//----------***Teacher***------------
struct Teacher {
     char id[10];
     char name[MAX_NAME_LENGTH];
     char subject[MAX_SUBJECT_LENGTH];
     char schedule[MAX_SCHEDULE_LENGTH];
};


Student students[MAX_STUDENTS];
int numStudents = 0;

Teacher teachers[MAX_TEACHERS];
int numTeachers = 0;

//---------***1. Enroll New Student***--------------


void enrollStudent()
{
	  if (numStudents >= MAX_STUDENTS) {
        cout << "Cannot enroll more students. Student database full." << endl;
        return;
      }

    cout << "                     \n\n        Enter Student ID: ";
    cin.ignore();
    cin.getline(students[numStudents].id, 10);
    cout << "        Enter Name: ";
    cin.getline(students[numStudents].name, MAX_NAME_LENGTH);
    cout << "        Enter Grade: ";
    cin >> students[numStudents].grade;
   
    students[numStudents].numCourses = 0; // initialize number of courses to 0
    cin.ignore();
    cout << "\n        Student enrolled: ID=" << students[numStudents].id
	     << ", Name=\"" << students[numStudents].name 
		 << "\", Grade=" << students[numStudents].grade << endl;
    cout<<"\n\nSTUDENT ENROLLED SUCCESSFULLY!\n";
    
    
    numStudents++;
    system("PAUSE");
}

//------------2-*******Update Student Details******------------

void update_student()
{
   char enterId[10];
   cout << "\n\n       Enter the ID of the student to update: ";
   cin.ignore();
   cin.getline(enterId,10);
   
  int index = -1;
  // Find the index of the student to update
  for (int i = 0; i < numStudents; i++) {
    if (strcmp(students[i].id, enterId) == 0) {
      index = i;
      break;
    }
  }

  if (index == -1) {
      cout << "     Student with ID " << enterId << " not found.\n";
      system("PAUSE");
      return;
  }
  
  // Display current student details
  
    cout << "\n  Current details:\n";
    cout << "     ID: " << students[index].id << endl;
    cout << "     Name: " << students[index].name << endl;
    cout << "     Grade: " << students[index].grade << endl;
 
    int choice;
    cout << "\n  What do you want to update?\n";
    cout << "     1. Name\n";
    cout << "     2. Grade\n";
    cout << "     Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
      cout << "    Enter new name: ";
      cin.ignore(); // Clear input buffer (optional, to avoid issues with spaces in names)
      cin.getline( students[index].name, MAX_NAME_LENGTH);
      break;
    case 2:
      cout << "    Enter new grade: ";
      cin >> students[index].grade;
      break;
    default:
      cout << "Invalid choice.\n";
  }

  cout << "STUDENT DETAILS UPDATED SUCCESSFULLY.\n";
  system("PAUSE");
}

//-----------*****3-Delete A Student***********--------------

void delete_student() {
   char enterId[10];
   cout << "Enter the ID of the student to Delete: ";
   cin.ignore();
   cin.getline(enterId,10);
   int index = -1;

  // Find the index of the student to delete
  for (int i = 0; i < numStudents; i++) {
    if (strcmp(students[i].id, enterId)==0) {
      index = i;
      break;
    }
  }

  if (index == -1) {
      cout << "Student with ID " << enterId << " not found.\n";
      system("PAUSE");
      return;
  }

  // Shift elements to remove the deleted student
  for (int i = index; i < numStudents - 1; i++) {
    students[i] = students[i + 1];
  }

  // Decrement number of students
  numStudents--;

  cout << "Student details Deleted successfully.\n";
  system("PAUSE");
  

}
//-----------*********4-Add New Teacher*********----------------

void addTeacher(){
	
      if (numTeachers >= MAX_TEACHERS) {
        cout << "Cannot add more teachers. Teacher database full." << endl;
        return;
      }
       cout<<"\n\n";
       cout << "               Enter Teacher ID: ";
       cin.ignore();
       cin.getline(teachers[numTeachers].id, 10);

       cout << "               Enter Name: ";
       cin.getline(teachers[numTeachers].name, MAX_NAME_LENGTH);

       cout << "               Enter Subject: ";
       cin.getline(teachers[numTeachers].subject, MAX_SUBJECT_LENGTH);

       cout << "               Enter Schedule: ";
       cin.getline(teachers[numTeachers].schedule, MAX_SCHEDULE_LENGTH);

        cout<<"\n\n";
       cout << "           Teacher added: ID=" << teachers[numTeachers].id << ", Name=\"" << teachers[numTeachers].name << "\", Subject=\"" << teachers[numTeachers].subject << "\", Schedule=\"" << teachers[numTeachers].schedule << "\"" << endl;

       numTeachers++;
       cout<<"\n              Teacher Added Successfully!\n\n\n";
       system("PAUSE");
}
//----------*********5-Update Teacher Details*************-----------
void update_teacher() {
  
  char enterId[10];
  cout << "Enter the ID of the Teacher to Update: ";
  cin.ignore();
  cin.getline(enterId,10);
  int index = -1;
  // Find the index of the teacher to update
  for (int i = 0; i < numTeachers; i++) {
    if (strcmp(teachers[i].id,enterId )== 0) {
      index = i;
      break;
    }
  }

  if (index == -1) {
    cout << "Teacher with ID " << enterId << " not found.\n";
    system("PAUSE");
    
    return;
  }

  // Display current teacher details
  cout << "\nCurrent details:\n";
  cout << "ID: " << teachers[index].id << endl;
  cout << "Name: " << teachers[index].name << endl;
  cout << "Subject: " << teachers[index].subject << endl;

  int choice;
  cout << "\nWhat do you want to update?\n";
  cout << "1. Name\n";
  cout << "2. Subject\n"; // Assuming you have a way to manage subjects
  cout << "Enter your choice: ";
  cin >> choice;

  switch (choice) {
    case 1:
      cout << "Enter new name: ";
      cin.ignore(); // Clear input buffer (optional)
      cin.getline(teachers[index].name, MAX_NAME_LENGTH);
      break;
    case 2:
      cout << "Enter new subject: ";
      cin.ignore(); // Clear input buffer (optional)
      cin.getline( teachers[index].subject, MAX_SUBJECT_LENGTH);
      break;
    default:
      cout << "Invalid choice.\n";
  }

  cout << "Teacher details updated successfully.\n";
  system("PAUSE");
}


//----------*********6-Delete A Teacher************-----------

void delete_teacher() {
  char enterId[10];
   cout << "Enter the ID of the teacher to Delete: ";
   cin.ignore();
   cin.getline(enterId,10);
  int index = -1;

  // Find the index of the teacher to delete
  for (int i = 0; i < numTeachers; i++) {
    if (strcmp(teachers[i].id,enterId) == 0 ){
      index = i;
      break;
    }
  }

  if (index == -1) {
     cout << "Teacher with ID " << enterId << " not found.\n";
     system("PAUSE");
     return;
  }

  // Shift elements to remove the deleted teacher
  for (int i = index; i < numTeachers - 1; i++) {
    teachers[i] = teachers[i + 1];
  }

  // Decrement number of teachers
  numTeachers--;


   cout << "Teacher details Deleted successfully.\n";
   system("PAUSE");

}

//------------*****7-Assign a course to a student*****-----------



bool assign_course() {
  char enterId[10];
   cout << "Enter the ID of the Student to Assign a Course : ";
   cin.ignore();
   cin.getline(enterId,10);
  int index = -1;

  // Find the student to assign the course to
  for (int i = 0; i < numStudents; i++) {
    if (strcmp(students[i].id,enterId )== 0) {
      index = i;
      break;
    }
  }

  if (index == -1) {
    cout << "Student with ID " <<enterId << " not found.\n";
     system("PAUSE");
    return false;
  }



 int courseId;
  cout << "      Available Courses with Course Id:\n";
      // List available courses (implement logic to display available courses)
      // ...
       cout<<"       ----------------------------------------------\n";
       cout<<"                 1- English \n";
       cout<<"                 2- Mathematics \n";
       cout<<"                 3- Physics \n";
       cout<<"                 4- Computer \n";
       cout<<"                 5- Chemistry \n";
       cout<<"       ----------------------------------------------\n";
       cout<<"                 Enter course Id  :";
     
      cin >> courseId;

      // Add course ID to student's course list
      if( courseId==1){
      	  cout<<"    To the Corresponding COURSE ID Enter Course Title  : ";
      	  cin.ignore();
      	  cin.getline(students[index].courses,MAX_SUBJECT_LENGTH);
      	 
      	  
	  }
	  if( courseId==2){
      	  cout<<"    To the Corresponding COURSE ID Enter Course Title  : ";
      	  cin.ignore();
      	  cin.getline(students[index].courses,MAX_SUBJECT_LENGTH);
      	  
      	  
	  }
	  if( courseId==3){
      	  cout<<"    To the Corresponding COURSE ID Enter Course Title  : ";
      	  
      	  cin.getline(students[index].courses,MAX_SUBJECT_LENGTH);
      	  //cin.ignore();
      	  
	  }
	  if( courseId==4){
      	 cout<<"     To the Corresponding COURSE ID Enter Course Title  : ";
      	  cin.ignore();
      	  cin.getline(students[index].courses,MAX_SUBJECT_LENGTH);
      	  //cin.ignore();
      	  
	  }
	  if( courseId==5){
      	  cout<<"     To the corresponding course id enter course title : ";
      	  cin.ignore();
      	  cin.getline(students[index].courses,MAX_SUBJECT_LENGTH);
      	  //cin.ignore();
      	  
	  }
    //  students[index].courses[students[index].numCourses] = courseId;
      students[index].numCourses++;

      cout << "Course assigned successfully!\n";
      system("PAUSE");
       
}

//------------*****8-Generate report card*****---------------


void generate_report_card() {
   char enterId[10];
   cout << "Enter the ID of the Student  : ";
   cin.ignore();
   cin.getline(enterId,10);	
   int index = -1;

  // Find the student to generate the report card for
  for (int i = 0; i < numStudents; i++) {
    if (strcmp(students[i].id,enterId )== 0) {
      index = i;
      break;
    }
  }

  if (index == -1) {
    cout << "Student with ID " << enterId<< " not found.\n";
    system("PAUSE");
    return;
  }

  // Header
  cout << "\n                    **Report Card**\n";
  cout<<"   ******-----------------------------------------------------*****\n";
  cout << "                  Student Name: " << students[index].name << endl;
  cout << "                  Student ID: " << students[index].id << endl;
  cout << "                  Grade: " << students[index].grade << endl;
  cout << "                  course: " << students[index].courses << endl;
  cout<<"   ******-----------------------------------------------------*****\n";

  
  cout << "\n                   **End of Report Card**\n";
  system("PAUSE");
}





//----------9-Display all students-------------

void display_students() {
  if (numStudents == 0) {
      cout << "No students found.\n";
      
      system("PAUSE"); 
      return;
  }

  cout << "\n                STUDENT LIST:\n";
  
  for (int i = 0; i < numStudents; i++) {
  	  cout<<"       ----------------------------------------------\n";
      cout << "             ID: " << students[i].id << endl;
      cout << "             Name: " << students[i].name << endl;
      cout << "             Grade: " << students[i].grade << endl;
      cout << "             Courses: ";
      if (students[i].numCourses == 0) {
        cout << "None\n";
        
      }
	  else
	  {
        
        cout <<"\""<< students[i].courses<<   "\"";
        cout<<endl;
    }
    //cout << "\n";
    cout<<"       ------------------------------------------------\n";
  }
  system("PAUSE");
}

//------------****10. Display all teachers****--------------

void display_teachers() {
  if (numTeachers == 0) {
    cout << "No teachers found.\n";
    system("PAUSE");
    return;
  }

  cout << "\n              Teacher List:\n";
  for (int i = 0; i < numTeachers; i++) {
  	  cout<<"       ------------------------------------------------\n";
      cout << "               ID: " << teachers[i].id <<endl;
      cout << "               Name: " << teachers[i].name << endl;
      cout << "               Subject: " << teachers[i].subject << endl;
      cout << "               Schedule: "<<teachers[i].schedule<<endl;
      
    // Consider including a section to display schedule details if implemented
    // (would require modifications to the Teacher struct and schedule handling)
      cout << endl;
  }
  cout<<"        ------------------------------------------------\n";
  system("PAUSE");
}

//------------*****11. Save records to file************---------

bool save_records() {
   ofstream outfile("Records.txt" ,ios::binary);

   // outFile << students.sizeof() << "\n";
  // Open file for writing in binary mode
 
  if (!outfile.is_open()) {
    cout<< "Error: Could not open file for saving records.\n";
    system("PAUSE");
    return false;
  }

  // Write number of students and teachers
  outfile.write((char*)&numStudents, sizeof(numStudents));
  outfile.write((char*)&numTeachers, sizeof(numTeachers));

  // Write student data
  for (int i = 0; i < numStudents; i++) {
    outfile.write((char*)&students[i], sizeof(Student));
    outfile.write((char*)&students[i].numCourses, sizeof(students[i].numCourses));
    for (int j = 0; j < students[i].numCourses; j++) {
      outfile.write((char*)&students[i].courses[j], sizeof(int));
    }
  }

  // Write teacher data
  for (int i = 0; i < numTeachers; i++) {
    outfile.write((char*)&teachers[i], sizeof(Teacher));
  }

  outfile.close();
  cout << "Records saved successfully to " << outfile << ".\n";
  system("PAUSE");
  return true;
}




//-----------*****12. Load records from file****---------




bool load_records() {
  // Open file for reading in binary mode
  ifstream infile("Record.txt",ios::binary);
  if (!infile.is_open()) {
    cout << "Error: Could not open file for loading records.\n";
    system("PAUSE");
    return false;
  }

  // Read number of students and teachers
  infile.read((char*)&numStudents, sizeof(numStudents));
  infile.read((char*)&numTeachers, sizeof(numTeachers));


  // Read student data
  for (int i = 0; i < numStudents; i++) {
    infile.read((char*)&students[i], sizeof(Student));
    infile.read((char*)&students[i].numCourses, sizeof(students[i].numCourses));
   // students[i].courses = new int[students[i].numCourses]; // Allocate for courses
    for (int j = 0; j < students[i].numCourses; j++) {
      infile.read((char*)&students[i].courses[j], sizeof(int));
    }
  }

  // Read teacher data
  for (int i = 0; i < numTeachers; i++) {
    infile.read((char*)&teachers[i], sizeof(Teacher));
  }

  infile.close();
  cout << "Records loaded successfully from " << "Record.txt" << ".\n";
  system("PAUSE");
  return true;
}
//---------------Diver Function-------------------

int main() {
    int choice;

    do {
    	system ("CLS");
    	cout << "\n\n                       #------------WELCOME TO SCHOOL MANAGEMENT SYSTEM----------------#\n\n";
        cout << "                                         1. Enroll a new student\n";
        cout << "                                         2. Update student details\n";
        cout << "                                         3. Delete a student\n";
        cout << "                                         4. Add a new teacher\n";
        cout << "                                         5. Update teacher details\n";
        cout << "                                         6. Delete a teacher\n";
        cout << "                                         7. Assign a course to a student\n";
        cout << "                                         8. Generate report card\n";
        cout << "                                         9. Display all students\n";
        cout << "                                        10. Display all teachers\n";
        cout << "                                        11. Save records to file\n";
        cout << "                                        12. Load records from file\n";
        cout << "                                        13. Exit\n\n";
        cout << "                       #------------------------------------------------------------------#\n\n";
        cout << "\n\n\n                            CHOICE AN OPTION : ";
        cin >> choice;

        switch (choice) {
            case 1:
			   system ("CLS"); 
			   enrollStudent();
			   break;
            case 2: 
               system ("CLS");
			   update_student();
			    break;
            case 3: 
                system ("CLS");
			    delete_student();
			    break;
            case 4: 
                system ("CLS");
			    addTeacher();
				break;
            case 5: 
                system ("CLS");
			    update_teacher(); 
				break;
            case 6:
			    system ("CLS"); 
			    delete_teacher();
				break;
            case 7:
            	system ("CLS");
			   assign_course() ;
				break;
            case 8:
            	system ("CLS");
			    generate_report_card() ;
			    break;
            case 9: 
                system ("CLS");
			    display_students();
				 break;
            case 10:
			    system ("CLS"); 
			    display_teachers(); break;
            case 11:
            	system ("CLS");
			    save_records();
				break;
            case 12:
            	system ("CLS");
			    load_records();
				 break;
            case 13: 
                system ("CLS");
			    cout<<"Exit of the Program"; 
				break;
            default:
            	system ("CLS");
			   cout << "Invalid option! Try again.\n";
			   system("PAUSE");
			   
        }
    } while (choice!=13);
    
    return 0;
  }

