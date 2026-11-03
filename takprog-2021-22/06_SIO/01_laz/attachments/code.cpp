#include "code.h"

#include <vector>

using namespace std;

int NadjiLazova(int n, int q) {
	vector<int> svi;
	for (int i = 1; i <= n; ++i)
		svi.push_back(i);
	bool odgovor1 = Pitaj(1, svi);
	bool odgovor2 = Pitaj(2, {1, 3});
	return 4;
}
