//
// Created by jinqiu on 2019/5/16.
//

#ifndef MLTOOL_INITIALIZATION_H
#define MLTOOL_INITIALIZATION_H

#include <src/math/matrix.h>
#include <src/math/vector.h>
#include <mltool.h>

MLTOOL_BEGIN
    PERCEPTRON_BEGIN


        class initialization {
        public:
            initialization() {}

            template<typename DataType, int numFeatures, int numClasses>
            inline static void RandomInitialization(Matrix<DataType, numFeatures, numClasses> &weights,
                                                    Vector<DataType, numClasses> &biases) {
                weights.randu();
                biases.randu();
            }

            template<typename DataType, int numFeatures, int numClasses>
            inline static void ZerosInitialization(Matrix<DataType, numFeatures, numClasses> &weights,
                                                   Vector<DataType, numClasses> &biases){
                weights.fill(0);
                biases.fill(0);
            }
        };
    PERCEPTRON_END
MLTOOL_END

#endif //MLTOOL_INITIALIZATION_H
