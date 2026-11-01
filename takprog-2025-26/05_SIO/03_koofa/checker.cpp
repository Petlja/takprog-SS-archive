#include<bits/stdc++.h>

#define maxN 3503
#define maxM 3503

using namespace std;

const int MAX_SIZE = 50'000'000;
bitset<MAX_SIZE> bs;

int rpos = 0;

int readBit() {
    if(rpos%8==0)
        rpos++;
    return bs[rpos++] ? 1 : 0;
}
int read20Bit() {
    int x = 0;
    for (int i = 0; i < 20; i++) {
        x = (x << 1) | readBit();
    }
    return x;
}

// This function reads the binary file and fills the bitset
void loadBitsetFromFile(ifstream& inf) {
    bs.reset();
    rpos = 0;

    unsigned char prva4bajta[4];
    inf.read(reinterpret_cast<char*>(prva4bajta), sizeof(prva4bajta));

    uint32_t readNum = (((int)prva4bajta[0]) << 24) | 
                    (((int)prva4bajta[1]) << 16) | 
                    (((int)prva4bajta[2]) <<  8) | 
                    prva4bajta[3];

    uint32_t bitCount = 0;
    for (int i = 30; i >= 0; i--) {
        if (i % 8 == 7) {
            continue; 
        }
        bitCount <<= 1;
        bitCount |= ((readNum & (1U << i)) ? 1 : 0);
    }


    vector<unsigned char> bytes((bitCount + 7) / 8, 0);
    inf.read(reinterpret_cast<char*>(bytes.data()), bytes.size());

    for (uint32_t i = 0; i < bitCount; i++) {
        int bit = (bytes[i / 8] >> (7 - (i % 8))) & 1;
        bs[i] = bit;
    }
}



int MAX_TOTAL_SIZE;

int n, m, tip[maxN][maxN];

int opt;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool unutra(int x, int y){
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

bool jeVoda(int x, int y){
    if (!unutra(x,y))
        return false;
    return tip[x][y] == 2;
}

int prebrojVodu(int x, int y){
    int r=0;
    for(int i = 0; i < 4; i++)
        r+=jeVoda(x+dx[i],y+dy[i]);
    return r;
}

void propagirajVodu(int x, int y){
    if (!unutra(x,y))
        return;
    
    if(tip[x][y] != 0)
        return;
    
    if(prebrojVodu(x,y) < 2)
        return;
    
    tip[x][y] = 2;
    for(int i=0;i<4;i++)
        propagirajVodu(x+dx[i],y+dy[i]);
}

int main(int argc, char* argv[])
{
	ifstream outFile(argv[1], ios::binary); // Participant answer
	ifstream solFile(argv[2]); // .out file
	ifstream inFile(argv[3]);  // .in file

	inFile >> n >> m;

    MAX_TOTAL_SIZE = n*m;

	for (int i = 1; i <= n; i++) {
		string a;
        inFile >> a;
        for(int j=1;j<=m;j++)
            if(a[j-1]=='0')
                tip[i][j]=2;
            else
                tip[i][j]=1;
	}

 //   cerr << n << " " << m << endl;

	solFile >> opt;

    loadBitsetFromFile(outFile);
    
    int K;

    K = read20Bit();

    /// Losa vrednost K
	if (K < 0 || K > n*m) {
        cerr<<"BAD K = " << K<<endl;
        return -1; // mora ovako jer kad vratis 0 petlja ispise 1
	}

    int Q;

	Q = read20Bit();


    /// Los broj operacija
	if (Q < 0 || Q > MAX_TOTAL_SIZE) {
        cerr<<"BAD Q = " << Q <<endl;
        return -1; // mora ovako jer kad vratis 0 petlja ispise 1
	}

	int totalBlockSize = 0;

	for (int i = 0; i < Q; i++) {
		int blockSize;
        blockSize = read20Bit();

        /// Los broj polja u operaciji
        if(blockSize <= 0 || blockSize > K){
            cerr<<"BAD block size = " << blockSize<<endl;
            return -1;
        }

		totalBlockSize += blockSize;

        /// Ukupna velicina svih operacija je prevelika
        if(totalBlockSize > MAX_TOTAL_SIZE){
            cerr<<"TOTAL SIZE EXCEEDED"<<endl;
            return -1;
        }
        
        vector<pair<int,int>> izabranaPolja;


        for(int it = 1; it <= blockSize; it++){
            int cellId = read20Bit();
            int x = cellId / 1000 + 1;
            int y = cellId % 1000 + 1;

            /// Dato polje nije unutar matrice 
            if(!unutra(x,y)){
                cerr<<"OUTSIDE OF MATRIX "<<x<<" "<<y<<endl;
                return -1;
            }

            /// Izabrano je zid polje za sklanjanje vode
            if(tip[x][y] == 1){
                cerr<<"WALL "<<x<<" "<<y<<endl;
                return -1;
            }

            izabranaPolja.push_back({x,y});
        }

        for(auto polje:izabranaPolja){
            tip[polje.first][polje.second] = 0;
        }

        for(auto polje:izabranaPolja){
            propagirajVodu(polje.first,polje.second);
        }
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			/// Nije sklonjena sva voda iz matrice
            if(tip[i][j] == 2){
                return -1;
            }
		}
	}
    //cerr<<opt<<" "<<K<<endl;
    int skor = min(10, (int)floor(1+9*opt/(double)K+1e-6));
	cerr<<"CORRECT, SCORE IS "<<skor<<endl;
    cout<<skor<<endl;
    return 0;
}
