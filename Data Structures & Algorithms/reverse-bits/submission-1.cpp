class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; i++) {
            // Extract each bit from the original number starting from the least significant bit
            uint32_t bit = (n >> i) & 1;
            // Place that bit into the correct reversed position in the result
            res += (bit << (31 - i));
        }
        return res;
    }
};