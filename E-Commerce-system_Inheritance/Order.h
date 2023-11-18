#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "Products.h"
#include "Product.h"

enum OrderStatus {
    None,
    Processing,
    Received,
    Awaiting,
    Created
};

class Order {
    int orderID;
    std::vector<Product*> products;
    double totalCost;
    OrderStatus status;

    double calculateCost();

public:
    Order(int orderID, Product* products);

    void AddProduct(Products* products);

    void allProducts();

    void changeStatus(OrderStatus status);

    double totally();

    const std::vector<Product*>& buy();
};
