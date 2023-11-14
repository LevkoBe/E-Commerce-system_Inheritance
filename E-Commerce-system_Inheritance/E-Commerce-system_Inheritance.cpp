
#include <iostream>
#include <vector>
#include "Products.h"
#include "ProductsReader.h"
#include "Customer.h"



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
    Customer john("John", 10000);
    john.balance();
    john.products();
}
