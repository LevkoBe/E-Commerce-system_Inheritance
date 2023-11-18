#pragma once
#include <iostream>
#include <memory>
#include "Products.h"
#include "Product.h"

class Customer;

enum OrderStatus {
	None,
	Processing,
	Received,
	Awaiting,
	Created
};

class Order
{
	int orderID;
	Customer* customer;
	std::vector<Product*> products;
	double totalCost;
	OrderStatus status;

	double calculateCost() {
		double cost = 0;
		for (auto& prods : products)
		{
			cost += prods->getPrice();
		}
		totalCost = cost;
		return totalCost;
	}

public:

	Order(int orderID, Customer* customer, Product* products) : orderID(orderID), customer(customer), products(std::vector<Product*>()), status(Created) { calculateCost(); this->products.push_back(products); }
	
	void AddProduct(Product* product) {
		products.push_back(product);
	}
	
	void changeStatus(OrderStatus status) {
		this->status = status;
	}
	
	void buy() {
		if (customer->balance() >= calculateCost())
		{
			status = Received;
			customer->spendMoney(totalCost);
			return;
		}
		std::cout << "Sorry, you don't have enough money. (Cost: " << totalCost << "; balance: " << customer->balance() << ")\n";
	}
};

