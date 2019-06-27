//
// Created by jinqiu on 19-6-27.
//

#include <iostream>

#include "mat.h"

using namespace std;
using namespace math;

int main()
{
    vector<vector<float >> vec={{1,2,3},{4,5,6},{7,8,9}};
    math::Mat mat0(vec);
    cout<<mat0<<endl;
    cout<<mat0.rows<<","<<mat0.cols<<endl;
    //math::Mat mat1(3,3);

    //cout<<mat1.fill(5)<<endl;

    return 0;
}