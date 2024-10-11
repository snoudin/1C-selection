#pragma once

#include <map>


class Tree {
  private:
    struct Node {
        std::map<std::pair<int, char>, Node*> children;
        int collisions = 0;

        std::pair<int, Node*> most_popular() const {
            //TODO
        }

        Node* descend(char c) const {
            //TODO
        }
    };
   
    Node* root = nullptr;
    Node* position = nullptr;
    std::string current = "";

  public:
    Tree() = default;

    Tree(const Tree&) = delete;
    Tree(Tree&&) = default;

    Tree& operator=(const Tree&) = delete;
    Tree& operator=(Tree&&) = default;

    void add(const std::string& word) {
        //TODO
    }

    void add(std::vector<std::string>> words) {
        for (const auto& word : words) {
            add(word);
        }
    }

    std::string process(const std::string& query) const {

    }

    std::string update(const std::string& suffix) const {

    }
};
