#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool has_extra_tokens(ifstream& ifs) {
	string s;
	ifs >> s;
	return s.size() != 0;
}

int main(int argc, char** argv) {
	ifstream ouf(argv[1]);
	ifstream sof(argv[2]);
	ifstream inf(argv[3]);
	
	int tacno, takmicar;
	sof >> tacno;
	ouf >> takmicar;
	if(has_extra_tokens(ouf) || tacno != takmicar)
		return -1;
	return 0;
}
