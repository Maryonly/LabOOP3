#ifndef NURSE_H
#define NURSE_H

#include "Human.h"

// ��������������� ����� Doctor
class Doctor;

class Nurse : public Human {
public:
    Nurse();  // ����������� �� �������������
    Nurse(std::string name, int age, std::string gender, int experience);  // ����������� � �����������
    Nurse(const Nurse& other);  // ����������� ���������
    void setExperience(int experience);
    int getExperience() const;

    void assistDoctor();
    void assistDoctor(Doctor doctor);  // �������������� �����

    void assignWard(std::string ward);
    Nurse getNurse();

    void printInfo() const;

    void saveToFile(const std::string& filename = "nurse_data.txt") const;
    void loadFromFile(const std::string& filename = "nurse_data.txt");


private:
    int experience;
    std::string shift;
    std::string nurseID;
    bool certified;
    std::string assignedWard;
    Doctor* assignedDoctor;  // �������� �� �����
};

#endif