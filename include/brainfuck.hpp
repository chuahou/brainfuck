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
         * Each element is represented as a char, and the length of the tape is
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
         * It is initially set to half of the array size.
         */
        int tape_ptr;

        /**
         * @brief Whether to operate with 0 at 0 or 0 at 127
         * 
         * Operating with 0 at 127 means that cells are initialized at 127, and
         * comparison operators [ and ] compare to 127 instead of 0. This is
         * done to emulate behaviour of interpreters having cells with range
         * [-127, 128].
         */
        bool zero_at_127;

        /**
         * @brief Checks if the tape pointer is in range
         * 
         * @return true tape pointer is in range
         * @return false tape pointer is out of range
         */
        bool check_ptr_valid();

    public:

        /* constructors and destructor */

        /**
         * @brief Construct a new Brainfuck object
         * 
         * Creates a new Brainfuck object with tape size set to default of
         * chbrainfuck::DEFAULT_TAPE_SIZE and
         * chbrainfuck::Brainfuck::zero_at_127 disabled.
         */
        Brainfuck();

        /**
         * @brief Construct a new Brainfuck object
         * 
         * Creates a new Brainfuck object with the specified tape size and
         * chbrainfuck::Brainfuck::zero_at_127 disabled.
         * 
         * @param size tape size of the Brainfuck object
         */
        Brainfuck(int size);

        /**
         * @brief Construct a new Brainfuck object
         * 
         * Creates a new Brainfuck object with the specified tape size and
         * boolean determining whether of not to enable
         * chbrainfuck::Brainfuck::zero_at_127.
         * 
         * @param size tape size of the Brainfuck objcet
         * @param use_zero_at_127 whether to enable zero_at_127
         */
        Brainfuck(int size, bool use_zero_at_127);

        /**
         * @brief Destroy the Brainfuck object
         */
        ~Brainfuck();

        /* accessors */

        /**
         * @brief Get the tape array
         * 
         * @return char* the tape array
         */
        char* get_tape() { return tape; }

        /**
         * @brief Get the length of the tape array
         * 
         * @return int length of tape array
         */
        int get_tape_size() { return tape_size; }

        /**
         * @brief Get the tape pointer
         * 
         * @return int array index of the tape pointer
         */
        int get_tape_ptr() { return tape_ptr; }

        /* brainfuck operations */

        /**
         * @brief Moves the pointer to the right
         * 
         * @return true op successful
         * @return false op failed
         */
        bool increment_ptr();

        /**
         * @brief Moves the pointer to the left
         * 
         * @return true op successful
         * @return false op failed
         */
        bool decrement_ptr();

        /**
         * @brief Increments the cell pointed at by the pointer
         */
        void increment_cell();

        /**
         * @brief Decrements the cell pointed at by the pointer
         */
        void decrement_cell();

        /**
         * @brief Returns the character in the cell pointed at by the pointer
         */
        char get_cell();

        /**
         * @brief Inputs a character to the cell pointed at by the pointer
         * 
         * @param value character to set the cell to
         */
        void set_cell(char value);

    };

}

#endif
