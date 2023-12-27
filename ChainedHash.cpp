#include "ChainedHash.h"
#include "Item.h"
# include <iostream>
using namespace std;

// constructor - initializes table to empty.
ItemHashTable::ItemHashTable()
{
  for (int counter = 0; counter < NUMBER_OF_BUCKETS; counter++)
    buckets[counter] = NULL;
}

// hashFunction
// pre-condition: receives an Item ID
// post-condition: returns hash function revealing the array index position
// within the fixed-sized array into which this Item will be stor ed.
int ItemHashTable::hashFunction(int ID) const
{
  // Compute hash function using the modulo operator
  int hash_value = ID % NUMBER_OF_BUCKETS;
  // return computed hash value
  return hash_value;

}

// insert
// pre-condition: receives an Item data value that must have a positive ID value.
// post-condition: save the given Item into the hash table, returns a Boolean value.
void ItemHashTable::insert(const Item& V)
{
  int index = hashFunction(V.getId());
  Item* current = buckets[index];

  if (buckets[index] == NULL)
    buckets[index] = new Item(V);

  else {
      Item* itemPoint = new Item(V);
      Item* tempPoint = buckets[index]->getNext();
      buckets[index]->setNext(itemPoint);
      itemPoint->setNext(tempPoint);
  }
}

// isContains
// pre-condition: receives an integer ID value. The integer ID is the 
// unique integer Stock Keeping Unit number for a product.
// post-condition: return true if the hash table contains an Item with 
// the given ID; else, return false.
bool ItemHashTable::isContains(int ID) const
{
  int index = hashFunction(ID);

  Item* current = buckets[index];
  while (current != NULL) {
      if ((*current).getId() == ID) {
        cout << "ID " << ID << " was found." << endl;
        return true; 
      }
    current = current->getNext();
  }
  cout << "ID " << ID << " was not found." << endl;
  return false;
}

// retrieve
// pre-condition: receives an integer ID value. The integer ID is the 
// unique integer Stock Keeping Unit number for a product. 
// post-condition: return Item matching the given ID.
// Item will contain invalid values of id -1 and name "undefined" and price of 0
// if not Item in the hash table has the given ID.
Item ItemHashTable::retrieve(int ID) const 
{
  // Create default Item that has invalid ID, undefined name, and price of 0.
  Item emptyItem;

  int index = hashFunction(ID);
  Item* current = buckets[index];
  
  while (current != NULL) {
    if ((*current).getId() == ID){
      Item found = *current;
      return found;
    }
     current = current->getNext();
  }
  return emptyItem;
  }
