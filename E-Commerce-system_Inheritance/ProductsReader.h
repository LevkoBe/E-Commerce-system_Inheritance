#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Products.h"

class ProductsReader
{
public:
    ProductsReader() {};

    std::vector<Products*> ReadFile(std::string filename, int startingIndex);

    Products* createProductsObject(std::string& line, int index);
};
