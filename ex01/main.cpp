#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "The program only takes two arguments.";
        return (0);
    }
    std::string s = argv[1];

    int i;
    i = 0;
    std::stack<int> stack;
    while (s[i])
    {
        if (isdigit(s[i]))
            stack.push(s[i] - '0');
        else
        {
            if (s[i] == '+')
            {
				if (stack.size() >= 2)
                {
                    int a = stack.top();
				    stack.pop();
				    int b = stack.top();
				    stack.pop();
				    add(a, b, &stack);
                }
                else 
                {
                    std::cout << "Error";
                    return (1);
                }
            }
            else if (s[i] == '*')
            {
				if (stack.size() >= 2)
                {
                    int a = stack.top();
				    stack.pop();
				    int b = stack.top();
				    stack.pop();
				    mult(a, b, &stack);
                }
                else 
                {
                    std::cout << "Error";
                    return (1);
                }            
            }
            else if (s[i] == '/')
            {
				if (stack.size() >= 2)
                {
                    int a = stack.top();
				    stack.pop();
				    int b = stack.top();
				    stack.pop();
                    if (a == 0) // Protection for division by 0
                    {
                        std::cout << "Error: bad formatting" << std::endl;
                        return (1);
                    }
				    div(a, b, &stack);
                }
                else 
                {
                    std::cout << "Error";
                    return (1);
                }            
            }
            else if (s[i] == '-')
            {
				if (stack.size() >= 2)
                {
                    int a = stack.top();
				    stack.pop();
				    int b = stack.top();
				    stack.pop();
				    minus(a, b, &stack);
                }
                else 
                {
                    std::cout << "Error: bad formatting";
                    return (1);
                }
            }
            else if ( s[i] == ' ')
            {
                //just skip
            }
            else
            {
                std::cout << "Error\n";
                return (1);
            }
        }
        i++;
    }

    rev(stack);

    while (!stack.empty())
    {
        std::cout << stack.top() << " ";
        stack.pop();
    }
    std::cout << "\n";
    return (0);
}