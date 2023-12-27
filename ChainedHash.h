#ifndef ITEM_HASH_TABLE_HDR
#define ITEM_HASH_TABLE_HDR

#include "Item.h"

// Define fixed maximum number of buckets in the hash table.
// For this activity, we will implement a fixed-sized array where
// each entry or bucket of this fixed-sized array contains exactly ONE Item.
#define NUMBER_OF_BUCKETS    20

class ItemHashTable
{
public:

  // constructor - initializes table to empty.
  ItemHashTable();

  // hashFunction
  // pre-condition: receives an Item id
  // post-condition: returns hash function that tells us the array index position
  // within the fixed-sized array into which this Item will be stored.
  int hashFunction(int id) const;

  // insert
  // pre-condition: receives an Item that must have a positive ID.
  // post-condition: save the given Item into the hash table
  void insert(const Item& V);

  // isContains
  // pre-condition: receives an integer ID value. The integer ID is the 
  // unique integer Stock Keeping Unit number for a product.
  // post-condition: return true if the hash table contains an Item with 
  // the given ID; else, return false.
  bool isContains(int ID) const;

  // retrieve
  // pre-condition: receives an integer ID value. The integer ID is the 
  // unique integer Stock Keeping Unit number for a product. 
  // post-condition: return Item matching the given ID.
  // Item will contain invalid values of id -1 and name "undefined" and price of 0
  // if not Item in the hash table has the given ID.
  Item retrieve(int ID) const;

private:
  // Fixed-sized array of Items. Each hash table bucket stores ONE Item.
  Item* buckets[NUMBER_OF_BUCKETS];
};

#endif
