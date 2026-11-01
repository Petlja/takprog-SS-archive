#include <bits/stdc++.h>

using namespace std;

int N, M;
int di[4] = {0, 0, 1, -1};
int dj[4] = {1, -1, 0, 0};
char t[15][15];

int check(int i, int j, int c, int k) {
	int ok = 0;	
	if(!c)
	{
		i += di[k];
		j += dj[k];
	}
	while(i < N && i >= 0 && j < M && j >= 0 && (t[i][j] == '.' || t[i][j] == 'C'))
	{
		if(t[i][j] == 'C')
			return 1;
		i += di[k];
		j += dj[k];
	}
	return ok;
}

int check(int i, int j, int c) {
	int ok = 0;	
	for(int k = 0; k < 4; k++)
		ok = max(ok, check(i, j, c, k));	
	return (ok == c);
}

int count(int pi, int pj)
{
	if(t[pi][pj] == '#')
		return 1;

	int num = t[pi][pj] - '0';
	int i, j;	
	for(int k = 0; k < 4; k++)
	{
		i = pi + di[k];
		j = pj + dj[k];
		if(i < N && i >= 0 && j < M && j >= 0 && t[i][j] == 'C')
			num--;
	}
	//if(num != 0)
	//	cout << pi << " " << pj << endl;
	return (num == 0);
}


int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ifstream ouf(argv[1]);
	ifstream sof(argv[2]);
	ifstream inf(argv[3]);

	{
		int k;
		sof >> k;
		if(k == -1)
		{		
			k = 0;
			ouf >> k;
			
			//cout << k << endl;

			return (k == -1) - 1;
		}	
	}

	inf >> N;
	inf >> M;

	char inC, outC;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			ouf >> outC;
			inf >> inC;
			if((inC != '.' && inC != outC) || (inC == '.' && outC != '.' && outC != 'C'))
				return -1;		
			t[i][j] = outC;
			
			//cout << outC;
		}
		//cout << endl;		
	}
	int ok = 1;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
		{		
			if(t[i][j] == '.' || t[i][j] == 'C')
			{	
				ok *= check(i, j, t[i][j] == '.');
	//			if(check(i, j, t[i][j] == '.') == 0)
	//				cout << i << " " << j << endl;
			}
			else
				ok *= count(i, j);
		}
	//cout << ok << endl;	
	return ok - 1;
}
