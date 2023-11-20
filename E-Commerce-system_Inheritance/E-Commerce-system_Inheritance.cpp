
#include <iostream>
#include <vector>
#include "Order.h"
#include "Customer.h"
#include "ProgramManager.h"
#include "E-Commerce-system_Inheritance.h"

std::vector<Customer*> customers = std::vector<Customer*>();
std::vector<Order*> orders = std::vector<Order*>();
ProgramManager programManager;

void help() {
    std::cout << "Available commands:" << std::endl;
    std::cout << "  - customer: Add a new customer" << std::endl;
    std::cout << "  - ship_storage: Retrieve products from storage" << std::endl;
    std::cout << "  - inventory: View inventory" << std::endl;
    std::cout << "  - catalog: View catalog" << std::endl;
    std::cout << "  - ship_products: Ship products to inventory" << std::endl;
    std::cout << "  - add: Add a product to the order" << std::endl;
    std::cout << "  - buy: Finish and buy the order" << std::endl;
    std::cout << "  - view_order: View products in order" << std::endl;
    std::cout << "  - view_products: View bought products" << std::endl;
    std::cout << "  - ---: Exit the program" << std::endl;
}

void ship_storage() {
    std::string filename;
    std::cout << "Enter storage with the products: "; // "products.txt"
    std::cin >> filename;
    programManager.retrieveFromStorage(filename);
}

void ship_products() {
    int productId;
    std::cout << "Enter product ID to ship: ";
    std::cin >> productId;
    int amount;
    std::cout << "Enter amouunt of products to ship: ";
    std::cin >> amount;
    programManager.productsShipment(productId, amount);
}

void create_customer() {
    std::string name;
    std::cout << "Enter name of the customer: ";
    std::cin >> name;
    int money;
    std::cout << "Enter amount of money the person has: ";
    std::cin >> money;
    customers.push_back(new Customer("John", 10000));
    programManager.setCustomer(customers.back());
}

void add(){
    int productId;
    std::cout << "Enter product ID to buy: ";
    std::cin >> productId;
    programManager.addToOrder(productId);
}


int main() {

    while (true) {
        std::cout << "\nEnter a command ('?' for a list of commands): ";
        std::string command;
        std::cin >> command;

        if (command == "---") {
            std::cout << "Exiting the program. Goodbye!" << std::endl;
            break;
        }
        else if (command == "?") {
            help();
        }
        else if (command == "customer")
        {
            create_customer();
        }
        else if (command == "ship_storage")
        {
            ship_storage();
        }
        else if (command == "inventory") {
            programManager.inventoryCheck();
        }
        else if (command == "catalog") {
            programManager.showCatalog();
        }
        else if (command == "ship_products") {
            ship_products();
        }
        else if (command == "add") {
            add();
        }
        else if (command == "play") {
            programManager.play();
        }
        else if (command == "buy") {
            programManager.finishOrder();
        }
        else if (command == "view_order") {
            programManager.showOrder();
        }
        else if (command == "view_products") {
            programManager.showProducts();
        }
        else {
            std::cout << "Invalid command. Type 'help' for a list of commands." << std::endl;
        }
    }

    for (Customer* customer : customers) {
        delete customer;
    }

    for (Order* order : orders) {
        delete order;
    }

    return 0;
}

/*
customer
John
10000
ship_storage
products.txt
inventory
catalog
ship_products
2
15
add
2
buy
view_order
view_products
exit
?

*/

/*
add
5
add
5
view_order
add
1
view_order
buy
view_products

*/
