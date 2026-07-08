#pragma once

#include <cstdint>
#include <unordered_map>
#include <string>
#include <vector>
#include "record.hpp"

class Database {
    public:

    std::vector<Record> records;

    void insert(Record r);

    std::string get(int id);

    void save();
    void load();

};