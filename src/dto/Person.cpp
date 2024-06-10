/*
 * Person.cpp
 *
 *  Created on: Apr. 14, 2024
 *      Author: juan
 */

#include "../../include/dto/Person.h"
#include <string>

using namespace std;

Person::Person() : name("Unknwon"), age(0), phone("Unknwon") {}

Person::Person(const string& name, int age, const string& phone)
    : name(name), age(age), phone(phone) {}

const string& Person::getName() const { 
	return name; 
}; 

void Person::setName(const string& name) { 
	this->name = name; 
};

int Person::getAge() const { 
	return age; 
};

void Person::setAge(int age) { 
	this->age = age; 
};

const string& Person::getPhone() const { 
	return phone; 
};

void Person::setPhone(const string& phone) { 
	this->phone = phone; 
};
