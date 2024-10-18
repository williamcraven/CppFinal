#include <iostream>
#include <array>
#include "student.h"
#include "roster.h"
#include "degree.h"

Student::Student (std::string student, 
                  std::string first, 
                  std::string last, 
                  std::string email, 
                  int age, 
                  std::array<int, 3> days,
                  DegreeProgram degree) : 
                    
                  studentId(student), 
                  firstName(first),
                  lastName(last),
                  emailAddress(email),
                  studentAge(age),
                  daysInCourse(days),
                  studentDegree(degree) {
}

//Accessors (getters)
std::string Student::GetStudentId() const {
  return studentId;
}
std::string Student::GetFirstName() const {
  return firstName;
}
std::string Student::GetLastName() const {
  return lastName;
}
std::string Student::GetEmailAddress() const {
  return emailAddress;
}
int Student::GetAge() const{
  return studentAge;
}
std::array<int, 3> Student::GetDaysInCourse() const {
  return daysInCourse;
}
DegreeProgram Student::GetDegree() const {
  return studentDegree;
}

//Mutators (setters)
void Student::SetStudentId(std::string student) {
  studentId = student;
}
void Student::GetFirstName(std::string first) {
  firstName = first;
}
void Student::GetLastName(std::string last) {
  lastName = last;
}
void Student::GetEmailAddress(std::string email) {
  emailAddress = email;
}
void Student::GetAge(int age) {
  studentAge = age;
}
void Student::GetDaysInCourse(std::array<int, 3> days) {
  daysInCourse = days;
}
void Student::GetDegreeProgram(DegreeProgram degree) {
  studentDegree = degree;
}

void Student::Print() {
  std::cout << studentId << "\t"
            << "First Name: " << firstName << "\t"
            << "Last Name: " << lastName << "\t"
            << "Age: " << studentAge << "\t"
            << "daysInCourse: " << "{" << daysInCourse[0] << ", " << daysInCourse[1] << ", " << daysInCourse[2] << "}\t"
            << "Degree Program: ";
  if (studentDegree == SOFTWARE) {
    std::cout << "Software" << std::endl;
  }
  else if (studentDegree == SECURITY) {
    std::cout << "Security" << std::endl;
  }
  else {
    std::cout << "Network" << std::endl;
  }
}

