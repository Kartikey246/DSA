// j is read pointer and i is write pointer. We always write s[j] to s[i].

// If the last 3 characters in front of i is abc, we clean them by i -= 3.

// In the end, return i == 0.


class Solution {
public:
    bool isValid(string s) {
        int i = 0, N = s.size();
        for (int j = 0; j < N; ++j) {
            s[i++] = s[j];
            if (i >= 3 && s[i - 3] == 'a' && s[i - 2] == 'b' && s[i - 1] == 'c') i -= 3;
        }
        return i == 0;
    }
};
