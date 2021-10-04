//
// Created by user on 04.10.2021.
//

#ifndef ACS_SIZOV_VLAD_HW1_DIAGONAL_H
#define ACS_SIZOV_VLAD_HW1_DIAGONAL_H

#include "Matrix.h"

class Diagonal : Matrix {


public:
    std::string name;
    double middle;
    std::vector<std::vector<int>> array;
    Diagonal(std::vector<int> arr, int demension) : Matrix(demension){
        this->name = "Диагональная матрица (на основ одномерного массива). Среднее значение:";
        int count = 0;
        int sum = 0;
        for (int i = 0; i < arr.size(); ++i) {
            std::vector<int> newVec;
            for (int j = 0; j < arr.size(); ++j) {
                if (i == j){
                    newVec.push_back(arr[i]);
                    sum += arr[i];
                }
                else
                    newVec.push_back(0);
                count++;
            }
            array.push_back(newVec);
        }
        this->middle = ((sum + 0.0) / count);
    }
};


#endif //ACS_SIZOV_VLAD_HW1_DIAGONAL_H
