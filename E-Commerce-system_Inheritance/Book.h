#pragma once
#include <iostream>
#include "Product.h"


class Book final : public Product {
    std::string author;
    int width;
    std::string* pages;
    std::string ID;
    int bookmark = 0;
    void generatePages() {
        pages = new std::string[width];
        for (int i = 0; i < width; i++)
        {
            pages[i] = "Generate some text, please.";
        }
    }
public:
    Book(int productID, std::string& name, double price, std::string author, int width, std::string ID) :
        Product(productID, name, price), author(author), width(width), ID(ID) {
        generatePages();
    }
    void display() const override {
        std::cout << "Page " << bookmark << ":\n\n";
        std::cout << pages[bookmark] << "\n\n";
    }
    int page() const { return bookmark; }
    void read() {
        display();
        bookmark--;
    }
    void forget() {
        bookmark = 0;
    }
};

