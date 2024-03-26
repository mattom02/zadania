#include "gtest/gtest.h"
#include "compress.hpp"

template<typename T> std::string result(const CompressedData<T>& compressedData){
    std::stringstream str;
    for(const auto& i : compressedData.value()){
        str << "{" << i.value << "," << i.count << "}\n";
    }
    return str.str();
}

TEST(compressDataTest1, isCorrect){
    Array2D<int> array = {{
        {0, 0, 0, 1, 1, 2, 3},
        {0, 0, 4, 4, 4, 2, 2},
        {2, 2, 2, 2, 2, 1, 2}
    }};

    CompressedData<int> compressedData = compressData(array);

    std::string str = "{0,3}\n{1,2}\n{2,1}\n{3,1}\n{0,2}\n{4,3}\n{2,2}\n{2,5}\n{1,1}\n{2,1}\n";

    EXPECT_EQ(result(compressedData), str);
}

TEST(compressDataTest, isCorrect2){
    Array2D<char> array = {{
        {'a', 'a', 'c', 'c', 'd'},
        {'+', '-', 'e', '4', '4'},
        {',', ',', ',', ',', ','}
    }};

    CompressedData<char> compressedData = compressData(array);

    std::string str = "{a,2}\n{c,2}\n{d,1}\n{+,1}\n{-,1}\n{e,1}\n{4,2}\n{,,5}\n";

    EXPECT_EQ(result(compressedData), str);
}

TEST(compressDataTest, isCorrect3){
    Array2D<float> array = {{
        {1.3, 1.3, 1.3},
        {1.3, 1.3, 1.3},
        {1.3, 1.3, 1.3}
    }};

    CompressedData<float> compressedData = compressData(array);

    std::string str = "{1.3,3}\n{1.3,3}\n{1.3,3}\n";

    EXPECT_EQ(result(compressedData), str);
}