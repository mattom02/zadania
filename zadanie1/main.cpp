#include "compress.hpp"

int main() {
    Array2D<int> array = {{
        {0, 0, 0, 1, 1, 2, 3},
        {0, 0, 4, 4, 4, 2, 2},
        {2, 2, 2, 2, 2, 1, 2}
    }};

    CompressedData<int> compressedData = compressData(array);

    for(const auto& i : compressedData.value()){
        std::cout << "{" << i.value << "," << i.count << "}\n";
    }
    return 0;
}
