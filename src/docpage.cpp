/**
 * @mainpage
 * @section Introduction
 * 
 * Another one. Yep. Another one. For more, go to
 * https://github.com/chuahou/brainfuck.
 * 
 * @section Details
 * 
 * Cells are 8-bit chars. Hence, the value varies between [0, 255] and not
 * [-127, 128], and overflow is left to the user to handle.
 * 
 * [ and ] can be set to compare to 127 instead of 0 to emulate the behaviour
 * of implementation with cell range [0, 255]. See
 * chbrainfuck::Brainfuck::zero_at_127.
 */
