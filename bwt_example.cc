#include "bwt.h"

int main(int argc, char *argv[])
{
    std::string *L;
    unsigned int *L_positions;
    std::string reference = "^AGCGCAGACGCAGACTCATACGACTACGTACGTACGTACGTCA|";
    std::tie(L, L_positions) = Bwt::Transform(&reference);
    std::cout << *L << std::endl;
}