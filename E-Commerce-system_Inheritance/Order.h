#pragma once
#include <iostream>
#include <memory>
#include "Products.h"
#include "Product.h"


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

	Order(int orderID, Product* products) : orderID(orderID), products(std::vector<Product*>()), status(Created) {
		calculateCost(); 
		this->products.push_back(products);
	}
	
	void AddProduct(Products* products) {
		if (products->available())
		{
			this->products.push_back(products->getProduct());
			return;
		}
		std::cout << "Product isn't available.\n";
	}

	void allProducts() {
		for (auto& product : products)
		{
			product->display();
		}
	}
	
	void changeStatus(OrderStatus status) {
		this->status = status;
	}

	double totally() {
		calculateCost();
		return totalCost;
	}
	
	std::vector<Product*> buy() {
		status = Received;
		return products;
	}
};

