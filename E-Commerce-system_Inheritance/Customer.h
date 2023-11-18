#pragma once
#include <iostream>
#include <vector>
#include "Order.h"
#include "Products.h"
#include "Product.h"
#include <ctime>


class Customer
{
	Order* order = nullptr;
	std::vector<Product*> bought_products;
	double money;
	std::string name;
public:
	Customer(std::string name, double money) : name(name), money(money), bought_products(std::vector<Product*>()) {};
	bool products() {
		if (bought_products.size() <= 0) {
			return 0;
		}
		for (const auto& product : bought_products) {
			product->display();
		}
		return 1;
	}

	void acquireMoney(int add) {
		money += add;
		std::cout << "You've got $" << add << ". You have $" << money << ".\n";
	}

	bool spendMoney(int spend) {
		if (money < spend) {
			std::cout << "Not enough money. But don't panic. That's ok:)...";
			return false;
		}
		money -= spend;
		std::cout << "You've spent $" << spend << ". You have left with $" << money << ".\n";
		return true;
	}

	void buy(Product* product) {
		if (spendMoney(product->getPrice()))
		{
			bought_products.push_back(product);
		}
	}

	double balance() const {
		return money;
		//std::cout << "You have $" << money << ". Enjoy it!\n";
	}

	Product* productByID(int ID) {
		for (const auto& product : bought_products)
		{
			if (product->getId() == ID)
			{
				return product;
			}
		}
		std::cout << "This cout should not be reachable.";
		throw std::runtime_error("Product not found. (Even although the search should not have been conducted. (ID = " + std::to_string(ID) + ")");
		return bought_products[0];
	}

	void sell(int ID) {
		Product* product = productByID(ID);
		std::srand(static_cast<unsigned int>(std::time(nullptr)));
		double price = product->getPrice() * static_cast<double>(std::rand()) / RAND_MAX;
		std::cout << "You're proposed to cell the product by the price '$" << price << "'. Would you like to? (yes/no or +/-): ";
		std::string aggreement;
		std::cin >> aggreement;
		if (aggreement[0] == 'y' || aggreement[0] == '+')
		{
			money += price;
			bought_products.erase(std::remove(bought_products.begin(), bought_products.end(), product), bought_products.end());
		}
		std::cout << "Looks like you're not satisfied with the price...\n";
	}
};

