#ifndef ENCLOSURE_H
#define ENCLOSURE_H

#include "Animal.h"

class Enclosure {
public:
    enum EnclosureType { AQUARIUM, CAGE, TERRARIUM, SAVANNAH };

private:
    int id;
    int size;
    EnclosureType type;
    Animal** currentAnimals;
    int maxAnimals;
    int currentNumAnimals;
public:
    Enclosure(int id, int size, int type, int maxAnimals);
    Enclosure(const Enclosure& other);
    Enclosure(Enclosure&& other);
    virtual ~Enclosure();

    Enclosure& operator=(const Enclosure& other);
    Enclosure& operator=(Enclosure&& other);

    bool addAnimal(Animal& animal);
    bool removeAnimal(const char*& animalName);
    bool isVisitReady() const;

    // Setters and Getters
    int getId() const;
    int getSize() const;
    EnclosureType getType() const;
    int getCurrentNumAnimals() const;

    bool setId(int id);
    bool setSize(int size);
    bool setType(int type);

    Animal** getAnimals() const;
};

#endif
