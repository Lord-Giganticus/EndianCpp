#include <type_traits>
#include <cstring>
#include <cstddef>
#include <fstream>

class BinaryWriter {
    private:
    std::ofstream* stream;
    public:
    ~BinaryWriter() {
        if (stream->is_open()) {
            stream->close();
        }
        delete stream;
    }
    BinaryWriter(std::ofstream* arg) {
        stream = arg;
    }
    void Seek(size_t pos, std::ios_base::seekdir dir) {
        stream->seekp(pos, dir);
    }
    template <typename T>
    void Write(T source);
    void WriteString(std::string str);
};