#ifndef REPTILE_H
#define REPTILE_H

#include "Animal.h"

class Reptile : public Animal {
public:
    enum ScaleType { SMOOTH, KEELED, SCUTES, GRANULAR, OSTEODERMS };

private:
    ScaleType scaleType;

public:
    Reptile(const char* name, const char* species, int age, ScaleType scaleType);
    Reptile(const Reptile& other);
    Reptile(Reptile&& other);
    virtual ~Reptile();

    Reptile& operator=(const Reptile& other);
    Reptile& operator=(Reptile&& other);

    void shedSkin() const;
    virtual void makeSound() const override;
    virtual void eat() const override;

    // Setter and Getter for scaleType
    bool setScaleType(ScaleType scaleType);
    ScaleType getScaleType() const;
};

#endif
