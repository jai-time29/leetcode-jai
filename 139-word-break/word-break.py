class Solution:
    def wordBreak(self, s: str, wordDict: list[str]) -> bool:
        n = len(s)
        words = set(wordDict)

        dp = [[False] * n for _ in range(n)]

        # Base case: individual substrings
        for i in range(n):
            if s[i] in words:
                dp[i][i] = True

        # Interval DP
        for length in range(2, n + 1):
            for i in range(n - length + 1):
                j = i + length - 1

                # Entire substring itself is a word
                if s[i:j+1] in words:
                    dp[i][j] = True
                    continue

                for k in range(i, j):
                    if dp[i][k] and dp[k+1][j]:
                        dp[i][j] = True
                        break

        return dp[0][n-1]
