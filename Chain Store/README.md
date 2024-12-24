
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

