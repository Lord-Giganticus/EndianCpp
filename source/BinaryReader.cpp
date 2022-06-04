#include <BinaryReader.hpp>
#include <Funcs.hpp>
using namespace std;

template <typename T>
T BinaryReader::Read() {
    char* ptr = ReadBytes(sizeof(T));
    stream->read(ptr, sizeof(T));
    return BitCast<T, char*>(ptr);
}

std::string BinaryReader::ReadString(size_t size) {
    return {ReadBytes(size), size};
}