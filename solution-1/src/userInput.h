#pragma once


#include <iostream>
#include <map>
#include <vector>

class UserInputHandler {

public:
    void addOption(int key, const std::string &description) {
        options[key] = description;
    }

    int getUserChoice(const std::string &prompt);

    static int getUserInput(const std::string &prompt);

    std::map<int, std::string> options;
};
