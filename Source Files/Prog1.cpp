//----------------------------------------------------------------------
// Name:          Devon Lee
//
// Course:        CS 2630, Section 01, Fall 2021
//
// Purpose:       This program reads a given number of RPN
//                (reverse-Polish-notation expressions and calculates
//                the final and intermediate answers. It then prints
//                this information (or an error message if the
//                expression is invalid) after each expression is read.
//
// Input:         An integer representing the number of RPN expressions
//			      to be evaluated followed by the expressions
//                themselves, each on its own line. Each expression is
//                to be terminated by the pound sign (#). All input
//                comes fron a single .in file.            
//
// Output:        An echo of each expression with an unique expression
//                number, the final answer to the expression or a
//                message indicating the invalidty of the expression,
//                and the intermediate answers (if applicable)
//                calculated while reading the expression.
// 
// Project Files: Prog1.cpp, RPNEval.h, RPNEval.cpp, MyStack.h,
//                MyStack.cpp, MyQueue.h, MyQueue.cpp, ItemType.h
//----------------------------------------------------------------------

#include <iostream>
#include "RPNEval.h"

using namespace std;  // For `cin` and `cout`

int main()
{
    // Number of expressions to be read from the input file
    int numExpressions;
    cin >> numExpressions;
    
    // One-indexed so printing `i` makes sense for colloquial counting
    for(int i = 1; i <= numExpressions; i++)
    {
        RPNEval RPN;
        cout << "Expression " << i << ":" << endl;
        RPN.ProcessExpression();
        
        // Used instead of a get method so that no garbage will be printed
        RPN.PrintAnswer();
        cout << "The Intermediate Results are: ";
        RPN.PrintIntermediateResults();
        cout << endl << endl;
    }
    
    cout << "Normal Termination of Program 1!" << endl;
    return 0;
}
