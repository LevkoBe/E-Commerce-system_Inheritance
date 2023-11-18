#pragma once
#include <iostream>

class IProduct {
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
    Product(int productID, const std::string& name, double price);
    virtual void display() const override;
    double getPrice() const override;
    int getId() const override;
};
