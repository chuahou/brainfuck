/**
 * @file program.hpp
 * @brief Contains the declaration of the Program class and its children, which
 * represent a brainfuck program reader and its various representations
 */

#ifndef __PROGRAM_HPP_INCLUDED__
#define __PROGRAM_HPP_INCLUDED__

#include <string>
#include "brainfuck.hpp"

namespace chbrainfuck
{

    /**
     * @brief The Program class contains an abstract representation of a
     * brainfuck program reader
     * 
     * It is to be inherited and implemented for different representations,
     * such as a single string or a file.
     */
    class Program
    {

    protected:

        /* abstract methods */

        /**
         * @brief Get the current character of the program
         * 
         * @return char the current character
         */
        virtual char get_char() = 0;

        /**
         * @brief Move to the next program character
         */
        virtual void next_char() = 0;

        /**
         * @brief Move to the previous program character
         */
        virtual void prev_char() = 0;

        /**
         * @brief Checks if we have passed the end of the program
         * 
         * @return true past last character
         * @return false not at end of program
         */
        virtual bool eof() = 0;

    public:

        /**
         * @brief Interprets the program
         * 
         * This generic method utilises the virtual methods to read and run the
         * program.
         * 
         * @param bf the brainfuck object to interpret on
         */
        void interpret(Brainfuck &bf);

    };

    /**
     * @brief Implementation of Program using a C++ std::string.
     */
    class CppStringProgram : public Program
    {

        /**
         * @brief The std::string program
         */
        std::string program;

        /**
         * @brief Current index to program
         */
        int index;

    protected:

        // implemented virtual functions
        char get_char();
        void next_char();
        void prev_char();
        bool eof();

    public:

        /**
         * @brief Construct a new CppStringProgram object
         * 
         * @param program the std::string program
         */
        CppStringProgram(std::string program) : program(program) {}

    };

}

#endif
