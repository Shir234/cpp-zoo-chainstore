#ifndef OBSERVER_H
#define OBSERVER_H

class Department;

class Observer {
public:
    virtual void update(const Department* department, int salePercentage) = 0;
    virtual ~Observer() = default;
};

#endif