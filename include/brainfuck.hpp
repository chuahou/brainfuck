/**
 * @file brainfuck.hpp
 *
 * @brief Contains the declaration of the Brainfuck class, which contains the entire
 * brainfuck interpreter state including pointer and tape.
 */

#ifndef __BRAINFUCK_HPP_INCLUDED__
#define __BRAINFUCK_HPP_INCLUDED__

/**
 * @brief Main namespace for the brainfuck interpreter.
 */
namespace chbrainfuck
{

    /**
     * @brief The Brainfuck class contains the entire brainfuck interpreter
     * state, including the pointer and tape.
     */
    class Brainfuck
    {
        // private variables
        
        /**
         * @brief An array representing the brainfuck tape.
         * 
         * Each element is represented as a char, and the lenght of the tape is
         * specified at runtime.
         */
        char* tape;

        /**
         * @brief Size of the tape.
         * 
         * The length of the tape array.
         */
        unsigned long int tape_size;

        /**
         * @brief Pointer to the position on the tape.
         * 
         * The tape pointer is represented by the array index to the tape array.
         */
        unsigned long int tape_ptr;

    };

}

#endif
