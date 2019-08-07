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
            if (!scanf("%c", &c)) exit(-1);
            bf.set_cell(c);
            break;

        case '[':
            if (bf.is_zero()) // jump to next ]
            {
                int leftb_count = 1; // [s encountered - ]s encountered
                while (leftb_count > 0)
                {
                    next_char();
                    switch(get_char())
                    {
                    case '[':
                        leftb_count++;
                        break;
                    case ']':
                        leftb_count--;
                        break;
                    }
                }
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
