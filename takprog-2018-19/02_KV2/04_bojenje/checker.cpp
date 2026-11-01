// Bojenje (Kvalifikacije 2, 2018-19). Petlja's checker for this task (240) survives with an empty source, so this one
// was written in 2026: the answer is a single integer, compared with the official one, as the round's other checkers
// compare their single values (Vrednost dodele).
#include <fstream>
#include <string>

int main(int argc, char *argv[])
{
    std::ifstream ouf(argv[1]), sof(argv[2]);
    std::string out, sol;
    sof >> sol;
    ouf >> out;
    return out == sol ? 0 : 1;
}
