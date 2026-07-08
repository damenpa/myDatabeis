#include "record.hpp"
#include "database.hpp"
#include <fstream>

void Database::insert(Record r) {
    records.push_back(r);
} 

std::string Database::get(int id) {
    for(const auto &r : records) {
        if(r.id == id) {
            return r.value;
        }
    }
}

void Database::save() {

    std::ofstream file("data/records.bin",std::ios::binary);
    for (auto& r : records) {
        r.serialize(file);
    }

}

void Database::load() {

    records.clear();
    std::ifstream file("data/records.bin",std::ios::binary);

    Record r;

        while(Record::deserialize(file,r)) {
            records.push_back(r);
        }
}




