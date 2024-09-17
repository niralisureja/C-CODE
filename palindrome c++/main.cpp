#include <iostream>
using namespace std;

bool isPalindrome(int x) {
    // If x is negative, it cannot be a palindrome
    if (x < 0) return false;

    int original = x;
    long long reversed = 0;  // Use long long to avoid overflow for large numbers

    // Reverse the digits of x
    while (x > 0) {
        int digit = x % 10;
        reversed = reversed * 10 + digit;
        x /= 10;
    }

    // Compare the original number with the reversed number
    return original == reversed;
}

int main() {
    int x = 121;  // Example input
    if (isPalindrome(x)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}
