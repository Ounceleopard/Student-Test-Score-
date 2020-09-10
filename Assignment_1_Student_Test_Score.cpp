/*	
	Name: Student Test Score Program
	Copyright: Brayan Villatoro 
	Author: Brayan Villatoro
	Date: 08/30/2020 10:02AM
	Description:  
	
	CSCI-373 (FALL 2020) (Prof. Abdu) (Assignment 1) (John Jay College) 
	-----------------------------------------------------------------------------------
	o Assign a grade (A, B, C, D, or F) based on a student’s test score 	  -Line 38-
	o Display class data (Class test average, Maximun and Minimum test score) -Line 80-
	o A loop structure (for-loop, while-loop, or do-while-loop) 			  -Line 73-
	o Conditional processing (if-then-else) 								  -Line 42-
	o Arrays 																  -Line 71-
*/

#include <iostream> 
#include <iomanip> 
using namespace std;

// Student 
class Student
{
private: 
string name; 
float testScore; 
char grade;	 
public: 
void setName(string n)
{
name = n;
}
void setTestScore (float ts) // Test Score 
{
testScore = ts; // Short score
}
// Grade letter assignment (https://jjay.smartcatalogiq.com/en/2018-2019/Undergraduate-Bulletin/Academic-Standards-and-Policies/Grades/Letter-Grades)
void gradeTable()
{
	if (testScore >= 90) // No cap > 90 : Extra credit grades accepted 
	grade = 'A'; 
	else if (testScore >= 80)
	grade = 'B'; 
	else if (testScore >= 70)
	grade = 'C';
	else if (testScore >= 60)
	grade = 'D';
	else grade = 'F';
}
// User/OS input/Grade prompt 
string getName(){
	return name;
}
float getTestScore(){
	return testScore;
}
char letterGrade(){
	return grade;
}
}; // End Student 

// Display
void display (Student students[],int t)
{
	if (t == 0) // Input complete
	return;
	cout << "==============================================" << endl;
	cout << left << endl << setw(10) << "Name" << setw(15) << "Test Score" << setw(7) << "Grade" << endl;
	cout << setw(10) << "=====" << setw(15) << "==========" << setw(7) << "=====" << endl;
	float maxi, mini, average, sum = 0; // Start Point
	maxi = mini = students[0].getTestScore();
	
	for(int i = 0; i < t; i++) 
{
	sum += students[i].getTestScore(); // Gets student #1 data > #2 > #3 
	// 		Test score 							 Grade (13) after (0) 
	cout << setw(14) << students[i].getName() << setw(13) << students[i].getTestScore() << students[i].letterGrade() << endl; // Order of data 
	maxi = max(maxi,students[i].getTestScore()); // Max value 
	mini = min(mini,students[i].getTestScore()); // Min value 
}
	average = sum / (float)t; // Grade sum / Number of students  
	cout << endl << "===========  Class Statistics  ===============" << endl << endl;
	cout << "Number of students in the class: " << t << endl; // # of students 
	cout << "Class Average: " << average << endl;  // Line 82
	cout << "Maximum Test Score: " << maxi <<endl; // Line 79
	cout << "Minimum Test Score: " << mini <<endl; // Line 80
} // End Display

// Main 
int main()
{
	int t; // # of students
	cout << endl << "How many students data do you wish to enter? ";
	cin >> t;
	cout << endl;
	Student students[t]; // Student objects (t)
	for(int i = 0; i < t; i++) // t = Repeat Cycle, Input Student Names, Student Scores
{ 
	string name;
	float score;
	cout << "Enter student: " << (i + 1) << " || Name: ";
	cin >> name ;
	students[i].setName(name);
	cout << endl << "Enter student: " << (i + 1) << " || Test score: ";
	cin >> score;
	cout << endl;
	students[i].setTestScore(score);
	students[i].gradeTable();
}
	display(students,t); 
	return 0;
} // End main

