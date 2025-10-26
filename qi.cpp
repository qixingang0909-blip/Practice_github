#include <iostream>
#include <string>
#include <cctype>   // toupper

int main() {
    std::string s;
    std::cout << "输入一行文字：";
    std::getline(std::cin, s);

    // 把每个字符转成大写
    for (char &ch : s) {
        // 为了兼容中文/符号，这里把 char 转成 unsigned char 再给 toupper
        ch = std::toupper(static_cast<unsigned char>(ch));
    }

    std::cout << "结果：" << s << "\n";
    return 0;
}
