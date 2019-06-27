//
// Created by jinqiu on 2019/5/16.
//

#ifndef MLTOOL_INITIALIZATION_H
#define MLTOOL_INITIALIZATION_H

#include <src/math/mat.h>
#include <src/core/mltool.h>

MLTOOL_BEGIN
    PERCEPTRON_BEGIN

        class RandomInitialization{
            RandomInitialization(){}

            template<typename DataType, int numFeatures, int numClasses>
            inline static void RandomInitialization(Matrix<DataType, numFeatures, numClasses> &weights,
                                                    Vector<int, numClasses> &biases) {
                weights.randu();
                biases.randu();
            }
        };

        class ZerosInitialization{
            ZerosInitialization(){}

            template<typename DataType, int numFeatures, int numClasses>
            inline static void ZerosInitialization(Matrix<DataType, numFeatures, numClasses> &weights,
                                                   Vector<int, numClasses> &biases){
                weights.fill(0);
                biases.fill(0);
            }
        };


    PERCEPTRON_END
MLTOOL_END

#endif //MLTOOL_INITIALIZATION_H
