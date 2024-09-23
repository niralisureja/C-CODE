#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    // Function to find the minimum number of extra characters
    // needed to construct the string 's' using the words from the 'dictionary'.
    int minExtraChar(std::string s, std::vector<std::string>& dictionary) {
        // Transform the dictionary into an unordered set for constant-time look-ups.
        std::unordered_set<std::string> wordSet(dictionary.begin(), dictionary.end());
      
        int stringLength = s.size();
        std::vector<int> dp(stringLength + 1);
        dp[0] = 0; // Base case: no extra character is needed for an empty substring.
      
        
        for (int i = 1; i <= stringLength; ++i) {
           
            dp[i] = dp[i - 1] + 1;

            
            for (int j = 0; j < i; ++j) {
                if (wordSet.count(s.substr(j, i - j))) {
                    
                    dp[i] = std::min(dp[i], dp[j]);
                }
            }
        }

       
        return dp[stringLength];
    }
};