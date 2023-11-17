#pragma once
#include <iostream>
#include "Product.h"
#include "Electronics.h"
#include "Book.h"
#include "Clothing.h"
#include <string>
#include <vector>
#include <map>
#include "ProductType.h"

const std::map<std::string, int> clothesSizeDictionary {
	{"Small",  1},
	{"Medium", 2},
	{"Large",  3},
};

const std::map<std::string, char> materialToSymbol = {
	{"Silk",   '"'},
	{"Denim",  '-'},
	{"Cotton", '*'},
	{"Wool",   '+'},
	{"Leather",'#'},
	{"Linen",  '&'},
	{"Velvet", '%'},
};

const std::map<std::string, std::string> colorToHex {
	{"Black",   "#000000"},
	{"White",   "#FFFFFF"},
	{"Red",     "#FF0000"},
	{"Green",   "#00FF00"},
	{"Blue",    "#0000FF"},
	{"Yellow",  "#FFFF00"},
	{"Purple",  "#800080"},
};

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

	Products(std::vector<std::string> arguments, int startingIndex): startingIndex(startingIndex) { getAdditionalAttributes(arguments); }

	double getPrice() const override {
		return price;
	}

	int getID() {
		return startingIndex * 1000 + newIndex++;
	}

	bool available() {
		if (quantity == 0) {
			std::cout << "Sorry, no more products of this kind.\n\n";
			return false;
		}
		return true;
	}

	void setPrice(double price) {
		this->price = price;
	}
    
	Product* getProduct() override {
		quantity--;
		int size = additionalAttributesDictionary.count("screenSize") > 0 ? std::stoi(additionalAttributesDictionary["screenSize"]) : 20;
		int capacity = additionalAttributesDictionary.count("energyCapacity") > 0 ? std::stoi(additionalAttributesDictionary["energyCapacity"]) : 20000;
		switch (productType)
		{
		case ElectronicsType:
			return new Electronics(getID(), productName, price, additionalAttributesDictionary["brand"], additionalAttributesDictionary["model"], size, capacity);
			break;
		case BookType:
			return new Book(getID(), productName, price, additionalAttributesDictionary["author"], std::stoi(additionalAttributesDictionary["width"]), additionalAttributesDictionary["id"]);
			break;
		case ClothingType:
			return new Clothing(getID(), productName, price, clothesSizeDictionary.find(additionalAttributesDictionary["size"])->second,
				colorToHex.find(additionalAttributesDictionary["color"])->second, materialToSymbol.find(additionalAttributesDictionary["material"])->second);
			break;
		default:
			break;
		}

    };

	void display() const {
		std::cout << "Products: " << productName << " (" << quantity << "x)" << std::endl;
	}

	bool changeQuantity(int changer) {
		if (quantity - changer < 0)
		{
			std::cout << "Sorry, you want to take away too much...";
			return false;
		}
		quantity += changer;
		return quantity > 1;
	}

	int quantityLevel() {
		return quantity;
	}

private:
	
	void getAdditionalAttributes(std::vector<std::string> arguments) {
		int count = arguments.size();

		productType = stringToProductType(arguments[0]);
		productName = arguments[1];
		price = std::stod(arguments[2]);
		quantity = std::stoi(arguments[3]);

		switch (productType)
		{
		// [Electronics, Laptop, 799.99, 10, Dell, Inspiron 15, 45000mAh]
		// [Electronics, Smartphone, 499.99, 15, Apple, iPhone 12, 5.0 inches]
		// Electronics -> brand (---), model (---), screenSize (#) inches, energyCapacity (#) mAh
		case ElectronicsType:
			additionalAttributesDictionary["brand"] = arguments[4];
			additionalAttributesDictionary["model"] = arguments[5];
			if (arguments.size() >= 8)
			{
				additionalAttributesDictionary["mAh"] = arguments[6].substr(0, arguments[6].length() - 3);
				additionalAttributesDictionary["screenSize"] = arguments[7].substr(0, arguments[7].length() - 7);
				break;
			}
			additionalAttributesDictionary[(arguments[6].back() == 'h') ? "mAh" : "screenSize"] =
				arguments[6].substr(0, arguments[6].size() - ((arguments[6].back() == 'h') ? 3 : 7));
			break;
		// [Books, The Catcher in the Rye, 14.99, 18, J.D. Salinger, Fiction, 978-0-316-76948-0]
		// Book -> author; (---) style; (---) id; (---) width; (#)
		case BookType:
			additionalAttributesDictionary["author"] = arguments[4];
			additionalAttributesDictionary["style"] = arguments[5];
			additionalAttributesDictionary["id"] = arguments[6];
			additionalAttributesDictionary["width"] = std::string(1, arguments[6][0]);
			break;
		// [Clothing, T-Shirt, 19.99, 50, Medium, Blue, Cotton]
		// Clothing: size; (#) color; (#abcdef) material; (*)
		case ClothingType:
			additionalAttributesDictionary["size"] = arguments[4];
			additionalAttributesDictionary["color"] = arguments[5];
			additionalAttributesDictionary["material"] = arguments[6];
			break;
		default:
			break;
		}
	}

};