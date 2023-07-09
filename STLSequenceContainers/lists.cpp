// std::list demo
// push back, push front
// Created by Qiuying Zhuo on 7/8/23.
//

#include <iostream>
#include <list>

using std::list, std::cout;

void print(const list<int> &my_list) {
    cout << "Vector content: { ";
    for (auto i: my_list) {
        cout << i << " ";
    }
    cout << "}\n\n";
}

int main() {

    // demo push back
    int inputs[] = {1, 2, 3, 4};
    list<int> numbers1;
    for (int i = 0; i < 4; i++) {
        cout << "Pushing back...\n";
        numbers1.push_back(inputs[i]);
    }
    print(numbers1);

    // demo push front
    for (int i = 0; i < 4; i++) {
        cout << "Pushing front...\n";
        numbers1.push_front(inputs[i]); // LIST SUPPORTS PUSH FRONT
    }
    print(numbers1);

    /** LIST DOES NOT SUPPORT RANDOM ACCESS */

//    // inserts at a specific position
//    for (int i = 3; i >= 0; i--) {
//        cout << "Inserting at index " << i * 2 << "...\n";
//        numbers1.insert(numbers1.begin() + i * 2, inputs[i]);
//    }
//    print(numbers1);
//
//    // modifies values
//    cout << "Modifying existing elements...\n";
//    for (int i = 0; i < 4; i++) {
//        numbers1[i * 2] = i * 3;
//    }
//    print(numbers1);

    return 0;
}


