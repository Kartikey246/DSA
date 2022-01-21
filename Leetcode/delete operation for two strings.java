/*
In the above solution, we can see that we are only ever accessing the current row and previous row of the dp array. So, we don't really need to maintain the whole dp array and the solution can be optimized to suffice with the use of only 2 rows.

A common and very easy trick to optimze space in such DP solutions is to declare two rows of dp and alternate between these rows on each iteration. We can easily alternate between the rows by doing a parity check - use row 0 for odd indices and 1 for even indices.

So, the only change to optimze the space in solution solution is to declare a two row dp matrix and AND (&) row index of dp with 1 to alternate between rows

We can see that for an index i, j of word1 and word2, we have following cases -

  1. word1[i] == word2[j] : The characters match and there's no need of deletion. Move on to next character of both words

  2. word1[i] != word2[j] : The characters don't match. We only have two choices if we want to equalize the words. Either -

    I. delete word1[i].
    II. delete word2[j].

  3. i == word1.length and j == word2.length : We have reached end of both words and both strings have been equalized. No further steps needed.

  4. i == word1.length OR j == word2.length : We have reached end of one word and only way to equalize is to delete rest of characters of the other word.

This can be easily implemented as a recursive function. Also, we don't need to explicitly delete any characters of the words. We will just denote deleting word1[i] (case 2.I) by recursing for (i+1)th index and deleting word2[j] (case 2.II) by recursing for (j + 1)th index.

*/








public static int minDistance(String word1, String word2) {
    if(word1.length() < word2.length()) {
        String tmp = word1;
        word1 = word2;
        word2 = tmp;
    }
    int[][] dp = new int[2][word2.length() + 1];
    for (int i = 0; i <= word1.length(); i++) 
        for (int j = 0; j <= word2.length(); j++) 
            if (i == 0 || j == 0) 
                dp[i & 1][j] = i + j;
            else if (word1.charAt(i - 1) == word2.charAt(j - 1)) 
                dp[i & 1][j] = dp[(i - 1) & 1][j - 1];
            else 
                dp[i & 1][j] = 1 + Math.min(dp[(i - 1) & 1][j], dp[i & 1][j - 1]);
    
    return dp[word1.length() & 1][word2.length()];
}
