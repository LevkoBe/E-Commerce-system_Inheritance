
#include <iostream>
#include <vector>
#include "Products.h"
#include "ProductsReader.h"



int main()
{
    ProductsReader reader;
    std::vector<Products*> productss = reader.ReadFile("products.txt", 0);

    for (const auto& products : productss) {
        products->display();
        while (products->available())
        {
            products->getProduct()->display();
        }
    }
}
