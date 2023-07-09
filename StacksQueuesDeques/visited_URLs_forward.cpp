/**
 * Back and forward buttons
 *
 * Challenge Description:
 * Use the same web browser back button code
 * Add the functionality of a forward button
 * Keep a history of the URLs visited each time the back button is pressed
 * This additional history is cleared when a new address is entered
 *
 * Test Code:
 * Use the same web browser back button code
 * Add the functionality of a forward button
 * Keep a history of the URLs visited each time the back button is pressed
 * This additional history is cleared when a new address is entered
 * Go back a few URLs (two, for examples)
 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    stack<string> back_stack;
    stack<string> forward_stack;
    string temp;

    while(temp != "exit") {
        cout << "[1] Visit URL   [2] Back   [3] Forward" << endl;
        cin >> temp;
        if (temp == "exit") { break;}

        // deal with valid input option
        if (temp == "1") {
            cout << "Enter ULR: ";
            cin >> temp;
            back_stack.push(temp);
            forward_stack = stack<string>(); // EMPTY THE STACK BY CREATING A NEW ONE
        }
        else if (temp == "2") {
            cout << "Going back...\n";
            forward_stack.push(back_stack.top());
            back_stack.pop();
        }
        else if (temp == "3") {
            if (forward_stack.empty()) {
                cout << "No forward history!\n";
            } else {
                cout << "Going forward...\n";
                back_stack.push(forward_stack.top());
                forward_stack.pop();
            }
        }

        // check and print
        if(back_stack.empty()) break;
        cout << "\nCurrent URL: " << back_stack.top() << endl;
    }
    return 0;
}

//Trial run:
//
//[1] Visit URL   [2] Back   [3] Forward
//1
//Enter ULR: www.one.com
//
//        Current URL: www.one.com
//[1] Visit URL   [2] Back   [3] Forward
//1
//Enter ULR: www.two.com
//
//        Current URL: www.two.com
//[1] Visit URL   [2] Back   [3] Forward
//1
//Enter ULR: www.myURL.com
//
//        Current URL: www.myURL.com
//[1] Visit URL   [2] Back   [3] Forward
//1
//Enter ULR: www.example.com
//
//        Current URL: www.example.com
//[1] Visit URL   [2] Back   [3] Forward
//1
//Enter ULR: www.last.com
//
//        Current URL: www.last.com
//[1] Visit URL   [2] Back   [3] Forward
//2
//Going back...
//
//Current URL: www.example.com
//[1] Visit URL   [2] Back   [3] Forward
//2
//Going back...
//
//Current URL: www.myURL.com
//[1] Visit URL   [2] Back   [3] Forward
//2
//Going back...
//
//Current URL: www.two.com
//[1] Visit URL   [2] Back   [3] Forward
//3
//Going forward...
//
//Current URL: www.myURL.com
//[1] Visit URL   [2] Back   [3] Forward
//3
//Going forward...
//
//Current URL: www.example.com
//[1] Visit URL   [2] Back   [3] Forward
//1
//Enter ULR: www.clear.com
//
//        Current URL: www.clear.com
//[1] Visit URL   [2] Back   [3] Forward
//3
//No forward history!
//
//Current URL: www.clear.com
//[1] Visit URL   [2] Back   [3] Forward
//2
//Going back...
//
//Current URL: www.example.com
//[1] Visit URL   [2] Back   [3] Forward
//2
//Going back...
//
//Current URL: www.myURL.com
//[1] Visit URL   [2] Back   [3] Forward
