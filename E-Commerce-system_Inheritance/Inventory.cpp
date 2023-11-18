#include "Inventory.h"

Inventory::Inventory(int threshold) : threshold(threshold) {}

void Inventory::amountIncrease(Products* products, int adding) {
    products->changeQuantity(adding);
}

void Inventory::amountDecrease(Products* products, int subtracting) {
    products->changeQuantity(-subtracting);
}

const std::vector<Products*>& Inventory::needRestocking(ProductsCatalog* catalog) {
    std::vector<Products*> toRestock;
    for (auto& product : catalog->allProducts()) {
        auto it = std::find(productsLists.begin(), productsLists.end(), product);
        if (it == productsLists.end() || product->quantityLevel() < threshold) {
            toRestock.push_back(product);
        }
    }
    return toRestock;
}

void Inventory::initialize(ProductsCatalog* catalog) {
    productsLists = catalog->allProducts();
}
