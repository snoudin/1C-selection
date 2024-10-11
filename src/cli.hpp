#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

std::string purify_string(const std::string& word) {
    std::string cleared;
    for (char c : word) {
        if (c == '-' or c == '_' or std::isalpha(c) or std::isdigit(c)) {
            cleared += c;
        }
    }
    return cleared;
}

std::vector<std::string> purify(const std::string& line) {
    std::vector<std::string> result;
    std::stringstream cin(line);
    std::string word;
    while (cin >> word) {
        std::string cleared(std::move(purify_string(word)));
        if (cleared.size() > 0) {
            result.push_back(cleared);
        }
    }
    return result;
}

void process_queries(auto& processor) {
    while (true) {
        std::string type, _;
        std::cin >> type;
        if (type == "quit" || type == "exit") break;
        if (type == "add_text") {
            std::getline(std::cin, _); // fix cin-getline conflict
            std::string line;
            std::getline(std::cin, line);
            processor.add(purify(line));
        } else if (type == "find") {
            std::string query;
            std::cin >> query;
            std::getline(std::cin, _); // fix cin-getline conflict
            std::cout << processor.process(purify_string(query)) << std::endl;
        } else if (type == "write") {
            std::string suffix;
            std::cin >> suffix;
            std::getline(std::cin, _); // fix cin-getline conflict
            std::cout << processor.update(purify_string(suffix)) << std::endl;
        } else {
            std::cout << "unsupported query, try again" << std::endl;
        }
    }
}

void print_help() {
    std::cout << "Welcome to WordSearcher" << std::endl;
    std::cout << "Currently supported characters are letters, digits, \'-\' and \'_\'" << std::endl;
    std::cout << "Following commands are supported:" << std::endl;
    std::cout << "\"add_text\" to add line of text as set of words to dictionary" << std::endl;
    std::cout << "The text should be given on a separate line" << std::endl;
    std::cout << "\"find\" to search best collocation for given prefix in dictionary" << std::endl;
    std::cout << "The prefix should be given on the same line" << std::endl;
    std::cout << "\"write\" to write few extra characters to the end of current query" << std::endl;
    std::cout << "The string should be given on the same line" << std::endl;
    std::cout << "\"quit\" or \"exit\" to finish work" << std::endl << std::endl;
}
