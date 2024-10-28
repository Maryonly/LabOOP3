#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <vector>
#include "Doctor.h"
#include "Patient.h"
#include "Nurse.h"

class Hospital {
public:
    Hospital(const std::string& name, const std::string& location, int maxCapacity);  // ����������� � �����������

    void addDoctor(const Doctor& doctor);
    void addPatient(const Patient& patient);
    void addNurse(const Nurse& nurse);
    void showStaff() const;

    static int getHospitalCount();  // ��������� ����� ��� ��������� ������� �������

private:
    const int maxCapacity;  // ����������� ������� ��������� �� ��������
    
    std::string name;
    std::string location;
    std::vector<Doctor> doctors;
    std::vector<Patient> patients;
    std::vector<Nurse> nurses;

    static int hospitalCount;  // �������� ���� ��� ��������� ������� ��������� �������
};

#endif
