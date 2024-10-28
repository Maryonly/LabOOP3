#include "Doctor.h"
#include "Patient.h"
#include <iostream>
#include <fstream>

Doctor::Doctor()
    : Human(), specialization("Unknown"), yearsOfExperience(0), medicalLicense("Unknown"), hospitalDepartment("Unknown"), salary(0.0), currentPatient(nullptr) {}

Doctor::Doctor(std::string name, int age, std::string gender, std::string specialization)
    : Human(name, age, gender), specialization(specialization), yearsOfExperience(0), medicalLicense("Unknown"), hospitalDepartment("Unknown"), salary(0.0), currentPatient(nullptr) {}

Doctor::Doctor(const Doctor& other)
    : Human(other), specialization(other.specialization), yearsOfExperience(other.yearsOfExperience), medicalLicense(other.medicalLicense), hospitalDepartment(other.hospitalDepartment), salary(other.salary), currentPatient(other.currentPatient) {}
void Doctor::setSpecialization(std::string specialization) {
    this->specialization = specialization;
}

std::string Doctor::getSpecialization() const {
    return specialization;
}

void Doctor::treatPatient() {
    if (currentPatient) {
        std::cout << "Doctor " << getName() << " is treating patient " << currentPatient->getName() << "." << std::endl;
    }
    else {
        std::cout << "No patient assigned to doctor " << getName() << "." << std::endl;
    }
}

// Перевантажений метод treatPatient, що приймає назву лікування
void Doctor::treatPatient(std::string treatment) {
    if (currentPatient) {
        std::cout << "Doctor " << getName() << " is treating patient " << currentPatient->getName() << " with " << treatment << "." << std::endl;
    }
    else {
        std::cout << "No patient assigned to doctor " << getName() << "." << std::endl;
    }
}

void Doctor::assignPatient(Patient* patient) {
    currentPatient = patient;
}

// Метод, що приймає інший об'єкт класу Doctor і змінює лікаря
void Doctor::changeDoctor(Doctor otherDoctor) {
    this->specialization = otherDoctor.getSpecialization();
    this->yearsOfExperience = otherDoctor.yearsOfExperience;
    std::cout << "Doctor changed to: " << otherDoctor.getName() << "\n";
}

// Метод, що повертає об'єкт класу Doctor
Doctor Doctor::getDoctor() {
    return *this;
}

void Doctor::printInfo() const {
    std::cout << "\nDoctor Information:\n"
        << "Name: " << getName() << "\n"
        << "Age: " << getAge() << "\n"
        << "Gender: " << getGender() << "\n"
        << "Specialization: " << specialization << "\n"
        << "Years of Experience: " << yearsOfExperience << "\n"
        << "Medical License: " << medicalLicense << "\n"
        << "Department: " << hospitalDepartment << "\n"
        << "Salary: " << salary << "\n";
    if (currentPatient) {
        std::cout << "Currently treating patient: " << currentPatient->getName() << "\n";
    }
    else {
        std::cout << "No patient is currently assigned.\n";
    }
}

// Метод для запису даних у файл
void Doctor::saveToFile(const std::string& filename) const {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Error opening file for writing.\n";
        return;
    }
    outFile << name << "\n" << age << "\n" << gender << "\n"
        << specialization << "\n" << yearsOfExperience << "\n"
        << medicalLicense << "\n" << hospitalDepartment << "\n"
        << salary << "\n";
    outFile << (currentPatient ? currentPatient->getName() : "No current patient") << "\n";
    outFile.close();
}

// Метод для зчитування даних із файлу
void Doctor::loadFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Error opening file for reading.\n";
        return;
    }
    std::getline(inFile, name);
    inFile >> age;
    inFile.ignore();
    std::getline(inFile, gender);
    std::getline(inFile, specialization);
    inFile >> yearsOfExperience;
    inFile.ignore();
    std::getline(inFile, medicalLicense);
    std::getline(inFile, hospitalDepartment);
    inFile >> salary;
    inFile.ignore();
    std::string patientName;
    std::getline(inFile, patientName);
    if (patientName != "No current patient") {
        std::cout << "Current patient: " << patientName << "\n";
    }
    inFile.close();
}