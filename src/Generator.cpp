#include "../include/Generator.hpp"

void generate() {
    std::fstream output("output.asm", std::ios::out);
    if (!output.is_open()) {
        std::cerr << "Failed to create .asm. Aborting\n";
        return;
    }
    output << "global _start";
    output.close();
}