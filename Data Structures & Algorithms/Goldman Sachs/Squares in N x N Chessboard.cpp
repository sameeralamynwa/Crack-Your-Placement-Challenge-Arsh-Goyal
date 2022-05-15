class Solution {
  public:
    long long squaresInChessBoard(int n) {
        return (long long) n * (n + 1) * (2 * n + 1) / 6;
    }
};
