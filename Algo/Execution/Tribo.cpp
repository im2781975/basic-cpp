// return true if you can partition array into two subsets such that the 
// sum of the elements in both subsets is equal or false otherwise.
bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2) return false;
    int target = sum / 2; /*
    int n = nums.size();
    vector <vector <bool>> dp(n + 1, vector <bool> (trg + 1, false));
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= target; j++) {
            if (j >= nums[i - 1])
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            else dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][target]; */
    vector<bool> dp(target + 1, false);
    dp[0] = true;
    for (int num : nums) {
        for (int j = target; j >= num; j--)
            dp[j] = dp[j] || dp[j - num];
    }
    return dp[target];
}
// find two values (at distinct positions) whose sum is trg
pair <int, int> findTwoSum(vector <int> & nums, int target) { /*
    pair <int, int> result = findTwoSum(nums, target);
    if (result.first != -1) {
        cout << "Indices: " << result.first << " and " << result.second ;
        cout << "Values: " << nums[result.first] << " and " << nums[result.second] ;
    } */
    unordered_map<int,int> mp;
    for (int i = 0; i < nums.size(); i++) {
        if (mp.count(target - nums[i]))
            return {mp[target - nums[i]], i};
        mp[nums[i]] = i;
    }
    return {-1, -1};
}
// Count ways to get target using + or - before each number in nums
int findTargetWays(vector <int>& nums, int target) {
    unordered_map <int, int> dp;
    dp[nums[0]] = dp[-nums[0]] = 1; /*
    for (int i = 1; i < nums.size(); i++) {
        unordered_map <int, int> next_dp;
        for (const auto& pair : dp) {
            next_dp[pair.first + nums[i]] += pair.second;
            next_dp[pair.first - nums[i]] += pair.second;
        }
        dp = next_dp;
    } */
    for (int i = 1; i < nums.size(); i++)
        for (auto [sum, cnt] : dp)
            dp[sum + nums[i]] += cnt, dp[sum - nums[i]] += cnt;
    
    return dp[target];
}
vector <int> dp(100, -1);
void Tribonacci(int n) {
    if (n <= 0) return 0;
    if (n <= 2) return 1; /*
    vector <int> dp(n + 1, 0);
    dp[0] = 0; dp[1] = 1; dp[2] = 1;
    for (int i = 3; i <= n; ++i)
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    return dp[n]; */
    if (dp[n] != -1) return dp[n];
    dp[n] = Tribonacci(n - 1) + Tribonacci(n - 2) + Tribonacci(n - 3);
    return dp[n];
}
