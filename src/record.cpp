#include "record.hpp"
#include <fstream>

void Record::serialize(std::ofstream& file) {

    file.write(
        reinterpret_cast<char*>(&id),
        sizeof(id)
    );

    int length = value.size();

    file.write(
        reinterpret_cast<char*>(&length), 
        sizeof(length)
    );

    file.write(
        value.data(),
        length
    );
}

bool Record::deserialize(std::ifstream& file,Record &r) {

    file.read(
        reinterpret_cast<char*>(&r.id),
        sizeof(r.id)
    );

    if(!file) return false;

    int length;

    file.read(
        reinterpret_cast<char*>(&length),
        sizeof(length)
    );

    r.value.resize(length);

    file.read(
        &r.value[0],
        length
    );
    
    return true;
}