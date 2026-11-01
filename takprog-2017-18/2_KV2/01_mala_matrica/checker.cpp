 # include <stdio.h>

long long au[2][3], ai[2][3], az[2][3];

int check() {
  int i, j;
  long long si, sz, s1, s2;
  for (i = 0; i < 2; i++)
    for (j = 0; j < 3; j++) {
      if ((au[i][j] != 0) && (au[i][j] != ai[i][j])) return -1;
      if (ai[i][j] <= 0) return -1;
    }
  si = sz = 0;
  for (i = 0; i < 2; i++)
    for (j = 0; j < 3; j++) {
      si += ai[i][j];
      sz += az[i][j];
    }
  if (si != sz) return -1;
  s1 = ai[0][0] + ai[0][1] + ai[1][0] + ai[1][1];
  s2 = ai[0][1] + ai[0][2] + ai[1][1] + ai[1][2];
  if (s1 != s2) return -1;
  return 0;
}

main(int argc, char *argv[]) {
  int r;
  int i, j;
  long long bi, bz;
  FILE *fc1, *fc2, *fc3;
  fc3 = fopen(argv[3], "r");
  for (i = 0; i < 2; i++)
    for (j = 0; j < 3; j++)
      fscanf(fc3, "%lld", &au[i][j]);
  fclose(fc3);
  fc1 = fopen(argv[1], "r");
  if (fc1 == NULL) return -1;
  fc2 = fopen(argv[2], "r");
  fscanf(fc2, "%lld", &bz);
  if (bz == -1) {
  	fscanf(fc1, "%lld", &bi);
  	fclose(fc2);
  	fclose(fc1);
  	if (bi == -1) r = 0;
  	else r = -1;
  	return r;
  } else {
  	for (i = 0; i < 2; i++)
    	for (j = 0; j < 3; j++)
      		fscanf(fc1, "%lld", &ai[i][j]);
  	fclose(fc1);
  	az[0][0] = bz;
    for (j = 1; j < 3; j++)
      fscanf(fc2, "%lld", &az[0][j]);
    for (j = 0; j < 3; j++)
      fscanf(fc2, "%lld", &az[1][j]);
  	fclose(fc2);
  	r = check();
  	return r;
  }
}

  
