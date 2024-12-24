#include <iostream>
using namespace std;

#include <cstring>
#include "Zoo.h"
#include "Enclosure.h"
#include "Person.h"
#include "Ticket.h"
#include "Mammal.h"
#include "Aquatic.h"
#include "Reptile.h"

void displayMenu();
void cleanBuffer();


void addEnclosureToZoo(Zoo& zoo);
void hireZookeeperForZoo(Zoo& zoo);
void admitVisitorToZoo(Zoo& zoo);
void addAnimalToEnclosure(Zoo& zoo);
void feedAnimalInZoo(Zoo& zoo);
void displayZooInformation(const Zoo& zoo);
void buyTicketsForZoo(Zoo& zoo);
void printTicketsInformation(const Zoo& zoo);
void visitEnclosuresInZoo(const Zoo& zoo);
void startTourInZoo(const Zoo& zoo);

void displayMenu() 
{
    cout << "------ Zoo Management System Menu ------" << endl;
    cout << "1. Add a new enclosure" << endl;
    cout << "2. Hire a new zookeeper" << endl;
    cout << "3. Admit a visitor and issue a ticket" << endl;
    cout << "4. Add an animal to an enclosure" << endl;
    cout << "5. Feed an animal" << endl;
    cout << "6. Display Zoo information" << endl;
    cout << "7. Buy Tickets" << endl;
    cout << "8. Print Tickets information" << endl;
    cout << "9. Visit enclosures" << endl;
    cout << "10. Start tour (guided tour in the zoo)" << endl;
    cout << "11. Exit" << endl;
    cout << "---------------------------------------" << endl;
    cout << "Enter your choice: ";
}


int main() 
{
    Zoo zoo("My Zoo", 20, 10, 100); // Example maximum capacities: 20 enclosures, 10 zookeepers, 100 visitors

    int choice;
    do 
    {
        displayMenu();
        cin >> choice;
        cleanBuffer();

        switch (choice) 
        {
            case 1:
                addEnclosureToZoo(zoo);
                break;
            case 2:
                hireZookeeperForZoo(zoo);
                break;
            case 3:
                admitVisitorToZoo(zoo);
                break;
            case 4:
                addAnimalToEnclosure(zoo);
                break;
            case 5:
                feedAnimalInZoo(zoo);
                break;
            case 6:
                displayZooInformation(zoo);
                break;
            case 7:
                buyTicketsForZoo(zoo);
                break;
            case 8:
                printTicketsInformation(zoo);
                break;
            case 9:
                visitEnclosuresInZoo(zoo);
                break;
            case 10:
                startTourInZoo(zoo);
                break;
            case 11:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number from 1 to 11." << endl;
                break;
        }
    } while (choice != 11);

    return 0;
}

void cleanBuffer()
{
    int c;
    do
    {
        c = getchar();
    } while (c != EOF && c != '\n');
}


void addEnclosureToZoo(Zoo& zoo) 
{
    int id, size;
    int type;
    cout << "Enter enclosure ID: ";
    cin >> id;
    cleanBuffer();

    cout << "Enter enclosure size: ";
    cin >> size;
    cleanBuffer();

    cout << "Enter enclosure type (0 - Aquarium, 1 - Cage, 2 - Terrarium, 3 - Savannah): ";
    cin >> type;
    cleanBuffer();

    if (type > 3 || type < 0)
    {
        cout << "Invalid enclosure type. Defaulting to Aquarium." << endl;
        type = 0;
    }

    Enclosure* enclosure = new Enclosure(id, size, type, 10); // Assuming maxAnimals = 10
    zoo.addEnclosure(enclosure);
    cout << "Enclosure added successfully." << endl;
}

void hireZookeeperForZoo(Zoo& zoo) 
{
    char name[50];
    int age;
    int maxEnclosures;

    cout << "Enter zookeeper name: ";
    cin.getline(name, 50);

    cout << "Enter zookeeper age: ";
    cin >> age;
    cleanBuffer();

    cout << "Enter maximum number of enclosures zookeeper can manage: ";
    cin >> maxEnclosures;
    cleanBuffer();

    ZooKeeper* zookeeper = new ZooKeeper(name, age, maxEnclosures);
    zoo.hireZooKeeper(zookeeper);
    cout << "Zookeeper hired successfully." << endl;
}

void admitVisitorToZoo(Zoo& zoo) 
{
    char name[50];
    int age;
    float ticketPrice;
    int ticketType;

    cout << "Enter visitor name: ";
    cin.getline(name, 50);

    cout << "Enter visitor age: ";
    cin >> age;
    cleanBuffer();

    cout << "Enter ticket price: ";
    cin >> ticketPrice;
    cleanBuffer();

    cout << "Enter ticket type (0 - Adult, 1 - Child, 2 - Senior, 3 - Tour): ";
    cin >> ticketType;
    cleanBuffer();

    if (ticketType > 3 || ticketType < 0)
    {
        cout << "Invalid ticket type. Defaulting to Adult." << endl;
        ticketType = 0;
    }

    Ticket ticket(ticketPrice, ticketType);    
    Visitor* visitor = new Visitor(name, age);
    zoo.admitVisitor(visitor);
    visitor->buyTicket(&ticket);
    cout << "Visitor admitted and ticket issued successfully." << endl;
}

