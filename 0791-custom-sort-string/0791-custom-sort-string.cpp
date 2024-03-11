class Solution {
public:
    unordered_map<char, int> map;
    string customSortString(string order, string s) {
    auto comp = [this](char a, char b) {
        int left = map.find(a) != map.end() ? map[a] : -1;
        int right = map.find(b) != map.end() ? map[b] : -1;

        return left < right;
    };
        vector<char> ans;

        for (int i = 0; i < order.length(); i++) {
            char c = order[i];
            map[c] = order.length() - i;
        }

        priority_queue<char, vector<char>, decltype(comp)> q(comp);

        for (auto c : s) {
            q.push(c);
        }

        while (!q.empty()) {
            ans.push_back(q.top());
            q.pop();
        }

        return string(ans.begin(), ans.end());
    }
};