// FILE: Animal.cpp
// AUTHOR: J. Mayfield
// DATE: 02/2025
// PURPOSE: Implementation of an Animal for CS2's Project #2

#include "Animal.hpp"
using namespace std;

Animal::Animal(const Animal &animal_to_copy)
{
    // The name and species and age of the animal are copied over
    _name = animal_to_copy._name;
    _species = animal_to_copy._species;
    _age = animal_to_copy._age;
}

Animal& Animal::operator++()
{
    _age++;
    return *this;
}

// Overloaded "less than" for two animals
bool Animal::operator<(const Animal &other) const
{
    // Can we decide based on the animal's name?
    if(_name < other._name)
        return true;
    if(_name > other._name)
        return false;

    // If the names are equal, decide based on the species
    if(_species < other._species)
        return true;
    if(_species > other._species)
        return false;

    // If the names and species are equal, decide based on their ages
    return _age < other._age;
}

// Overloaded "greater than" for two animals
// Coder's trick: Just use already defined <
bool Animal::operator>(const Animal &other) const
{
    return other < *this;
}

// Overloaded "equals" for two animals
bool Animal::operator==(const Animal &other) const
{
    // Two animals are equal if all of their attributes are the same
    return (_name==other._name && _species==other._species && _age==other._age);
}

// Overloaded "not equals" for two animals
// Coder's trick: This is the opposite of two animals being equal to each other
bool Animal::operator!=(const Animal &other) const
{
    return !operator==(other);
}

istream& operator>>(istream &is, Animal &a)
{
    is >> a._name >> a._species >> a._age;
    return is;
}

ostream& operator<<(ostream &os, const Animal &a)
{
    os << a._name << " the " << a._species << " is " << a._age << " year(s) old.";
    return os;
}