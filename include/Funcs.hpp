#include <type_traits>
#include <cstring>
#include <cstddef>
#include <array>
typedef unsigned char u8;

template <typename To, typename From>
static inline To BitCast(const From& source) {
    std::aligned_storage_t<sizeof(To), alignof(To)> storage;
    std::memcpy(&storage, &source, sizeof(storage));
    return reinterpret_cast<To&>(storage);
}

template <typename From>
static inline char* ToBytes(const From& source) {
    auto array = BitCast<std::array<u8, sizeof(From)>, From>(source);
    char* ptr = new char[sizeof(From)];
    std::memcpy(ptr, &array, sizeof(From));
    return ptr;
}