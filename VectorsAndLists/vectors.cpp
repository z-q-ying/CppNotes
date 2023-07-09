// std::vector demo
// push back, push front, inserts at a specific position, modify existing elements
// Created by Qiuying Zhuo on 7/8/23.
//

#include <iostream>
#include <vector>

using std::vector, std::cout;

void print(const vector<int> &my_vector) {
    cout << "Vector content: { ";
    for (auto i: my_vector) {
        cout << i << " ";
    }
    cout << "}\n\n";
}

int main() {

    // demo push back
    int inputs[] = {1, 2, 3, 4};
    vector<int> numbers1;
    for (int i = 0; i < 4; i++) {
        cout << "Pushing back...\n";
        numbers1.push_back(inputs[i]);
    }
    print(numbers1);

    // demo push front: insert(numbers.begin(), num)
    for (int i = 0; i < 4; i++) {
        cout << "Pushing front...\n";
        numbers1.insert(numbers1.begin(), inputs[i]);
    }
    print(numbers1);

    // inserts at a specific position
    for (int i = 3; i >= 0; i--) {
        cout << "Inserting at index " << i * 2 << "...\n";
        numbers1.insert(numbers1.begin() + i * 2, inputs[i]);
    }
    print(numbers1);

    // modifies values
    cout << "Modifying existing elements...\n";
    for (int i = 0; i < 4; i++) {
        numbers1[i * 2] = i * 3;
    }
    print(numbers1);

    return 0;
}


