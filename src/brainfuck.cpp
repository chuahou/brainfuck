/**
 * @file brainfuck.cpp
 * @brief Implements the Brainfuck class
 */

#include <limits>
#include <stdexcept>

#include <brainfuck.hpp>

using namespace chbrainfuck;

// constructors and destructors

Brainfuck::Brainfuck() : tape_size(DEFAULT_TAPE_SIZE), tape_ptr(tape_size / 2),
    zero_at_127(false)
{
    tape = new char[tape_size];
    zero_all_cells();
}

Brainfuck::Brainfuck(int size) : zero_at_127(false)
{
    if (size <= 0)
        throw std::invalid_argument("Invalid size");
    tape_size = size;
    tape_ptr = tape_size / 2;
    tape = new char[tape_size];
    zero_all_cells();
}

Brainfuck::Brainfuck(int size, bool zero_at_127) : zero_at_127(zero_at_127)
{
    if (size <= 0)
        throw std::invalid_argument("Invalid size");
    tape_size = size;
    tape_ptr = tape_size / 2;
    tape = new char[tape_size];
    zero_all_cells();
}

Brainfuck::Brainfuck(const Brainfuck& other) : tape_size(other.tape_size),
    tape_ptr(other.tape_ptr), zero_at_127 (other.zero_at_127)
{
    tape = new char[tape_size];
    for (int i = 0; i < tape_size; i++)
    {
        tape[i] = other.tape[i];
    }
}

Brainfuck& Brainfuck::operator=(Brainfuck& rhs)
{
    tape_size = rhs.tape_size;
    tape_ptr = rhs.tape_ptr;
    zero_at_127 = rhs.zero_at_127;
    tape = new char[tape_size];
    for (int i = 0; i < tape_size; i++)
    {
        tape[i] = rhs.tape[i];
    }

    return *this;
}

Brainfuck::~Brainfuck()
{
    delete[] tape;
}

// brainfuck operations

bool Brainfuck::increment_ptr()
{
    // increment pointer
    tape_ptr++;

    // check if exceeded
    if (tape_ptr >= tape_size)
    {
        tape_ptr = tape_size - 1;
        return false;
    }

    return true;
}

bool Brainfuck::decrement_ptr()
{
    // decrement pointer
    tape_ptr--;

    // check if exceeded
    if (tape_ptr < 0)
    {
        tape_ptr = 0;
        return false;
    }

    return true;
}

void Brainfuck::increment_cell()
{
    if (!check_ptr_valid())
        throw std::out_of_range("Invalid tape pointer");
    tape[tape_ptr]++;
}

void Brainfuck::decrement_cell()
{
    if (!check_ptr_valid())
        throw std::out_of_range("Invalid tape pointer");
    tape[tape_ptr]--;
}

char Brainfuck::get_cell()
{
    if (!check_ptr_valid())
        throw std::out_of_range("Invalid tape pointer");
    return tape[tape_ptr];
}

void Brainfuck::set_cell(char value)
{
    if (!check_ptr_valid())
        throw std::out_of_range("Invalid tape pointer");
    tape[tape_ptr] = value;
}

bool Brainfuck::is_zero()
{
    return (tape[tape_ptr] == (zero_at_127) ? 127 : 0);
}

// helper functions

bool Brainfuck::check_ptr_valid()
{
    return (tape_ptr >= 0 && tape_ptr < tape_size);
}

void Brainfuck::zero_all_cells()
{
    int zero = (zero_at_127) ? 127 : 0;
    for (int i = 0; i < tape_size; i++)
    {
        tape[i] = zero;
    }
}
