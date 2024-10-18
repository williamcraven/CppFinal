#include <iostream>
#include "student.h"
#include "roster.h"

int main() {
  std::cout << "Course Title: Scripting and Programming - Applications - C867" << std::endl
            << "Programming Language: C++" << std::endl
            << "Student ID: 011721568" << std::endl
            << "Name: William Craven" << std::endl << std::endl;

  Roster classRoster;

  classRoster.printAll();
  std::cout << std::endl;

  classRoster.printInvalidEmails();
  std::cout << std::endl;

  for (int i = 0; i < classRoster.GetRosterSize(); ++i) {
    std::string studentID = classRoster.GetStudent(i)->GetStudentId();
    classRoster.printAverageDaysInCourse(studentID);
  }
  std::cout << std::endl;

  classRoster.printByDegreeProgram(SOFTWARE);
  std::cout << std::endl;

  classRoster.remove("A3");
  std::cout << std::endl;

  classRoster.printAll();
  std::cout << std::endl;

  classRoster.remove("A3");
  std::cout << std::endl;

  //Automatic Destructor call after main ends

  return 0;
}