class Solution {
  public:
    int findPosition(int n , int m , int k) {
        return 1 + (--k + --m) % n;
    }
};
