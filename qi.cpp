#include <iostream>
#include "qi.h"

int main()
{
    double lhs{0.0}, rhs{0.0};
    char op{'+'};

    bool retFlag;
    int retVal = input(lhs, op, rhs, retFlag);
    if (retFlag)
        return retVal;

    double result{0.0};
    switch (op)
    {
        case '+':
            result = lhs + rhs;
            break;
        case '-':
            result = lhs - rhs;
            break;
        case '*':
            result = lhs * rhs;
            break;
        case '/':
            if (rhs == 0.0)
            {
                std::cerr << "错误：除数不能为 0。\n";
                return 1;
            }
            result = lhs / rhs;
            break;
        default:
            std::cerr << "不支持的运算符：" << op << "，请使用 + - * /。\n";
            return 1;
    }

    std::cout << "结果：" << result << '\n';
    return 0;
}

int input(double &lhs, char &op, double &rhs, bool &retFlag)
{
    retFlag = true;
    std::cout << "请输入表达式 (例如 12.5 * 3): ";
    if (!(std::cin >> lhs >> op >> rhs))
    {
        std::cerr << "输入格式有误，形如：数 运算符 数\n";
        return 1;
    }
    retFlag = false;
    return {};
}