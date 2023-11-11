#pragma once
#include <iostream>
#include "Product.h"


class Book final : public Product {
    std::string author;
    int width;
    std::string* pages;
    int bookmark = 0;
    void generatePages() {
        pages = new std::string[width];
        for (int i = 0; i < width; i++)
        {
            pages[i] = "Generate some text, please.";
        }
    }
public:
    Book(int productID, std::string& name, double price, std::string author, int width) :
        Product(productID, name, price), author(author), width(width) {
        generatePages();
    }
    void display() const override {
        std::cout << "Book: " << std::endl;
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

