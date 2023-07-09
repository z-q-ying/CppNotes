//
// std::queue demo
// push from one end and pop front another end
// Created by Qiuying Zhuo on 7/9/23.
//

#include <iostream>
#include <queue>

using std::queue, std::cout, std::endl;

int main() {

    int inputs[] = {8, 7, 6, 5, 4, 3, 2, 1};
    int length = sizeof(inputs) / sizeof(int);

    queue<int> numbers;

    // pushing
    int i = length;
    while (i--) {
        cout << "Pushing " << inputs[i] << "..." << endl;
        numbers.push(inputs[i]);
    }

    // printf using POP and FRONT
    cout << "{ ";
    while (numbers.size() > 0) {
        cout << numbers.front() << " "; // Queue only has FRONT, not top
        numbers.pop();
    }
    cout << "}" << endl;

    return 0;
}