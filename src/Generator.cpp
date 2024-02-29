#include "../include/Generator.hpp"

void generate_asm() {
    std::fstream output("output.asm", std::ios::out);
    if (!output.is_open()) {
        std::cerr << "Failed to create .asm. Aborting\n";
        return;
    }
    output << "global _start\n";
    output << "_start:\n";
    output.close();
}

void generate_exit() {
    std::fstream output("output.asm", std::ios::app);
    if (!output.is_open()) {
        std::cerr << "Failed to open output.asm. Aborting\n";
        return;
    }
    output << "\tmov rax, 60\n";
    output << "\tmov rdi, 0\n"; //Will change based on what the user set the return value.
    output << "\tsyscall";
}