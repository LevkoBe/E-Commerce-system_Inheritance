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
	void calculateCost() {
		double cost = 0;
		for (auto& prods : products)
		{
			cost += prods->getPrice();
		}
		totalCost = cost;
	}
public:
	Order(int orderID, Customer* customer, std::vector<Product*> products) : orderID(orderID), customer(customer), products(products), status(Created) { calculateCost(); }
	void AddProduct(Product* product) {
		products.push_back(product);
	}
	void changeStatus(OrderStatus status) {
		this->status = status;
	}
	std::vector<Product*> buy() {
		this->status = Received;
		return products;
	}
};

