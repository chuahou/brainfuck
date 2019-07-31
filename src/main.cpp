/**
 * @file main.cpp
 * @brief Main entry point of interpreter
 */

#include <cstdio>
#include <string>
#include <brainfuck.hpp>
#include <program.hpp>

using namespace chbrainfuck;

int main(int argc, char** argv)
{
    std::string program;
    const char* filename = "rdebath_brainfucktest.b";

    // read program
    FILE* fp = fopen(filename, "r");
    int c;
    do
    {
        c = fgetc(fp);
        switch (c)
        {
        case '>':
        case '<':
        case '+':
        case '-':
        case '.':
        case ',':
        case '[':
        case ']':
            program += (char)c;
            break;
        }
    } while (c != EOF);

    fclose(fp); 

    CppStringProgram csp(program);
    Brainfuck bf;

    csp.interpret(bf);

    return 0;
}