void addAnimalToEnclosure(Zoo& zoo) 
{
  //  cout << "Adding animal to enclosure functionality placeholder." << endl;
    char name[50], species[50];
    int age, type, enclosureId;

    cout << "Enter animal name: ";
    cin.getline(name, 50);
    
    cout << "Enter animal type (0 - Mammal, 1 - Aquatic, 2 - Reptile): ";
    cin >> type;
    cleanBuffer();

    cout << "Enter animal species: ";
    cin.getline(species, 50);

    cout << "Enter animal age: ";
    cin >> age;
    cleanBuffer();

    cout << "Enter enclosure ID: ";
    cin >> enclosureId;
    cleanBuffer();

    Animal* animal;
    switch (type) 
    {
        case 0:
            animal = new Mammal(name, species, age, Mammal::SHORT); // Assuming default fur type is SHORT
            break;
        case 1:
            animal = new Aquatic(name, species, age, Aquatic::FRESHWATER); // Assuming default water type is FRESHWATER
            break;
        case 2:
            animal = new Reptile(name, species, age, Reptile::SMOOTH); // Assuming default scale type is SMOOTH
            break;
        default:
            cout << "Invalid animal type. Animal not added." << endl;
            return;
    }

    // Find the enclosure by ID and add the animal
    for (int i = 0; i < zoo.getNumEnclosures(); i++) 
    {
        if (zoo.getEnclosures()[i]->getId() == enclosureId) 
        {
            zoo.getEnclosures()[i]->addAnimal(*animal);
            cout << "Animal added to enclosure successfully." << endl;
            return;
        }
    }
    cout << "Enclosure not found. Animal not added." << endl;
}

void feedAnimalInZoo(Zoo& zoo) 
{
    for (int i = 0; i < zoo.getNumEnclosures(); ++i) {
        Enclosure* enclosure = zoo.getEnclosures()[i];
        Animal** animals = enclosure->getAnimals();
        for (int j = 0; j < enclosure->getCurrentNumAnimals(); ++j) {
            animals[j]->eat();
        }
    }
    cout << "All animals have been fed." << endl;
}

void displayZooInformation(const Zoo& zoo) 
{
    cout << "Zoo Name: " << zoo.getName() << endl;
    cout << "Number of Enclosures: " << zoo.getNumEnclosures() << endl;
    cout << "Number of Zoo Keepers: " << zoo.getNumZooKeepers() << endl;
    cout << "Number of Visitors: " << zoo.getNumVisitors() << endl;

    // Display Enclosure information
    for (int i = 0; i < zoo.getNumEnclosures(); i++)
    {
        Enclosure* enclosure = zoo.getEnclosures()[i];
        cout << "Enclosure ID: " << enclosure->getId() << ", Size: " << enclosure->getSize() << ", Type: " << enclosure->getType() << ", Current Number of Animals: " << enclosure->getCurrentNumAnimals() << endl;
    }

    // Display ZooKeeper information
    for (int i = 0; i < zoo.getNumZooKeepers(); i++)
    {
        cout << "ZooKeeper Name: " << zoo.getZooKeepers()[i]->getName() << ", Age: "
            << zoo.getZooKeepers()[i]->getAge() << ", Max Enclosures: "
            << zoo.getZooKeepers()[i]->getMaxEnclosures() << endl;
    }

    // Display Visitor information
    for (int i = 0; i < zoo.getNumVisitors(); i++)
    {
        cout << "Visitor Name: " << zoo.getVisitors()[i]->getName() << ", Age: "
            << zoo.getVisitors()[i]->getAge() << endl;
    }
}

void buyTicketsForZoo(Zoo& zoo) 
{
    char visitorName[50];
    float ticketPrice;
    int ticketType;

    cout << "Enter visitor name: ";
    cin.getline(visitorName, 50);

    cout << "Enter ticket price: ";
    cin >> ticketPrice;
    cleanBuffer();

    cout << "Enter ticket type (0 - Adult, 1 - Child, 2 - Senior, 3 - Tour): ";
    cin >> ticketType;
    cleanBuffer();

    if (ticketType > 3 || ticketType < 0)
    {
        cout << "Invalid ticket type. Defaulting to Adult." << endl;
        ticketType = 0;
    }

    Ticket ticket(ticketPrice, ticketType);

    for (int i = 0; i < zoo.getNumVisitors(); i++) 
    {
        if (strcmp(zoo.getVisitors()[i]->getName(), visitorName) == 0) 
        {
            zoo.getVisitors()[i]->buyTicket(&ticket);
            cout << "Ticket bought successfully." << endl;
            return;
        }
    }

    cout << "Visitor not found. Ticket not bought." << endl;
}

void printTicketsInformation(const Zoo& zoo) 
{
    for (int i = 0; i < zoo.getNumVisitors(); i++) 
    {
        Ticket* ticket = zoo.getVisitors()[i]->getTickets();
        if (ticket != nullptr) 
        {
            cout << "Visitor Name: " << zoo.getVisitors()[i]->getName() << ", Ticket Price: " << ticket->getPrice() << ", Ticket Type: " << ticket->getType() << endl;
        }
        else 
        {
            cout << "Visitor Name: " << zoo.getVisitors()[i]->getName() << ", No Ticket" << endl;
        }
    }
}

void visitEnclosuresInZoo(const Zoo& zoo) 
{
    char visitorName[50];

    cout << "Enter visitor name: ";
    cin.getline(visitorName, 50);

    for (int i = 0; i < zoo.getNumVisitors(); i++) 
    {
        if (strcmp(zoo.getVisitors()[i]->getName(), visitorName) == 0) 
        {
            cout << "Visitor is visiting enclosures." << endl;
            return;
        }
    }

    cout << "Visitor not found. Cannot visit enclosures." << endl;
}

void startTourInZoo(const Zoo& zoo) 
{
    char guideName[50];

    cout << "Enter guide name: ";
    cin.getline(guideName, 50);

    cout << "Starting tour with guide " << guideName << "." << endl;
    // Assuming tour logic is to visit all enclosures
    visitEnclosuresInZoo(zoo);
}