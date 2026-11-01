// Petlja's grader before 2025 read the exit code as a score: < 0 wrong, 0 accepted (score 1), > 0 accepted
// with that score. Today's grader accepts only exit 0 and reads the score from stdout, so main below maps one to the
// other. The checker's own code is unchanged.
#define main legacy_main
#include<bits/stdc++.h>

using namespace std;

const int maxi=2000;
int n,m,k;
int a[maxi][maxi],b[maxi][maxi],c[maxi][maxi];
bool obb[maxi][maxi],obc[maxi][maxi];
bool in_range(int x, int y)
{
    if (x>0 && x<=n && y>0 && y<=m) return 1;
    return 0;
}

void dfs(int a[][maxi], bool ob[][maxi],int x, int y)
{
    if (!in_range(x,y) || a[x][y] || ob[x][y]) return;
    ob[x][y]=1;
    dfs(a,ob,x-1,y);
    dfs(a,ob,x+1,y);
    dfs(a,ob,x,y-1);
    dfs(a,ob,x,y+1);
 return;
}

int main(int argc, char *argv[])
{
    ifstream outFile(argv[1]);
    ifstream solFile(argv[2]);
    ifstream inFile(argv[3]);

   inFile>>n>>m>>k;

   string vrsta;
   for (int i=1;i<=n;i++)
   {
       inFile>>vrsta;

       for (int j=1;j<=m;j++)
        if (vrsta[j-1]=='.') a[i][j]=0; else a[i][j]=1;
   }


   for (int i=1;i<=n;i++)
   {
       solFile>>vrsta;

       for (int j=1;j<=m;j++)
        if (vrsta[j-1]=='.') b[i][j]=0; else
            if (vrsta[j-1]=='x') b[i][j]=1; else
            b[i][j]=2;
   }

   int n1=0;

    while(outFile>>vrsta)
    {
        n1++;
        if (n1>n) return -1;

        if ((int)vrsta.size()!=m) return -1;

        for (int j=1;j<=m;j++)
            if (vrsta[j-1]=='.') c[n1][j]=0; else
                if (vrsta[j-1]=='x') c[n1][j]=1; else
                if(vrsta[j-1]=='o') c[n1][j]=2; else
                return -1;
    }

    inFile.close();
    solFile.close();
    outFile.close();


    if (n1!=n) return -1;


    //provera da li matrica c popunjena na pravi nacin

    int promenjenaPolja=0;
    for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++){
        if (c[i][j]==0 && a[i][j]!=0) return -1;
        if (c[i][j]==1 && a[i][j]!=1) return -1;
        if (c[i][j]==2 && a[i][j]!=0) return -1;
        if (c[i][j]==2) promenjenaPolja++;
    }

    if (promenjenaPolja>k) return -1;

    //matrica je validno popunjena racunanje skora

     int komisijaJezera=0;
     int takmicarJezera=0;

    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
         if (!b[i][j] && !obb[i][j]){
          komisijaJezera++;
          dfs(b,obb,i,j);
         }

    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
         if (!c[i][j] && !obc[i][j]){
          takmicarJezera++;
          dfs(c,obc,i,j);
         }

    double procenat = (1.00*takmicarJezera)/komisijaJezera;

    int bodovi=0;
    if (procenat>1.00)
        bodovi=100;
    else
      bodovi= max(0,100- int((1.00-procenat)*1000));

      if (n==10) return int((1.00*bodovi)/10);
      if (n==100) return int((1.00*bodovi)/5);
      return int((1.00*bodovi)/4);
}

#undef main
#include <cstdio>
int main(int argc, char *argv[])
{
    int r = legacy_main(argc, argv);
    if (r < 0) return 1;
    if (r > 0) printf("%d\n", r);
    return 0;
}
