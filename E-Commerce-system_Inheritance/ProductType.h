#pragma once
#include <string>

enum ProductType {
	ElectronicsType,
	BookType,
	ClosingType,
	Unknown
};

inline ProductType stringToProductType(std::string& productTypeString) {
	static const std::map<std::string, ProductType> stringToEnum = {
		{"Electronics", ElectronicsType},
		{"Book", BookType},
		{"Closing", ClosingType}
	};
	auto it = stringToEnum.find(productTypeString);
	if (it != stringToEnum.end()) {
		return it->second;
	}
	return Unknown;
}
