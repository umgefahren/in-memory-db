//
// Created by Hannes Furmans on 09.02.22.
//

#include <gtest/gtest.h>
#include "objects.h"

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