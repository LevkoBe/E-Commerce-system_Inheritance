#pragma once
#include "Inventory.h"
#include "ProductsCatalog.h"
#include "Order.h"
#include "Customer.h"
#include "ProductsReader.h"

class ProgramManager
{
    ProductsReader reader;
	Inventory* inventory = nullptr;
	ProductsCatalog* productsCatalog = nullptr;
	Order* order = nullptr;
	int orderID = 0;
	int startingIndex = 0;
	Customer* customer = nullptr;

	Products* productsByID(int productID);

	bool existsProductsByID(int productID);

public:
	ProgramManager() {};

	void retrieveFromStorage(std::string filename);

	void setCustomer(Customer* customer) { this->customer = customer; };

	void inventoryCheck();

	void showCatalog();

	void addToOrder(int productID);

	void showOrder();

	void showProducts();

	void finishOrder();

	void productsShipment(int productID, int amount);
};

