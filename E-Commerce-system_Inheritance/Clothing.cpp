#include "Clothing.h"

Clothing::Clothing(int productID, const std::string& name, double price, int size, const std::string& color, char material) :
    Product(productID, name, price), color(color), size(size), material(material) {}

void Clothing::display() const {
    std::cout << "Size: " << size << "; color: " << color << "; material: " << material << "; price: " << price << ".\n";
}

void Clothing::wear() {
    condition++;
}

void Clothing::wash() {
    condition = 0;
}
