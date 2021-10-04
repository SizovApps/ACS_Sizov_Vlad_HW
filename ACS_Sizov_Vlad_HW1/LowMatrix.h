//
// Created by user on 04.10.2021.
//

#ifndef ACS_SIZOV_VLAD_HW1_LOWMATRIX_H
#define ACS_SIZOV_VLAD_HW1_LOWMATRIX_H

#include "Matrix.h"

class LowMatrix : Matrix {

public:
    std::string name;
    double middle;
    std::vector<std::vector<int>> array;
    LowMatrix(std::vector<int> arr, int demension) : Matrix(demension){
        this->name  = "Нижняя треугольная матрица (одномерный массив с формулой пересчета). Среднее значение:";
        int counter = 0;
        int count = 0;
        int sum = 0;
        for (int i = 0; i < demension; ++i) {
            std::vector<int> newVec;
            for (int j = 0; j < demension; ++j) {
                if (j < demension && j < i+1){
                    newVec.push_back(arr[counter]);
                    sum += arr[counter];
                    counter++;
                }
                else
                    newVec.push_back(0);
                count++;
            }
            this->array.push_back(newVec);
        }
        this->middle = ((sum + 0.0) / count);
    }
};


#endif //ACS_SIZOV_VLAD_HW1_LOWMATRIX_H
