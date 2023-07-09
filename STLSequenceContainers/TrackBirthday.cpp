/**
 * Keep track of guests (children) at a small birthday party
 * Simple purpose: logistics for catering and party favors
 *
 * We're interested in the following information per child:
 * - Name
 * - Gender
 * - Age
 *
 * Challenge description:
 * Use the same birthday party logistics vector and list code
 * Add the following features to the application:
 * - Print a guest's data by index (e.g. my_guests[3])
 * - Remove a quest by index
 * - Calculate the average age in the group
 *
 * Make it work with vectors or with lists
 */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <list>

using namespace std;

#define USE_VECTOR
// #define USE_LIST;

class Guest {
public:
    Guest() {}

    ~Guest() {}

    void setGender(string in) {
        char i = in.c_str()[0];
        if (i == 'B' || i == 'b' || i == 'M' || i == 'm') {
            gender = "Boy";
        } else {
            gender = "Girl";
        }
    }

    string name;
    string gender;
    int age;
};

#ifdef USE_VECTOR
typedef vector<Guest> my_container;
#elif defined USE_LIST
typedef list<Guest> my_container;
#endif

/** PAY ATTENTION TO HOW THE CONTAINER IS HANDLED */

void read_file(my_container *my_guests) {
    string in_str;
    ifstream in_file("my_guests.txt");
    if(in_file.is_open()){
        Guest tmp;
        while(getline(in_file, in_str)) {
            tmp.name = in_str;
            getline(in_file, in_str);
            tmp.setGender(in_str);
            getline(in_file, in_str);
            tmp.age = stoi(in_str);
            my_guests->push_back(tmp);
        }
        in_file.close();
    }
    else
        cout << "Unable to open file!\n\n";
}

void print_guests(my_container *my_guests) {
    auto it = my_guests->begin();
    cout << "-- Container Content Start --\n";
    cout << "-----------------------------\n";
    while(it != my_guests->end()) { // OK TO USE < FOR VECTOR BUT NOT FOR LIST; NO RANDOM ACCESS IS SUPPORTED
        cout << "Name  : " << it->name << endl;
        cout << "Gender: " << it->gender << endl;
        cout << "Age   : " << it->age << endl;
        cout << "-----------------------------\n";
        it++; // OK TO USE it+=1 FOR VECTOR BUT NOT FOR LIST; NO RANDOM ACCESS IS SUPPORTED
    }
    cout << "--- Container Content END ---\n";
}

bool get_guest(my_container *container, int index, Guest &res) {
    auto it = container->begin();
    for (int i = 0; i < index; i++, it++) {
        if (it==container->end()) return false; // if reaching the end of the container, return
    }
    res = *it;
    return true; // report failure
}

bool delete_guest(my_container *container, int index) {
    auto it = container->begin();
    for (int i = 0; i < index; i++, it++) {
        if (it == container->end()) return false;
    }
    container->erase(it);
    return true; // report success
}

float average_age(const my_container &container) {
    float avg = 0.0f;
    for (Guest g: container) {
        avg += g.age;
    }
    avg = avg / container.size();
    return avg;
}

int main() {
    // testing read and print files
    my_container *my_guests = new my_container;
    read_file(my_guests); // read file and populate my_container
    print_guests(my_guests); // printf

    // testing print by index, remove by index and calculate the average age in the group
    Guest tmp;
    int index = 3;
    if (get_guest(my_guests, index, tmp)) {
        cout << "Name  : " << tmp.name << endl;
        cout << "Gender: " << tmp.gender << endl;
        cout << "Age   : " << tmp.age << endl;
        cout << "-----------------------------\n";
    } else {
        cout << "Failed to get guest!!!";
    }

    if(!delete_guest(my_guests, index)) {
        cout << "Failed to delete guest!!!";
    }

    print_guests(my_guests);

    cout << "\n\nThe average age is " << average_age(*my_guests) << endl;

    return 0;
}