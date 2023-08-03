#ifndef RPN_HPP
#define RPN_HPP
#include <stack>
#include <iostream>

void    add(int a, int b, std::stack<int> *stack);
void    rev(std::stack<int>& stack);
void    insertBottom(std::stack<int>& stack, int x);
void    minus(int a, int b, std::stack<int> *stack);
void    mult(int a, int b, std::stack<int> *stack);
void    div(int a, int b, std::stack<int> *stack);
#endif