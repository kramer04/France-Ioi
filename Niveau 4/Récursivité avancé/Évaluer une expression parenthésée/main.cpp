#include <iostream>
#include <cstring>
#include <cctype>
int expression();
int main() {
    std::cout << expression() << std::endl;
}
int expression() {
    int acc = 0;
    int num;
    char op = '\0';
    char c = std::cin.get();
    while (c != '\n' && c != ')') {
        if (strchr("+-*/%", c) != nullptr) {
            op = c;
            c = std::cin.get();
        } else {
            if (c == '(') {
                num = expression();
                c = std::cin.get();
            } else {
                num = 0;
                while (isdigit(c)) {
                    num = num * 10 + c - '0';
                    c = std::cin.get();
                }
            }
            switch (op) {
                case '\0': acc = num; break;
                case '+': acc += num; break;
                case '-': acc -= num; break;
                case '*': acc *= num; break;
                case '/': acc /= num; break;
                case '%': acc %= num; break;
            }
        }
    }
    return acc;
}
