class Solution {
public:
    unordered_map<int, int> n2i;
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        for (int i = 0; i < arr2.size(); ++i) n2i[arr2[i]] = i + 10;
        sort(arr1.begin(), arr1.end(), [this](int a, int b) {
            if (n2i[a] == n2i[b]) return a < b;
            if (n2i[a] == 0) return false;
            if (n2i[b] == 0) return true;
            return n2i[a] < n2i[b];
        });

        return arr1; 
    }
};