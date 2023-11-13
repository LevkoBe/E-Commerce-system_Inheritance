
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
    std::vector<Products*> productss = reader.ReadFile("products.txt", 0);

    for (const auto& products : productss) {
        products->display();
    }
}
