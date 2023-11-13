#pragma once
#include <string>

enum ProductType {
	ElectronicsType,
	BookType,
	ClothingType,
	Unknown
};

inline ProductType stringToProductType(std::string& productTypeString) {
	static const std::map<std::string, ProductType> stringToEnum = {
		{"Electronics", ElectronicsType},
		{"Book", BookType},
		{"Books", BookType},
		{"Clothing", ClothingType},
		{"Clothings", ClothingType}
	};
	auto it = stringToEnum.find(productTypeString);
	if (it != stringToEnum.end()) {
		return it->second;
	}
	return Unknown;
}
