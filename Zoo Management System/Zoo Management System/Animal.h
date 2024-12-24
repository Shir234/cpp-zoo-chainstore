#ifndef ANIMAL_H
#define ANIMAL_H

class Animal {
protected:
    char* name;
    char* species;
    int age;

public:
    Animal(const char* name, const char* species, int age);
    Animal(const Animal& other);
    Animal(Animal&& other);
    virtual ~Animal();

    Animal& operator=(const Animal& other);
    Animal& operator=(Animal&& other); // Move assignment operator

    virtual void makeSound() const = 0;     // make this abstract and must be overriden
    virtual void eat() const = 0;

    // Setters and Getters
    const char* getName() const;
    const char* getSpecies() const;
    int getAge() const;

    bool setName(const char*& name);
    bool setSpecies(const char*& species);
    bool setAge(int age);

};

#endif
