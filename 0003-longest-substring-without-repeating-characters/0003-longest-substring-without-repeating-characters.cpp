class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int len = s.length();

        for (auto c : s) {
            set.insert(c);
        }

        int ws = set.size();

        for (; ws > 0; ws--) {
            unordered_map<char, int> map;
            for (int i = 0; i < ws - 1; i++) {
                map.find(s[i]) != map.end() ? map[s[i]]++ : map[s[i]] = 1;
            }

            for (int b = 0, e = ws - 1; e < len; b++, e++) {
                if (map.find(s[e]) != map.end())
                    map[s[e]]++;
                else
                    map[s[e]] = 1;

                int sum = 0;
                for (auto kv : map) {
                    int val = get<1>(kv);
                    if (val == 1) sum++;
                }

                if (ws == sum)
                    return ws;

                map[s[b]]--;
                if (map[s[b]] == 0)
                    map.erase(s[b]);
            }
        }

        return 0;
    }
};