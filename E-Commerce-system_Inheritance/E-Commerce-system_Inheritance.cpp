
#include <iostream>
#include <vector>

class IProduct {
protected:
    int productID;
    std::string name;
    double price;
public:
    virtual void display() const = 0;
};

class Product : public IProduct {
protected:
    int productID;
    std::string name;
    double price;
public:
    virtual void display() const override {};
    Product(int productID, std::string& name, double price) : productID(productID), name(name), price(price) {};
};


class Electronics final : public Product {
    std::string brand;
    std::string model;
    int screenSize;
    int energyCapacity;
    double batteryLevel = 100.0;
public:
    Electronics(int productID, std::string& name, double price, std::string& brand, std::string& model, int screenSize, int energyCapacity):
        Product(productID, name, price), brand(brand), model(model), screenSize(screenSize), energyCapacity(energyCapacity) {};
    void display() const override {
        std::cout << "Electronics: " << std::endl;
        std::cout << "Brand: " << brand << "; model: " << model << "; screen size: " << screenSize << "; price: " << price << ".\n\n";
    }
    void battery() {
        std::cout << "Battery level : " << batteryLevel << " % (" << batteryLevel * double(energyCapacity) << "mAh).\n\n";
    }
};

class Book final : public Product {
    std::string author;
    int width;
    std::string* pages;
    int bookmark = 0;
    void generatePages() {
        pages = new std::string[width];
        for (int i = 0; i < width; i++)
        {
            pages[i] = "Generate some text, please.";
        }
    }
public:
    Book(int productID, std::string& name, double price, std::string author, int width) : 
        Product(productID, name, price), author(author), width(width) { generatePages(); }
    void display() const override {
        std::cout << "Book: " << std::endl;
        std::cout << "Page " << bookmark << ":\n\n";
        std::cout << pages[bookmark] << "\n\n";
    }
    int page() const { return bookmark; }
    void read() {
        display();
        bookmark--;
    }
    void forget() {
        bookmark = 0;
    }
};


class Closing final : public Product {
    int size;
    std::string color; // hex: #abcdef
    char material;
    int condition = 0; // --> enum
public:
    Closing(int productID, std::string& name, double price, int size, std::string color, char material) :
        Product(productID, name, price), color(color), size(size), material(material) {}
    void display() const override {
        std::cout << "Closing: " << std::endl;
        std::cout << "Size: " << size << "; color: " << color << "; material: " << material << "; price: " << price << ".\n\n";
    }
    void wear() {
        condition++;
    }
    void wash() {
        condition = 0;
    }
};



int main()
{
    std::vector<Product*> products;
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
