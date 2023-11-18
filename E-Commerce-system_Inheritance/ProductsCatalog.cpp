#include "ProductsCatalog.h"

ProductsCatalog::ProductsCatalog() {}

void ProductsCatalog::addProducts(std::vector<Products*> products) {
    for (auto& prods : products) {
        addProducts(prods);
    }
}

void ProductsCatalog::addProducts(Products* products) {
    if (std::find(productsPossible.begin(), productsPossible.end(), products) != productsPossible.end()) {
        std::cout << "Such a product already exists in the catalog.\n";
        return;
    }
    productsPossible.push_back(products);
}

bool ProductsCatalog::changeProducts(Products* products, double newPrice) {
    auto it = std::find(productsPossible.begin(), productsPossible.end(), products);
    if (it == productsPossible.end()) {
        std::cout << "Such a product doesn't exist in the catalog.\n";
        return false;
    }
    if (newPrice != 0.0) {
        products->setPrice(newPrice);
    }
    return true;
}

void ProductsCatalog::removeProducts(Products* products) {
    auto it = std::find(productsPossible.begin(), productsPossible.end(), products);
    if (it == productsPossible.end()) {
        std::cout << "Such a product doesn't exist in the catalog.\n";
        return;
    }
    productsPossible.erase(it);
    std::cout << "Successfully removed from the catalog.\n";
}

std::vector<Products*> ProductsCatalog::allProducts() {
    return productsPossible;
}

void ProductsCatalog::displayProducts() {
    for (auto& products : productsPossible) {
        products->display();
    }
}
