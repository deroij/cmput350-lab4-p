#include <cassert>  // assert
#include <cstddef>  // size_t
#include <cstdint>  // uint64_t, uint32_t

// Expands the binary representation of input by a factor of scale.
// e.g., expand(0b1111ull, 3) == 0b001001001001
uint64_t expand(uint64_t input, uint32_t scale) {
    assert(scale >= 1);

    uint64_t result = 0;

    for (uint32_t i = 0; i < 64; ++i) {
        uint64_t position = static_cast<uint64_t>(i) * scale;

        if (position >= 64) {
            break;
        }

        uint64_t bit = (input >> i) & 1;
        result |= bit << position;
    }

    return result;
}

int main() {
    // test here...
    // Known cases
    assert(expand(0b1111ull, 3) == 0b001001001001ull);
    assert(expand(0b0101ull, 2) == 0b00010001ull);

    // No change
    assert(expand(0b101101ull, 1) == 0b101101ull);

    // Expand 0 is also 0
    assert(expand(0, 5) == 0);

    // Cuts off the end
    assert(expand(0b111ull, 40) == ((uint64_t{1} << 40) | 1));

    return 0;
}
