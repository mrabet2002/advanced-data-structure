#include <iostream>
#include "ArrayStack/ArrayStack.h"
#include "LinkedListStack/LinkedListStack.h"

using namespace std;

double calculate(double val1, double val2, char op)
{
    switch (op)
    {
    case '+':
        return val1 + val2;
    case '*':
        return val1 * val2;
    case '-':
        return val1 - val2;
    case '/':
        return val1 / val2;
    }
    throw "Invalid operation exception!!";
}

double getNumberFromExpression(string expression, int *firstDigitIndex)
{
    double result = expression[(*firstDigitIndex)++] - '0', exponent = 10;
    while (isdigit(expression[*firstDigitIndex]) || expression[*firstDigitIndex] == '.')
    {
        if (expression[(*firstDigitIndex)] == '.')
        {
            (*firstDigitIndex)++;
            while (isdigit(expression[*firstDigitIndex]))
            {
                result += (expression[(*firstDigitIndex)++] - '0') * (1. / exponent);
                exponent *= 10;
            }
            break;
        }
        result += (expression[(*firstDigitIndex)++] - '0') * exponent;
    }
    (*firstDigitIndex)--;
    return result;
}

double calculateBracketedExpression(string expression)
{
    Stack<double> *operands = new LinkedListStack<double>();
    Stack<char> *operators = new LinkedListStack<char>();
    try
    {
        for (int i = 0; i < expression.size(); i++)
        {
            char op;
            switch (expression[i])
            {
            case '(':
                operators->push('(');
                break;
            case ')':
                while ((op = operators->pop()) != '(')
                    operands->push(
                        calculate(operands->pop(), operands->pop(), op));
                break;
            case '+':
            case '*':
            case '-':
            case '/':
                operators->push(expression[i]);
                break;
            default:
                operands->push(
                    getNumberFromExpression(expression, &i));
            }
        }
    }
    catch (PopOnEmptyStackException &e)
    {
        std::cerr << e.what() << '\n';
    }
    return operands->peek();
}

int main(int argc, char const *argv[])
{

    string exp = "((((55.2+5.35+33)+22)-(1-4*6.315))";
    cout << calculateBracketedExpression(exp) << endl;
    return 0;
}