#include "PriceListItem.h"
//Default constructor to initialize private members
PriceListItem::PriceListItem() {
	_itemName = "Default Name";//default name
	_code = "0000000000";//default code
	_price = 0.0;//default price
	_taxable = false;//default taxable
}
//Parameters constructor
PriceListItem::PriceListItem(const string &itemName, const string &code, double price, bool taxable) {
	_itemName = itemName;
	_code = code;
	_price = price;
	_taxable = taxable;
}
//Copy constructor to copy contents between PriceListItem objects
PriceListItem::PriceListItem(const PriceListItem &a) {
	_itemName = a._itemName;
	_code = a._code;
	_price = a._price;
	_taxable = a._taxable;
}
//Assignment operator to assign contents between PriceListItem objects
PriceListItem& PriceListItem::operator=(const PriceListItem &a) {
	if (this != &a)//avoid selft assignment
	{
		_itemName = a._itemName;//assign name
		_code = a._code;//assign code
		_price = a._price;//assign price
		_taxable = a._taxable;//assign taxable
	}
	return *this;
}
//Return the name of an item
string PriceListItem::getItemName() {
	return _itemName;
}
//return the code of an item
string PriceListItem::getCode() {
	return _code;
}
//return the price of an item
double PriceListItem::getPrice() {
	return _price;
}
//return if is taxable?
bool PriceListItem::isTaxable() {
	return _taxable;
}
//set the name of an item
void PriceListItem::setItemName(string &itemnName) {
	_itemName = itemnName;
}
//set the code of an item
void PriceListItem::setCode(string &code) {
	_code = code;
}
//set the price of an item
void PriceListItem::setPrice(double &price) {
	_price = price;
}
//set the taxable value of an item
void PriceListItem::setTaxable(bool &taxable) {
	_taxable = taxable;
}
