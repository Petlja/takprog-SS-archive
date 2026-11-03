#include<iostream>
#include<fstream>

using namespace std;

int main(){
    string primer = "00";

    ifstream inf(primer + ".in");
    ofstream ouf(primer + ".out");

    int n,m;

    inf >> n >> m;

    cerr << "Matrica je dimenzije " << n << " * " << m << endl;

    ouf << "3" << endl;
    ouf << "5" << endl;
    ouf << "2" << endl;
    ouf << "2 4" << endl;
    ouf << "2 5" << endl;
    ouf << "2" << endl;
    ouf << "2 3" << endl;
    ouf << "2 4" << endl;
    ouf << "1" << endl;
    ouf << "2 1" << endl;
    ouf << "3" << endl;
    ouf << "2 3" << endl;
    ouf << "2 4" << endl;
    ouf << "3 4" << endl;
    ouf << "2" << endl;
    ouf << "2 2" << endl;
    ouf << "1 4" << endl;

    inf.close();
    ouf.close();

    return 0;
}
