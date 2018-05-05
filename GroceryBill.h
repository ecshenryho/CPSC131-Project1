#pragma once

#include "PriceList.h"

class GroceryBill {
public:
	//parameters constructor
	GroceryBill(const PriceList *priceList, double taxRate);
	void scanItem(string scanCode, double quantity); // add item and quantity to bill; throw exception if item's code is not found in the pricelist
	void scanItemsFromFile(string filename); // Scan multiple codes and quantities from the given text file
	double getTotal(); // return the total cost of all items scanned
	void printBill(); // Print the bill to cout. Each line contains the name of an item, total price, and the letter "T" if tax was addded.
	//destructor
	~GroceryBill();
private:
	const PriceList* _priceList;//const pointer to access priceList array without changing the original values
	PriceListItem* listItemBill;//pointer to allocate dynamic array holding items for a bill
	double* _quantity;//pointer to allocate dynamic array holding the quantity of an item
	double _taxRate;//variable holding tax rate
	int maxItemOnBills;//the maximum item on a single bill
	int indexListItemBill;//the index number keep track items added to bill
	double total;//total price of a bill
};
