#pragma once
#include <iostream>
#include <vector>
#include "Products.h"
#include "ProductsCatalog.h"


class Inventory
{
	std::vector<Products*> productsLists;
	int threshold = 1;

public:
	Inventory(int threshold = 0, std::vector<Products*> list = std::vector<Products*>()) : threshold(threshold), productsLists(list) {};
	void amountIncrease(Products* products, int adding) {
		products->changeQuantity(adding);
	}
	void amountDecrease(Products* products, int subtracting) {
		products->changeQuantity(-subtracting);
		//std::vector<Products*> toRestock = needRestocking();
		//if (toRestock.empty())
		//{
		//	return;
		//}
		//for (auto& product : toRestock)
		//{
		//	std::cout << "Need restocking of product:\n";
		//	product->display();
		//}
	}

	std::vector<Products*> needRestocking(ProductsCatalog* catalog) {
		std::vector<Products*> toRestock = std::vector<Products*>();
		for (auto& product : catalog->allProducts())
		{
			auto it = std::find(productsLists.begin(), productsLists.end(), product);
			if (it == productsLists.end())
			{
				toRestock.push_back(product);
			}
			else if (product->quantityLevel() < threshold) {
				toRestock.push_back(product);
			}
		}
		return toRestock;
	}

	void initialize(ProductsCatalog* catalog) {
		productsLists = catalog->allProducts();
	}
};

