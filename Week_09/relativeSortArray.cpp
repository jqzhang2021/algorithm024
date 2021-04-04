class Solution {
public:
     //构建权重表
    static unordered_map<int, int> weightMap;

    static void makeWeightMap(vector<int>& arr2)
    {
        weightMap.clear();
        for(int i = 0; i < arr2.size(); i++)
        {
            weightMap.insert({arr2[i], i});
        }
    }

    static int getWeight(int key)
    {
        if(weightMap.count(key) != 0)
        {
            return weightMap[key];
        }
        return key + 2000;
    }

    static bool cmp(int a, int b)
    {
        return getWeight(a) < getWeight(b);
    }

    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) 
    {
        makeWeightMap(arr2);
        sort(arr1.begin(), arr1.end(), cmp);
        return arr1;
    }
};

unordered_map<int, int> Solution::weightMap;
