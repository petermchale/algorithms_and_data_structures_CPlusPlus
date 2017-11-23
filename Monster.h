//
// Created by Peter McHale on 11/2/17.
//

#ifndef CLION_WORKSPACE_MONSTER_H
#define CLION_WORKSPACE_MONSTER_H


#include <string>

class Monster {

    int size;
    int power = 100;
    std::string name;

public:
    Monster(int size, const std::string &name);

    int getSize() const;

    void setSize(int size);

    const std::string &getName() const;

    void setName(const std::string &name);
};


#endif //CLION_WORKSPACE_MONSTER_H
