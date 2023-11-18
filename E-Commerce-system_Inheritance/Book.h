#pragma once
#include <iostream>
#include "Product.h"


class Book final : public Product {
    std::string author;
    int width;
    std::string* pages;
    std::string ID;
    int bookmark = 0;
    void generatePages();
public:
    Book(int productID, std::string& name, double price, std::string author, int width, std::string ID) :
        Product(productID, name, price), author(author), width(width), ID(ID) {
        generatePages();
    }
    void display() const override;
    int page() const { return bookmark; }
    void read();
    void forget();
};

