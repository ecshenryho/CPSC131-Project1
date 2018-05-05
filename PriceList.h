#pragma once
#include <string>
#include <stdexcept>
#include "PriceListItem.h"

using namespace std;

class PriceList {
public:
	//Default constructor
	PriceList();
	//Copy constructor
	PriceList(const PriceList &a);
	//Assignment operator "="
	PriceList& operator=(const PriceList &a);
	// Load information from a text file with the given filename (Completed)
	void createPriceListFromDatafile(string filename);
	// add to the price list information about a new item. A max of 1,000,000 entries can be added
	void addEntry(string itemName, string code, double price, bool taxable);
	// return true only if the code is valid
	bool isValid(string code) const;
	// return price, item name, taxable? as an PriceListItem object; throw exception if code is not found
	PriceListItem getItem(string code) const;
	//Return maximum size of a priceList object can hold
	int getMaxItemStore();
	//Destructor to deallocate and prevent dangling pointers.
	~PriceList();
private:
	PriceListItem *listOfItems;//Pointer to PiceListItem type
	int maxItemStore;// number of objects type PriceListItem or index for dynamic array.
	int indexPriceList; //index number of a dynamic array, the array will store all imtems needed.
};
