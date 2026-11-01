// Two Circles (Pripreme 2017). Petlja's checker for this task (91, eps-check) survives only as a Windows binary, so
// this one was written in 2026 from the statement: the answer is one number R, accepted with an absolute or relative
// error of at most 10^-3.
#include <cmath>
#include <fstream>

int main(int argc, char *argv[])
{
    std::ifstream ouf(argv[1]), sof(argv[2]);
    double out, sol;
    if (!(sof >> sol) || !(ouf >> out) || !std::isfinite(out))
        return 1;
    double err = std::fabs(out - sol);
    return err <= 1e-3 || err <= 1e-3 * std::fabs(sol) ? 0 : 1;
}
