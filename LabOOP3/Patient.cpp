#include "Patient.h"
#include "Doctor.h"
#include <iostream>
#include <fstream>
#include <algorithm>

Patient::Patient()
    : Human(), diagnosis("Unknown"), insuranceNumber("Unknown"), roomNumber("Unknown"), attendingDoctor("Unknown"), isInCriticalCondition(false) {}

Patient::Patient(std::string name, int age, std::string gender, std::string diagnosis)
    : Human(name, age, gender), diagnosis(diagnosis), insuranceNumber("Unknown"), roomNumber("Unknown"), attendingDoctor("Unknown"), isInCriticalCondition(false) {}

Patient::Patient(const Patient& other)
    : Human(other), diagnosis(other.diagnosis), insuranceNumber(other.insuranceNumber), roomNumber(other.roomNumber), attendingDoctor(other.attendingDoctor), isInCriticalCondition(other.isInCriticalCondition) {}
void Patient::allocateAndSortAges() {
    // ������������ ��������� ����� ��� ������� �������� � �����
    srand(time(0));
    int size = rand() % 10 + 1; // ��������� ����� �� 1 �� 10

    // �������� ���'��� � ������
    std::vector<int> ages(size, getAge());

    // ������� �������� � ����������� �������
    std::sort(ages.begin(), ages.end());

    // ��������� ������������� ������
    std::cout << "Sorted ages in dynamically allocated memory:\n";
    for (int age : ages) {
        std::cout << age << " ";
    }
    std::cout << std::endl;
}

void Patient::setDiagnosis(std::string diagnosis) {
    this->diagnosis = diagnosis;
}

std::string Patient::getDiagnosis() const {
    return diagnosis;
}

void Patient::updateInfo(std::string newDiagnosis) {
    diagnosis = newDiagnosis;
    std::cout << "Diagnosis updated to: " << newDiagnosis << std::endl;
}

// �������������� ����� updateInfo ��� ���� ��� ��������
void Patient::updateInfo(int newAge) {
    setAge(newAge);
    std::cout << "Age updated to: " << newAge << std::endl;
}

// �����, �� ������ ��'��� ����� Doctor
void Patient::assignDoctor(Doctor doctor) {
    attendingDoctor = doctor.getName();
    std::cout << "Assigned doctor: " << attendingDoctor << std::endl;
}

// �����, �� ������� ��'��� ����� Patient
Patient Patient::getPatient() {
    return *this;
}

void Patient::printInfo() const {
    std::cout << "\nPatient Information:\n"
        << "Name: " << getName() << "\n"
        << "Age: " << getAge() << "\n"
        << "Gender: " << getGender() << "\n"
        << "Diagnosis: " << diagnosis << "\n"
        << "Insurance Number: " << insuranceNumber << "\n"
        << "Room Number: " << roomNumber << "\n"
        << "Attending Doctor: " << attendingDoctor << "\n"
        << "Critical Condition: " << (isInCriticalCondition ? "Yes" : "No") << "\n";
}

// ����� ��� ������ ����� � ����
void Patient::saveToFile(const std::string& filename) const {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Error opening file for writing.\n";
        return;
    }
    outFile << name << "\n" << age << "\n" << gender << "\n"
        << diagnosis << "\n" << insuranceNumber << "\n"
        << roomNumber << "\n" << attendingDoctor << "\n"
        << isInCriticalCondition << "\n";
    outFile.close();
}

// ����� ��� ���������� ����� �� �����
void Patient::loadFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Error opening file for reading.\n";
        return;
    }
    std::getline(inFile, name);
    inFile >> age;
    inFile.ignore();
    std::getline(inFile, gender);
    std::getline(inFile, diagnosis);
    std::getline(inFile, insuranceNumber);
    std::getline(inFile, roomNumber);
    std::getline(inFile, attendingDoctor);
    inFile >> isInCriticalCondition;
    inFile.close();
}