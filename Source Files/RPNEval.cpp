#include "RPNEval.h"

//----------------------------------------------------------------------
// RPNEval constructor; initializes `isValid` to false.
//----------------------------------------------------------------------
RPNEval::RPNEval()
{
    isValid = false;
}


//----------------------------------------------------------------------
// Returns whether or not the expression is valid based on the value of
// `isValid`.
// 
// @return True if the expression is valid or false otherwise
//----------------------------------------------------------------------
bool RPNEval::IsValid()
{
    return isValid;
}

//----------------------------------------------------------------------
// Returns `answer`, the final answer to an expression. WARNING: Will
// contain garbage if a final answer has not yet been determined and/or
// the expression is invalid.
// 
// @return The answer to the expression
//----------------------------------------------------------------------
ItemType RPNEval::getAnswer()
{
    return answer;
}


//----------------------------------------------------------------------
// This is the starting method for using this class. It reads an
// expression from the input stream character by character until it
// encounters a "#", echos the input, and calls an appropriate methods
// to handle the various types of input. Following the pound sign, up to
// 256 characters or the newline character (\n) (whichever comes first)
// are ignored. The final answer to a valid expression is saved in the
// attribute `answer`.
//----------------------------------------------------------------------
void RPNEval::ProcessExpression()
{
    isValid = true;  // True until proven false by various conditions
    char input;
    bool inputCompleted = false;  // Read until "#" encountered
    
    while (isValid && !inputCompleted)
    {
        cin >> input;
        
        if (IsDigit(input))
        {
            cin.putback(input);
            ProcessOperand();  // Number will be read as one unit here
        }
        else if (IsOperator(input))
        {
            cout << input << " ";
            ProcessOperator(input);
        }
        else if (input == END_OF_LINE_SIGNAL)
        {
            inputCompleted = true;
        }
        else  // Foreign character
        {
            cout << input << " ";
            isValid = false;
        }
    }
    
    // Ignores the rest of the line
    cin.ignore(NUM_CHARACTERS_IGNORED_AFTER_EXPRESSION, '\n');
    cout << endl;  // Start new line after echoing input
    
    // One final answer should remain in the stack if the expression is valid
    if (operands.GetSize() == 1)
        answer = operands.Pop();
    else
        isValid = false;
}

//----------------------------------------------------------------------
// Determines if `toEvaluate` is a digit by comparing its value to the
// ASCII codes for 0-9.
// 
// @param toEvaluate The character to determine status as a digit
// @return True if the character is a digit or false otherwise
//----------------------------------------------------------------------
bool RPNEval::IsDigit(const char toEvaluate)
{
    return (toEvaluate >= ASCII_0 && toEvaluate <= ASCII_9);
}

//----------------------------------------------------------------------
// Reads an operand from the input stream and echos that operand
// followed by a space. This method then pushes the operand to the stack
// if the stack is not full. If the stack is full, an error message gets
// printed.
//----------------------------------------------------------------------
void RPNEval::ProcessOperand()
{
    ItemType operand;
    cin >> operand;
    cout << operand << " ";
    
    try
    {
        operands.Push(operand);
    }
    catch(FullStack exceptionObject)
    {
        cout << "ERROR: Not enough room in memory to store operand."
             << endl;
    }
}

//----------------------------------------------------------------------
// Determines if the given character is an operator (+, -, *, or /) by
// comparing it to constants representing the characters the signs of
// each of the four basic mathematical operators.
// 
// @param toEvaluate The character to determine status as an operator
// @return True if the character is an operator or false otherwise
//----------------------------------------------------------------------
bool RPNEval::IsOperator(const char toEvaluate)
{
    if (toEvaluate == PLUS_SIGN || toEvaluate == MINUS_SIGN ||
        toEvaluate == MULT_SIGN || toEvaluate == DIV_SIGN)
        return true;
    return false;
}

//----------------------------------------------------------------------
// Applies one operator to two operands and puts the answer in the stack
// and the queue, all if safe to do so. This method catches any
// `EmptyStack`, `FullStack` or `FullQueue` exceptions and also checks
// for division by zero.
// 
// @param operator_ The operator corresponding to the operation to be
//                  performed
//----------------------------------------------------------------------
void RPNEval::ProcessOperator(const char operator_)
{
    ItemType firstOperand, secondOperand, intermediateAnswer;
   
    try
    {
        secondOperand = operands.Pop();
        firstOperand = operands.Pop();
        
        if (secondOperand != 0)
        {
            intermediateAnswer = PerformOperation(firstOperand, secondOperand,
                                                  operator_);
            try
            {
                operands.Push(intermediateAnswer);
                intrmedteAns.Enqueue(intermediateAnswer);
            }
            catch (FullStack exceptionObject)
            {
                cout << "ERROR: The stack became inexplicably full." << endl;
            }
            catch (FullQueue exceptionObject)
            {
                cout << "ERROR: Not enough room in memory to store "
                     << "intermedate answer." << endl;
            }
        }
        else
            isValid = false;
    }
    catch (EmptyStack exceptionObject)
    {
       isValid = false;
       //cout << "ERROR: Too few operands to perform operation." << endl;
    }
}

//----------------------------------------------------------------------
// Evaluates `firstOperand` `operator_` `secondOperand` and returns the
// result. WARNING: Division by zero is not checked. Returns -1 if an
// invalid operator is detected.
// 
// @param firstOperand The first operand in the mathematical expression
// @param secondOperand The second operand in the mathematical
//                      expression
// @param firstOperand The operator of the mathematical expression
// @return The result of the calculation or -1 if the operation failed
//----------------------------------------------------------------------
ItemType RPNEval::PerformOperation(const ItemType firstOperand,
                                   const ItemType secondOperand,
                                   const char operator_)
{
    switch (operator_)
    {
    case PLUS_SIGN:
        return (firstOperand + secondOperand);
    case MINUS_SIGN:
        return (firstOperand - secondOperand);
    case MULT_SIGN:
        return (firstOperand * secondOperand);
    case DIV_SIGN:
        return (firstOperand / secondOperand);
    default:
        isValid = false;
        cout << "ERROR: Invalid operator." << endl;
        return -1;
    }
}


//----------------------------------------------------------------------
// Prints `answer` if the processed expression is valid or an
// alternative message if it is not.
//----------------------------------------------------------------------
void RPNEval::PrintAnswer()
{
    if (isValid)
        cout << "The value is: " << answer << endl;
    else
        cout << "Invalid Expression" << endl;
    
}

//----------------------------------------------------------------------
// Prints each member of `intrmedteAns` in order, each followed by a
// space.
//----------------------------------------------------------------------
void RPNEval::PrintIntermediateResults()
{
    int numAnswers = intrmedteAns.GetSize();
    for (int i = 0; i < numAnswers; i++)
    {
        try
        {
            ItemType toPrint = intrmedteAns.Dequeue();
            cout << toPrint << " ";
        }
        catch(EmptyQueue exceptionObject)
        {
            cout << "ERROR: Too few intermediate answers to perform operation."
                 << endl;
        }
    }
}
