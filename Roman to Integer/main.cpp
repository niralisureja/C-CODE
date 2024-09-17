#include <iostream>
#include <unordered_map>
using namespace std;

int romanToInt(string s) {
    // Create a map for Roman numerals and their corresponding integer values
    unordered_map<char, int> romanMap = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}
    };
    
    int total = 0;  // This will store the final integer result
    int n = s.length();
    
    // Loop through the string
    for (int i = 0; i < n; i++) {
        // Check if the current numeral is smaller than the next numeral
        if (i < n - 1 && romanMap[s[i]] < romanMap[s[i + 1]]) {
            total -= romanMap[s[i]];  // Subtract if a smaller numeral precedes a larger one
        } else {
            total += romanMap[s[i]];  // Otherwise, add the numeral's value
        }
    }
    
    return total;
}

int main() {
    string s;
    cout << "Enter a Roman numeral: ";
    cin >> s;

    int result = romanToInt(s);
    cout << "The integer value is: " << result << endl;
    
    return 0;
}
