class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        for (int x : nums) total += x;

        if (target < -total || target > total)
            return 0;

        int n = nums.size();

        vector<vector<int>> dp(
            n + 1,
            vector<int>(2 * total + 1, 0)
        );

        dp[0][total] = 1;   // actual sum = 0

        for (int i = 0; i < n; i++) {
            for (int sum = -total; sum <= total; sum++) {

                int ways = dp[i][sum + total];

                if (ways == 0) continue;

                dp[i + 1][sum + nums[i] + total] += ways;
                dp[i + 1][sum - nums[i] + total] += ways;
            }
        }

        return dp[n][target + total];
    }
};