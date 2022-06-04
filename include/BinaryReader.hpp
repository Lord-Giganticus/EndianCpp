#include <type_traits>
#include <cstring>
#include <cstddef>
#include <fstream>

class BinaryReader {
    private:
    std::ifstream* stream;
    public:
    ~BinaryReader() {
        if (stream->is_open()) {
            stream->close();
        }
        delete stream;
    }
    BinaryReader(std::ifstream* arg) {
        stream = arg;
    }
    void Seek(size_t pos, std::ios_base::seekdir dir) {
        stream->seekg(pos, dir);
    }
    template <typename T>
    T Read();
    char* ReadBytes(size_t size) {
        char* ptr = new char[size];
        stream->read(ptr, size);
        return ptr;
    }
    std::string ReadString(size_t size);
};