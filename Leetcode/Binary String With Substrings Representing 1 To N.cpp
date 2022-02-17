class Solution {
public:
bool queryString(string S, int N, int X = 0) {
  vector<bool> seen(N);
  for (auto i = 0; i < S.size() && X < N; ++i) {
    if (S[i] == '0') continue;
    for (auto j = i, num = 0; num <= N && j < S.size(); ++j) {
      num = (num << 1) + S[j] - '0';
      if (num > 0 && num <= N && !seen[num - 1]) {
        ++X;
        seen[num - 1] = true;
      }
    }
  }
  return X == N;
}
};
