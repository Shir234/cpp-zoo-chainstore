#ifndef TOURGUIDE_H
#define TOURGUIDE_H

#include "Person.h"

class TourGuide : virtual public Person {
private:
    char** languages;
    int numLanguages;

public:
    TourGuide(const char*& name, int age, int maxLanguages);
    TourGuide(const TourGuide& other) = delete;
    //TourGuide(TourGuide&& other);
    virtual ~TourGuide();

    //TourGuide& operator=(const TourGuide& other);

    void giveTour() const;
    void speak() const override;

    // Setters and Getters for languages
    char** getLanguages() const;
    bool setLanguages(const char*& languages);

private:
    TourGuide& operator=(const TourGuide& other);
    TourGuide& operator=(TourGuide&& other);

};

#endif
