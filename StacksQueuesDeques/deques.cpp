//
// std::deque demo
// push_back, push_front
// Created by Qiuying Zhuo on 7/9/23.
//

#include <iostream>
#include <deque>

using std::deque, std::cout, std::endl;

void print(const deque<int> &numbers) {
    cout << "Deque: { ";
    for (auto i: numbers) {
        cout << i << " ";
    }
    cout << "}" << endl;
}

int main() {

    int inputs[] = {8, 7, 6, 5, 4, 3, 2, 1};
    int length = sizeof(inputs) / sizeof(int);

    deque<int> numbers;

    int i = length;
    while (i--) {
        cout << "Pushing back " << inputs[i] << "..." << endl;
        numbers.push_back(inputs[i]);

    }
    print(numbers);
    cout << endl;

    i = length;
    while (i--) {
        cout << "Pushing front " << inputs[i] << "..." << endl;
        numbers.push_front(inputs[i]);
    }
    print(numbers);

    return 0;
}