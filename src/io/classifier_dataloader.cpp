/*
 * Copyright (C) 2015, Simon Fuhrmann
 * TU Darmstadt - Graphics, Capture and Massively Parallel Computing
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms
 * of the BSD 3-Clause license. See the LICENSE.txt file for details.
 */

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

            Mat data(vec_datasets);

            for(int i=0;i<numDatasets;++i){
                for(int j=0;j<=numFeatures;++j){
                    if(j<numFeatures){
                        datasets(i,j)=data(i,j);
                    }else{
                        labels(i,0)=data(i,j);
                    }
                }

            for(auto i=0;i<vec_datasets.size();++i){
                std::copy(vec_datasets[i].begin(),vec_datasets[i].end()-1,datasets.data[i]);
                labels(i,0)= static_cast<int>(*(vec_datasets[i].end()-1));
            }
        }

    IO_END
MLTOOL_END
