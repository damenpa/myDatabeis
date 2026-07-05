#pragma once

#include <cstdint>
#include <string>
#include <fstream>

class Record {
    public:

    uint32_t id;
    std::string value;

    Record(uint32_t id, std::string value) : id(id), value(value) {
        
    }

    Record() = default;

    void serialize(std::ofstream& file,Record &r);
    Record deserialize(std::ifstream& file);

};