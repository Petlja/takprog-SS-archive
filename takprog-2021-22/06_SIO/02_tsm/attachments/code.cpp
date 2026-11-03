#include <vector>
vector<int> NadjiPoredak(int N, int M, int* X, int* Y, int* W) {
  vector<int> sol;
  for(int i = 1; i <= N; i++) {
    sol.push_back(W[i]);
  }
  return sol;
}
