#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

const int P = 250000;
bool is_prime[P];

void gen_primes()
{
	for(int i = 2; i < P; i++)
		is_prime[i] = true;
	for(int i = 2; i < P; i++)
		if(is_prime[i])
			for(int j = 2 * i; j < P; j += i)
				is_prime[j] = false;
}

int main(int argc, char *argv[])
{
	ifstream outFile(argv[1]);
	ifstream solFile(argv[2]);
	ifstream inFile(argv[3]); 

	int n;
	inFile >> n;

	std::vector<int> a(n);
	for(int i = 0; i < n; i++)
	  inFile >> a[i];

	// ucitavamo da li resenje postoji
	int first_sol;
	solFile >> first_sol;
	bool sol_exists = first_sol != -1;

	// ucitavanje takmicarskog resenja
	if(!sol_exists)
		{
			if(outFile.eof()) return -1; // nema niceg na ulazu
			int first;
			outFile >> first;
			
			if(first == -1) return 0; // nema resenja 
			else return -1; // nasao resenje gde ga nema
		}
	
	std::vector<int> b(n);
	for(int i = 0; i < n; i++)
		if(!outFile.eof())
			outFile >> b[i];
		else
			return -1; // nedovoljno brojeva na izlazu
	
	for(int i = 0; i < n; i++)
		if(b[i] <= 0 || a[i] % b[i] != 0)
			return -1; // nije ravnomerno podeljeno

	gen_primes();
	
	for(int i = 0; i < n; i++)
		if(!is_prime[b[i]])
			return -1; // slozen broj

	vector<int> c(n);
	for(int i = 0; i < n; i++)
		c[i] = a[i] / b[i];

	sort(c.begin(), c.end());
	for(int i = 0; i < n - 1; i++)
		if(c[i] == c[i + 1])
			return -1; // iste nagrade

	outFile.close();
	solFile.close();
	inFile.close();

	return 0; // dobar rezultat i kraj
}
