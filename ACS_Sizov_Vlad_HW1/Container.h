#ifndef ACS_SIZOV_VLAD_HW1_CONTAINER_H
#define ACS_SIZOV_VLAD_HW1_CONTAINER_H

#include <vector>
#include "Matrix.h"
#include "Array2d.h"
#include "LowMatrix.h"
#include "Diagonal.h"
#include <iostream>
#include <fstream>

class Container {
    static int const maxLen = 10000;
    int curLen = 0;
    std::vector<Array2d> matrixesArr2d;
    std::vector<Diagonal> matrixesDiagonal;
    std::vector<LowMatrix> matrixesLowMatrix;

public:
    void AddMatrix(std::vector<std::vector<int>> arr, int typeOfMatrix){
        matrixesArr2d.push_back(Array2d(arr, arr.size()));
        curLen++;
    }
    std::vector<double> ShellSort(std::vector<double> array){
        int length = array.size();
        int h = 1;
        while( h < length / 3){
            h = 3 * h + 1;
        }

        while( h > 0 ){
            for ( int i = h; i < length; i++){

                for ( int j = i; j > 0 && array[j] < array[j-h]; j-=h){
                    double cur = array[j];
                    array[j] = array[j-h];
                    array[j-h] = cur;
                }
            }
            //decreasing h
            h = --h / 3;

        }
        return array;
    }

    void AddArr(std::vector<int> arr, int typeOfMatrix, int demension){
        if (typeOfMatrix == 2) {
            matrixesDiagonal.push_back(Diagonal(arr, demension));
            curLen++;
        } else {
            matrixesLowMatrix.push_back(LowMatrix(arr, demension));
            curLen++;
        }
    }

    void PrintInformation(std::string outputFileName){
        std::ofstream out;          // поток для записи
        out.open(outputFileName); // окрываем файл для записи
        if (out.is_open())
        {
            std::vector<double> middles;
            out << "Количество матриц в контейнере: " << curLen << std::endl;
            out << "Список матриц: " << std::endl;
            for (int i = 0; i < matrixesArr2d.size(); ++i) {
                out << matrixesArr2d[i].name << " " << matrixesArr2d[i].middle << std::endl;
                middles.push_back(matrixesArr2d[i].middle);
                for (int j = 0; j < matrixesArr2d[i].array.size(); ++j) {
                    for (int k = 0; k < matrixesArr2d[i].array[j].size(); ++k) {
                        out << matrixesArr2d[i].array[j][k] << " ";
                    }
                    out << std::endl;
                }
                out << std::endl;
            }

            for (int i = 0; i < matrixesDiagonal.size(); ++i) {
                out << matrixesDiagonal[i].name << " " << matrixesDiagonal[i].middle << std::endl;
                middles.push_back(matrixesDiagonal[i].middle);
                for (int j = 0; j < matrixesDiagonal[i].array.size(); ++j) {
                    for (int k = 0; k < matrixesDiagonal[i].array[j].size(); ++k) {
                        out << matrixesDiagonal[i].array[j][k] << " ";
                    }
                    out << std::endl;
                }
                out << std::endl;
            }

            for (int i = 0; i < matrixesLowMatrix.size(); ++i) {
                out << matrixesLowMatrix[i].name << " " << matrixesLowMatrix[i].middle << std::endl;
                middles.push_back(matrixesLowMatrix[i].middle);
                for (int j = 0; j < matrixesLowMatrix[i].array.size(); ++j) {
                    for (int k = 0; k < matrixesLowMatrix[i].array[j].size(); ++k) {
                        out << matrixesLowMatrix[i].array[j][k] << " ";
                    }
                    out << std::endl;
                }
                out << std::endl;
            }

            std::vector<double> sorted = ShellSort(middles);
            for (int i = 0; i < sorted.size(); ++i) {
                out << sorted[i] << " ";
            }

        }

        std::cout << "End of program" << std::endl;
    }


};




#endif //ACS_SIZOV_VLAD_HW1_CONTAINER_H
