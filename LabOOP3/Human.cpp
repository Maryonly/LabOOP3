#include "Human.h"

Human::Human()
    : name("Unknown"), age(0), gender("Unknown"), nationality("Unknown"), address("Unknown") {}

Human::Human(std::string name, int age, std::string gender)
    : name(name), age(age), gender(gender), nationality("Unknown"), address("Unknown") {}

Human::Human(const Human& other)
    : name(other.name), age(other.age), gender(other.gender), nationality(other.nationality), address(other.address) {}
void Human::setName(std::string name) {
    this->name = name;
}

void Human::setAge(int age) {
    this->age = age;
}

void Human::setGender(std::string gender) {
    this->gender = gender;
}

std::string Human::getName() const {
    return name;
}

int Human::getAge() const {
    return age;
}

std::string Human::getGender() const {
    return gender;
}