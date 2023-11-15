#pragma once
#include <iostream>
#include <vector>
#include "Products.h"


class Inventory
{
	std::vector<Products*> productsLists;
	int threshold = 1;

public:
	Inventory(int threshold = 0, std::vector<Products*> list = std::vector<Products*>()) : threshold(threshold), productsLists(list) {};
	bool amountIncrease()
};

