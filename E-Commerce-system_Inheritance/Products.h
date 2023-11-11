#pragma once
#include <iostream>
#include "Product.h"
#include "Electronics.h"
#include "Book.h"
#include "Closing.h"
#include <string>
#include <vector>

class IProducts {
protected:
    int productID;
    std::string name;
    double price;
public:
    virtual Product* getProduct() const = 0;
};

class Products : public IProducts {
protected:
	int startingIndex;
	std::string productType; // enum 
	std::string productName;
	double price;
	int quantity;
	std::vector<std::string> additionalAttributes;

public:

	Products(int startingIndex, const std::string& productType, const std::string& productName, double price, int quantity, const std::vector<std::string>& additionalAttributes)
		: startingIndex(startingIndex), productType(productType), productName(productName), price(price), quantity(quantity), additionalAttributes(additionalAttributes) {}

    Product* getProduct() const override {

		switch (arguments[0][0])
		{
		case 'E': // Electronics
			return createElectronicsObject(index, arguments);
		case 'B': // Book
			return new Book(index, arguments[1], std::stod(arguments[2]), arguments[3], std::stoi(arguments[4]));
		case 'C': // Closing
			return new Closing(index, arguments[1], std::stod(arguments[2]), std::stoi(arguments[3]), arguments[4], arguments[5][0]);
		default:
			return new Product(0, arguments[0], 0.0);
		}
    };
private:
	Product* createElectronicsObject(int index, std::vector<std::string> arguments) {
		// [Electronics, Laptop, 799.99, 10, Dell, Inspiron 15, 45000mAh]
		// [Electronics, Smartphone, 499.99, 15, Apple, iPhone 12, 5.0 inches]
		int count = arguments.size();
		std::string mAhOrScreen = arguments[count - 1];
		int length = mAhOrScreen.size();
		if (count >= 7)
		{
			int mAh = std::stoi(arguments[5].substr(0, mAhOrScreen.length() - 3));
			int screenSize = std::stoi(arguments[6].substr(0, mAhOrScreen.length() - 7));
			return new Electronics(index, arguments[1], std::stod(arguments[2]), arguments[3], arguments[4], mAh, screenSize);
		}
		if (mAhOrScreen[length - 1] == 'h') { // mAh
			int mAh = std::stoi(mAhOrScreen.substr(0, mAhOrScreen.length() - 3));
			return new Electronics(index, arguments[1], std::stod(arguments[2]), arguments[3], arguments[4], 20, mAh);
		} // inches
		int screenSize = std::stoi(mAhOrScreen.substr(0, mAhOrScreen.length() - 7));
		return new Electronics(index, arguments[1], std::stod(arguments[2]), arguments[3], arguments[4], screenSize, 20000);
	}
};