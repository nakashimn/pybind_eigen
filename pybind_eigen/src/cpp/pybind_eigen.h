#include <iostream>
#include <Eigen/Core>
#include <Eigen/Geometry>
#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <pybind11/stl.h>

template <typename T> using RMatrix = Eigen::Matrix<T, -1, -1, Eigen::RowMajor>;
template <typename T> bool is_enable_dot(RMatrix<T> matrix0, RMatrix<T> matrix1);
template <typename T> RMatrix<T> eigen_dot_mat_mat(RMatrix<T> matrix0, RMatrix<T> matrix1);
template <typename T> RMatrix<T> eigen_dot_mat_vec(RMatrix<T> matrix, Eigen::VectorXf vector);
