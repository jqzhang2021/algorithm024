class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int arr[26] = {0};
        int size = s.size();
        for(int i = 0; i < size; i++)
        {
            arr[s[i] - 'a'] += 1;
            arr[t[i] - 'a'] -= 1;
        }
        for(auto& i : arr)
        {
            if(i > 0) return false;
        }
        return true;
    }
};
