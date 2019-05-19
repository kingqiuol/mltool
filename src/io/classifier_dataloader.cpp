//
// Created by jinqiu on 19-5-19.
//

#include "classifier_dataloader.h"


MLTOOL_BEGIN
    IO_BEGIN
        void TwoClassfierDataloader::load_data(const std::string &file_path)
        {
            std::ifstream file(file_path);

            std::vector<std::vector<double>> vec_datasets;
            std::string ss;
            while(getline(file,ss)){
                std::vector<double> data;

                std::stringstream w(ss);
                double temp;
                while(w>>temp){
                    data.push_back(temp);
                }
                if(data.size()){
                    continue;
                }
                vec_datasets.push_back(data);
            }
            srand(static_cast<unsigned  int>(time(0)));
            std::random_shuffle(vec_datasets.begin(),vec_datasets.end());

            this->numDatasets= static_cast<int>(vec_datasets.size());
            this->numFeatures= static_cast<int>(vec_datasets[0].size()-1);

            datasets.copy()
        }

    IO_END
MLTOOL_END
