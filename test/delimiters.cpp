//--------------------------------------------------------------------
//
//   delimiters.cpp
//
//--------------------------------------------------------------------

#include <iostream>

#if LAB6_TEST1
#   include "../src/StackLinked.cpp"
#else
#   include "../src/StackArray.cpp"
#endif

//--------------------------------------------------------------------

bool delimitersOk ( const string &expression );

//--------------------------------------------------------------------

int main()
{
    string inputLine;            // Input line
    char   ch;                   // Holding pen for input chars

    cout << "This program checks for properly matched delimiters."
         << endl;

    while( cin )
    {
        cout << "Enter delimited expression (<EOF> to quit) : "
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

        if ( delimitersOk (inputLine) )
            cout << "Valid" << endl;
        else
            cout << "Invalid" << endl;
    }

    return 0;
}

//--------------------------------------------------------------------
// delimitersOk: the function that students must implement for
//    Programming Exercise 3.
// Note: we used the term "braces" to describe '[' and ']'. It would
//    have been better to use the term "brackets". The program can be
//    easily modified to process any set of matching delimiters.
//--------------------------------------------------------------------

// delimitersOk function
//precondition: gets passed the expression
//postcondition: returns whether delimieters are matched

bool delimitersOk ( const string &expression )
{
  #if !LAB6_TEST1
//      cout << "Testing array implementation" << endl;
      StackArray<char> delimiterStack;
  #else
//      cout << "Testing linked implementation" << endl;
      StackLinked<char> delimiterStack;
  #endif

  int characterCount = expression.length();
  bool isBalanced = true;
  int index = 0;
  char nextCharacter = ' ';

  while(isBalanced && (index < characterCount))
  {

    nextCharacter = expression.at(index);
    switch(nextCharacter)
    {

      case '(': case '[': case '{':
        delimiterStack.push(nextCharacter);
        break;
      case ')': case ']': case '}':
        if(delimiterStack.isEmpty())
        {
          isBalanced = false;
        }
        else
        {
            char openDelimiter = delimiterStack.peek();
            delimiterStack.pop();
            if(((openDelimiter == '(') && (nextCharacter == ')')) || ((openDelimiter == '[') && (nextCharacter == ']')) || ((openDelimiter == '{') && (nextCharacter == '}')))
            {
              isBalanced = true;
            }
            else
            {
              isBalanced = false;
            }
        }
        break;
      default:
        break;
    }
    index++;
  }
  if(!(delimiterStack.isEmpty()))
    isBalanced = false;
  return isBalanced;
}
