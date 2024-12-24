# cpp-zoo-chainstore

## Part 1: Problem Definition and System Design
### World Problem: Zoo Management System
The goal of this project was to design and implement a comprehensive software solution to manage a Zoo Management System. This system simulates the interactions and workflows of a modern zoo, leveraging object-oriented programming (OOP) principles to ensure scalability, modularity, and maintainability.
### System Overview
The Zoo Management System consists of 12 classes and models, including main operations and functionality of different objects (add enclosures, hire zookeepers, etc) . 
### Design and Planning Process
The design process began by identifying the main entities and their relationships. Each entity was modeled as a class, encapsulating relevant data and behaviors. For example: 
  - Animal Hierarchy: Animals were categorized into hierarchical classes (`Mammal`, `Reptile`, `Aquatic`) based on shared attributes and unique behaviors.
  - Roles in the Zoo: Roles such as visitors, zookeepers, and tour guides were modeled as classes with   
distinct responsibilities. 
The next step involved integrating system requirements with OOP principles to create a robust and extensible design: 
  - Encapsulation: Each class encapsulates its data and methods, providing a clear and controlled interface for interaction.
  - Inheritance: Abstract base classes were used to group shared attributes and behaviors, enabling derived classes to specialize functionality with minimal code duplication.
  - Polymorphism: Abstract methods (`makeSound()`, `prepareTour()`) ensure extensibility, allowing new animal types or roles to be added seamlessly.
  - Dynamic Allocation: The system dynamically allocates and manages entities such as enclosures, animals, staff, and visitors to support scalability.
  - Operator Overloading: Usability was enhanced by overloading operators to intuitively represent operations:
 `+/-`: Add or remove animals from enclosures, or assign and deassign enclosures to zookeepers. -
 `==, <, >`: Compare attributes like age, ticket prices, or enclosure types. 
