
#include <iostream>
#include <vector>
#include "Order.h"
#include "Customer.h"
#include "ProgramManager.h"

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


int main() {
    std::string filename = "products.txt";
    std::vector<Customer*> customers = std::vector<Customer*>();
    std::vector<Order*> orders = std::vector<Order*>();

    ProgramManager programManager;

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
            std::string name;
            std::cout << "Enter name of the customer: ";
            std::cin >> name;
            int money;
            std::cout << "Enter amount of money the person has: ";
            std::cin >> money;
            customers.push_back(new Customer("John", 10000));
            programManager.setCustomer(customers.back());
        }
        else if (command == "ship_storage")
        {
            std::string filename;
            std::cout << "Enter storage with the products: "; // "products.txt"
            std::cin >> filename;
            programManager.retrieveFromStorage(filename);
        }
        else if (command == "inventory") {
            programManager.inventoryCheck();
        }
        else if (command == "catalog") {
            programManager.showCatalog();
        }
        else if (command == "ship_products") {
            int productId;
            std::cout << "Enter product ID to ship: ";
            std::cin >> productId;
            int amount;
            std::cout << "Enter amouunt of products to ship: ";
            std::cin >> amount;
            programManager.productsShipment(productId, amount);
        }
        else if (command == "add") {
            int productId;
            std::cout << "Enter product ID to buy: ";
            std::cin >> productId;
            programManager.addToOrder(productId);
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
