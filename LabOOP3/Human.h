#ifndef HUMAN_H
#define HUMAN_H

#include <string>

class Human {
public:
    Human();  // ����������� �� �������������
    Human(std::string name, int age, std::string gender);  // ����������� � �����������
    Human(const Human& other);  // ����������� ���������
    void setName(std::string name);
    void setAge(int age);
    void setGender(std::string gender);
    std::string getName() const;
    int getAge() const;
    std::string getGender() const;

protected:
    std::string name;
    int age;
    std::string gender;
    std::string nationality;
    std::string address;
};

#endif