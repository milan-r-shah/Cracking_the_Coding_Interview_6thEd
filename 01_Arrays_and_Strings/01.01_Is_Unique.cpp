/*
CtCI 6th Ed | Chapter 1: Arrays and Strings

Problem 1.1 (pg 90):
Implement an algorithm to determine if a string has all unique characters.
What if you cannot use additional data structures?
*/

/*
Here, for simplicity, it's assumed that the character set is ASCII.
*/

#include <iostream>
#include <string>
#include <vector>

// isUnique
bool isUnique(std::string str) {
    // If the string length is more than 128 then just return false
    // because there are only 128 unique ASCII characters.
    if (str.length() > 128)
        return false;

    // vector of 0s having size 128 = total ASCII characters
    std::vector<int> asciiVec(128);

    for (int i = 0; i < str.length(); ++i) {
        // get the ASCII value of a character from the string
        int asciiVal = (int)str[i];

        // for that specific index increase the count 
        asciiVec[asciiVal]++;

        // if the count is more than 1 then it means that that specific
        // character is being repeated. So return 'false'
        if (asciiVec[asciiVal] > 1)
            return false;
    }

    return true;
}

// helper function
void test(std::string str) {
    if (isUnique(str))
        std::cout << str << " --> true\n";
    else
        std::cout << str << " --> false\n";
}

int main() {
    test("milan");
    test("shah");
    test(" ");
    test("   ");
    test("\\");
    test("\\\\");
    test("\"");

    return 0;
}