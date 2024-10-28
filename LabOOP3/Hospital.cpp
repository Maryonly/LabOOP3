#include "Hospital.h"
#include <iostream>

// ����������� ���������� ����
int Hospital::hospitalCount = 0;

// ����������� � ����������� �� ������� �����������
Hospital::Hospital(const std::string& name, const std::string& location, int maxCapacity)
    : name(name), location(location), maxCapacity(maxCapacity) {
    // �������� ������� ������� ��� �������� ���� �����
    hospitalCount++;
}

// ������ ����� �� ������, ���� �� ���������� ������� �����
void Hospital::addDoctor(const Doctor& doctor) {
    if (doctors.size() < maxCapacity) {
        doctors.push_back(doctor);
    }
    else {
        std::cout << "Cannot add doctor. Maximum capacity reached.\n";
    }
}

// ������ �������� �� ������, ���� �� ���������� ������� �����
void Hospital::addPatient(const Patient& patient) {
    if (patients.size() < maxCapacity) {
        patients.push_back(patient);
    }
    else {
        std::cout << "Cannot add patient. Maximum capacity reached.\n";
    }
}

// ������ ��������� �� ������, ���� �� ���������� ������� �����
void Hospital::addNurse(const Nurse& nurse) {
    if (nurses.size() < maxCapacity) {
        nurses.push_back(nurse);
    }
    else {
        std::cout << "Cannot add nurse. Maximum capacity reached.\n";
    }
}

// �������� ���������� ��� �������� �����
void Hospital::showStaff() const {
    std::cout << "Hospital: " << name << "\nLocation: " << location << "\nMaximum Capacity: " << maxCapacity << "\nDoctors: " << std::endl;
    for (const auto& doctor : doctors) {
        std::cout << "- " << doctor.getName() << " (Specialization: " << doctor.getSpecialization() << ")" << std::endl;
    }
    std::cout << "Nurses: " << std::endl;
    for (const auto& nurse : nurses) {
        std::cout << "- " << nurse.getName() << " (Experience: " << nurse.getExperience() << " years)" << std::endl;
    }
    std::cout << "Patients: " << std::endl;
    for (const auto& patient : patients) {
        std::cout << "- " << patient.getName() << " (Diagnosis: " << patient.getDiagnosis() << ")" << std::endl;
    }
}

// ��������� ����� ��� ��������� ������� �������
int Hospital::getHospitalCount() {
    return hospitalCount;
}
