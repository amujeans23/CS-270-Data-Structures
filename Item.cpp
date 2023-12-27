    
#include "Item.h"
#include <iostream>
// Say using std so we can write string without std::string
using namespace std;

// Default constructor
// Initialize Item attributes to represent an invalid or undefined Item.
// Assigns id to -1, name to "undefined", and price to $0.
Item::Item() {
  this->id = -1;
  this->name = "undefined";
	this->price = 0.0;
  this->next = NULL;
}

// Initializes id and name to given values.
// const for a parameter means that parameter variable will not be changed.
// The & for a parameter means that the computer will pass a reference to
// the actual argument sent by the caller instead of a copy.
// A string contains an array of char values so it's more efficient to 
// pass the address instead of a copy of the whole string including its array.
Item::Item(int id, const string& name, float p) {
  // yes, the formal argument can have the same name as the attribute.
  // this->id means the id owned by the class object.  id alone is the formal argument given.
  this->id = id;
  this->name = name;
  this->price = p;
  this->next = NULL;
}

// getNext
// pre-conditions: none
// post-conditions: return the next node through pointers
Item* Item :: getNext() const{
  return this-> next;
}

// setNext
// pre-conditions: pointer name
// post-conditions: set a pointer to the pointer variable
void Item:: setNext(Item* pointer){
  this-> next = pointer;
}
// return unique product ID as an integer
int Item::getId() const {
  return this->id;
}

// return name of product as a string
// Again to be efficient, retrun a const & that refers to the string data contained
// by this Item.  Const ensures that the outside code cannot change the product name.
const string&  Item::getName() const {
  return this->name;
}

float Item::getPrice() const {
  return this->price;
}

void Item::print() const {
  std::cout << this->id << ": " << this->name << " $" << this->price << std::endl;
}
