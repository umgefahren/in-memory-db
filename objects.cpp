//
// Created by Hannes Furmans on 09.02.22.
//

#include "objects.h"
#include <memory>
#include <string>

unique_ptr<string> StringObject::getUniqueString() {
    auto ret = std::move(this->internal_value);
    return ret;
}

void StringObject::setUniqueString(unique_ptr<string> new_string) {
    this->internal_value.reset();
    this->internal_value = move(new_string);
}

unique_ptr<string> StringObject::getClonedString() {
    auto ret = std::make_unique<string>(*this->internal_value);
    return ret;
}

unique_ptr<vector<uint8_t>> BinaryObject::getUniqueData() {
    auto ret = std::move(this->internal_value);
    return ret;
}

void BinaryObject::setUniqueData(unique_ptr<vector<uint8_t>> new_data) {
   this->internal_value.reset();
   this->internal_value = move(new_data);
}

unique_ptr<vector<uint8_t>> BinaryObject::getClonedBytes() {
    auto ret = std::make_unique<vector<uint8_t>>(*this->internal_value);
    return ret;
}
