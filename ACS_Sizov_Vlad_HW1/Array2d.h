//
// Created by user on 04.10.2021.
//

#ifndef ACS_SIZOV_VLAD_HW1_ARRAY2D_H
#define ACS_SIZOV_VLAD_HW1_ARRAY2D_H

#include "Matrix.h"

class Array2d : Matrix {

public:
    std::string name;
    double middle;
    std::vector<std::vector<int>> array;
    Array2d(std::vector<std::vector<int>> arr, int demension) : Matrix(demension){
        this->name  = "Обычный двумерный массив.  Среднее значение:";
        this->array = arr;
        int count = 0;
        int sum = 0;
        for (int i = 0; i < arr.size(); ++i) {
            for (int j = 0; j < arr[i].size(); ++j) {
                count++;
                sum += arr[i][j];
            }
        }
        this->middle = ((sum + 0.0) / count);
    }
};


#endif //ACS_SIZOV_VLAD_HW1_ARRAY2D_H
