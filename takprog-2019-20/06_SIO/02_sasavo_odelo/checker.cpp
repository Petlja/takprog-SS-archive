#include<bits/stdc++.h>
#define MAXN 1000007
using namespace std;
int n,cnt[MAXN],c[MAXN],u[MAXN],v[MAXN];
int main(int argc, char *argv[])
{
    FILE* fout = fopen(argv[1], "r"); //Takmicarev output
	FILE* fsol = fopen(argv[2], "r"); //Komisijski output
	FILE* fin = fopen(argv[3], "r"); //Input
	fscanf(fin, "%d", &n);
	for(int i=0;i<n-1;i++) fscanf(fin,"%d %d",&u[i],&v[i]);
	fclose(fin);
	int o1=0;
	fscanf(fsol,"%d",&o1);
    if(o1==-1) { //Komisija nije nasla resenje
        for(int i=1;i<=n;i++) {
            fscanf(fout,"%d",&cnt[i]);
            if(cnt[i]!=-1) return -1; //Takmicar ispisuje neko resenje
        }
        fclose(fsol);
        fclose(fout);
        return 0; //Ni takmicar nije nasao resenje
     }
    fclose(fsol);
	for(int i=1;i<=n;i++) {
        fscanf(fout,"%d",&cnt[i]);
        if(cnt[i]<=0) return -1; //Takmicar ispisuje nevalidno resenje, ili tvrdi da resenje ne postoji
        c[i]=cnt[i];
	}
    for(int i=0;i<n-1;i++) if(c[u[i]]!=c[v[i]]) {
        cnt[u[i]]--;
        cnt[v[i]]--;
    }
    fclose(fout);
    for(int i=1;i<=n;i++) if(cnt[i]!=0) return -1;//nevalidno bojenje
	return 0; //Trkmicar ispisuje tacno resenje
}
