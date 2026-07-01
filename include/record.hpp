#pragma once

#include <cstdint>
#include <string>

class Record {
    public:

    uint32_t id;
    std::string value;

    Record(uint32_t id, std::string value) : id(id), value(value) {
        
    }

};