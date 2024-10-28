#include "Nurse.h"
#include "Doctor.h"
#include <iostream>
#include <fstream>

Nurse::Nurse()
    : Human(), experience(0), shift("Day"), nurseID("Unknown"), certified(false), assignedWard("Unknown"), assignedDoctor(nullptr) {}

Nurse::Nurse(std::string name, int age, std::string gender, int experience)
    : Human(name, age, gender), experience(experience), shift("Day"), nurseID("Unknown"), certified(false), assignedWard("Unknown"), assignedDoctor(nullptr) {}

Nurse::Nurse(const Nurse& other)
    : Human(other), experience(other.experience), shift(other.shift), nurseID(other.nurseID), certified(other.certified), assignedWard(other.assignedWard), assignedDoctor(other.assignedDoctor) {}

void Nurse::setExperience(int experience) {
    this->experience = experience;
}

int Nurse::getExperience() const {
    return experience;
}

void Nurse::assistDoctor() {
    if (assignedDoctor) {
        std::cout << "Nurse " << getName() << " is assisting Doctor " << assignedDoctor->getName() << "." << std::endl;
    }
    else {
        std::cout << "No doctor assigned to nurse " << getName() << "." << std::endl;
    }
}

// Перевантажений метод assistDoctor, що приймає об'єкт класу Doctor
void Nurse::assistDoctor(Doctor doctor) {
    std::cout << "Nurse " << getName() << " is assisting Doctor " << doctor.getName() << "." << std::endl;
}

// Метод для призначення відділення
void Nurse::assignWard(std::string ward) {
    assignedWard = ward;
    std::cout << "Assigned ward: " << ward << std::endl;
}

// Метод, що повертає об'єкт класу Nurse
Nurse Nurse::getNurse() {
    return *this;
}

void Nurse::printInfo() const {
    std::cout << "\nNurse Information:\n"
        << "Name: " << getName() << "\n"
        << "Age: " << getAge() << "\n"
        << "Gender: " << getGender() << "\n"
        << "Experience: " << experience << " years\n"
        << "Shift: " << shift << "\n"
        << "Nurse ID: " << nurseID << "\n"
        << "Certified: " << (certified ? "Yes" : "No") << "\n"
        << "Assigned Ward: " << assignedWard << "\n";
}

// Метод для запису даних у файл
void Nurse::saveToFile(const std::string& filename) const {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Error opening file for writing.\n";
        return;
    }
    outFile << name << "\n" << age << "\n" << gender << "\n"
        << experience << "\n" << shift << "\n"
        << nurseID << "\n" << certified << "\n"
        << assignedWard << "\n";
    outFile << (assignedDoctor ? assignedDoctor->getName() : "No assigned doctor") << "\n";
    outFile.close();
}

// Метод для зчитування даних із файлу
void Nurse::loadFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Error opening file for reading.\n";
        return;
    }
    std::getline(inFile, name);
    inFile >> age;
    inFile.ignore();
    std::getline(inFile, gender);
    inFile >> experience;
    inFile.ignore();
    std::getline(inFile, shift);
    std::getline(inFile, nurseID);
    inFile >> certified;
    inFile.ignore();
    std::getline(inFile, assignedWard);
    std::string doctorName;
    std::getline(inFile, doctorName);
    if (doctorName != "No assigned doctor") {
        std::cout << "Assigned doctor: " << doctorName << "\n";
    }
    inFile.close();
}