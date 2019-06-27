//
// Created by jinqiu on 2019/6/27.
//
#include "mat.h"
/* ------------------------ Constructors ---------------------- */

/** Constructing Matrix Based on Matrix Row/Column. */
Mat::Mat(int row, int col) {
    this->rows = row;
    this->cols = col;

    this->data = new float *[rows]();
    for (int i = 0; i < rows; ++i) {
        this->data[i] = new float[cols]();
    }
}

/** Copy ctor from matrix of same type. */
Mat::Mat(const Mat &other) {
    this->rows = other.rows;
    this->cols = other.cols;

    this->data = new float *[rows]();
    for (int i = 0; i < rows; ++i) {
        this->data[i] = new float[cols]();
        std::copy(other.data[i], other.data[i] + cols, this->data[i]);
    }
}

/* ------------------------ Constructors ---------------------- */

/** Deconstruct matrix and release resources. */
Mat::~Mat() {
    for (int i = 0; i < rows; ++i) {
        if (data[i]) {
            delete[] data[i];
        }
    }

    if (data) {
        delete[] data;
    }

    data = nullptr;
}

/* ------------------------- Management ----------------------- */

/** Fills all vector elements with the given value. */
Mat &Mat::fill(const float &value) {
    for (int i = 0; i < rows; ++i) {
        std::fill(data[i], data[i] + cols, value);
    }

    return *this;
}

/** Tests if the matrix is square. */
bool Mat::is_square(void) const {
    return cols == rows;
}

/** Returns a row of the matrix as vector. */
Mat Mat::row(int index) const {
    Mat tmp(1, cols);
    std::copy(data[index], data[index] + cols, tmp.data);

    return tmp;
}

/** Returns a column of the matrix as vector. */
Mat Mat::col(int index) const {
    Mat tmp(rows, 1);

    for (int i = 0; i < rows; ++i) {
        tmp[0][i] = data[index][i];
    }

    return tmp;
}

/** Returns the smallest element in the matrix. */
float Mat::minimum(void) const {
    float min_val = data[0][0];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (min_val > data[i][j]) {
                min_val = data[i][j];
            }
        }
    }

    return min_val;
}

/** Returns the largest element in the matrix. */
float Mat::maximum(void) const {
    float max_val = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (max_val < data[i][j]) {
                max_val = data[i][j];
            }
        }
    }

    return max_val;
}

/** Stacks this (left) and another matrix (right) horizontally. */
Mat Mat::hstack(const Mat &other) const {
    assert(this->rows == other.rows);

    Mat tmp(rows, cols + other.cols);
    for (int i = 0; i < rows; ++i) {
        std::copy(data[i], data[i] + cols, tmp.data[i]);
        std::copy(other.data[i], other.data[i] + other.cols, tmp.data[i] + cols);
    }

    return tmp;
}

/** Stacks this (top) and another matrix (bottom) vertically. */
Mat Mat::vstack(const Mat &other) const {
    assert(this->cols == other.cols);

    Mat tmp(rows + other.rows, cols);
    int i = 0;
    for (; i < rows; ++i) {
        std::copy(data[i], data[i] + cols, tmp.data[i]);
    }
    for (; i < tmp.rows; ++i) {
        int index = i - rows;
        std::copy(other.data[index], other.data[index] + cols, tmp.data[i]);
    }

    return tmp;
}

/** Returns a new matrix with the specified row deleted. */
Mat Mat::delete_row(int index) const {
    Mat tmp(rows - 1, cols);
    int j = 0;
    for (int i = 0; i < rows; ++i) {
        if (i = index) continue;
        std::copy(data[i], data[i] + cols, tmp.data[j]);
        ++j;
    }

    return tmp;
}

/** Returns a new matrix with the specified column deleted. */
Mat Mat::delete_col(int index) const {
    Mat tmp(rows, cols - 1);
    for (int i = 0; i < rows; ++i) {
        int k = 0;
        for (int j = 0; j < cols; ++j) {
            if (j == index) continue;
            tmp.data[i][k] = data[i][j];
            ++k;
        }
    }

    return tmp;
}

/* ---------------------- Unary operators --------------------- */

/** Component-wise negation on self, returns self. */
Mat &Mat::negate(void) {
    for (int i = 0; i < rows; ++i) {
        std::for_each(data[i], data[i] + cols, [](float &val) { val = -val; });
    }

    return *this;
}

/** Returns a component-wise negation on copy of self. */
Mat Mat::negated(void) const {
    return Mat(*this).negate();
}

/** Transpose the current matrix. Only available for square matrices. */
Mat &Mat::transpose(void) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::swap(this->data[i][j], this->data[j][i]);
        }
    }

    return *this;
}

/** Returns a transposed copy of self by treating rows as columns. */
Mat Mat::transposed(void) const {
    Mat tmp(cols, rows);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            tmp.data[j][i] = this->data[i][j];
        }
    }

    return tmp;
}

/* --------------------- Binary operators --------------------- */

