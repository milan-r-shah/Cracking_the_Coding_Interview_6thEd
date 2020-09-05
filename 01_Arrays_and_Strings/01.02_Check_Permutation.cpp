/*
* CtCI 6th Ed | Chapter 1: Arrays and Strings
* 
* Problem 1.2 Check Permutation (pg 90):
* Given two strings,write a method to decide if one is a permutation of the other.
*/

/*
Here, it's assumed that lower-case and upper-case strings are different
i.e. "milan" is permutation of "nalim" but not of "naliM" or "Milan" 
Also, blank-space are considered. So, "milan" is not permutation of "milan  " or "m ilan"
*/

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

// checkPermutation -- sort strings & then compare
bool checkPermutation1(std::string str1, std::string str2) {
    if (str1.length() != str2.length())
        return false;

    std::sort(str1.begin(), str1.end());
    std::sort(str2.begin(), str2.end());

    if (str1 == str2)
        return true;
    else
        return false;
}

// checkPermutation -- using character map
bool checkPermutation2(std::string str1, std::string str2) {
    if (str1.length() != str2.length())
        return false;

    std::vector<int> ascii_vec(128);

    for (int i = 0; i < str1.length(); ++i) {
        // get the ASCII value of a character from the string
        int ascii_val = (int)str1[i];

        // for that specific index increase the count
        ascii_vec[ascii_val]++;
    }

    for (int i = 0; i < str2.length(); ++i) {
        int ascii_val = (int)str2[i];
        if (--ascii_vec[ascii_val] < 0)
            return false;
    }

    return true;
}

// checkPermutation -- using character map - range-based for loop
bool checkPermutation3(std::string str1, std::string str2) {
    if (str1.length() != str2.length())
        return false;

    std::vector<int> ascii_vec(128);

    for (const char &ch1 : str1)
        ascii_vec[ch1]++;

    for (const char &ch2 : str2)
        if (--ascii_vec[ch2] < 0)
            return false;

    return true;
}

// checkPermutation -- using map
bool checkPermutation4(std::string str1, std::string str2) {
    if (str1.length() != str2.length())
        return false;

    std::map<char, int> char_map;

    for (const char &ch1 : str1)
        char_map[ch1]++;

    for (const char &ch2 : str2)
        if (--char_map[ch2] < 0)
            return false;

    return true;
}

// helper function
void test(std::string str1, std::string str2) {
    if (checkPermutation4(str1, str2))
        std::cout << str1 << " is Permutation of " << str2 << " !\n";
    else
        std::cout << str1 << " is not Permutation of " << str2 << " !\n";
}

int main() {
    test("milan", "nalim");
    test("milan", "Milan");
    test("milan", "nalim            ");
    test("milan", "shah");

    return 0;
}