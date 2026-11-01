# include <stdio.h>

# define MAXN 30030
# define MAXM 1001000

long long ps[MAXN];
int x[MAXN];
int p[MAXM], q[MAXM], z[MAXM];
int t, s, n, m;

int check(char *fn1, char *fn2, char *fn3) {
  int i, j, k;
  int rt, rz;
  int pp, qq, zz, tz;
  FILE *fc1, *fc2, *fc3;
  fc1 = fopen(fn1, "r");
  if (fc1 == NULL) return -1;  
  fc2 = fopen(fn2, "r");  
  fc3 = fopen(fn3, "r");  
  fscanf(fc3, "%d", &t);
  for (s = 1; s <= t; s++) {
  	fscanf(fc3, "%d%d", &n, &m);
  	for (i = 1; i <= m; i++)
  	  fscanf(fc3, "%d%d%d", &p[i], &q[i], &z[i]);
    fscanf(fc2, "%d", &rz);
    if (rz < 0) {
  	  fscanf(fc1, "%d", &rt);
  	  if (rt >= 0) 
	    return -1;
  	  else
  	    continue;
    } else {
  	  for (i = 1; i <= n; i++)
  	    fscanf(fc2, "%d", &tz);
  	  fscanf(fc1, "%d", &rt);
      if (rt < 0) return -1;
	  ps[0] = 0;
	  for (i = 1; i <= n; i++) {
	  	fscanf(fc1, "%d", &x[i]);
		ps[i] = ps[i-1] + x[i];
	  }    	  
	  for (i = 1; i <= m; i++) {
		pp = p[i];
		qq = q[i];
		zz = z[i];
		if ((ps[qq] - ps[pp-1]) * zz <= 0) return -1;
	  }
    }
  }
  fclose(fc1);
  fclose(fc2);
  fclose(fc3);
  return 0;
}

main(int argc, char *argv[]) {
  int r;
  int i, j;
  long long bi, bz;
  FILE *fc1, *fc2, *fc3;
  r = check(argv[1], argv[2], argv[3]);
//  printf("%d\n", r);
  return r;
}
