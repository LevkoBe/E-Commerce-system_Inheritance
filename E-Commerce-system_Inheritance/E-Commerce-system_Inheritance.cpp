
#include <iostream>
#include <vector>
#include "Product.h"
#include "Electronics.h"
#include "Book.h"
#include "Closing.h"
#include "ProductsReader.h"



int main()
{
    ProductsReader reader;
    std::vector<Product*> products = reader.ReadFile("products.txt", 0);

    std::string name = "[Product Name]";
    std::string brand = "Dell";
    std::string model = "Inspiron 15";

    products.push_back(new Electronics(0, name, 799.99, brand, model, 20, 20000));
    products.push_back(new Book(1, name, 7999.99, brand, 10));
    products.push_back(new Closing(2, name, 2.77, 10, "#123456", 'v'));
    for (const auto& product : products) {
        product->display();
    }
}
