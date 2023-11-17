#pragma once
#include "Products.h"

class ProductsCatalog
{
	std::vector<Products*> productsPossible = std::vector<Products*>();
public:
	ProductsCatalog() {};
	void addProducts(Products* products) {
		if (std::find(productsPossible.begin(), productsPossible.end(), products) != productsPossible.end())
		{
			std::cout << "Such a product already exists in the catalog.\n";
			return;
		}
		productsPossible.push_back(products);
	}
	bool changeProducts(Products* products, double newPrice=0.0) {
		auto it = std::find(productsPossible.begin(), productsPossible.end(), products);
		if (it == productsPossible.end())
		{
			std::cout << "Such a product doesn't exists in the catalog.\n";
			return false;
		}
		if (newPrice != 0.0)
		{
			products->setPrice(newPrice);
		}
		return true;
	}
	void removeProducts(Products* products) {
		if (std::find(productsPossible.begin(), productsPossible.end(), products) == productsPossible.end())
		{
			std::cout << "Such a product already doesn't exist in the catalog.\n";
			return;
		}
		productsPossible.erase(std::remove(productsPossible.begin(), productsPossible.end(), products), productsPossible.end());
		std::cout << "Succesfully removed from the catalog.\n";
	}
	void allProducts() {
		for (auto& products : productsPossible)
		{
			products->display();
		}
	}
};

