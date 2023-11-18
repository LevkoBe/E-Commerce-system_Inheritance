#pragma once
#include <iostream>
#include <vector>
#include "Products.h"
#include "ProductsCatalog.h"

class Inventory {
    std::vector<Products*> productsLists;
    int threshold;

public:
    Inventory(int threshold = 1);
    void amountIncrease(Products* products, int adding);
    void amountDecrease(Products* products, int subtracting);
    const std::vector<Products*>& needRestocking(ProductsCatalog* catalog);
    void initialize(ProductsCatalog* catalog);
};
