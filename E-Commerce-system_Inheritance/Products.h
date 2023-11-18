#pragma once
#include <iostream>
#include <vector>
#include "Product.h"
#include "Electronics.h"
#include "Book.h"
#include "Clothing.h"
#include <map>
#include "ProductType.h"
#include "Dictionaries.h"

class IProducts {
protected:
    int productID;
    std::string name;
    double price;

public:
    virtual Product* getProduct() = 0;
    virtual double getPrice() const = 0;
};

class Products : public IProducts {
protected:
    int startingIndex;
    int newIndex = 0;
    ProductType productType;
    std::string productName;
    double price;
    int quantity;
    std::map<std::string, std::string> additionalAttributesDictionary;

public:
    Products(const std::vector<std::string>& arguments, int startingIndex);
    double getPrice() const override;
    int getID();
    bool available();
    void setPrice(double price);
    Product* getProduct() override;
    void display() const;
    int startIndex();
    bool changeQuantity(int changer);
    int quantityLevel();

private:
    void getAdditionalAttributes(const std::vector<std::string>& arguments);
};
