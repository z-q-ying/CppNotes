//
// std::priority_queue demo
// push from one end and pop front another end
// Created by Qiuying Zhuo on 7/9/23.
//

#include <iostream>
#include <queue>

using std::priority_queue, std::cout, std::endl;

int main() {

    int inputs[] = {8, 6, 4, 2, 7, 5, 3, 1}; // RANDOM
    int length = sizeof(inputs) / sizeof(int);

    priority_queue<int> numbers;

    // pushing
    int i = length;
    while (i--) {
        cout << "Pushing " << inputs[i] << "..." << endl;
        numbers.push(inputs[i]);
    }

    // printf using POP and FRONT
    cout << "{ ";
    while (numbers.size() > 0) {
        cout << numbers.top() << " "; // Priority Queue only has TOP, not front
        numbers.pop();
    }
    cout << "}" << endl;

    return 0;
}