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

	Products* productsByID(int productID) {
		for (auto& products : productsCatalog->allProducts())
		{
			if (products->startIndex() == productID)
			{
				return products;
			}
		}
	}

	bool existsProductsByID(int productID) {
		for (auto& products : productsCatalog->allProducts())
		{
			if (products->startIndex() == productID)
			{
				return true;
			}
		}
		return false;
	}

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
			inventory = new Inventory(15);
			inventory->initialize(productsCatalog);
		}
		std::cout << "Checking inventory...\n";
		for (auto& products : inventory->needRestocking(productsCatalog))
		{
			std::cout << "- ";
			products->display();
			inventoryIsOk = false;
		}
		if (inventoryIsOk)
		{
			std::cout << "Inventory is ok. No need to renew anything.\n";
			return;
		}
		std::cout << "These products ^ need restocking.\n";
	}

	void showCatalog() {
		for (auto& products : productsCatalog->allProducts())
		{
			products->display();
		}
	}

	void addToOrder(int productID) {
		if (existsProductsByID(productID))
		{
			Products* products = productsByID(productID);
			if (order == nullptr)
			{
				order = new Order(orderID, products->getProduct());
				orderID++;
			}
			else {
				order->AddProduct(products);
			}
			std::cout << "You've got new product in your order.\n";
		}
	}

	void showOrder() {
		order->allProducts();
	}

	void finishOrder() {
		double totalCost = order->totally();
		double balance = customer->balance();
		if (balance < totalCost)
		{
			std::cout << "Sorry, you don't have enough money. (Cost: " << totalCost << "; balance: " << balance << ")\n";
		}
		std::vector<Product*> prods = order->buy();
		for (auto& product : prods)
		{
			customer->buy(product);
		}
	}

	void productsShipment(int productID, int amount) {
		if (inventory != nullptr)
		{
			if (!existsProductsByID(productID))
			{
				std::cout << "Sorry, there's no such product...\n";
				return;
			}
			Products* products = productsByID(productID);
			inventory->amountIncrease(products, amount);
			std::cout << "Product updated:\n";
			products->display();
		}
	}
};

