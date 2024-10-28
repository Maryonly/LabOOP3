#include "Hospital.h"
#include "Doctor.h"
#include "Patient.h"
#include "Nurse.h"
#include <iostream>

void yearsToHundred(const Patient& patient) {
    int age = patient.getAge();
    int yearsLeft = 100 - age;
    std::cout << "Patient " << patient.getName() << " has "
        << yearsLeft << " years left to reach 100." << std::endl;
}

// Функція для створення об'єкта пацієнта та використання методів класу
Patient createPatient(const std::string& name, int age, const std::string& gender, const std::string& diagnosis) {
    // Створюємо об'єкт класу Patient з параметрами
    Patient patient(name, age, gender, diagnosis);

    // Оновлюємо діагноз пацієнта за допомогою методу updateInfo
    std::string newDiagnosis = "Updated Diagnosis";
    patient.updateInfo(newDiagnosis);

    // Викликаємо метод printInfo для виведення інформації про пацієнта
    patient.printInfo();

    // Використовуємо getPatient() для повернення об'єкта
    return patient.getPatient();
}

int main() {
    Hospital hospital("City Hospital", "Downtown", 30);
    // Статичні об'єкти
    Doctor doc1("Dr. Smith", 45, "Male", "Cardiology");
    Doctor doc2("Dr. Brown", 50, "Female", "Neurology");
    Patient patient1("John Doe", 60, "Male", "Heart Disease");
    Patient patient2("Jane Roe", 55, "Female", "Diabetes");
    Nurse nurse1("Emily Johnson", 30, "Female", 5);

    // Динамічні об'єкти
    Doctor* doc3 = new Doctor("Dr. White", 40, "Male", "Pediatrics");
    Doctor* doc4 = new Doctor("Dr. Green", 38, "Female", "Orthopedics");
    Patient* patient3 = new Patient("Mike Wayne", 25, "Male", "Fracture");
    Patient* patient4 = new Patient("Anna Lee", 45, "Female", "Asthma");
    Nurse* nurse2 = new Nurse("Kate Winslow", 29, "Female", 3);

    doc1.assignPatient(&patient1);   // Призначаємо пацієнта лікарю
    nurse1.assistDoctor(doc1);     // Призначаємо лікаря медсестрі
    doc1.treatPatient("Differential Diagnosis");  // Лікар лікує пацієнта
    patient1.setDiagnosis("Confirmed Diagnosis");

    patient1.saveToFile();
    nurse1.saveToFile();
    doc1.saveToFile();
    doc2.saveToFile();
    doc2.loadFromFile();

    std::cout << "\n--- Staff and Patient Information ---\n";
    // Використання методів для перевірки створених об'єктів
    doc1.printInfo();
    doc2.printInfo();
    patient1.printInfo();
    patient2.printInfo();
    nurse1.printInfo();

    doc3->printInfo();
    doc4->printInfo();
    patient3->printInfo();
    patient4->printInfo();
    nurse2->printInfo();

    // Вектори для об'єктів Doctor і Patient
    std::vector<Doctor> doctors;
    std::vector<Patient> patients;

    // Додавання об'єктів у вектори
    doctors.emplace_back("Dr.Johnson", 52, "Female", "Oncology");
    doctors.emplace_back("Dr.Garcia", 43, "Male", "Dermatology");
    doctors.emplace_back("Dr. White", 40, "Male", "Pediatrics");

    patients.emplace_back("Robert Brown", 75, "Male", "Arthritis");
    patients.emplace_back("Lisa Miller", 40, "Female", "Thyroid Issues");
    patients.emplace_back("Mike Wayne", 25, "Male", "Fracture");

    // Використання методів об'єктів у векторах
    std::cout << "\n--- Doctors Information ---\n";
    for (auto& doctor : doctors) {
        doctor.printInfo();
        doctor.setSpecialization("Updated Specialization");
        std::cout << "Updated Specialization: " << doctor.getSpecialization() << "\n";
    }

    std::cout << "\n--- Patients Information ---\n";
    for (auto& patient : patients) {
        patient.printInfo();
        patient.updateInfo("Updated Diagnosis");
        std::cout << "Updated Diagnosis: " << patient.getDiagnosis() << "\n";
    }

    // Додавання нових об'єктів у вектори
    doctors.emplace_back("Dr. Green", 38, "Female", "Orthopedics");
    doctors.emplace_back("Dr. Black", 42, "Male", "Oncology");

    patients.emplace_back("Anna Lee", 45, "Female", "Asthma");
    patients.emplace_back("Chris Evans", 30, "Male", "Skin Infection");

    std::cout << "\n--- Updated Doctors Information ---\n";
    for (const auto& doctor : doctors) {
        doctor.printInfo();
    }

    std::cout << "\n--- Updated Patients Information ---\n";
    for (const auto& patient : patients) {
        patient.printInfo();
    }

    Patient patient5("Alice Green", 34, "Female", "Flu");
    // Виклик методу, що виділяє динамічну пам'ять та сортує значення
    patient5.allocateAndSortAges();

    // Додаємо персонал та пацієнтів до лікарні
    hospital.addDoctor(doc1);
    hospital.addPatient(patient1);
    hospital.addNurse(nurse1);
    hospital.showStaff();

    // Виводимо кількість лікарень після створення
    std::cout << "Current hospital count: " << Hospital::getHospitalCount() << std::endl;

    // Виклик функції, що працює з об'єктом
    yearsToHundred(patient1);

    //patient2.getPatient();


    // Виклик функції createPatient для створення пацієнта
    Patient patient = createPatient("Linda Martinez", 55, "Female", "Hypertension");
    // Очищення динамічної пам'яті
    delete doc3;
    delete doc4;
    delete patient3;
    delete patient4;
    delete nurse2;
    return 0;
}

