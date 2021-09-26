#ifndef RPN_Eval_H_
#define RPN_Eval_H_

#include <iostream>
#include "ItemType.h"
#include "MyStack.h"
#include "MyQueue.h"

using namespace std;

//----------------------------------------------------------------------
// This class reads and processes an expression in Reverse Polish
// Notation (RPN). It calculates both an final answer and a list of
// immediate answers depending on the expression. If the expression is
// deemed invalid at any point in the process, the `answer` attribute
// will not be initialized, and if no calculations can be completed at
// all, no intermediate answers will exist. This evaluator will catch
// invalid expressions that contain foreign characters, blank lines,
// and/or too many operators or operands, but every expression must be
// terminated with the pound sign (#). It is reccommended to use
// `PrintAnswer()` rather than `GetAnswer()` because the latter may
// return garbage, but the former will check expression validity and
// print out text instead of an answer if the expression is invalid.
//----------------------------------------------------------------------
class RPNEval
{
private:
    // Constants for non-numeric input symbols
    static const char PLUS_SIGN = '+';
    static const char MINUS_SIGN = '-';
    static const char MULT_SIGN = '*';
    static const char DIV_SIGN = '/';
    static const char END_OF_LINE_SIGNAL = '#';

    // Constants for input parameters
    static const int ASCII_0 = 48;
    static const int ASCII_9 = 57;
    static const int NUM_CHARACTERS_IGNORED_AFTER_EXPRESSION = 256;

    bool isValid;
    ItemType answer;  // The final answer to the expression, if it exists
    MyStack operands;  // Holds all operands encountered during processing
    MyQueue intrmedteAns;  // Holds answers calculated during processing

    //------------------------------------------------------------------
    // Determines if `toEvaluate` is a digit (0-9).
    // 
    // @param toEvaluate The character to determine status as a digit
    // @return True if the character is a digit or false otherwise
    //------------------------------------------------------------------
    bool IsDigit(const char toEvaluate);

    //------------------------------------------------------------------
    // Reads an operand from the input stream, echos that operand
    // followed by a space, and stores the newly-read variable.
    //------------------------------------------------------------------
    void ProcessOperand();

    //------------------------------------------------------------------
    // Determines if the given character is an operator (+, -, *, or /).
    // 
    // @param toEvaluate The character to determine status as an
    //                   operator
    // @return True if the character is an operator or false otherwise
    //------------------------------------------------------------------
    bool IsOperator(const char toEvaluate);

    //------------------------------------------------------------------
    // Applies one operator to two operands and handles the answer. This
    // method checks for division by zero and invalidates the expression
    // if it encounters it.
    // 
    // @param operator_ The operator corresponding to the operation to
    //                  be performed
    //------------------------------------------------------------------
    void ProcessOperator(const char operator_);

    //------------------------------------------------------------------
    // Evaluates `firstOperand` `operator_` `secondOperand` and returns
    // the result. WARNING: Division by zero is not checked. Returns -1
    // if an invalid operator is detected.
    // 
    // @param firstOperand The first operand in the mathematical
    //                     expression
    // @param secondOperand The second operand in the mathematical
    //                      expression
    // @param firstOperand The operator of the mathematical expression
    // @return The result of the calculation or -1 if the operation
    //         failed
    //------------------------------------------------------------------
    ItemType PerformOperation(const ItemType firstOperand,
                              const ItemType secondOperand,
                              const char operator_);

public:
    //------------------------------------------------------------------
    // RPNEval constructor; initializes an evaluator flagged as invalid.
    //------------------------------------------------------------------
    RPNEval();

    //------------------------------------------------------------------
    // Returns whether or not the expression is valid.
    // 
    // @return True if the expression is valid or false otherwise
    //------------------------------------------------------------------
    bool IsValid();

    //------------------------------------------------------------------
    // Returns the final answer to an expression. WARNING: May contain
    // garbage if a final answer has not yet been determined or the
    // expression is invalid.
    // 
    // @return The answer to the expression
    //------------------------------------------------------------------
    ItemType getAnswer();

    //------------------------------------------------------------------
    // This is the starting method for using this class. It reads an
    // expression from the input stream, echos the input, and determines
    // a final answer as well as a series of intermediate answers. The
    // expression should be contained entirely on one line with each
    // operator and operand separated by a space. The pound sign (#)
    // should terminate every expression.
    //------------------------------------------------------------------
    void ProcessExpression();

    //------------------------------------------------------------------
    // Prints the answer to the processed expression if it is valid or a
    // message if it is not.
    //------------------------------------------------------------------
    void PrintAnswer();

    //------------------------------------------------------------------
    // Prints all of the intermediate results (each time two operands
    // were combined) calculated during the processing of an expression,
    // each followed by a space.
    //------------------------------------------------------------------
    void PrintIntermediateResults();
};

#endif
