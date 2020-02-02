#include "pybind_eigen.h"

int add(int x, int y){
    return x+y;
}

template <typename T>
using RMatrix = Eigen::Matrix<T, -1, -1, Eigen::RowMajor>;

template <typename T>
bool is_enable_dot(RMatrix<T> matrix0, RMatrix<T> matrix1){
    return matrix0.cols() == matrix1.rows();
}

template <typename T>
RMatrix<T> eigen_dot_mat_mat(RMatrix<T> matrix0, RMatrix<T> matrix1){
    if(!is_enable_dot(matrix0, matrix1)){
        return RMatrix<T>();
    };
    return matrix0 * matrix1;
}

template <typename T>
RMatrix<T> eigen_dot_mat_vec(RMatrix<T> matrix, Eigen::VectorXf vector){
    return matrix * vector;
}


namespace py = pybind11;
PYBIND11_MODULE(pybind_eigen, mod){
    mod.doc() = "Eigen on python.";
    mod.def("add", &add);
    mod.def("is_enable_dot", &is_enable_dot<float>, "is_enable_dot(np.array, np.array) -> bool");
    mod.def("dot_mat_mat", &eigen_dot_mat_mat<float>, "eigen_dot(np.array, np.array) -> np.array");
    mod.def("dot_mat_vec", &eigen_dot_mat_vec<float>, "eigen_dot(np.array, np.array) -> np.array");
}
