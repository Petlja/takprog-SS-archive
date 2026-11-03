#include <iostream>

long long Prodaja(int N, int K, int *A);

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, K; std::cin >> N >> K;
    int *A = new int[N + 1];

    for (int i = 1; i <= N; i++) {
        std::cin >> A[i];
    }

    long long ans = Prodaja(N, K, A);

    std::cout << ans << std::endl;

    delete[] A;
    return 0;
}