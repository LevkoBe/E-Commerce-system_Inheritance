#include "Products.h"

Products::Products(const std::vector<std::string>& arguments, int startingIndex)
    : startingIndex(startingIndex) {
    getAdditionalAttributes(arguments);
}

double Products::getPrice() const {
    return price;
}

int Products::getID() {
    return startingIndex * 1000 + newIndex++;
}

bool Products::available() {
    if (quantity == 0) {
        std::cout << "Sorry, no more products of this kind.\n\n";
        return false;
    }
    return true;
}

void Products::setPrice(double price) {
    this->price = price;
}

Product* Products::getProduct() {
    quantity--;
    int size = additionalAttributesDictionary.count("screenSize") > 0 ? std::stoi(additionalAttributesDictionary["screenSize"]) : 20;
    int capacity = additionalAttributesDictionary.count("energyCapacity") > 0 ? std::stoi(additionalAttributesDictionary["energyCapacity"]) : 20000;
    switch (productType) {
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
}

void Products::display() const {
    std::cout << "Products: " << productName << " (" << quantity << "x)" << " [id: " << startingIndex << "]" << std::endl;
}

int Products::startIndex() {
    return startingIndex;
}

bool Products::changeQuantity(int changer) {
    if (quantity + changer < 0) {
        std::cout << "Sorry, you want to take away too much...\n";
        return false;
    }
    quantity += changer;
    return quantity > 1;
}

int Products::quantityLevel() {
    return quantity;
}

void Products::getAdditionalAttributes(const std::vector<std::string>& arguments) {
    int count = arguments.size();

    productType = stringToProductType(arguments[0]);
    productName = arguments[1];
    price = std::stod(arguments[2]);
    quantity = std::stoi(arguments[3]);

    switch (productType) {
    case ElectronicsType:
        additionalAttributesDictionary["brand"] = arguments[4];
        additionalAttributesDictionary["model"] = arguments[5];
        if (arguments.size() >= 8) {
            additionalAttributesDictionary["mAh"] = arguments[6].substr(0, arguments[6].length() - 3);
            additionalAttributesDictionary["screenSize"] = arguments[7].substr(0, arguments[7].length() - 7);
            break;
        }
        additionalAttributesDictionary[(arguments[6].back() == 'h') ? "mAh" : "screenSize"] =
            arguments[6].substr(0, arguments[6].size() - ((arguments[6].back() == 'h') ? 3 : 7));
        break;
    case BookType:
        additionalAttributesDictionary["author"] = arguments[4];
        additionalAttributesDictionary["style"] = arguments[5];
        additionalAttributesDictionary["id"] = arguments[6];
        additionalAttributesDictionary["width"] = std::string(1, arguments[6][0]);
        break;
    case ClothingType:
        additionalAttributesDictionary["size"] = arguments[4];
        additionalAttributesDictionary["color"] = arguments[5];
        additionalAttributesDictionary["material"] = arguments[6];
        break;
    default:
        break;
    }
}
