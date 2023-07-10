/**
 * Landmark Pins
 *
 * Solve a Basic Problem:
 * Keep track of landmark pins on a map--a name will do
 * Coordinates are expressed as latitude and longitude pairs
 * - These are the coordinates used in GPS
 * - We'll use a pair of integers
 * - Use positive coordinate: 34°24'N, 90°W -> 34, 270
 *
 * Some Important Details:
 * We expect to have as many pins as needed, all typed in
 * There are infinite coordinates
 * A two-dimensional vector indexed by coordinates is not an option
 * - Indexes are discrete; coordinates are continuous
 * - Our model has 360 × 360 = 129.600
 * - Most points would be empty, wasting a lot of space
 */

#include <iostream>
#include <map>

using namespace std;

int main() {
    map<pair<int, int>, string> pins;
    pair<pair<int, int>, string> p;
    pair<int, int> landmark;

    int coordinate_lat[] = {1, 3, 5, 7, 9};
    int coordinate_long[] = {2, 4, 6, 8, 10};
    string names[] = {"Kirkland", "Redmond", "Bellevue", "Seattle", "Bothell"};
    int length = 3;

    for (int i = 0; i < length; i++) {
        landmark.first = coordinate_lat[i];
        landmark.second = coordinate_long[i];
        p.first = landmark;
        p.second = names[i];
        pins.insert(p);
    }

    cout << "{ ";
    for (auto it = pins.begin(); it != pins.end(); it++) {
        cout << "(" << it->first.first << ", " << it->first.second << ")->" << it->second << "  ";
    }
    cout << "}\n";

    return 0;
}

// Test:
//
//{ (1, 2)->Kirkland  (3, 4)->Redmond  (5, 6)->Bellevue  }
//
//Process finished with exit code 0
