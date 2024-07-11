#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN &other)
{
    *this = other;
}

RPN &RPN::operator=(const RPN &other)
{
    (void)other;
    return *this;
}

RPN::~RPN()
{
}

std::string RPN::itoa(int num)
{
    std::stringstream ss;
    ss << num;
    std::string str = ss.str();
    return str;
}

void RPN::RevPolish(std::string calc)
{
    std::stack<std::string> stack;
    std::istringstream iss(calc);
    std::string token;

    while (iss >> token)
    {
        if (std::isdigit(token[0]))
            stack.push(token);
        else
        {
            if (stack.size() <= 1)
            {
                std::cerr << "Error" << std::endl;
                return ;
            }
            int a = atoi(stack.top().c_str());
            stack.pop();
            int b = atoi(stack.top().c_str());
            stack.pop();
            switch (token[0])
            {
                case '+':
                    stack.push(itoa(b + a));
                    break;
                case '-':
                    stack.push(itoa(b - a));
                    break;
                case '/':
                    stack.push(itoa(b / a));
                    break;
                case '*':
                    stack.push(itoa(b * a));   
                    break;
                default:
                    break;
            }
        }
    }
    std::cout << atoi(stack.top().c_str()) << std::endl;
}