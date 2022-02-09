//
// Created by Hannes Furmans on 09.02.22.
//

#include <gtest/gtest.h>
#include "objects.h"
#include <cstddef>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

TEST(StringTest, Basic) {
    auto initial_string = "Hello World";
    auto init_string = make_unique<string>(initial_string);
    StringObject string_obj = StringObject(move(init_string));
    auto copied_string = string_obj.getClonedString();
    auto moved_string = string_obj.getUniqueString();
    ASSERT_EQ(initial_string, *moved_string) << "Dereferenced string doesn't keeps it's value.";
    ASSERT_EQ(initial_string, *copied_string) << "Cloning of internal value, didn't work";

    auto new_string = "World Hello";
    auto new_string_ptr = make_unique<string>(new_string);
    string_obj.setUniqueString(move(new_string_ptr));
    auto second_get = string_obj.getClonedString();
    ASSERT_NE(initial_string, *second_get);
    ASSERT_EQ(new_string, *second_get);
}

TEST(ByteTest, Basic) {
    auto initial_string = new string("Hello World");
    std::vector<uint8_t> initial_binary(initial_string->begin(), initial_string->end());
    auto initial_pointer = make_unique<std::vector<uint8_t>>(initial_binary);
    auto * binary_obj = new BinaryObject(move(initial_pointer));
    auto copied_bytes = binary_obj->getClonedBytes();
    auto moved_bytes = binary_obj->getUniqueData();
    ASSERT_EQ(initial_binary, *moved_bytes);
    ASSERT_EQ(initial_binary, *copied_bytes);

    auto new_string = new string("World Hello");
    std::vector<uint8_t> new_binary(new_string->begin(), new_string->end());
    auto new_binary_ptr = make_unique<std::vector<uint8_t>>(new_binary);
    binary_obj->setUniqueData(move(new_binary_ptr));
    auto second_get = binary_obj->getClonedBytes();
    ASSERT_NE(initial_binary, *second_get);
    ASSERT_EQ(new_binary, *second_get);

    delete binary_obj;
    delete initial_string;
    delete new_string;
}