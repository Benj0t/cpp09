#include "RPN.hpp"

void insertBottom(std::stack<int>& stack, int x)
{
    if (!(stack.size()))
    {
        stack.push(x);
        return;
    }
    int a = stack.top();
    stack.pop();
    insertBottom(stack, x);
    stack.push(a);
}

void rev(std::stack<int>& stack)
{
    if (stack.size() > 0) 
    {
        int x = stack.top();
        stack.pop();
        rev(stack);
        insertBottom(stack, x);
    }
}

void    add(int a, int b, std::stack<int> *stack)
{
    int c = b + a;
    stack->push(c);
}

void    minus(int a, int b, std::stack<int> *stack)
{
    int c = b - a;
    stack->push(c);
}
void    mult(int a, int b, std::stack<int> *stack)
{
    int c = b * a;
    stack->push(c);
}
void    div(int a, int b, std::stack<int> *stack)
{
    int c = b / a;
    stack->push(c);
}