////NAME: postfix.cpp
//DESC: postfix driver file
//COMPILER: GNU g++ compiler on Linux
//AUTHOR: Bri Schmidt
//LAST UPDATED: October 1, 2018

#include <iostream>

#if LAB6_TEST1
#   include "../src/StackLinked.cpp"
#else
#   include "../src/StackArray.cpp"
#endif
//------------------------------------------------------
//    prototype
    double postfixConverter (const string &expression);
//    end prototype
//------------------------------------------------------

int main()
{
  string inputLine;            // Input line
  char   ch;                   // Holding pen for input chars

  cout << "This program performs calculations using postfix notation."
       << endl;

  double result;
  while( cin )
  {
      cout << "Enter expression (<EOF> to quit) : "
           << endl;
           //trigger EOF through ctrl-D
      // Read in one line
      inputLine = "";
      cin.get(ch);
      while( cin && ch != '\n' )
      {
          inputLine = inputLine + ch;
          cin.get(ch);
      }

      if( ! cin )              // Reached EOF: stop processing
          break;

      result = postfixConverter (inputLine);
      cout << result << endl;
  }

  return 0;
}

double postfixConverter (const string &expression)
{
  #if !LAB6_TEST1
      StackArray<double> operandStack;
  #else
      StackLinked<double> operandStack;
  #endif

  double result;
  int characterCount = expression.length();
  int index = 0;
  char nextCharacter = ' ';
  int operand1;
  int operand2;
  double divoperand1;
  double divoperand2;

  while(index < characterCount)
  {
    char nextCharacter = expression.at(index);
    switch (nextCharacter)
    {
      case '0'...'9':
        operand1 = nextCharacter - '0';
        operandStack.push(operand1);
        break;
      case '+':
        operand1 = operandStack.pop();
        operand2 = operandStack.pop();
        result = operand1+operand2;
        operandStack.push(result);
        break;
      case '-':
        operand1 = operandStack.pop();
        operand2 = operandStack.pop();
        result = operand2-operand1;
        operandStack.push(result);
        break;
      case '*':
        operand1 = operandStack.pop();
        operand2 = operandStack.pop();
        result = operand1*operand2;
        operandStack.push(result);
        break;
      case '/':
        divoperand1 = operandStack.pop();
        divoperand2 = operandStack.pop();
        result = divoperand2/divoperand1;
        operandStack.push(result);
        break;
      default:
        cout << "improper character encountered, please try again" << endl;
        break;
    }
    index++;
  }
  result = operandStack.pop();
  if(!operandStack.isEmpty())
  {
    cout << "Stack is not empty, something is wrong with expression!" << endl;
    return 0;
  }
  return result;
}
