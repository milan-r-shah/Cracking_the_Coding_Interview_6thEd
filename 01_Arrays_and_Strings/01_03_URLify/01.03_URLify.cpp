#include <iostream>
#include <string>

// URLify -- using while loop
void URLify1(std::string &str, int true_str_len) {
    int pos_ptr = str.length() - 1;
    int char_ptr = true_str_len - 1;

    while (char_ptr != 0) {
        if (str[char_ptr] == ' ') {
            str[pos_ptr--] = '0';
            str[pos_ptr--] = '2';
            str[pos_ptr--] = '%';
            char_ptr--;
        } else {
            str[pos_ptr--] = str[char_ptr--];
        }
    }
}

// URLify -- using for loop
void URLify2(std::string &str, int true_str_len) {
    int pos_ptr = str.length() - 1;

    for (int i = true_str_len - 1; i >= 0; --i) {
        if (str[i] == ' ') {
            str[pos_ptr--] = '0';
            str[pos_ptr--] = '2';
            str[pos_ptr--] = '%';
        } else {
            str[pos_ptr--] = str[i];
        }
    }
}

int main() {
    std::string str1 = "Mr John Smith    ";
    int true_len1 = 13;
    std::cout << "Input:  \"" << str1 << "\", " << true_len1 << "\n";
    URLify1(str1, true_len1);
    std::cout << "Output: \"" << str1 << "\"\n";

    std::string str2 = "Mr John Smi h      ";
    int true_len2 = 13;
    std::cout << "Input:  \"" << str2 << "\", " << true_len2 << "\n";
    URLify1(str2, true_len2);
    std::cout << "Output: \"" << str2 << "\"\n";

    std::string str3 = "Mr  John Smith      ";
    int true_len3 = 14;
    std::cout << "Input:  \"" << str3 << "\", " << true_len3 << "\n";
    URLify1(str3, true_len3);
    std::cout << "Output: \"" << str3 << "\"\n";

    std::string str4 = "Mr John Smith    ";
    int true_len4 = 13;
    std::cout << "Input:  \"" << str4 << "\", " << true_len4 << "\n";
    URLify2(str4, true_len4);
    std::cout << "Output: \"" << str4 << "\"\n";

    return 0;
}