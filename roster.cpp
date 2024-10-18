#include <iostream>
#include "roster.h"
#include "student.h"
#include "degree.h"
#include <array>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

Roster::Roster() {
  std::string studentData[numStudents] = {
    "A1,John,Smith,John.Smith@email.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,William,Craven,wcrave9@wgu.edu,29,20,30,45,SOFTWARE"
  };

  classRosterArray.fill(nullptr);

  for (int i = 0; i < numStudents; ++i) {
    std::stringstream ss(studentData[i]);
    std::vector<std::string> singleStudent; 
    std::string studentDataPart; 

    int j = -1;
    while (std::getline(ss, studentDataPart, ',')) {
      singleStudent.push_back(studentDataPart);
      j++;
    }

    DegreeProgram degreeProgram = SECURITY;
    if (singleStudent[j] == "NETWORK") {
      degreeProgram = NETWORK;
    }
    else if (singleStudent[j] == "SOFTWARE") {
      degreeProgram = SOFTWARE;
    }

    add(singleStudent[0],
        singleStudent[1],
        singleStudent[2],
        singleStudent[3],
        std::stoi(singleStudent[4]),
        std::stoi(singleStudent[5]),
        std::stoi(singleStudent[6]),
        std::stoi(singleStudent[7]),
        degreeProgram);
  }
}

Roster::~Roster() {
  for (int i = 0; i < numStudents; ++i) {
    delete classRosterArray[i];
    classRosterArray[i] = nullptr;
  }
}

void Roster::add(std::string studentID, 
         std::string firstName, 
         std::string lastName,
         std::string emailAddress,
         int age,
         int daysInCourse1,
         int daysInCourse2,
         int daysInCourse3,
         DegreeProgram degreeProgram) {
  Student* newStudent = new Student(studentID, 
                                  firstName, 
                                  lastName,
                                  emailAddress,
                                  age,
                                  {daysInCourse1, daysInCourse2, daysInCourse3},
                                  degreeProgram);

  for (int i = 0; i < numStudents; ++i) {
    if (classRosterArray[i] == nullptr) {
      classRosterArray[i] = newStudent;
      break;
    }
  }
}
    
void Roster::remove(std::string studentID) {
  bool notFound = false;
  for (int i = 0; i < numStudents; ++i) {
    if (classRosterArray[i] != nullptr && studentID == classRosterArray[i]->GetStudentId()) {
      delete classRosterArray[i];
      classRosterArray[i] = nullptr;
      notFound = true;
    }
  }

  if (!notFound) {
      std::cout << "ERROR: Such a student with this ID was not found." << std::endl;
  }
}

void Roster::printAll() {
  for (int i = 0; i < numStudents; ++i) {
    if (classRosterArray[i] != nullptr) {
      classRosterArray[i]->Print();
    }
    
  }
}

void Roster::printAverageDaysInCourse(std::string studentID) {
  std::array<int, 3> avgValues;
  double avg;

  for (int i = 0; i < numStudents; ++i) {
    if (classRosterArray[i]->GetStudentId() == studentID) {
      avgValues = classRosterArray[i]->GetDaysInCourse();
      break;
    }
    
  }

  avg = (avgValues[0] + avgValues[1] + avgValues[2]) / 3.0;
  
  std::cout << "Average days in course for student " << studentID << ": " 
            << std::fixed << std::setprecision(2) << avg << std::endl;
}

void Roster::printInvalidEmails() {
  for (int i = 0; i < numStudents; ++i) {
    std::string email = classRosterArray[i]->GetEmailAddress();
    if (email.find(' ') != std::string::npos ||
        email.find('@') == std::string::npos ||
        email.find('.') == std::string::npos) {
      std::cout << "Invalid email: " << email << std::endl;
    }
  }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
  for (int i = 0; i < numStudents; ++i) {
    DegreeProgram degree = degreeProgram;
    if (degree == classRosterArray[i]->GetDegree()) {
      classRosterArray[i]->Print();
    }
  }
}

int Roster::GetRosterSize() const {
  return classRosterArray.size();
}

Student* Roster::GetStudent(int index) const {
  return classRosterArray[index];
}