# bwt

**The Burrows–Wheeler transform in 50 lines of readable C++.**

The BWT is the index behind short-read aligners such as BWA and Bowtie. This header-only version is written for understanding: it sorts pointers to every rotation of the input, then reads off the last column `L` and the position each rotation started at (the suffix array). [RAMICS](https://doi.org/10.1093/nar/gku473) uses a speed-optimised variant of the same idea.

## Try it

```
g++ -std=c++11 bwt_example.cc -o bwt_example
./bwt_example
```

```
45
TGTTTTGGCC^CCGGTTAGAAAAAAAACACCACCCCACGGGCG|A
```

The first line is the input length; the second is the transform of `^AGCGCAGACGCAGACTCATACGACTACGTACGTACGTACGTCA|`. Runs of identical characters, like the eight `A`s, are what make the transformed string so compressible and so fast to search.

## Use it

```cpp
#include "bwt.h"

std::string text = "^BANANA|";
std::string *L;            // last column of the sorted rotations
unsigned int *positions;   // start offset of each rotation
std::tie(L, positions) = Bwt::Transform(&text);
```

Licensed under GPL v3.
