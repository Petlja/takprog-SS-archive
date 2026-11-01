#include <bits/stdc++.h>
using namespace std;

const int SIZE_LIMIT = 30000;

enum tip_cvora {MIN, MAX, VAR} ;

struct node {
	tip_cvora tip;
	node* left;
	node* right;
	int var;
};

string s;
size_t i;
int n, k;

int a[20];

node* parse() {
	if (i >= s.size()) {
		return nullptr;
	}

	char c = s[i++];

	if (c == '[' || c == '(') {
		node* t = new node;
		t->tip = (c == '[' ? MAX : MIN);
		t->var = 0;
		
		// leva strana
		t->left = parse();
		if (!t->left) {
			return nullptr;
		}

		// preskacemo zarez
		if (s[i++] != ',') {
			return nullptr;
		}

		// desna strana
		t->right = parse();
		if (!t->right) {
			return nullptr;
		}

		// sparena zagrada
		if (s[i++] != (c == '[' ? ']' : ')')) {
			return nullptr;
		}

		// ok
		return t;
	}

	if ('a' <= c && c < 'a' + n) {
		node* t = new node;
		t->tip = VAR;
		t->left = nullptr;
		t->right = nullptr;
		t->var = c - 'a';
		return t;
	}

	return nullptr;
}

int eval(node* p) {
	if (p->tip == VAR) {
		return a[p->var];
	}
	if (p->tip == MIN) {
		return min(eval(p->left), eval(p->right));
	} else {
		return max(eval(p->left), eval(p->right));
	}
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ifstream outf(argv[1]);
	ifstream solf(argv[2]);
	ifstream inf(argv[3]);

	inf >> n >> k;
	k--;

	outf >> s;

	if (s.size() > SIZE_LIMIT) {
		// predugacak string
		return -1;
	}

	i = 0;

	auto p = parse();

	if (i != s.size()) {
		// ima visak
		return -1;
	}

	if (p == nullptr) {
		return -1;
	}

	// evaluiraj
	for (int i=0; i<n; i++) {
		if (i < k) {
			a[i] = 0;
		} else if (i == k) {
			a[i] = 1;
		} else {
			a[i] = 2;
		}
	}

	do {
		if (eval(p) != 1) {
			return -1;
		}
	} while (next_permutation(a, a+n));

	// ok
	return 0;
}
