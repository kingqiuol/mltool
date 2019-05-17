//
// Created by jinqiu on 2019/5/17.
//

#ifndef MLTOOL_DATALOADER_H
#define MLTOOL_DATALOADER_H

#include <src/core/mltool.h>
#include "defines.h"

MLTOOL_BEGIN
    IO_BEGIN

        class DataLoader{
        public:
            virtual ~DataLoader();
            virtual void load_data(const std::string &);
            virtual void save_model(const std::string &);
        };

    IO_END
MLTOOL_END

#endif //MLTOOL_DATALOADER_H
