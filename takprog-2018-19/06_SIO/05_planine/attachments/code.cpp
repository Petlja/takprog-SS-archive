#include "code.h"

std::vector<int> Nadji(int N, int K) 
{
	// neka slucajna pitanja
	int x = Pitaj(2, 1);
	int y = Pitaj(2, 3);
	int z = Pitaj(3, 3);
	
	// primer kada hocemo da vratimo (2, 3)
	std::vector<int> out;
	out.push_back(2);
	out.push_back(3);
	return out;
}
