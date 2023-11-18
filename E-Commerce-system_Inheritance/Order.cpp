#include "Order.h"

double Order::calculateCost() {
    double cost = 0;
    for (auto& prods : products) {
        cost += prods->getPrice();
    }
    totalCost = cost;
    return totalCost;
}

Order::Order(int orderID, Product* products) : orderID(orderID), products(std::vector<Product*>()), status(Created) {
    calculateCost();
    this->products.push_back(products);
}

void Order::AddProduct(Products* products) {
    if (products->available()) {
        this->products.push_back(products->getProduct());
        return;
    }
    std::cout << "Product isn't available.\n";
}

void Order::allProducts() {
    for (auto& product : products) {
        product->display();
    }
}

void Order::changeStatus(OrderStatus status) {
    this->status = status;
}

double Order::totally() {
    calculateCost();
    return totalCost;
}

std::vector<Product*> Order::buy() {
    status = Received;
    return products;
}
