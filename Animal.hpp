// FILE: Animal.hpp
// PURPOSE: Definition for an Animal for CS2's Project #2

#ifndef _ANIMAL_HPP_
#define _ANIMAL_HPP_

#include <iostream>
#include <string>
using namespace std;

class Animal
{
    private:
        string _name; // Name of animal
        string _species; // Species of animal
        int _age; // Age (in years) of animal

    public:
        // Default constructor
        // Defaults to empty string for the name and species and 0 for the age
        Animal(): _name(""), _species(""), _age(0) {}

        // Parameterized constructor
        // Builds an animal out of a name and species (age starts at 0)
        Animal(const string &name, const string &species, const int &age):
            _name(name), _species(species), _age(age) {}

        // Copy constructor
        // Uses existing animal's data to create another
        Animal(const Animal &animal_to_copy);

        // Accessor - get the name of the animal
        string get_name() const {return _name;}

        // Accessor - get the species of the animal
        string get_species() const {return _species;}

        // Accessor - get the age of the animal
        int get_age() const {return _age;}

        // Increment op - used to increment age
        Animal& operator++();

        // Overloaded comparison operators
        bool operator<(const Animal &other) const;
        bool operator>(const Animal &other) const;
        bool operator==(const Animal &other) const;
        bool operator!=(const Animal &other) const;

        friend istream& operator>>(istream &is, Animal &a);
        friend ostream& operator<<(ostream &os, const Animal &a);
};

#endif