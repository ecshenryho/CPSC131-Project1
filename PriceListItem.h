#pragma once
#include <string>
using namespace std;

class PriceListItem {
public:
	//Default constructor
	PriceListItem();
	//Parameters constructor
	PriceListItem(const string &itemName, const string &code, double price, bool taxable);
	//assigment operater "="
	PriceListItem& operator=(const PriceListItem &a);
	//Copy constructor
	PriceListItem(const PriceListItem &a);
	//return the name of an item
	string getItemName();
	//return the code of an item
	string getCode();
	//return the price of an item
	double getPrice();
	//return if is taxable?
	bool isTaxable();
	//set the name of an item
	void setItemName(string &itemnName);
	//set the code of an item
	void setCode(string &code);
	//set the price of an item
	void setPrice(double &price);
	//set the taxable value of an item
	void setTaxable(bool &taxable);
private:
	string _itemName;//the name of an item
	string _code;//the code of an item
	double _price;//the price of an item
	bool _taxable;//taxbale or not for an item
};
