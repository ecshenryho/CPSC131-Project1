#include "GroceryBill.h"
#include <iostream>
#include<fstream>
#include<string>
#include<stdexcept>
#include<iomanip>
using namespace std;

GroceryBill::GroceryBill(const PriceList *priceList, double taxRate) {
	_priceList = priceList;//pointer to the address of the price list array
	_taxRate = taxRate;//set tax rate
	maxItemOnBills = 1000;//initialize maximum size requrired for a bill
	listItemBill = new PriceListItem[maxItemOnBills];//allocate dynamic array for a bill
	_quantity = new double[maxItemOnBills];// allocate dynamic array for quantity
	indexListItemBill = 0;//initialized index to 0
	total = 0.0;//initalize total price to 0
}
//destructor deallocate and prevent dangling pointer
GroceryBill::~GroceryBill() {
	delete[]listItemBill;
	_quantity = NULL;
	_priceList = NULL;
	listItemBill = NULL;
}
void GroceryBill::scanItem(string scanCode, double quantity) {
	//scan item, catch exception if code is not found and throw again to main to handle exception
	//First catch exception threw form PriceListItem PriceList::getItem, then throw to main to handle
	try {
		listItemBill[indexListItemBill] = _priceList->getItem(scanCode);
		_quantity[indexListItemBill] = quantity;
		indexListItemBill++;
	}
	catch (const exception &e) {
		throw e;//throw exception was catched from getItem
	}
}
// Scan multiple codes and quantities from the given text file
// Each line contains two numbers separated by space: the first is the code (an integer), the second the quantity (a float/double)
// Example line from text file:
// 15000000 1.5
void GroceryBill::scanItemsFromFile(string filename) {
	// To be completed
	// HINT: Look at code in PriceList::createPriceListFromDatafile(string filename)
	ifstream myfile(filename);
	if (myfile.is_open()) {
		cout << "Successfully opened file " << filename << endl;
		string code;
		double quantity;
		while (myfile >> code >> quantity) {
			scanItem(code, quantity);
		}
		myfile.close();
	}
	else
		throw invalid_argument("Could not open file " + filename);//throw exception if could not open file
}
// return the total cost of all items scanned
double GroceryBill::getTotal() {
	total = 0.0;
	for (int i = 0; i < indexListItemBill; i++)
	{
		if (listItemBill[i].isTaxable() == 1)
			total += ((listItemBill[i].getPrice())*(1 + _taxRate / 100)*(_quantity[i]));
		else
			total += (listItemBill[i].getPrice())*(_quantity[i]);
	}
	return total;
}
// Print the bill to cout. Each line contains the name of an item, total price, and the letter "T" if tax was addded. 
// The last line shows the total.
// An example:
//Plastic_Wrap	1.60547 T
//Sugar_white	5.475
//Waffles_frozen	5.16
//Oil_Canola_100%_pure	2.69
//Potatoes_red	13.446
//TOTAL 	28.3765
void GroceryBill::printBill() {
	cout << setprecision(7);
	for (int i = 0; i <indexListItemBill; i++)
	{
		cout << setw(24) << left << listItemBill[i].getItemName() << "    " << listItemBill[i].getPrice();
		if (listItemBill[i].isTaxable() == 1)
		{
			cout << "     T";
		}
		cout << endl;
	}
	cout << setw(19) << left << "Total		" << setprecision(6) << getTotal() << endl;
}

