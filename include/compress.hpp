#pragma once
#include <iostream>
#include <array>
#include <vector>
#include <optional>

template<typename T> struct Data{
    T value;
    size_t count;
};

constexpr size_t sizeX{32};
constexpr size_t sizeY{16};

template<typename T> using Array2D = std::array<std::array<T, sizeX>, sizeY>;

template<typename T> using CompressedData = std::optional<std::vector<Data<T>>>;

template<typename T> CompressedData<T> compressData(const Array2D<T>& input){
    CompressedData<T> compressedData;
    std::vector<Data<T>> dataVector;
    Data<T> data;
    T prev;
    for (size_t i = 0; i < input.size(); i++){
        for (size_t j = 0; j < input[0].size(); j++){
            if(j == 0){
                data.value = input[i][j];
                data.count = 1;
            }
            else{
                if(input[i][j] == prev){
                    data.count++;
                }
                else{
                    dataVector.push_back(data);
                    data.value = input[i][j];
                    data.count = 1;
                }
            }
            prev = input[i][j];
        }
    }
    if(dataVector.size() > input.size() * input[0].size()){
        return compressedData;
    }
    else{
        compressedData.emplace(dataVector);
        return compressedData;
    }
}