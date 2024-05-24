class Solution {

public:
    vector<int> numOfLetter = vector<int>(26, 0);
    int n, ans;
    bool isPossible(const string& s) {
        vector<int> tmp(numOfLetter);
        for (auto c : s) {
            if (--tmp[c - 'a'] < 0) return false;
        }

        return true;
    }
    void sol(vector<string>& words, vector<int>& score, int k, int sum) { 
        if (n == k) {
            ans = max(ans, sum);
            return;
        }

        sol(words, score, k + 1, sum);
        if (isPossible(words[k])) {
            for (auto c : words[k]) {
                numOfLetter[c - 'a']--;
                sum += score[c - 'a'];
            }
            sol(words, score, k + 1, sum);
            for (auto c : words[k]) {
                numOfLetter[c - 'a']++;
                sum -= score[c - 'a'];
            }
        }
     }
    int maxScoreWords(vector<string>& words, vector<char>& letters,
                      vector<int>& score) {
                        n = words.size();
                        ans = 0;
        for (auto c : letters) {
            numOfLetter[c - 'a']++;
        }

        sol(words, score, 0, 0);
        return ans;
    }
};