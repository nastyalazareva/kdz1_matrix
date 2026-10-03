#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>


struct Naive{
    bool a;
    std::uint64_t b;
    std::uint32_t c;
    char d;
    std::uint64_t e;
};

struct Packed{
    std::uint64_t b;
    std::uint64_t e;
    std::uint32_t c;
    char d;
    bool a;
};

#pragma pack(push, 1)
struct Forced{
    bool a;
    std::uint64_t b;
    std::uint32_t c;
    char d;
    std::uint64_t e;
};
#pragma pack(pop)

static_assert(sizeof(Naive) == 32, "Naive wrong");
static_assert(sizeof(Packed) == 24, "Packed wrong");
static_assert(sizeof(Forced) == 22, "Forced wrong");

std::uint64_t sNaive(std::vector<Naive>& sp);
std::uint64_t sPacked(std::vector<Packed>& v);
std::uint64_t sForced(std::vector<Forced>& v);