#ifndef PERSON_H
#define PERSON_H

class Person {
protected:
    char* name;
    int age;

public:
    Person(const char*& name, int age);
    Person(const Person& other) = delete;
    //Person(Person&& other);
    virtual ~Person();

    //Person& operator=(const Person& other);
    //Person& operator=(Person&& other);

    virtual void speak() const = 0;

    // Setters and Getters
    const char* getName() const;
    int getAge() const;
   
    bool setName(const char*& name);
    bool setAge(int age);
   
private:
    Person& operator=(const Person& other);
    Person& operator=(Person&& other);
};

#endif
