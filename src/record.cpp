#include "record.hpp"
#include <fstream>

void Record::serialize(std::ofstream& file, Record &r) {

    file.write(
        reinterpret_cast<char*>(&r.id),
        sizeof(r.id)
    );

    int length = r.value.size();

    file.write(
        reinterpret_cast<char*>(&length), 
        sizeof(length)
    );

    file.write(
        r.value.data(),
        length
    );
}

Record Record::deserialize(std::ifstream& file) {

    Record r;

    file.read(
        reinterpret_cast<char*>(&r.id),
        sizeof(r.id)
    );

    int length;

    file.read(
        reinterpret_cast<char*>(&length),
        sizeof(length)
    );

    r.value.resize(length);

    file.read(
        r.value.data(),
        length
    );

    return r;
}