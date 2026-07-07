#include "record.hpp"
#include "database.hpp"
#include <fstream>

void Database::insert(int id, std::string value) {
    records.push_back(Record(id,value));
} 

std::string Database::get(int id) {
    for(const auto &r : records) {
        if(r.id == id) {
            return r.value;
        }
    }
}

void Database::save() {

    std::ofstream file("records.bin",std::ios::binary);
    for (auto& r : records) {
        r.serialize(file);
    }

}

void Database::load() {

    records.clear();
    std::ifstream file("records.bin",std::ios::binary);

    Record r;

        while(Record::deserialize(file,r)) {
            records.push_back(r);
        }
}




