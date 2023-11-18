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
public:
	ProgramManager() {};

	void retrieveFromStorage(std::string filename) {
		std::vector<Products*> productss = reader.ReadFile(filename, startingIndex);
		productsCatalog = new ProductsCatalog();
		productsCatalog->addProducts(productss);
		startingIndex += 1000;
	}

	void setCustomer(Customer* customer) { this->customer = customer; }

	void inventoryCheck() {
		bool inventoryIsOk = true;
		if (inventory == nullptr)
		{
			if (productsCatalog == nullptr) {
				std::cout << "Sorry, you don't have a product catalog. Please, add a catalog.\n";
				return;
			}
			inventory->initialize(productsCatalog);
		}
		for (auto& products : inventory->needRestocking(productsCatalog))
		{
			products->display();
			inventoryIsOk = false;
		}
		if (inventoryIsOk)
		{
			std::cout << "Inventory is ok. No need to renew anything.\n";
		}
	}

	void showCatalog() {
		for (auto& products : productsCatalog->allProducts())
		{
			products->display();
		}
	}

	void addToOrder(Product* product) {
		if (order == nullptr)
		{
			order = new Order(orderID, customer, product);
			orderID++;
		}
		order->AddProduct(product);
	}

	void finishOrder() {
		order->buy();
	}
};

