
#include <iostream>
#include <vector>
#include "Order.h"
#include "Customer.h"
#include "ProgramManager.h"



int main()
{
    // customer / balance, products /
    // inventory empty
    // catalog add
    // inventory view
    // create an order
    // buy products
    // view bought products
    "products.txt";
    std::vector<Customer*> customers = std::vector<Customer*>();
    std::vector<Order*> orders = std::vector<Order*>();
    
    customers.push_back(new Customer("John", 10000));
    ProgramManager programManager;
    programManager.setCustomer(customers[0]);

}
