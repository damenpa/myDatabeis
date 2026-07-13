#pragma once

#include <cstdint>
#include <unordered_map>
#include <string>
#include <vector>
#include "record.hpp"

class Database {
    public:

    Database() {
        load();
        buildIndex();
    }

    std::unordered_map<uint32_t,size_t> index;

    std::vector<Record> records;

    bool insert(Record &r);
    std::string get(uint32_t id);
    bool update(uint32_t id, std::string &value);
    bool remove(uint32_t id);
    void list();

    void buildIndex();

    void save();
    void load();

};