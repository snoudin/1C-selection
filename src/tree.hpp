#pragma once

#include <map>
#include <string>
#include <vector>

class Tree {
  private:
    struct Node {
        std::map<std::pair<int, char>, Node*> children;
        int collisions = 0;
        int max_subtree = 0;

        std::pair<int, Node*> most_popular() const {
            if (collisions == max_subtree) return {collisions, this};
            auto [k, v] = *children.begin();
            return {k.first, v};
        }

        Node* add(char c) const { // increases counters
            //TODO
        }

        Node* descend(char c) const { // for search only
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
        Node* cur = root;
        for (char c : word) {
            cur = cur->add(c);
        }
    }

    void add(std::vector<std::string> words) {
        for (const auto& word : words) {
            add(word);
        }
    }

    std::string process(const std::string& query) const {
        return "No collisions found";
    }

    std::string update(const std::string& suffix) const {
        return "No collisions found";
    }
};
