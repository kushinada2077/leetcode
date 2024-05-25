class Solution {
public:
    int n; 
    vector<string> sen;
    vector<string> ans;
    unordered_set<string> dic;
    void sol(const string& s, int k) {
        if (n == k) {
            string tmp = "";
            for (auto word : sen) tmp += (word + " ");
            tmp = tmp.substr(0, tmp.size() - 1);
            ans.push_back(tmp);
            return;
        }

        for (int i = 1; i <= n - k; i++) {
            string word = s.substr(k, i);
            if (dic.find(word) != dic.end()) {
                sen.push_back(word);
                sol(s, k + i);
                sen.pop_back();
            }
       }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        for (auto word : wordDict) dic.insert(word);
        sol(s, 0);
        return ans;
    }
};