//
// Created by Hannes Furmans on 09.02.22.
//

#ifndef IN_MEMORY_DB_OBJECTS_H
#define IN_MEMORY_DB_OBJECTS_H

#include <string>
#include <optional>
#include <memory>

using namespace std;

enum ObjectType {
    BinaryData,
    String,
};

class objects {
protected:
    ObjectType kind;
public:
    explicit objects(ObjectType kind) {
        this->kind = kind;
    }
    virtual ~objects() {};
};

class StringObject : public objects {
    using objects::objects;
private:
    unique_ptr<string> internal_value;
public:
    explicit StringObject(unique_ptr<string> intialValue, ObjectType kind = ObjectType::String) : objects(kind) {
        this->internal_value = move(intialValue);
    };
    ~StringObject() override {
        this->internal_value.reset();
    }
    unique_ptr<string> getUniqueString();
    void setUniqueString(unique_ptr<string> new_string);
    unique_ptr<string> getClonedString();
};

#endif //IN_MEMORY_DB_OBJECTS_H
