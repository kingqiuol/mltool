//
// Created by jinqiu on 2019/5/17.
//

#ifndef MLTOOL_MATRIX1_H
#define MLTOOL_MATRIX1_H

#include <src/core/mltool.h>
#include <src/math/vector.h>

#include "defines.h"

MLTOOL_BEGIN
    MATH_NAMESPACE_BEGIN

        template<typename T>
        class Matrix {
        public:
            typedef T ValueType;

            /* ------------------------ Constructors ---------------------- */

            /** Default ctor that leaves values uninitialized. */
            Matrix(void) : m(nullptr), rows(0), cols(0) {}

            /** Default initialization using matrix rows and columns. */
            Matrix(int row, int col);

            /** Default initialization using vector. */
            Matrix(const std::vector <T> &vec, int row, int col);

            /** Ctor taking a pointer to initialize values. */
            explicit Matrix(T const *values, int row, int col);

            /** Ctor that initializes ALL elements. */
            explicit Matrix(T const &value, int row, int col);

            /** Copy ctor from matrix of same type. */
            Matrix(Matrix<T> const &other);

            /* ------------------------ Deconstruction ---------------------- */

            /** Destructor matrix. */
            ~Matrix();

            /* ------------------------- Management ----------------------- */

            /** Fills all vector elements with the given value. */
            Matrix<T> &fill(T const &value);

            /** Tests if the matrix is square. */
            bool is_square(void) const;

            /** Returns a row of the matrix as vector. */
            Vector <T,N> row(int index) const;

            /** Returns a column of the matrix as vector. */
            Vector <T,N> col(int index) const;

            /** Returns the smallest element in the matrix. */
            T minimum(void) const;

            /** Returns the largest element in the matrix. */
            T maximum(void) const;

            /** Stacks this (left) and another matrix (right) horizontally. */
            template<int O>
            Matrix<T, N, M + O> hstack(Matrix<T, N, O> const &other) const;

            /** Stacks this (top) and another matrix (bottom) vertically. */
            template<int O>
            Matrix<T, N + O, M> vstack(Matrix<T, O, M> const &other) const;

            /** Stacks this matrix (left) and another vector (right) horizontally. */
            Matrix<T, N, M + 1> hstack(Vector <T, N> const &other) const;

            /** Stacks this matrix (top) and another vector (bottom) vertically. */
            Matrix<T, N + 1, M> vstack(Vector <T, M> const &other) const;

            /** Returns a new matrix with the specified row deleted. */
            Matrix<T, N - 1, M> delete_row(int index) const;

            /** Returns a new matrix with the specified column deleted. */
            Matrix<T, N, M - 1> delete_col(int index) const;

        private:
            T **m;
            int rows;
            int cols;
        };

        /* ------------------------ Constructors ---------------------- */
        template<typename T>
        inline
        Matrix<T>::Matrix(int row, int col):rows(row), cols(col) {
            m = new T *[row];
            for (int i = 0; i < cols; ++i) {
                m[i] = new T[cols]();
            }
        }

        template<typename T>
        inline
        Matrix<T>::Matrix(const std::vector <T> &vec, int row, int col) {
            rows = row;
            cols = col;

            m = new T *[row];
            for (int i = 0; i < cols; ++i) {
                m[i] = new T[cols];
                std::copy(vec.begin() + i * cols, vec.begin() + (i + 1) * cols, m[i]);
            }
        }

        template<typename T>
        inline
        Matrix<T>::Matrix(T const *values, int row, int col) {
            rows = row;
            cols = col;

            m = new T *[row];
            for (int i = 0; i < cols; ++i) {
                m[i] = new T[cols];
                std::copy(values + i * cols, values + (i + 1) * cols, m[i]);
            }
        }

        template<typename T>
        inline
        Matrix<T>::Matrix(T const &value, int row, int col) {
            rows = row;
            cols = col;

            m = new T *[row];
            for (int i = 0; i < cols; ++i) {
                m[i] = new T[cols];
                std::fill(m[i], m[i] + cols, value);
            }
        }

        template<typename T>
        inline
        Matrix<T>::Matrix(Matrix<T> const &other) {
            rows = other.rows;
            cols = other.cols;

            m = new T *[row];
            for (int i = 0; i < cols; ++i) {
                m[i] = new T[cols];
                std::copy(other.m[i], other.m[i] + cols, m[i]);
            }
        }

        /* ------------------------ Deconstruction ---------------------- */
        template<typename T>
        inline
        Matrix<T>::~Matrix() {
            for (int i = 0; i < rows; ++i) {
                if (m[i]) {
                    delete[]m[i];
                }
            }

            if (m) delete[]m;
        }

        /* ---------------------------- Management ------------------------ */
        template<typename T>
        inline Matrix<T> &
        Matrix<T>::fill(T const &value) {
            for (int i = 0; i < rows; ++i) {
                std::fill(m[i], m[i] + cols, value);
            }
            return *this;
        }

        template<typename T>
        inline bool
        Matrix<T>::is_square() const {
            return rows == cols;
        }

        template<typename T>
        inline Vector <T,N>
        Matrix<T>::row(int index) const
        {
            return Vector<T,cols>(m[i],m[i]+cols);
        }

    MATH_NAMESPACE_END
MLTOOL_END

#endif //MLTOOL_MATRIX1_H
