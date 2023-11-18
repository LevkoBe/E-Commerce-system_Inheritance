#include "Book.h"

void Book::generatePages() {
    pages = new std::string[width];
    for (int i = 0; i < width; i++)
    {
        pages[i] = "Generate some text, please.";
    }
}

void Book::display() const {
    //std::cout << "Page " << bookmark << ":\n";
    //std::cout << pages[bookmark] << "\n";
    std::cout << "Book by " << author << ", has " << width << " pages.\n";
}

void Book::read() {
    display();
    bookmark--;
}

void Book::forget() {
    bookmark = 0;
}