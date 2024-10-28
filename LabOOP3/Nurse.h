#ifndef NURSE_H
#define NURSE_H

#include "Human.h"

// Передоголошення класу Doctor
class Doctor;

class Nurse : public Human {
public:
    Nurse();  // Конструктор за замовчуванням
    Nurse(std::string name, int age, std::string gender, int experience);  // Конструктор з параметрами
    Nurse(const Nurse& other);  // Конструктор копіювання
    void setExperience(int experience);
    int getExperience() const;

    void assistDoctor();
    void assistDoctor(Doctor doctor);  // Перевантажений метод

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
    Doctor* assignedDoctor;  // Вказівник на лікаря
};

#endif