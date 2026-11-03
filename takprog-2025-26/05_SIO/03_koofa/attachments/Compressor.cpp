#include<bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 50'000'000;
bitset<MAX_SIZE> bs;

int pos=0;
void writeBit(int b){
    if(pos%8==0){
        bs[pos]=0;
        pos++;
    }
    if(b!=0)
        bs[pos]=1;
    else
        bs[pos]=0;
    pos++;
}
void writeAs28Bit(int x){
    for(int i=27;i>=0;i--)
        writeBit(x&(1<<i));
}
void writeAs20Bit(int x){
    for(int i=19;i>=0;i--)
        writeBit(x&(1<<i));
}

void saveBitsetToFile(std::bitset<MAX_SIZE>& bs, int bitCount, const std::string& outName) {
    std::ofstream out(outName, std::ios::binary |  ios::trunc);
    if (!out) {
        std::cerr << "Ne mogu da otvorim izlazni fajl.\n";
        return;
    }

    std::uint32_t n = static_cast<std::uint32_t>(bitCount);
    pos=0;
    bs<<=32;
    writeAs28Bit(n);
    bitCount+=32;

    std::vector<unsigned char> bytes((bitCount + 7) / 8, 0);

    for (int i = 0; i < bitCount; ++i) {
        if (bs[i]) {
            bytes[i / 8] |= static_cast<unsigned char>(1u << (7 - (i % 8)));
        }
    }

    out.write(reinterpret_cast<const char*>(bytes.data()), bytes.size());
}

int main(){
    string fileName;
    cout<<"Ime fajla koji zelite da kompresujete:"<<endl;
    cin>>fileName;

    ifstream inf(fileName);

    if(!inf.is_open()){
        cout<<"Ne mogu da otvorim fajl. Proverite da li je ime fajla dobro zadato."<<endl;
        return 1;
    }

    int K, Q;
    inf>>K;

    if(K<1 or K>1'000'000){
        cout<<"Greska! Vrednost K mora biti izmedju 1 i 1000000"<<endl;
        return 1;
    }

    inf>>Q;

    if(Q<0 or Q>1'000'000){
        cout<<"Greska! Vrednost Q mora biti izmedju 0 i 1000000"<<endl;
        return 1;
    }

    writeAs20Bit(K);
    writeAs20Bit(Q);

    int sumaL = 0;

    for(int i=1;i<=Q;i++){
        int l;
        inf>>l;
        if(l<1 or l>K){
            cout<<"Greska! Vrednost l mora biti izmedju 1 i K ("<<K<<")"<<endl;
            return 1;
        }

        sumaL += l;
        if(sumaL > 1'000'000){
            cout<<"Greska! Suma svih vrednosti l ne sme biti veca od 1000000"<<endl;
            return 1;
        }

        writeAs20Bit(l);

        for(int j=1;j<=l;j++){
            int x,y;
            inf>>x>>y;
            if(x<1 or x>1000){
                cout<<"Greska! Vrednost x mora biti izmedju 1 i 1000"<<endl;
                return 1;
            }
            if(y<1 or y>1000){
                cout<<"Greska! Vrednost y mora biti izmedju 1 i 1000"<<endl;
                return 1;
            }

            int cellId = (x-1)*1000 + y-1;
            writeAs20Bit(cellId);
        }
    }
    inf.close();
    cout<<"Fajl uspesno ucitan. Zapocinjem kompresiju."<<endl;

    const string outputFile = fileName + "_compressed.txt";

    saveBitsetToFile(bs,pos,outputFile);

    cout<<"Sacuvan kompresovani fajl u "<<outputFile<<endl;

}
