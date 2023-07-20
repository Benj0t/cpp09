#include <cctype>

int areDigit(char *str)
{
    for (int i = 0; str[i]; i++)
        if(!std::isdigit(str[i]))
            return (0);
    return 1; 
}