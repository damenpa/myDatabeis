#include "database.hpp"
#include "record.hpp"
#include <iostream>
#include <fstream>

int main() {
    
    Record r(1,"Hola");
    Database db = Database();

    db.load();
    std::cout << db.get(1) << "\n";

}