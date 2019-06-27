//
// Created by jinqiu on 2019/5/17.
//

#ifndef MLTOOL_PERCEPTRON_H
#define MLTOOL_PERCEPTRON_H

#include <src/core/mltool.h>

#include "initialization.h"
#include "learning_policies.h"

MLTOOL_BEGIN
    PERCEPTRON_BEGIN

        template <class LearnPolicy=SimpleWeightUpdates,
                class WeightInitializationPolicy=ZerosInitialization>
        class Perceotron
        {
            typedef Matrix<double, numFeatures, numClasses> MatDataType;
        public:
            Perceotron(const size_t numclasses=0,
                       const size_t numFeatures=0,
                       const size_t maxIterations = 1000);

        public:
            /** Get the maximum number of iterations*/
            size_t max_iterations() const {return maxIterations;}
            /** Modify the maximum number of iterations*/
            size_t &max_iterations() {return maxIterations;}

            /** Get the number of classes this perceptron has been trained for*/
            size_t getNumClasses() const { return numClasses;}

            /** Get the weight matrix*/
            const MatDataType Weights() const {return weights;}
            /** Modify the weight matrix.  You had better know what you are doing!*/
            MatDataType &Weights() {return weights;}

            /** Get the biases*/
            const Vec1d Biases() const {return bias;}
            /** Modify the biases.  You had better know what you are doing!*/
            Vec1d &Biases() {return bias;}
        private:
            size_t maxIterations;

            size_t numClasses;
            size_t numFeatures;

            MatDataType weights;
            Vec1d bias;
        };

    PERCEPTRON_END
MLTOOL_END

#endif //MLTOOL_PERCEPTRON_H
