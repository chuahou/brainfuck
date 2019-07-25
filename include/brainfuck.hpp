/**
 * @file brainfuck.hpp
 * @brief Contains the declaration of the Brainfuck class, which contains the entire
 * brainfuck interpreter state including pointer and tape
 */

#ifndef __BRAINFUCK_HPP_INCLUDED__
#define __BRAINFUCK_HPP_INCLUDED__

/**
 * @brief Main namespace for the brainfuck interpreter
 */
namespace chbrainfuck
{

    /**
     * @brief The default tape size if not specified
     */
    const int DEFAULT_TAPE_SIZE = 1024;

    /**
     * @brief The Brainfuck class contains the entire brainfuck interpreter
     * state, including the pointer and tape
     */
    class Brainfuck
    {
        
        /**
         * @brief An array representing the brainfuck tape
         * 
         * Each element is represented as a char, and the lenght of the tape is
         * specified at runtime.
         */
        char* tape;

        /**
         * @brief Size of the tape
         * 
         * The length of the tape array.
         */
        int tape_size;

        /**
         * @brief Pointer to the position on the tape
         * 
         * The tape pointer is represented by the array index to the tape array.
         */
        int tape_ptr;

    public:

        /**
         * @brief Construct a new Brainfuck object
         * 
         * Creates a new Brainfuck object with tape size set to default of
         * chbrainfuck::DEFAULT_TAPE_SIZE.
         */
        Brainfuck();

        /**
         * @brief Construct a new Brainfuck object
         * 
         * Creates a new Brainfuck object with the specified tape size.
         * 
         * @param size tape size of the Brainfuck object
         */
        Brainfuck(int size);

        /**
         * @brief Destroy the Brainfuck object
         */
        ~Brainfuck(); 

    };

}

#endif
