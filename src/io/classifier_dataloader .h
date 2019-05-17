//
// Created by jinqiu on 2019/5/17.
//

#ifndef MLTOOL_CLASSIFIER_DATALOADER_H
#define MLTOOL_CLASSIFIER_DATALOADER_H

#include <src/core/mltool.h>
#include <src/math/matrix.h>
#include <src/math/vector.h>
#include "dataloader.h"

MLTOOL_BEGIN
    IO_BEGIN

        class TwoClassfierDataloader:public DataLoader
        {
        public:
            void load_data(const std::string &);
            void loade_data();
        private:
            int numDatasets;
            int numFeatures;
            Matrix<double ,numDatasets,numFeatures> datasets;
            Matrix<int ,numDatasets,1> labels;
        };

    IO_END
MLTOOL_END



#endif //MLTOOL_CLASSIFIER_DATALOADER_H
