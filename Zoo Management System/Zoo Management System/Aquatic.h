#ifndef AQUATIC_H
#define AQUATIC_H

#include "Animal.h"

class Aquatic : public Animal {
public:
    enum WaterType { FRESHWATER, SALTWATER, BRACKISH, COLD, TROPICAL, TEMPERATE };

private:
    WaterType waterType;

public:
    Aquatic(const char* name, const char* species, int age, WaterType waterType);
    Aquatic(const Aquatic& other);
    Aquatic(Aquatic&& other);
    virtual ~Aquatic();

    Aquatic& operator=(const Aquatic& other);
    Aquatic& operator=(Aquatic&& other);

    void swim() const;
    virtual void makeSound() const override;
    virtual void eat() const override;

    // Setter and Getter for waterType
    bool setWaterType(WaterType waterType);
    WaterType getWaterType() const;
};

#endif
