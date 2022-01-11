/*
You are given two 0-indexed arrays of strings startWords and targetWords. Each string consists of lowercase English letters only.

For each string in targetWords, check if it is possible to choose a string from startWords and perform a conversion operation on it to be equal to that from targetWords.

The conversion operation is described in the following two steps:

Append any lowercase letter that is not present in the string to its end.
For example, if the string is "abc", the letters 'd', 'e', or 'y' can be added to it, but not 'a'. If 'd' is added, the resulting string will be "abcd".
Rearrange the letters of the new string in any arbitrary order.
For example, "abcd" can be rearranged to "acbd", "bacd", "cbda", and so on. Note that it can also be rearranged to "abcd" itself.
Return the number of strings in targetWords that can be obtained by performing the operations on any string of startWords.

Note that you will only be verifying if the string in targetWords can be obtained from a string in startWords by performing the operations. The strings in startWords do not actually change during this process.

*/






class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        //potential targets that can be achieved
        //why map the target? smaller than potential start words after change
 unordered_map<string, int> target;
        for(auto t: targetWords) {
            sort(t.begin(), t.end());
            target[t]++;
        }       
        
        /*simple approach is that i have the answers already stored in the map
        now as given in the question we have to add a different alphabet in the 
        start words one by one.*/
         int ans = 0;
        for(auto s: startWords)  {
            for(char c = 'a'; c <= 'z'; ++c) {
                if(count(s.begin(), s.end(), c)) continue;
                auto t = s + c;
                sort(t.begin(), t.end());
                
                if(target.find(t) != target.end()) {
                    ans += target[t];
                    target.erase(t);// as the question wants the no. of targetwords that can be obtained, as this word has already been counted erase it to avoid any spoorious hits
                }
            }
        }
        return ans;
        
        
    }
};
