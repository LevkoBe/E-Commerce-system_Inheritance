#pragma once
#include <iostream>

class IProduct {
protected:
    int productID;
    std::string name;
    double price;
public:
    virtual void display() const = 0;
    virtual double getPrice() const = 0;
    virtual int getId() const = 0;
};

class Product : public IProduct {
protected:
    int productID;
    std::string name;
    double price;
public:
    virtual void display() const override {};
    double getPrice() const override {
        return price;
    }
    int getId() const override {
        return productID;
    }
    Product(int productID, std::string& name, double price) : productID(productID), name(name), price(price) {};
};