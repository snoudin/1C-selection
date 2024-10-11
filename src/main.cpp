#include "tree.hpp"
#include "cli.hpp"

int main() {
    print_help();

    Tree processor;
    process_queries(processor);
}
