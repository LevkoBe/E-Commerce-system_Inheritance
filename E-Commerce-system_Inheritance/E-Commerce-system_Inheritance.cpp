
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
    std::string filename = "products.txt";
    std::vector<Customer*> customers = std::vector<Customer*>();
    std::vector<Order*> orders = std::vector<Order*>();
    
    customers.push_back(new Customer("John", 10000));
    ProgramManager programManager;
    programManager.setCustomer(customers[0]);
    programManager.retrieveFromStorage(filename);
    programManager.showCatalog();
    programManager.inventoryCheck();
    programManager.productsShipment(2, 15);
    programManager.inventoryCheck();
    programManager.addToOrder(2);
    programManager.addToOrder(3);
    programManager.showOrder();
    programManager.finishOrder();

}
