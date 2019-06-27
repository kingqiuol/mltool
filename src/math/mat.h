//
// Created by jinqiu on 2019/6/27.
//

#ifndef MLTOOL_MAT_H
#define MLTOOL_MAT_H

#include <assert.h>
#include <iostream>
#include <algorithm>

#include "defines.h"

MATH_NAMESPACE_BEGIN

class Mat {
public:
    /* ------------------------ Constructors ---------------------- */

    /** Default ctor that leaves values uninitialized. */
    Mat(void) {}

    /** Constructing matrix based on matrix row/column. */
    Mat(int row, int col);

    /** Copy ctor from matrix of same type. */
    Mat(const Mat &other);

    /** Constructing matrix by vector  */
    Mat(std::vector<std::vector<float >>&);

    /* ------------------------ Constructors ---------------------- */

    /** Deconstruct matrix and release resources . */
    ~Mat();

    /* ------------------------- Management ----------------------- */

    /** Fills all vector elements with the given value. */
    Mat &fill(const float &value);

    /** Tests if the matrix is square. */
    bool is_square(void) const;

    /** Returns a row of the matrix as vector. */
    Mat row(int index) const;

    /** Returns a column of the matrix as vector. */
    Mat col(int index) const;

    /** Returns the smallest element in the matrix. */
    float minimum(void) const;

    /** Returns the largest element in the matrix. */
    float maximum(void) const;

    /** Stacks this (left) and another matrix (right) horizontally. */
    Mat hstack(const Mat &other) const;

    /** Stacks this (top) and another matrix (bottom) vertically. */
    Mat vstack(const Mat &other) const;

    /** Returns a new matrix with the specified row deleted. */
    Mat delete_row(int index) const;

    /** Returns a new matrix with the specified column deleted. */
    Mat delete_col(int index) const;

    /* ---------------------- Unary operators --------------------- */

    /** Component-wise negation on self, returns self. */
    Mat &negate(void);

    /** Returns a component-wise negation on copy of self. */
    Mat negated(void) const;

    /** Transpose the current matrix. Only available for square matrices. */
    Mat &transpose(void);

    /** Returns a transposed copy of self by treating rows as columns. */
    Mat transposed(void) const;

    /* --------------------- Binary operators --------------------- */

    /** Matrix with matrix multiplication. */
    Mat mult(const Mat &rhs) const;

    /* --------------------- Object operators --------------------- */

    /** Element access operator. */
    float &operator()(int row, int col);

    /** Const element access operator. */
    float const &operator()(int row, int col) const;

    /** Comparison operator. */
    bool operator==(const Mat &rhs) const;

    /** Comparison operator. */
    bool operator!=(const Mat &rhs) const;

    /** Assignment operator. */
    Mat &operator=(const Mat &rhs);

    /** Component-wise negation. */
    Mat operator-(void) const;

    /** Self-substraction with other matrix. */
    Mat &operator-=(const Mat &rhs);

    /** Substraction with other matrix. */
    Mat operator-(const Mat &rhs) const;

    /** Self-addition with other matrix. */
    Mat &operator+=(const Mat &rhs);

    /** Addition with other matrix. */
    Mat operator+(const Mat &rhs) const;

    /** Multiplication with other matrix. */
    Mat operator*(const Mat &rhs) const;

    /** Component-wise self-substraction with scalar. */
    Mat &operator-=(const float &rhs);

    /** Component-wise substraction with scalar. */
    Mat operator-(const float &rhs) const;

    /** Component-wise self-addition with scalar. */
    Mat &operator+=(const float &rhs);

    /** Component-wise addition with scalar. */
    Mat operator+(const float &rhs) const;

    /** Component-wise self-multiplication with scalar. */
    Mat &operator*=(const float &rhs);

    /** Component-wise multiplication with scalar. */
    Mat operator*(const float &rhs) const;

    /** Component-wise self-division by scalar. */
    Mat &operator/=(const float &rhs);

    /** Component-wise division by scalar. */
    Mat operator/(const float &rhs) const;

    /** Print matrix information  */
    friend std::ostream &operator<<(std::ostream &, Mat &);


public:
    int rows;
    int cols;

    float **data;
};

MATH_NAMESPACE_END

#endif //MLTOOL_MAT_H
