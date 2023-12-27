// Represents a store item by an integer SKU ID and name

#ifndef ITEM_HDR
#define ITEM_HDR

#include <string>

class Item {
  // Declare public methods/commands that form our interface seen all code
  // outside of class Item
  public:
    // Default constructor - assigns id to -1, name to "undefined" string, price to $0.
    Item();

    // Initializes id and name to given values.
    // const for a parameter means that parameter variable will not be changed.
    // The & for a parameter means that the computer will pass a reference to
    // the actual argument sent by the caller instead of a copy.
    // A string contains an array of char values so it's more efficient to 
    // pass the address instead of a copy of the whole string including its array.
    // Specify price of item.
    Item(int id, const std::string& name, float p);

    Item* getNext() const;

    void setNext(Item* pointer);

    // return product ID as an integer
    int getId() const;

    // return name of product as a string
    // Again to be efficient, retrun a const & that refers to the string data contained
    // by this Item.  Const ensures that the outside code cannot change the product name.
    const std::string& getName() const;

    // return price of this Item as a float.
    float getPrice() const;

    // prints id and name
    void print() const;

  private:
    int id;
    std::string name;
    float price;
    Item* next;
};

#endif
