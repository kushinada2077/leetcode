class Solution {
public:
    int n;
    vector<vector<string>> ans;
    bool isPal(string s) {
        int st = 0, en = s.size() - 1;
        while (st < en) {
            if (s[st++] != s[en--]) return false;
        }
        return true;
    }
    bool isAllPal(vector<string>& p) {
        for (auto s : p) {
            if (!isPal(s)) return false;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        n = s.size();
        int brute = (1 << n);

        for (int i = 0; i < brute; i++) {
            string str = "";
            vector<string> tmp;
            int cnt = 0;
            for (int j = n - 1; j >= 0; j--) {
                str += s[n - j - 1];
                if (i & (1 << j)) {
                    tmp.push_back(str);
                    cnt += str.size();
                    str = "";
                }
            }
            if (cnt == n && isAllPal(tmp)) ans.push_back(tmp);
        }

        return ans;
    }
};