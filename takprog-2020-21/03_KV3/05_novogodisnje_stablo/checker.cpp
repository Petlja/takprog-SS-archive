#include<bits/stdc++.h>
using namespace std;
int n,q;
int main(int argc, char *argv[])
{
    FILE* fout = fopen(argv[1], "r");
	FILE* fsol = fopen(argv[2], "r");
	FILE* fin = fopen(argv[3], "r");
	if(fin==NULL || fsol==NULL || fout==NULL) {
		return -1;
	}
	fscanf(fin, "%d %d", &n,&q);
	for(int i=0;i<q;i++) {
		int k,t;
		if(feof(fout) || feof(fsol)) return -1;
		fscanf(fsol,"%d",&k);
		fscanf(fout,"%d",&t);
		if(k!=t) return -1;
	} 
	return 0;
}
