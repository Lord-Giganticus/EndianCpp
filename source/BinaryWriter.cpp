#include <BinaryWriter.hpp>
#include <Funcs.hpp>
using namespace std;

template <typename T>
void BinaryWriter::Write(T source) {
    char* ptr = ToBytes(source);
    stream->write(ptr, sizeof(T));
    delete ptr;
}

void BinaryWriter::WriteString(std::string str) {
    char* ptr = (char*)str.c_str();
    stream->write(ptr, str.size());
    delete ptr;
}