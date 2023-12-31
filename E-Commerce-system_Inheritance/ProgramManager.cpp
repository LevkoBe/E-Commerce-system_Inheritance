#include "ProgramManager.h"

Products* ProgramManager::productsByID(int productID) {
	for (auto& products : productsCatalog->allProducts())
	{
		if (products->startIndex() == productID)
		{
			return products;
		}
	}
}

bool ProgramManager::existsProductsByID(int productID) {
	for (auto& products : productsCatalog->allProducts())
	{
		if (products->startIndex() == productID)
		{
			return true;
		}
	}
	return false;
}

void ProgramManager::retrieveFromStorage(const std::string& filename) {
	std::vector<Products*> productss = reader.ReadFile(filename, startingIndex);
	if (productsCatalog == nullptr)
	{
		productsCatalog = new ProductsCatalog();
	}
	productsCatalog->addProducts(productss);
	startingIndex += 1000;
}

void ProgramManager::showCatalog() {
	for (auto& products : productsCatalog->allProducts())
	{
		products->display();
	}
}

void ProgramManager::showOrder() {
	if (order != nullptr)
	{
		order->allProducts();
		return;
	}
	std::cout << "You have no orders.\n";
}

void ProgramManager::showProducts() {
	if (customer->products())
	{
		customer->display_products();
	}
}

void ProgramManager::finishOrder() {
	double totalCost = order->totally();
	double balance = customer->balance();
	if (balance < totalCost)
	{
		std::cout << "Sorry, you don't have enough money. (Cost: " << totalCost << "; balance: " << balance << ")\n";
	}
	std::vector<Product*> prods = order->buy();
	for (auto& product : prods)
	{
		customer->buy(product);
	}
	delete order;
	order = nullptr;
}

void ProgramManager::addToOrder(int productID) {
	if (existsProductsByID(productID))
	{
		Products* products = productsByID(productID);
		if (order == nullptr)
		{
			order = new Order(orderID, products->getProduct());
			orderID++;
		}
		else {
			order->AddProduct(products);
		}
		std::cout << "You've got new product in your order.\n";
	}
}

void ProgramManager::inventoryCheck() {
	bool inventoryIsOk = true;
	if (inventory == nullptr)
	{
		if (productsCatalog == nullptr) {
			std::cout << "Sorry, you don't have a product catalog. Please, add a catalog.\n";
			return;
		}
		inventory = new Inventory(15);
		inventory->initialize(productsCatalog);
	}
	std::cout << "Checking inventory...\n";
	for (auto& products : inventory->needRestocking(productsCatalog))
	{
		std::cout << "- ";
		products->display();
		inventoryIsOk = false;
	}
	if (inventoryIsOk)
	{
		std::cout << "Inventory is ok. No need to renew anything.\n";
		return;
	}
	std::cout << "These products ^ need restocking.\n";
}

void ProgramManager::productsShipment(int productID, int amount) {
	if (inventory != nullptr)
	{
		if (!existsProductsByID(productID))
		{
			std::cout << "Sorry, there's no such product...\n";
			return;
		}
		Products* products = productsByID(productID);
		inventory->amountIncrease(products, amount);
		std::cout << "Product updated:\n";
		products->display();
	}
}

void ProgramManager::play() { // casting
	if (customer && customer->products())
	{
		for (const auto product : customer->allProducts()) {
			if (Electronics* gadget = dynamic_cast<Electronics*>(product))
			{
				gadget->play();
				return;
			}
		}
		std::cout << "Sorry, you don't have an electronics.\n";
		return;
	}
	std::cout << "Sorry, you don't have a customer.\n";
}
