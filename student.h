#ifndef STUDENT_H
#define STUDENT_H

#include "degree.h"
#include <string>
#include <array>

class Student {
public:
  //Constructor
  Student(std::string student, 
          std::string first, 
          std::string last, 
          std::string email, 
          int age,
          std::array<int, 3> days,
          DegreeProgram degree);

  //Accessors (getters)
  std::string GetStudentId() const;
  std::string GetFirstName() const;
  std::string GetLastName() const;
  std::string GetEmailAddress() const;
  int GetAge() const;
  std::array<int, 3> GetDaysInCourse() const;
  DegreeProgram GetDegree() const;

  //Mutators (setters)
  void SetStudentId(std::string student);
  void GetFirstName(std::string first);
  void GetLastName(std::string last);
  void GetEmailAddress(std::string email);
  void GetAge(int age);
  void GetDaysInCourse(std::array<int, 3> days);
  void GetDegreeProgram(DegreeProgram degree);

  void Print();

private:
  std::string studentId;
  std::string firstName;
  std::string lastName;
  std::string emailAddress;
  int studentAge;
  std::array<int, 3> daysInCourse;

  DegreeProgram studentDegree;
};

#endif