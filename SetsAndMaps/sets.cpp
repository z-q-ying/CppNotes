//
// std::set and variants demo
// insertion (insert) and deletion (erase)
// Created by Qiuying Zhuo on 7/9/23.
//

#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;

void print(const set<int> &numbers) {
    set<int>::iterator it = numbers.begin();
    cout << "Set { ";
    while(it != numbers.end()) {
        cout << *it << " ";
        it++;
    }
    cout << "}" << endl;
}

void print(const unordered_set<int> &numbers) {
    cout << "Set { ";
    for (const auto &element: numbers) {
        cout << element << " ";
    }
    cout << "}" << endl;
}

int main() {
    int inputs[] = {1, 3, 5, 7, 9, 7, 5, 3, 1, 2, 4, 6, 8};
    int length = sizeof(inputs) / sizeof(int); // size: 13

    set<int> this_ordered_set;
    unordered_set<int> this_unordered_set;

    for (int i = 0; i < length; i++) {
        cout << "Entering number " << inputs[i] << "...\n";
        this_ordered_set.insert(inputs[i]);
        this_unordered_set.insert(inputs[i]);
    }
    cout << "Ordered "; print(this_ordered_set);
    cout << "Unordered "; print(this_unordered_set);

    int nums_to_erase[] = {1, 9, 5, 10, 11};
    length = sizeof(nums_to_erase) / sizeof(int);
    for (int i = 0; i < length; i++) {
        cout << "Removing " << nums_to_erase[i] << "...\n";
        this_ordered_set.erase(nums_to_erase[i]);
        this_unordered_set.erase(nums_to_erase[i]);
    }
    cout << "Ordered "; print(this_ordered_set);
    cout << "Unordered "; print(this_unordered_set);

    return 0;
}

//Test:
//
//Entering number 3...
//Entering number 5...
//Entering number 7...
//Entering number 9...
//Entering number 7...
//Entering number 5...
//Entering number 3...
//Entering number 1...
//Entering number 2...
//Entering number 4...
//Entering number 6...
//Entering number 8...
//Ordered Set { 1 2 3 4 5 6 7 8 9 }
//Unordered Set { 8 6 4 2 9 7 5 3 1 }
//Removing 1...
//Removing 9...
//Removing 5...
//Removing 10...
//Removing 11...
//Ordered Set { 2 3 4 6 7 8 }
//Unordered Set { 8 6 4 2 7 3 }
//
//Process finished with exit code 0
