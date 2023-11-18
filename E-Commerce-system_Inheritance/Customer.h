#pragma once
#include <iostream>
#include <vector>
#include "Order.h"
#include "Products.h"
#include "Product.h"
#include <ctime>

class Customer {
    Order* order = nullptr;
    std::vector<Product*> bought_products;
    double money;
    std::string name;

public:
    Customer(std::string name, double money);

    bool products();

    void acquireMoney(int add);

    bool spendMoney(int spend);

    void buy(Product* product);

    double balance() const;

    Product* productByID(int ID);

    void sell(int ID);
};
