#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";

        string longest = "";
        for (int i = 0; i < s.size(); ++i) {
            // Odd-length palindrome
            string oddPalindrome = expandAroundCenter(s, i, i);
            if (oddPalindrome.size() > longest.size()) {
                longest = oddPalindrome;
            }

            // Even-length palindrome
            string evenPalindrome = expandAroundCenter(s, i, i + 1);
            if (evenPalindrome.size() > longest.size()) {
                longest = evenPalindrome;
            }
        }

        return longest;
    }

private:
    string expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return s.substr(left + 1, right - left - 1);
    }
};

int main() {
    Solution solution;
    string s = "babad";
    cout << "Longest Palindromic Substring: " << solution.longestPalindrome(s) << endl;
    return 0;
}
