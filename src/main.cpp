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
    std::string helloworld =
        "++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.";

    CppStringProgram csp(helloworld);
    Brainfuck bf;

    csp.interpret(bf);

    return 0;
}
