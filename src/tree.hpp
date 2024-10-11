#pragma once

#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>

class Tree {
  private:
    struct Node {
        std::map<char, std::pair<Node*, int>> children;
        std::set<std::pair<int, char>> best; // tree-based versions are faster on such sizes
        int collisions = 0; // how many repetition has this exact word
        int max_subtree = 0; // maximum repetitions of words that start with this prefix

        std::pair<Node*, char> most_popular() {
            if (collisions == max_subtree) return std::make_pair(this, '\0');
            auto [cnt, c] = *best.begin();
            return std::make_pair(children[c].first, c);
        }

        Node* descend(char c) { // does not change counters
            if (children[c].first == nullptr) {
                children[c] = { new Node(), 0 };
            }
            return children[c].first;
        }

        void update(char c, int old_cnt, int new_cnt) {
            best.erase(std::make_pair(-old_cnt, c)); // max number, least character
            best.insert(std::make_pair(-new_cnt, c));
            children[c].second = new_cnt;
            max_subtree = std::max(max_subtree, new_cnt);
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

    std::string find_best() const {
        std::string answer = current;
        auto best = position;
        auto next = best->most_popular();
        while (best != next.first) {
            best = next.first;
            answer += next.second;
            next = best->most_popular();
        }
        return answer;
    }

  public:
    Tree() = default;

    Tree(const Tree&) = delete;
    Tree(Tree&&) = default;

    Tree& operator=(const Tree&) = delete;
    Tree& operator=(Tree&&) = default;

    void add(const std::string& word) { // change counters
        if (root == nullptr) {
            root = new Node();
        }
        Node* cur = root;
        std::vector<Node*> path;
        path.reserve(word.size());
        for (char c : word) {
            path.push_back(cur);
            cur = cur->descend(c);
        }
        cur->collisions += 1;
        cur->max_subtree = std::max(cur->max_subtree, cur->collisions);
        for (int i = word.size() - 1; i + 1 > 0; --i) {
            char c = word[i];
            Node* from = path[i];
            auto [next, cur_cnt] = from->children[c];
            if (next->max_subtree > cur_cnt) {
                from->update(c, cur_cnt, next->max_subtree);
            }
        }
    }

    void add(std::vector<std::string> words) {
        for (const auto& word : words) {
            add(word);
        }
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
