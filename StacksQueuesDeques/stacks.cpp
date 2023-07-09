//
// std::stack demo
// push from one end only
// Created by Qiuying Zhuo on 7/9/23.
//

#include <iostream>
#include <stack>

using std::stack, std::cout, std::endl;

int main() {

    int inputs[] = {8, 7, 6, 5, 4, 3, 2, 1};
    int length = sizeof(inputs) / sizeof(int);

    stack<int> numbers;

    // pushing
    int i = length;
    while (i--) {
        cout << "Pushing " << inputs[i] << "..." << endl;
        numbers.push(inputs[i]);

    }

    // printf using POP and TOP
    cout << "{ ";
    while (numbers.size() > 0) {
        cout << numbers.top() << " "; // Stack only has TOP, not front
        numbers.pop();
    }
    cout << "}" << endl;

    return 0;
}