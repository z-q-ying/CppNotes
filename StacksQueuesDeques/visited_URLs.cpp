/**
 * Solve a Basic Problem
 * Keep track of visited URLs in a web browser
 * Simple purpose: Implement a back button
 * We're interested in keeping the current URL always available through a function
 *
 * Test:
 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    stack<string> back_stack;
    string temp;

    while(temp != "exit") {
        cout << "[1] Visit URL   [2] Back" << endl;
        cin >> temp;
        if (temp == "exit") { break;}
        else if (temp == "1") {
            cout << "Enter ULR: ";
            cin >> temp;
            back_stack.push(temp);
        }
        else if (temp == "2") {
            cout << "Going back ...\n";
            back_stack.pop();
        }
        if(back_stack.empty()) break;
        cout << "Current URL: " << back_stack.top() << endl;
    }
    return 0;
}

//Trial run:
//
//[1] Visit URL   [2] Back
//1
//Enter ULR: www.mywork.com
//Current URL: www.mywork.com
//[1] Visit URL   [2] Back
//1
//Enter ULR: www.mysite.com
//Current URL: www.mysite.com
//[1] Visit URL   [2] Back
//1
//Enter ULR: www.cppreference.com
//Current URL: www.cppreference.com
//[1] Visit URL   [2] Back
//2
//Going back ...
//Current URL: www.mysite.com
//[1] Visit URL   [2] Back
//2
//Going back ...
//Current URL: www.mywork.com
//[1] Visit URL   [2] Back
//2
//Going back ...
//
//Process finished with exit code 0