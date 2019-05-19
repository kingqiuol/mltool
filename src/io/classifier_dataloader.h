//
// Created by jinqiu on 19-5-19.
//

#ifndef MLTOOL_CLASSIFIER_DATALOADER_H
#define MLTOOL_CLASSIFIER_DATALOADER_H

#include <fstream>
#include <sstream>
#include <string>

#include <src/core/mltool.h>
#include <src/math/matrix.h>
#include <src/math/vector.h>
#include "dataloader.h"

MLTOOL_BEGIN
IO_BEGIN
    /**
     * This class is classified data loading Class,
     * mainly used for binary data loading.
     * */
    class TwoClassfierDataloader:public DataLoader
    {
    public:
        TwoClassfierDataloader():numDatasets(0),numFeatures(0){}

        /** Loading bi-categorized data based on data set path*/
        void load_data(const std::string &);

        /** Get data set size*/
        int getNumbersOfDatasets() const{return numDatasets;}

        /** Number of features obtained*/
        int getNumbersOfFestures() const{return numFeatures;}

    public:
        Matrix<double ,numDatasets,numFeatures> datasets;
        Matrix<int ,numDatasets,1> labels;
    private:
        int numDatasets; //Number of data sets
        int numFeatures; //Number of classification features
    };

IO_END
MLTOOL_END

#endif //MLTOOL_CLASSIFIER_DATALOADER_H
