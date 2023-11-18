#pragma once
#include <iostream>
#include <vector>
#include "Products.h"
#include "ProductsCatalog.h"


class Inventory
{
	std::vector<Products*> productsLists = std::vector<Products*>();
	int threshold = 1;

public:
	Inventory(int threshold = 0) : threshold(threshold) {};
	void amountIncrease(Products* products, int adding) {
		products->changeQuantity(adding);
	}
	void amountDecrease(Products* products, int subtracting) {
		products->changeQuantity(-subtracting);
	}

	const std::vector<Products*>& needRestocking(ProductsCatalog* catalog) {
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

