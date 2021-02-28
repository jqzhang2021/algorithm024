class Solution {
public:
    void removeValueFromMap(unordered_map<int, int>& map, int value)
    {
        if(map[value] > 0)
        {
            map[value] -= 1;
            if(map[value] == 0)
            {
                map.erase(value);
            }
        }
    }
    void addValueToMap(unordered_map<int, int>& map, int value)
    {
        if(map.count(value) == 0)
        {
            map.insert({value, 1});
        }
        else
        {
            map[value] += 1;
        }
    }
    bool lemonadeChange(vector<int>& bills) 
    {
        unordered_map<int, int> map;
        int size = (int)bills.size();
        for(int i = 0; i < size; i++)
        {
            int value = bills[i];
            if(value == 5)
            {
                addValueToMap(map, 5);
                //cout << "5" << " -- " << map[10] << " -- " << map[5] << endl;
            }
            else if(value == 10)
            {
                if(map[5] < 1)
                {
                    return false;
                }
                removeValueFromMap(map, 5);
                addValueToMap(map, 10);
                //cout << "10" << " -- " << map.count(10) << " -- " << map.count(5) << endl;
            }
            else if(value == 20)
            {
                //cout << "20" << " -- " << map.count(10) << " -- " << map.count(5) << endl;
                if(map[10] == 0 && map[5] < 3)
                {
                    return false;
                }
                if(map[10] > 0 && map[5] < 1)
                {
                    return false;
                }
                if(map[10] > 0)
                {
                    removeValueFromMap(map, 10);
                    removeValueFromMap(map, 5);
                }
                else
                {
                    removeValueFromMap(map, 5);
                    removeValueFromMap(map, 5);
                    removeValueFromMap(map, 5);
                }
                addValueToMap(map, 20);
            }
        }
        return true;
    }
};
