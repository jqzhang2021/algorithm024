class Solution {
public:
    //取某一位上的bit
    int getBit(uint32_t n, int index)
    {
        return (n & (1 << index)) >> index;
    }

    uint32_t reverseBits(uint32_t n) 
    {
        uint32_t result = 0;
        for(int i = 0; i < 32; i++)
        {
            result |= (getBit(n, i) << (31 - i));
        }
        return result;
    }
};
