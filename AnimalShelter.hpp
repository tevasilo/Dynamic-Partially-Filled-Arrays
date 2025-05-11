#ifndef _ANIMALSHELTER_HPP_
#define _ANIMALSHELTER_HPP_


#include <iostream>
#include <string>
#include "Animal.hpp"
class AnimalShelter{
	
	private:
		
		Animal *_myArr;  //Declare the dynamic array
		unsigned int _animals;  //Declare the animals variable
		unsigned int _rooms;  //Declare the rooms variable

	public:

		AnimalShelter();	//Declare default constructor

		AnimalShelter(std::istream &is);	//Declare input constructor

		int size() const {return _animals;}		//Declare the size method

		int emptyRooms() const {return _rooms - _animals;} //Declare the emptyrRooms method

		void adoptAll() { _animals = 0;}		//Declare the adoptAll method

		AnimalShelter& adopt(const Animal &animal);		//Declare the adopt method

		Animal* find(const Animal &animal);		//Declare the find method

		Animal* celebrateBirthday(const Animal &animal);	//Declare the celebrateBirthday method
	
		AnimalShelter& operator=(const AnimalShelter &new_shelter); 			//Declare the overloaded '=' 
		AnimalShelter& operator+=(const Animal &new_animal);				//Declare the overloaded '+=' for Animal
		AnimalShelter& operator+=(const AnimalShelter &new_shelter);			//Declare the overloaded '+=' for AnimalShelter
		AnimalShelter operator+(const AnimalShelter &new_shelter) const;		//Declare the overloaded '+' 
		friend std::istream& operator>>(std::istream &is, AnimalShelter &a);		//Declare the overloaded '>>' 
		friend std::ostream& operator<<(std::ostream &os, const AnimalShelter &a);	//Declare the overloaded '<<' 

};

#endif
