/**
 * Challenge Description:
 * Keep track of guests in a hotel--for now, just use a name
 * The hotel has 20 floors with 15 rooms each
 * Rooms are numbered as [floor #][room #], for example, 114, 502, 1408
 * Do not accept duplicate entries
 *
 * Some Important Details:
 * Guest objects may take considerable storage, not just a name
 * Room numbers outside the format do not exist: 2, 100, 1816, 2204
 * A vector indexed by room number would waste a lot of space
 * Possible index: [0-2015]
 * 85 entries wasted per floor: 10, 16-99]
 *
 * Test Code:
 * Enter a series of room numbers with names (four, for example)
 * Print them all out
 * Enter a duplicate key for an existing entry, with a different name
 * Delete an existing entry, not the duplicate from one step above
 * Print the contents of the map to assert that there are no duplicates
 */

#include <iostream>
#include <map>

using namespace std;

int main() {
    map<int, string> hotel;
    pair<int, string> p;
    int room_nums[] = {1101, 405, 607, 405};  // with duplicate
    string guests[] = {"A B", "C D", "E E", "F G"};
    int length = 4;

    for (int i = 0; i < length; i++) {
        p.first = room_nums[i];
        p.second = guests[i];
        hotel.insert(p);
    }

    cout << "Guests: { ";
    for (auto it = hotel.begin(); it != hotel.end(); it++) {
        cout << it->first << "->" << it->second << "   ";
    }
    cout << "}" << endl << endl;

    cout << "Removing guests in 607 and (not existing 1010)..." << endl;
    hotel.erase(607);
    hotel.erase(1010);
    cout << "Guests: { ";
    for (auto it = hotel.begin(); it != hotel.end(); it++) {
        cout << it->first << "->" << it->second << "   ";
    }
    cout << "}" << endl;

    return 0;
}

// Test:
//
//Guests: { 405->C D   607->E E   1101->A B   }
//
//Removing guest in 607 and (not existing 1010)...
//Guests: { 405->C D   1101->A B   }
//
//Process finished with exit code 0
