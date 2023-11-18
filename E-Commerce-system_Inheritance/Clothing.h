#pragma once
#include <iostream>
#include "Product.h"


class Clothing final : public Product {
    int size;
    std::string color; // hex: #abcdef
    char material;
    int condition = 0; // --> enum
public:
    Clothing(int productID, const std::string& name, double price, int size, const std::string& color, char material) :
        Product(productID, name, price), color(color), size(size), material(material) {}
    void display() const override {
        std::cout << "Size: " << size << "; color: " << color << "; material: " << material << "; price: " << price << ".\n";
    }
    void wear() {
        condition++;
    }
    void wash() {
        condition = 0;
    }
};