/** Matrix with matrix multiplication. */
Mat Mat::mult(const Mat &rhs) const {
    assert(this.cols == rhs.rows);

    Mat tmp(rows, rhs.cols);
    for (int i = 0; i < tmp.rows; ++i) {
        for (int j = 0; j < tmp.cols; ++j) {
            Mat r_cols = rhs.col(j).transpose();
            tmp.data[i][j] = std::inner_product(data[i], data[i] + cols, r_cols.data, 0);
        }
    }

    return tmp;
}

/* --------------------- Object operators --------------------- */

/** Element access operator. */
float &Mat::operator()(int row, int col) {
    return this->data[row][col];
}

/** Const element access operator. */
float const &Mat::operator()(int row, int col) const {
    return this->data[row][col];
}

/** Comparison operator. */
bool Mat::operator==(const Mat &rhs) const {
    if (cols != rhs.cols || rows != rhs.rows) return false;

    for (int i = 0; i < rows; ++i) {
        if (!std::equal(data[i], data[i] + cols, rhs.data[i]))
            return false;
    }

    return true;
}

/** Comparison operator. */
bool Mat::operator!=(const Mat &rhs) const {
    if (cols != rhs.cols || rows != rhs.rows) return true;

    for (int i = 0; i < rows; ++i) {
        if (!std::equal(data[i], data[i] + cols, rhs.data[i]))
            return true;
    }

    return false;
}

/** Assignment operator. */
Mat &Mat::operator=(const Mat &rhs) {

    if (!data) {
        rows = rhs.rows;
        cols = rhs.cols;

        data = new float *[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new float[cols]();
        }
    }

    assert(rhs.rows == rows);
    assert(rhs.cols == cols);

    for (int i = 0; i < rows; ++i) {
        std::copy(rhs.data[i], rhs.data[i] + cols, data[i]);
    }

    return *this;
}

/** Component-wise negation. */
Mat Mat::operator-(void) const {
    return this->negate();
}

/** Self-substraction with other matrix. */
Mat &Mat::operator-=(const Mat &rhs) {
    assert(rhs.rows == rows);
    assert(rhs.cols == cols);

    for (int i = 0; i < rows; ++i) {
        std::transform(data[i], data[i] + cols, rhs.data[i], data[i], std::minus<float>());
    }

    return *this;
}

/** Substraction with other matrix. */
Mat Mat::operator-(const Mat &rhs) const {
    return Mat(*this) -= rhs;
}

/** Self-addition with other matrix. */
Matr &Mat::operator+=(const Mat &rhs) {
    assert(rhs.rows == rows);
    assert(rhs.cols == cols);

    for (int i = 0; i < rows; ++i) {
        std::transform(data[i], data[i] + cols, rhs.data[i], data[i], std::plus<float>());
    }
}

/** Addition with other matrix. */
Mat Mat::operator+(const Mat &rhs) const {
    return Mat(*this) += rhs;
}

/** Multiplication with other matrix. */
Mat Mat::operator*(const Mat &rhs) const {
    return this->mult(rhs);
}

/** Component-wise self-substraction with scalar. */
Mat &Mat::operator-=(const float &rhs) {
    for (int i = 0; i < rows; ++i) {
        std::for_each(data[i], data[i] + cols, [rhs](float &val) { val -= rhs; });
    }

    return *this;
}

/** Component-wise substraction with scalar. */
Mat Mat::operator-(const float &rhs) const {
    return Mat(*this) -= rhs;
}

/** Component-wise self-addition with scalar. */
Mat &Mat::operator+=(const float &rhs) {
    for (int i = 0; i < rows; ++i) {
        std::for_each(data[i], data[i] + cols, [rhs](float &val) { val += rhs; });
    }

    return *this;
}

/** Component-wise addition with scalar. */
Mat Mat::operator+(const float &rhs) const {
    return Mat(*this) += rhs;
}

/** Component-wise self-multiplication with scalar. */
Mat &Mat::operator*=(const float &rhs) {
    for (int i = 0; i < rows; ++i) {
        std::for_each(data[i], data[i] + cols, [rhs](float &val) { val *= rhs; });
    }

    return *this;
}

/** Component-wise multiplication with scalar. */
Mat Mat::operator*(const float &rhs) const {
    return Mat(*this) *= rhs;
}

/** Component-wise self-division by scalar. */
Mat &Mat::operator/=(const float &rhs) {
    for (int i = 0; i < rows; ++i) {
        std::for_each(data[i], data[i] + cols, [rhs](float &val) { val /= rhs; });
    }

    return *this;
}

/** Component-wise division by scalar. */
Mat Mat::operator/(const float &rhs) const {
    return Mat(*this) /= rhs;
}

/** Print matrix information  */
std::ostream &operator<<(std::ostream &out, Mat &rhs) {
    out << "[ ";
    for (int i = 0; i < rhs.rows; ++i) {
        out << "[ ";
        for (int j = 0; j < rhs.cols; ++j) {
            out << ths(i, j) << " ,";
        }
        out << " ]";
        if (i == rhs.rows - 1) {
            out << " ]";
        }
        out << std::endl;
    }
}