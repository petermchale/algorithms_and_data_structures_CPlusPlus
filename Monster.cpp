//
// Created by Peter McHale on 11/2/17.
//

#include "Monster.h"

Monster::Monster(int size, const std::string &name) : size(size), name(name) {}

int Monster::getSize() const {
    return size;
}

void Monster::setSize(int size) {
    Monster::size = size;
}

const std::string &Monster::getName() const {
    return name;
}

void Monster::setName(const std::string &name) {
    Monster::name = name;
}
