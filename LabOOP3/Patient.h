#ifndef PATIENT_H
#define PATIENT_H

#include "Human.h"
#include <vector>  // ��� ������������ ������� ������ ������
#include <cstdlib> // ��� ������� rand() �� srand()
#include <ctime>   // ��� ����������� ���������� ���������� �����

// ��������������� ����� Doctor, ������� �� ��������������� � ����������
class Doctor;

class Patient : public Human {
public:
    Patient();  // ����������� �� �������������
    Patient(std::string name, int age, std::string gender, std::string diagnosis);  // ����������� � �����������
    Patient(const Patient& other);  // ����������� ���������
    void setDiagnosis(std::string diagnosis);
    std::string getDiagnosis() const;

    void updateInfo(std::string newDiagnosis);
    void updateInfo(int newAge);  // �������������� ����� ��� ��������� ���

    void assignDoctor(Doctor doctor);  // �����, �� ������ ��'��� ����� Doctor
    Patient getPatient();  // ������� ��'��� ����� Patient

    void printInfo() const;

    void allocateAndSortAges();

    void saveToFile(const std::string& filename = "patient_data.txt") const;
    void loadFromFile(const std::string& filename = "patient_data.txt");


private:
    std::string diagnosis;
    std::string insuranceNumber;
    std::string roomNumber;
    std::string attendingDoctor;
    bool isInCriticalCondition;
};

#endif