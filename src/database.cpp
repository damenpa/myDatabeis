#include "record.hpp"
#include "database.hpp"
#include <fstream>
#include <iostream>

bool Database::insert(Record r) {
    
    if(index.find(r.id) != index.end()) {
        return false;
    }

    records.push_back(r);
    index[r.id] = records.size() - 1;
    return true;
} 

std::string Database::get(uint32_t id) {

    if(index.find(id) == index.end()) {
        return "not found";
    }

    size_t pos = index.at(id);
    return records[pos].value;
}

bool Database::remove(uint32_t id) {
    for(auto it = records.begin(); it != records.end(); it++) {
        if(it->id == id) {
            records.erase(it);
            buildIndex();
            return true;
        }
    }
    return false;
}    

bool Database::update(uint32_t id, std::string value) {

    if(index.find(id) == index.end()) {
        return false;
    }

    size_t pos = index.at(id);
    records[pos].value = value;
    return true;
}

void Database::list() {
    for(auto &r : records) {
        std::cout << r.id << " " << r.value << std::endl;
    }
}

void Database::buildIndex() {

    index.clear();

    for(size_t i = 0; i < records.size(); i++) {
        index[records[i].id] = i;
    }
}


void Database::save() {

    std::ofstream file("data/records.bin",std::ios::binary);
    for (auto &r : records) {
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

    buildIndex();
}




