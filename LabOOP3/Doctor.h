#ifndef DOCTOR_H
#define DOCTOR_H

#include "Human.h"

// Передоголошення класу Patient, оскільки він використовується як вказівник
class Patient;

class Doctor : public Human {
public:
    Doctor();  // Конструктор за замовчуванням
    Doctor(std::string name, int age, std::string gender, std::string specialization);  // Конструктор з параметрами
    Doctor(const Doctor& other);  // Конструктор копіювання
    void setSpecialization(std::string specialization);
    std::string getSpecialization() const;

    void treatPatient();
    void treatPatient(std::string treatment);  // Перевантажений метод

    void assignPatient(Patient* patient);  // Призначити пацієнта
    void changeDoctor(Doctor otherDoctor);  // Метод, що приймає об'єкт класу Doctor
    Doctor getDoctor();  // Повертає об'єкт класу Doctor

    void printInfo() const;
    void saveToFile(const std::string& filename = "doctor_data.txt") const;
    void loadFromFile(const std::string& filename = "doctor_data.txt");


private:
    std::string specialization;
    int yearsOfExperience;
    std::string medicalLicense;
    std::string hospitalDepartment;
    double salary;
    Patient* currentPatient;  // Вказівник на поточного пацієнта
};

#endif