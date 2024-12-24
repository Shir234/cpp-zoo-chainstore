#ifndef TICKET_H
#define TICKET_H

class Ticket {
public:
    enum Type { ADULT, CHILD, SENIOR, TOUR };

private:
    float price;
    Type type;

public:
    Ticket(float price, int type);
    Ticket(const Ticket& other);
    Ticket(Ticket&& other);
    ~Ticket();

    Ticket& operator=(const Ticket& other);

    void print() const;
    float calculateDiscount() const;

    // Setters and Getters
    bool setPrice(float price);
    float getPrice() const;

    bool setType(int type);
    Type getType() const;
};

#endif
