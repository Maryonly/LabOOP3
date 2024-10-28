#ifndef DOCTOR_H
#define DOCTOR_H

#include "Human.h"

// ��������������� ����� Patient, ������� �� ��������������� �� ��������
class Patient;

class Doctor : public Human {
public:
    Doctor();  // ����������� �� �������������
    Doctor(std::string name, int age, std::string gender, std::string specialization);  // ����������� � �����������
    Doctor(const Doctor& other);  // ����������� ���������
    void setSpecialization(std::string specialization);
    std::string getSpecialization() const;

    void treatPatient();
    void treatPatient(std::string treatment);  // �������������� �����

    void assignPatient(Patient* patient);  // ���������� ��������
    void changeDoctor(Doctor otherDoctor);  // �����, �� ������ ��'��� ����� Doctor
    Doctor getDoctor();  // ������� ��'��� ����� Doctor

    void printInfo() const;
    void saveToFile(const std::string& filename = "doctor_data.txt") const;
    void loadFromFile(const std::string& filename = "doctor_data.txt");


private:
    std::string specialization;
    int yearsOfExperience;
    std::string medicalLicense;
    std::string hospitalDepartment;
    double salary;
    Patient* currentPatient;  // �������� �� ��������� ��������
};

#endif