#include "AnimalShelter.hpp"
using namespace std;


AnimalShelter::AnimalShelter(){ //Define the default constructor

	_animals = 0;
  _rooms = 5;
  _myArr = new Animal[_rooms];
}

AnimalShelter::AnimalShelter(std::istream &is){ //Define the input constructor

    _animals = 0;
    _rooms = 5;
    _myArr = new Animal[_rooms];
    
   is >> *this;
}
    
	
AnimalShelter& AnimalShelter::adopt(const Animal &animal){	//Define the adopt method
	
	for(int i = 0; i < _animals; i++){
		if(animal == _myArr[i]){
			
			for (int j = i; j < _animals-1; j++) {
           _myArr[j] = _myArr[j + 1];
      	}
      	_animals--;
      	break;
   	}
   
	}
		return *this;
}

Animal* AnimalShelter::find(const Animal &animal){ //Define the find method
	
	for(int i = 0; i < _animals; i++){
		
		if(animal == _myArr[i]){
		
			return &_myArr[i];
		} 
	}
	return nullptr;
	
	}

Animal* AnimalShelter::celebrateBirthday(const Animal &animal){ //Define the celebrateBirthday method

	int x = 0;
	int temporalAge;
	for(int i = 0; i < _animals; i++){
		
		if(animal == _myArr[i]){
			temporalAge = _myArr[i].get_age();		
			temporalAge++;
			x = i;
			break;
		}
	
	}
	_myArr[x] = Animal(_myArr[x].get_name(), _myArr[x].get_species(), temporalAge);
	return &_myArr[x];

}

    
AnimalShelter& AnimalShelter::operator=(const AnimalShelter &new_shelter){ //Define the overloaded '='

	if(this != &new_shelter){
		delete[] _myArr;;
		_rooms = new_shelter._rooms;
		_animals = new_shelter._animals;
		_myArr = new Animal[_rooms];
		for(int i = 0; i < new_shelter._animals; i++){
			_myArr[i] = new_shelter._myArr[i];		
		}
	}
	return *this;
 }
    
AnimalShelter& AnimalShelter::operator+=(const Animal &new_animal){ //Define the overloaded '+=' for Animal
	
	bool repeated = false;
	for(int i = 0; i < _rooms; i++){
		if(new_animal == _myArr[i]){
			repeated = true;
		}
	}
	if(repeated){
		repeated = false;
		return *this;
	}
	else{
		if(_animals >= _rooms){ //Expand dynamic array twice its size
			_rooms *=2;
			Animal *newArr = new Animal[_rooms];
			for(int i = 0; i < _animals; i++){
				newArr[i] = _myArr[i];
			}
			delete[] _myArr;
			_myArr = newArr;
			_myArr[_animals] = new_animal;
			_animals++;	
		}
		else{
			_myArr[_animals] = new_animal;
			_animals++;				
		}
		return *this;
	}
}

AnimalShelter& AnimalShelter::operator+=(const AnimalShelter &new_shelter){ //Define the overloaded '+=' for AnimalShelter
			
	for(int i = 0; i < new_shelter._animals; i++){
		
		*this += new_shelter._myArr[i];
	}
	return *this;	
}

AnimalShelter AnimalShelter::operator+(const AnimalShelter &new_shelter) const{ //Define the overloaded '+'
	
	AnimalShelter addedShelter;
	addedShelter._rooms = _rooms + new_shelter._rooms;
	addedShelter._animals = 0;
	addedShelter._myArr = new Animal[new_shelter._rooms];
	
	for(int i = 0; i < _animals; i++){
		addedShelter += _myArr[i];
	}
	
	for(int i = 0; i < new_shelter._animals; i++){
		addedShelter += new_shelter._myArr[i];
	}
	return addedShelter;
}	

std::istream& operator>>(std::istream &is, AnimalShelter &a){ //Define the overloaded '>>'
	Animal temporary;
	while(is >> temporary){
	a+=temporary;
	}
    return is;
}	


std::ostream& operator<<(std::ostream &os, const AnimalShelter &a){ //Define the overloaded '<<'
    
    if(a.size() == 0){
		return os;    
    }else{
    	for(int i = 0; i < a.size(); i++){
    		os << a._myArr[i] << endl;
    	}
    	return os;
    }
}	