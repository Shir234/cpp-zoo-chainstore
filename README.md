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


## Part 2+3: Continuation Chain Store Management System
### Overview
This project is a continuation of the Chain Store Management System, originally designed by another team as their Part 1 submission. The initial part defined the problem, designed the class structure, and created the main and header files. Parts 2+3 focused on implementing the functionality, adding exception handling, and adjusting the initial plan where necessary to deliver a complete solution to the original problem.

### Process
#### Review the initial implementation
The first step was to analyze the original codebase, the class structure, headers and main function, understand the problem definition and intended workflow.
identifying areas requiring improvement or clarification (missing methods definitions, inconsistencies between classes relationships)
#### adjust the design:
While preserving the original design intent, certain adjustments were made to align with project requirements and OOP principles:
- Abstract Classes: Abstract classes were redefined or removed where unnecessary. The Department class was changed from abstract to concrete to align with implementation logic.
- Class Relationships: Inherited classes and relationships were adjusted to reduce redundancy.
- Memory Allocation: Replaced static arrays with dynamically allocated structures for better flexibility and scalability.
- Setters and Getters: Added necessary setters and getters for encapsulation.
- Constructor/Destructor and Operators: In each class that had dynamic allocations, I added:
  - Constructor, copy constructor, move constructor, destructor, assignment operator, and move assignment operator.
  - These additions ensure proper memory management and resource handling.


#### Implementation of Functionality:
Implemented all remaining methods and completed the functionality of the system, including:
- Adding and managing branches, departments, employees, and inventory.
- Introducing user-friendly operations for adding/removing items, hiring employees, and viewing system details.
- Ensuring seamless interaction between different components through encapsulated class.
### Enhancements:
#### Exception Handling:
- Added exception handling to manage invalid inputs, inventory overflows, and other runtime errors.
- Designed custom exception classes for specific scenarios, improving error feedback and debugging capabilities.
- Implemented the following exception handling practices:
  - Set Methods: Set methods now throw exceptions instead of returning a boolean to indicate errors.
  - Constructors: Constructors throw exceptions or call other methods that may throw exceptions, ensuring that errors are captured during object creation.
  - Memory Management: Used try-catch blocks when handling memory free operations to ensure resources are freed properly and exceptions are caught without causing program termination.
  - Input Validation: Some try-catch blocks are placed inside while loops to ensure valid input, preventing errors from terminating the program.
  - General Exception Handling: A catch(...) block is implemented in the main function to prevent the program from exiting without handling exceptions.



### Design Patterns: 
- Singleton: Used in the ChainStore class to ensure only one instance of the store exists.
- Prototype: Implemented in the Branch class for efficient cloning of branches.
- Observer: Added to notify dependent entities (e.g., departments and items) of changes in inventory or promotions.

