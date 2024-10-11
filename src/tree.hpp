#pragma once

#include <map>
#include <set>
#include <string>
#include <vector>

class Tree {
  private:
    struct Node {
        std::map<char, std::pair<Node*, int>> children;
        std::set<std::pair<int, char>> best; // tree-based versions are faster on such sizes
        int collisions = 0;
        int max_subtree = 0;

        std::pair<int, Node*> most_popular() {
            if (collisions == max_subtree) return std::make_pair(collisions, this);
            auto [cnt, c] = *best.begin();
            return std::make_pair(cnt, children[c].first);
        }

        Node* add(char c) { // increases counters
            //TODO
        }

        Node* descend(char c) { // for search only
            if (children[c].first == nullptr) {
                children[c] = { new Node(), 0 };
            }
            return children[c].first;
        }

        ~Node() {
            for (auto [c, node] : children) {
                delete node.first;
            }
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
        cur->collisions += 1;
    }

    void add(std::vector<std::string> words) {
        for (const auto& word : words) {
            add(word);
        }
    }

    std::string find_best() const {
        
    }

    std::string process(const std::string& query) {
        position = root;
        current = query;
        for (char c : query) {
            position = position->descend(c);
        }
        if (position->max_subtree > 0) {
            return std::move(find_best());
        }
        return "No collisions found";
    }

    std::string update(const std::string& suffix) {
        current += suffix;
        for (char c : suffix) {
            position = position->descend(c);
        }
        if (position->max_subtree > 0) {
            return std::move(find_best());
        }
        return "No collisions found";
    }

    ~Tree() {
        delete root;
    }
};
