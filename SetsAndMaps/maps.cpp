//
// std::map and variants demo
// insertion (insert) and deletion (erase)
// Created by Qiuying Zhuo on 7/9/23.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

int main() {
    int length = 4;
    int keys[] = {2, 8, 6, 4};
    string values[] = {"hello", "world", "hi", "there"};

    map<int, string> this_map;
    pair<int, string> p;
    for (int i = 0; i < length; i++) {
        cout << "Inserting " << keys[i] << ": " << values[i] << endl;
        p.first = keys[i];
        p.second = values[i];
        this_map.insert(p);
    }

    cout << "Ordered Map: { ";
    for (auto it = this_map.begin(); it != this_map.end(); it++) {
        cout << it->first << ": " << it->second << "   ";
    }
    cout << "}" << endl << endl;

    unordered_map<int, string> that_map;
    for (int i = 0; i < length; i++) {
        cout << "Inserting " << keys[i] << ": " << values[i] << endl;
        p.first = keys[i];
        p.second = values[i];
        that_map.insert(p);
    }

    cout << "Unordered Map: { ";
    for (auto it = that_map.begin(); it != that_map.end(); it++) {
        cout << it->first << "->" << it->second << "   ";
    }
    cout << "}" << endl << endl;

    int keys_to_remove[] = {1, 2, 8, 7};
    for (int i = 0; i < length; i++) {
        cout << "Deleting key " << keys_to_remove[i]<< endl;
        this_map.erase(keys_to_remove[i]);
        that_map.erase(keys_to_remove[i]);
    }

    cout << "Ordered Map: { ";
    for (auto it = this_map.begin(); it != this_map.end(); it++) {
        cout << it->first << ": " << it->second << "   ";
    }
    cout << "}" << endl << endl;

    cout << "Unordered Map: { ";
    for (auto it = that_map.begin(); it != that_map.end(); it++) {
        cout << it->first << "->" << it->second << "   ";
    }
    cout << "}" << endl;

    return 0;
}

// Test:
//
//        Inserting 2: hello
//        Inserting 8: world
//        Inserting 6: hi
//        Inserting 4: there
//        Ordered Map: { 2: hello   4: there   6: hi   8: world   }
//
//Inserting 2: hello
//        Inserting 8: world
//        Inserting 6: hi
//        Inserting 4: there
//        Unordered Map: { 4->there   6->hi   8->world   2->hello   }
//
//Deleting key 1
//Deleting key 2
//Deleting key 8
//Deleting key 7
//Ordered Map: { 4: there   6: hi   }
//
//Unordered Map: { 4->there   6->hi   }
//
//Process finished with exit code 0
