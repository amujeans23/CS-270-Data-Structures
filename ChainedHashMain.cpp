#include "Item.h"
#include "ChainedHash.h"
#include <iostream>
using namespace std;

// message
// pre-conditions: recieves an item and hash table item, prints out a pmessage identifying the item ID and item hash value
// post-condition: none
  void message(Item groceryItem, ItemHashTable table){
	   std::cout << "Item ID: " << groceryItem.getId() << endl << "Item Hash Value: " << table.hashFunction(groceryItem.getId()) << endl;
  }

int main() {
	std::cout << "Hello Hash Table!\n";

	Item butter(20, "butter", 4.00);
	Item eggos(40, "eggos", 7.00);
	Item syrup(63, "syrup", 5.00);

	butter.print();
	eggos.print();
	syrup.print();

	ItemHashTable groceryTable;

  message(butter, groceryTable);
  message(eggos, groceryTable);
  message(syrup, groceryTable);

  groceryTable.insert(butter);
  groceryTable.insert(eggos);
  groceryTable.insert(syrup);

  groceryTable.isContains(butter.getId());
  groceryTable.isContains(eggos.getId());
  groceryTable.isContains(syrup.getId());

  Item returnedItem = groceryTable.retrieve(butter.getId());
  returnedItem.print();
  Item returnedItem2 = groceryTable.retrieve(eggos.getId());
  returnedItem2.print();
  Item returnedItem3 = groceryTable.retrieve(syrup.getId());
  returnedItem3.print();

	return 0;
}
