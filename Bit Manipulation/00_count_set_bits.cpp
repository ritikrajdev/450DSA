// Naive
class Solution {
  public:
    int setBits(int N) {
        int c = 0;
        do {
            if (N&1) c++;
        } while (N = N>>1);
        return c;
    }
};


// Brian Kernighan's Algorithm: 
// Subtracting 1 from a decimal number flips all the bits after the rightmost set bit(which is 1) including the rightmost set bit. 
// for example : 
// 10 in binary is 00001010 
// 9 in binary is 00001001 
// 8 in binary is 00001000 
// 7 in binary is 00000111

class Solution {
  public:
    int setBits(int N) {
        int c = 0;
        while (N)
            N = N&(N-1), c++;
        return c;
    }
};
// Time Complexity -> O(set_bits) || O(log n)



// Bitmap O(1)
// Creating a map by dividing int in 4 parts 8 bits each part
class Solution {
  public:
    static int bitmap[256];
    static int created_bitmap;
    
    Solution() {
        if (!created_bitmap) {
            bitmap[0] = 0;
            for (int i = 1; i < 256; i++) 
                bitmap[i] = (i & 1) + bitmap[i / 2];
            created_bitmap = true;
        }
    }
    
    int mapAnd256(int n) {
	// Donno why this n & 256 is not working but n & 0xff works.
        return bitmap[n & 0xff];
    }

    int setBits(int n) {
        return  mapAnd256(n)+
        mapAnd256(n >> 8)+
        mapAnd256(n >> 16)+
        mapAnd256(n>>24);
    }
};

int Solution::created_bitmap = false;
int Solution::bitmap[256] = {0};


// C++ inbuilt function
// __builtin_popcount(n)
