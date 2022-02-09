//
// Created by Hannes Furmans on 09.02.22.
//

#include "objects.h"


unique_ptr<string> StringObject::getUniqueString() {
    auto ret = std::move(this->internal_value);
    return ret;
}

void StringObject::setUniqueString(unique_ptr<string> new_string) {
    this->internal_value = move(new_string);
}

unique_ptr<string> StringObject::getClonedString() {
    auto ret = std::make_unique<string>(*this->internal_value);
    return ret;
}
