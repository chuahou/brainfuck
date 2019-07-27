/**
 * @file main.cpp
 * @brief Main entry point of interpreter
 */

#include <cstdio>
#include <string>
#include <brainfuck.hpp>

using namespace chbrainfuck;

/**
 * @brief Interprets a provided whole brainfuck program
 * 
 * @param len length of program
 * @param program program as char array
 * @param tsize size of tape
 * @param zero_at_127 whether to set zero at 127
 */
void interpret(int len, char *program, int tsize, bool zero_at_127)
{
    // create new Brainfuck object
    Brainfuck bf(tsize, zero_at_127);

    // iterate through program
    for (int i = 0; i < len; i++)
    {
        switch (program[i])
        {
        case '>':
            bf.increment_ptr();
            break;

        case '<':
            bf.decrement_ptr();
            break;

        case '+':
            bf.increment_cell();
            break;

        case '-':
            bf.decrement_cell();
            break;

        case '.':
            printf("%c", bf.get_cell());
            break;

        case ',':
            char c;
            scanf("%c", &c);
            bf.set_cell(c);
            break;

        case '[':
            if (bf.is_zero()) // jump to next ]
            {
                while (program[i] != ']')
                {
                    i++;
                }
                i++; // go past ]
            }
            break;

        case ']':
            if (!bf.is_zero()) // jump to prev [
            {
                int rightb_count = 1; // ]s encountered - [s encountered
                while (rightb_count > 0)
                {
                    i--;
                    switch (program[i])
                    {
                    case '[':
                        rightb_count--;
                        break;
                    case ']':
                        rightb_count++;
                        break;
                    }
                }
            }
            break;

        default:
            break;
        }
    }
}

int main(int argc, char** argv)
{
    std::string helloworld =
        "++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.";

    // make char * :(
    char* helloworld_cstr = new char[helloworld.size()];
    std::copy(helloworld.begin(), helloworld.end(), helloworld_cstr);

    interpret(helloworld.size() - 1, helloworld_cstr, 30000, false);

    // free char * :(
    delete[] helloworld_cstr;

    return 0;
}
