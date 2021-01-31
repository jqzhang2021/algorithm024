#include <vector>

using std::vector;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        int start = digits.size() - 1;
        for (int i = start; i >= 0; i--)
        {
            carry = (digits[i] + 1) / 10;
            digits[i] = (digits[i] + 1) % 10;
            if (carry == 0)
            {
                break;
            }
        }
        if (carry > 0)
        {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};
