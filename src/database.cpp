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


