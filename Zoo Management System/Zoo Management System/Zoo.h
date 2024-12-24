#ifndef ZOO_H
#define ZOO_H

#include "Enclosure.h"
#include "ZooKeeper.h"
#include "Visitor.h"


class Zoo {
private:
    char* name;
    Enclosure** enclosures;
    int maxEnclosures;
    int numEnclosures;
    ZooKeeper** zooKeepers;
    int maxZooKeepers;
    int numZooKeepers;
    Visitor** visitors;
    int maxVisitors;
    int numVisitors;

public:
    Zoo(const char* name, int maxEnclosures, int maxZooKeepers, int maxVisitors);
    Zoo(const Zoo& other);
    Zoo(Zoo&& other);
    ~Zoo();

    Zoo& operator=(const Zoo& other);
    
    void addEnclosure(Enclosure*& enclosure);
    void hireZooKeeper(ZooKeeper*& zookeeper);
    void admitVisitor(Visitor*& visitor);


    // Setters and Getters
    const char* getName() const;
    Enclosure** getEnclosures() const;
    int getNumEnclosures() const;

    ZooKeeper** getZooKeepers() const;
    int getNumZooKeepers() const;

    Visitor** getVisitors() const;
    int getNumVisitors() const;


    bool setName(const char*& name);
    bool setEnclosures(Enclosure**& enclosures, int numEnclosures);
    bool setZooKeepers(ZooKeeper**& zooKeepers, int numZooKeepers);
    bool setVisitors(Visitor**& visitors, int numVisitors);
};

#endif
