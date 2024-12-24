#ifndef VISITOR_H
#define VISITOR_H

#include "Person.h"

class Ticket;

class Visitor : public Person {
private:
    Ticket* tickets;

public:
    Visitor(const char* name, int age);
    Visitor(const Visitor& other) = delete;
    //Visitor(Visitor&& other);
    virtual ~Visitor();

 /*   Visitor& operator=(const Visitor& other);*/

    void buyTicket(Ticket* ticket);
    void visitEnclosure(Enclosure& enclosure) const;
    virtual void speak() const override;

    // Setters and Getters for tickets
    Ticket* getTickets() const;
private:
    Visitor& operator=(const Visitor& other);
    Visitor& operator=(Visitor&& other);
};

#endif