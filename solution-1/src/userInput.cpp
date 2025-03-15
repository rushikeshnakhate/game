
#include "userInput.h"

int UserInputHandler::getUserChoice(const std::string &prompt) {
    int choice;
    while (true) {
        std::cout << prompt << "\n";
        for (const auto &option: options) {
            std::cout << option.first << ". " << option.second << "\n";
        }
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (options.find(choice) != options.end()) {
            return choice;
        } else {
            std::cerr << "Invalid choice! Please try again.\n";
        }
    }
}

int UserInputHandler::getUserInput(const std::string &prompt) {
    int input;
    std::cout << prompt;
    std::cin >> input;
    return input;
}


void initializeGame(int &N, int &matchCondition, UserInputHandler &inputHandler) {
    inputHandler.addOption(1, "Face Value");
    inputHandler.addOption(2, "Suit");
    inputHandler.addOption(3, "Both Face Value and Suit");
    inputHandler.addOption(4, "Custom Matching Condition");  // Easily extendable
    N = UserInputHandler::getUserInput("Enter the number of packs to use: ");
    matchCondition = inputHandler.getUserChoice("Choose matching condition:");
    std::cout << "You selected " << N << " packs and condition: " << inputHandler.options[matchCondition] << "\n";
}
