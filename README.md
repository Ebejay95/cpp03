# CPP Module 03

**An exploration of Inheritance in C++.**

This project focuses on inheritance mechanics in C++, demonstrating various aspects of class inheritance including multiple inheritance and the diamond problem.

## Structure

### ex00/
The `ex00` directory introduces the base class:
- **ClapTrap.cpp**: Implementation of the ClapTrap base class
- **ClapTrap.hpp**: Header file for ClapTrap
- **main.cpp**: Tests basic ClapTrap functionality

### ex01/
The `ex01` directory demonstrates basic inheritance:
- **ClapTrap.cpp/hpp**: Base class files
- **ScavTrap.cpp**: Implementation of ScavTrap derived class
- **ScavTrap.hpp**: Header for ScavTrap
- **main.cpp**: Tests inheritance functionality

### ex02/
The `ex02` directory adds another derived class:
- **ClapTrap.cpp/hpp**: Base class files
- **ScavTrap.cpp/hpp**: First derived class
- **FragTrap.cpp**: Implementation of FragTrap derived class
- **FragTrap.hpp**: Header for FragTrap
- **main.cpp**: Tests multiple derived classes

### ex03/
The `ex03` directory tackles the diamond problem:
- **ClapTrap.cpp/hpp**: Base class files
- **ScavTrap.cpp/hpp**: First derived class
- **FragTrap.cpp/hpp**: Second derived class
- **DiamondTrap.cpp**: Implementation combining ScavTrap and FragTrap
- **DiamondTrap.hpp**: Header for DiamondTrap
- **main.cpp**: Tests diamond inheritance

## Features

- **Class Inheritance**: Implementation of base and derived classes
- **Multiple Inheritance**: Managing multiple parent classes
- **Virtual Functions**: Proper use of virtual functions
- **Diamond Problem Resolution**: Handling multiple inheritance paths
- **Member Function Overriding**: Customizing inherited behavior

## Usage

To compile each exercise, navigate to its directory and run:
```bash
make
```

### Running the Programs

For each exercise:
```bash
./trap
```

## Compilation

All exercises are compiled with:
```bash
c++ -Wall -Wextra -Werror -std=c++98 *.cpp
```

## Learning Objectives

- Understanding inheritance mechanics
- Managing virtual functions
- Resolving the diamond problem
- Implementing proper access specifiers
- Memory management in inherited classes
- Orthodox Canonical Form in inheritance
