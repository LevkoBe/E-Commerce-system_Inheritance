#include "ProductsReader.h"

std::vector<Products*> ProductsReader::ReadFile(std::string filename, int startingIndex) {
    std::vector<Products*> toBeReturned = std::vector<Products*>();
    std::ifstream inputFile(filename);
    if (!inputFile) {
        inputFile.close();
        std::cout << "Sorry, incorrect file name." << std::endl;
        return toBeReturned;
    }
    std::string line;

    while (getline(inputFile, line))
    {
        if (line[0] == '\#')
        {
            continue;
        }
        Products* nextProducts = createProductsObject(line, startingIndex++);
        if (nextProducts->getPrice() == 0.0)
        {
            std::cout << "There's an error in the file " << filename << ". It is recommended to fix the error.\n";
            continue;
        }
        toBeReturned.push_back(nextProducts);
    }
    return toBeReturned;
}

Products* ProductsReader::createProductsObject(std::string& line, int index) {
    std::istringstream iss(line);
    std::string argument;
    std::vector<std::string> arguments;

    while (std::getline(iss, argument, ','))
    {
        size_t start = argument.find_first_not_of(" ");
        size_t end = argument.find_last_not_of(" ");
        argument = (start != std::string::npos && end != std::string::npos) ? argument.substr(start, end - start + 1) : "";
        arguments.push_back(move(argument));/// read more todo
    }
    return new Products(arguments, index);
}
