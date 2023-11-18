#pragma once
#include "Products.h"

class ProductsCatalog {
    std::vector<Products*> productsPossible;

public:
    ProductsCatalog();

    void addProducts(const std::vector<Products*>& products);

    void addProducts(Products* products);

    bool changeProducts(Products* products, double newPrice = 0.0);

    void removeProducts(Products* products);

    const std::vector<Products*>& allProducts();

    void displayProducts();
};
