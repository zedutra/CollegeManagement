/*
 * Person.h
 *
 *  Created on: Apr. 14, 2024
 *      Author: juan
 */

#ifndef INCLUDE_PERSON_H_
#define INCLUDE_PERSON_H_

#include <string>

using namespace std;

class Person {
	string name;
	int age;
	string phone;
public:
	Person();
    Person(const string& name, int age, const string& phone);
    virtual ~Person() {}

    const string& getName() const;
    void setName(const string& name);

    int getAge() const;
    void setAge(int age);

    const string& getPhone() const;
    void setPhone(const string& phone);
};

#endif 
