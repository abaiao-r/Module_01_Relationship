# Module_01_Relationship

# Introduction

This project aims to explore various relationships between objects in Object-Oriented Programming (OOP). The exercises focus on practical applications of composition, aggregation, inheritance, and association using a computer system model. Understanding these relationships is crucial for designing flexible and maintainable code.

## Why is Relationships in OOP Relevant?

Relationships in OOP are essential because they help model real-world interactions between objects, making software more intuitive. They support encapsulation, which protects data and simplifies complexity. Relationships also promote code reusability through inheritance and composition, allowing developers to build on existing code efficiently. Additionally, they enable polymorphism, providing flexibility in how objects are used. Well-defined relationships lead to better maintainability and organization of code, making it easier to update systems. Overall, understanding these relationships is crucial for creating robust and scalable software solutions.

## How to Run

1. **Clone the Repository**:  
   ```sh
   git clone git@github.com:abaiao-r/Module_01_Relationship.git
   cd Module_01_Relationship
   ```

2. **For each exercise, go to its directory, compile the code, and run the executable**:
   ```sh
    cd ex00
    make all
    ./relationship
   ```

## Exercises

### Exercise 00: Putting it into Practice

- **Synopsis**: This exercise aims to practice object relationships by implementing classes and structures representing a computer system. You will work with composition, aggregation, inheritance, and association to build a functional model.

- **Relevance**: This exercise is relevant as it helps in understanding how different types of relationships between objects impact the design and functionality of a system. By working on these relationships, you can learn how to create robust, scalable, and maintainable software solutions.

### Exercise IV.1: Composition

- **Description**: Implement the `Position` and `Statistic` structures, and the `Worker` class that uses these structures as composition.

- **Composition**: Means that an object is composed of other objects. The composed objects cannot exist independently of the parent object. When the parent object is destroyed, the composed objects are also destroyed. In this exercise, the `Worker` class is composed of `Position` and `Statistic` structures. The `Worker` class manages the lifecycle of these structures.

### Exercise IV.2: Aggregation

- **Description**: Introduce the `Shovel` class with a method to be used by a `Worker`. Ensure proper management of the `Shovel` object during the worker's lifecycle.

- **Aggregation**: Means that an object can exist independently of the parent object. The parent object contains a reference to the aggregated object, but the aggregated object can exist on its own. In this exercise, the `Worker` class aggregates the `Shovel` class. The `Worker` class manages the lifecycle of the `Shovel` object, but the `Shovel` object can exist independently of the `Worker` object.

### Exercise IV.3: Inheritance

- **Description**: Create an abstract `Tool` class and derive `Shovel` and `Hammer` from it. Modify the `Worker` class to manage multiple tools and handle tool allocation.

- **Inheritance**: Means that a class can inherit attributes and methods from a parent class. The derived class can extend or override the behavior of the parent class. In this exercise, the `Shovel` and `Hammer` classes inherit from the `Tool` class. The `Worker` class manages multiple tools and handles tool allocation using inheritance.

### Exercise IV.4: Association

- **Description**: Design a `Workshop` class that manages a list of `Worker` objects. Implement methods for workers to join or leave workshops and execute work within the workshop.

- **Association**: Means that objects are related to each other but can exist independently. The associated objects can interact with each other but do not manage each other's lifecycle. In this exercise, the `Workshop` class manages a list of `Worker` objects. The `Worker` objects can join or leave the workshop and execute work within the workshop using association.

## Conclusion

This module provides a hands-on approach to understanding and implementing object relationships in OOP. By working through these exercises, I have gained practical experience in using composition, aggregation, inheritance, and association to model complex systems. These relationships are essential for creating flexible, scalable, and maintainable software solutions.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Author

👤 ** André Francisco Baião Rolão Cândido da Silva **
