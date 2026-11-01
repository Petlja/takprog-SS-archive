#include <cstdio>

#define OK 0
#define WA -1

int main(int argc, char *argv[]) {
    FILE *out = fopen(argv[1], "r");
    FILE *in = fopen(argv[3], "r");

    if(in == NULL || out == NULL)
		return WA;

    int n, q;

    fscanf(in, "%d %d", &n, &q);

    char *s = new char[n + 2];

    fscanf(in, " %s", s + 1);

    bool imaLazova = false;
    for (int i = 1; i <= n; ++i)
		if (s[i] == '1')
			imaLazova = true;

    int lazov;
    if(fscanf(out, "%d", &lazov) != 1)
		return WA;

    if (lazov < -1 || lazov == 0 || lazov > n)
		return WA;

	if (lazov == -1) {
		if (imaLazova)
			return WA;
		else
			return OK;
	} else {
		if (s[lazov] == '1')
			return OK;
		else
			return WA;
	}
}
