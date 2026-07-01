#include "database.hpp"
#include "record.hpp"
#include <iostream>

int main() {
    Database db = Database();

    db.insert(1,"Yolis");
    db.insert(2,"Pedro");

    std::cout << db.get(2) << std::endl;
    
}