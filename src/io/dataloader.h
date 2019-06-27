/*
 * Copyright (C) 2015, Simon Fuhrmann
 * TU Darmstadt - Graphics, Capture and Massively Parallel Computing
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms
 * of the BSD 3-Clause license. See the LICENSE.txt file for details.
 */

#ifndef MLTOOL_DATALOADER_H
#define MLTOOL_DATALOADER_H

#include <src/core/mltool.h>
#include "defines.h"

MLTOOL_BEGIN
    IO_BEGIN

        class DataLoader{
        public:
            virtual ~DataLoader();
            virtual void load_data(const std::string &) = 0;
        };

    IO_END
MLTOOL_END

#endif //MLTOOL_DATALOADER_H
