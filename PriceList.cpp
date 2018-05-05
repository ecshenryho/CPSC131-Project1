#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "PriceList.h"
#include "PriceListItem.h"

using namespace std;
//Default constructor to initialize private members 
PriceList::PriceList() {
	maxItemStore = 1000000;//maximum items can be hold
	listOfItems = new PriceListItem[maxItemStore];//dynamic arrays to store items' information
	indexPriceList = 0;//index initialize to 0
}
//copy constructor for Pricelist objects
PriceList::PriceList(const PriceList &a) {
	indexPriceList = a.indexPriceList;//set new index
	maxItemStore = a.maxItemStore;//set new size
	listOfItems = new PriceListItem[maxItemStore];//allocate new array
	for (int i = 0; i <indexPriceList; i++)
	{
		listOfItems[i] = a.listOfItems[i];//copy contents
	}
}
//Assignment operator for Pricelist object
PriceList& PriceList::operator=(const PriceList &a) {
	if (this != &a) {//avoid self-assignment
		delete[]listOfItems;//delete old array
		indexPriceList = a.indexPriceList;//set new index
		maxItemStore = a.maxItemStore;//set new size
		listOfItems = new PriceListItem[maxItemStore];//allocate new array
		for (int i = 0; i < indexPriceList; i++)
		{
			listOfItems[i] = a.listOfItems[i];//copy contents
		}
	}
	return *this;//return object
}
////Destructor to deallocate and prevent dangling pointers.
PriceList::~PriceList() {
	delete[]listOfItems;//deallocate
	listOfItems = NULL;//set pointer null
}
// Load information from a text file with the given filename.
void PriceList::createPriceListFromDatafile(string filename) {
	ifstream myfile(filename);

	if (myfile.is_open()) {
		cout << "Successfully opened file " << filename << endl;
		string name;
		string code;
		double price;
		bool taxable;
		while (myfile >> name >> code >> price >> taxable) {
			//cout << code << " " << taxable << endl;
			addEntry(name, code, price, taxable);
		}
		myfile.close();
	}
	else
		throw invalid_argument("Could not open file " + filename);//throw exception if could not open
}

// return true only if the code is valid
bool PriceList::isValid(string code) const {
	for (int i = 0; i < indexPriceList; i++)
	{
		if ((listOfItems[i].getCode()) == code)//go through the list to check for code
		{
			return true;//return true if found
		}
	}
	return false;//return false if not found
}
// return price, item name, taxable? as an ItemPrice object; throw exception if code is not found
PriceListItem PriceList::getItem(string code) const {
	bool check = true;
	int i = 0;
	for (; i < indexPriceList && check; i++)
	{
		if (listOfItems[i].getCode() == code) {//check all the list to see if we can find code
			check = false;
		}
	}
	if (check)
		throw invalid_argument("item's code is not found in the pricelist");//throw exception if could not found code
	return listOfItems[i - 1];
}
// add to the price list information about a new item
void PriceList::addEntry(string itemName, string code, double price, bool taxable) {
	PriceListItem newItem;//create a new object type PriceListItem to hold information of an item
	newItem.setItemName(itemName);
	newItem.setCode(code);
	newItem.setPrice(price);
	newItem.setTaxable(taxable);
	listOfItems[indexPriceList] = newItem;//add an item to array list items with corresponding position index
	indexPriceList++;//increase the position index
}
//Return maximum size of a priceList object can hold
int PriceList::getMaxItemStore() {
	return maxItemStore;
}
