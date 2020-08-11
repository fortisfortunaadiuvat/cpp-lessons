//
// Created by hakan on 11.08.2020.
//

#include <iostream>
#include <eigen3/Eigen/Dense>

using namespace Eigen;
using namespace std;

int main() {
    Matrix2d mat;
    Vector2d u(-1,1) , v (2,0);

    mat << 1,2,
            3,4;

    std::cout << mat(1,1) << "\n" ;
    std::cout << "Here is the matrix cross vector(u):\n" << mat * u << "\n";

    mat.transposeInPlace() ;

    std::cout << "Here is the matrix cross vector(u) after transpose:\n" << mat * u << "\n";
    std::cout << "Here is sum of the matrix elements:\n" << mat.sum() << "\n";
    std::cout << "Here is product of the matrix elements:\n" << mat.prod() << "\n";
    std::cout << "Here is average of the matrix elements:\n" << mat.mean() << "\n";
    std::cout << "Here is min element in the matrix :\n" << mat.minCoeff() << "\n";
    std::cout << "Here is max element in the matrix elements:\n" << mat.maxCoeff() << "\n";
    std::cout << "Here is sum of the diagonal of the matrix:\n" << mat.trace() << "\n";

    MatrixXf mat2(2,2);
    mat2 << 1,2,3,4;

    mat2 = mat2 - MatrixXf::Identity(2,2);

    std::cout << "Here is the matrix after the subtraction operation:\n" << mat2 << "\n";

    return 0;
}
