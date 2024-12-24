#ifndef MAMMAL_H
#define MAMMAL_H

#include "Animal.h"

class Mammal : public Animal {
public:
    enum FurType { SHORT, LONG, CURLY, WATERPROOF, THICK, PATTERNED };

private:
    FurType furType;

public:
    Mammal(const char* name, const char* species, int age, FurType furType);
    Mammal(const Mammal& other);
    Mammal(Mammal&& other);
    virtual ~Mammal();

    Mammal& operator=(const Mammal& other);
    Mammal& operator=(Mammal&& other);

    void groom() const;
    virtual void makeSound() const override;
    virtual void eat() const override;

    // Setter and Getter for furType
    bool setFurType(FurType furType);
    FurType getFurType() const;
};

#endif
