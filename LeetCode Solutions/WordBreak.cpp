class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        // Create a hashset of words for fast query
		unordered_set<string> words(wordDict.begin(), wordDict.end());

		int n = s.size();

		//Here a vector db is used to store the comparison results: db[i]=1 means that the sub-string (from 0 to i) in string s can find matched words in dict.
		vector<int> dp(n + 1, 0);

		dp[0] = 1;

		for (int i = 1; i <= n; ++i) {
			for (int j = i - 1; j >=0; --j) {
                
				if (dp[j] && words.count(s.substr(j, i-j))) {
                    dp[i] = 1;
				    break;
                }
					
			}

		}
		return dp[n];	
	  
    }
};