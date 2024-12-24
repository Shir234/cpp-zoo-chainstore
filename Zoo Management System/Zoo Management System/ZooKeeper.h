#ifndef ZOOKEEPER_H
#define ZOOKEEPER_H

#include "Person.h"
#include "Enclosure.h"

class ZooKeeper : virtual public Person {
private:
    Enclosure** assignedEnclosures;
    int maxEnclosures;
    int numAssignedEnclosures;

public:
    ZooKeeper(const char* name, int age, int maxEnclosures);
    ZooKeeper(const ZooKeeper& other) = delete;
    //ZooKeeper(ZooKeeper&& other);
    virtual ~ZooKeeper();

    //ZooKeeper& operator=(const ZooKeeper& other);

    void feedAnimal(Animal*& animal);
    void cleanEnclosure(Enclosure& enclosure);
    bool addEnclosure(Enclosure& enclosure);
    bool removeEnclosure(Enclosure& enclosure);
    void speak() const override;

    // Setters and Getters for assignedEnclosures
    Enclosure** getAssignedEnclosures() const;
    int getMaxEnclosures() { return maxEnclosures; }

private:
    ZooKeeper& operator=(const ZooKeeper& other);
    ZooKeeper& operator=(ZooKeeper&& other);

};

#endif
