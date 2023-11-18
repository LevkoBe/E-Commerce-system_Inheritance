#include "Product.h"

Product::Product(int productID, const std::string& name, double price)
    : productID(productID), name(name), price(price) {}

void Product::display() const {
    std::cout << "Product ID: " << productID << "; Name: " << name << "; Price: $" << price << ".\n";
}

double Product::getPrice() const {
    return price;
}

int Product::getId() const {
    return productID;
}
