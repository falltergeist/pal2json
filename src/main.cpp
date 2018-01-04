/*
 * Copyright (c) 2015-2018 Falltergeist developers
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

// C++ standard includes
#include <algorithm>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <string>

// pal2json includes

// Third party includes

uint32_t readUINT32(std::ifstream& stream)
{
    uint32_t value;
    auto buff = reinterpret_cast<char*>(&value);
    stream.read(buff, 4);
    std::reverse(buff, buff + 4);
    return value;
}

int32_t readINT32(std::ifstream& stream)
{
    return readUINT32(stream);
}

uint8_t readUINT8(std::ifstream& stream)
{
    uint8_t value;
    auto buff = reinterpret_cast<char*>(&value);
    stream.read(buff, 1);
    return value;
}

void usage(const std::string& binaryName)
{
    std::cout << "PAL to JSON converter v0.0.2" << std::endl;
    std::cout << "Copyright (c) 2015-2018 Falltergeist developers" << std::endl;
    std::cout << "Usage: " << binaryName << " <PAL filename>" << std::endl;
}

int main(int argc, char** argv)
{
    if (argc != 2) {
        usage(argv[0]);
        return 1;
    }

    std::string filename = argv[1];
    std::ifstream in;

    in.open(filename.c_str(), std::ios_base::binary | std::ios_base::in);
    if (!in.is_open()) {
        std::cout << "Can't open file: " << filename << std::endl;
        usage(argv[0]);
        return 1;
    }

    std::cout << "{" << std::endl;
    std::cout << "    \"indexes\": [" << std::endl;

    for (unsigned i = 0; i != 256; i++) {
        uint8_t red = readUINT8(in);
        uint8_t green = readUINT8(in);
        uint8_t blue = readUINT8(in);

        std::cout << "        {" << std::endl;
        std::cout << "            \"red\": "   << (unsigned int) red   << "," << std::endl;
        std::cout << "            \"green\": " << (unsigned int) green << "," << std::endl;
        std::cout << "            \"blue\": "  << (unsigned int) blue  << std::endl;
        std::cout << "        }" << ( i != 255 ? "," : "") << std::endl;
    }

    std::cout << "    ]" << std::endl;
    std::cout << "}" << std::endl;

    in.close();
    return 0;
}
