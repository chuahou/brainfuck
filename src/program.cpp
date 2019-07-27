/**
 * @file program.cpp
 * @brief Implements the Program class
 */

#include <cstdio>
#include <program.hpp>

using namespace chbrainfuck;

void Program::interpret(Brainfuck &bf)
{
    // iterate through program
    while (!eof())
    {
        switch (get_char())
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
                while (get_char() != ']')
                {
                    next_char();
                }
                next_char(); // go past ]
            }
            break;

        case ']':
            if (!bf.is_zero()) // jump to prev [
            {
                int rightb_count = 1; // ]s encountered - [s encountered
                while (rightb_count > 0)
                {
                    prev_char();
                    switch (get_char())
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

        next_char();
    }
}

char CppStringProgram::get_char()
{
    return program[index];
}

void CppStringProgram::next_char()
{
    index++;
}

void CppStringProgram::prev_char()
{
    index--;
}

bool CppStringProgram::eof()
{
    return (index >= program.size());
}
