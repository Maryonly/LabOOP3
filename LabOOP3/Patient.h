#ifndef PATIENT_H
#define PATIENT_H

#include "Human.h"
#include <vector>  // Для використання вектора замість масиву
#include <cstdlib> // Для функцій rand() та srand()
#include <ctime>   // Для ініціалізації генератора випадкових чисел

// Передоголошення класу Doctor, оскільки він використовується в параметрах
class Doctor;

class Patient : public Human {
public:
    Patient();  // Конструктор за замовчуванням
    Patient(std::string name, int age, std::string gender, std::string diagnosis);  // Конструктор з параметрами
    Patient(const Patient& other);  // Конструктор копіювання
    void setDiagnosis(std::string diagnosis);
    std::string getDiagnosis() const;

    void updateInfo(std::string newDiagnosis);
    void updateInfo(int newAge);  // Перевантажений метод для оновлення віку

    void assignDoctor(Doctor doctor);  // Метод, що приймає об'єкт класу Doctor
    Patient getPatient();  // Повертає об'єкт класу Patient

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