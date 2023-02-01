#include <iostream>
#include <eigen3/Eigen/Dense>
#include "useful_function.h"

int main(){
  // constant parameters
  int M = 30;
  int N = 40;
  int P = 50;

  double F = 1.0;

  // initializing eigen matrices
  Eigen::MatrixXd A_eigen(M, P);
  Eigen::MatrixXd B_eigen(P, N);

  initialize_eigen_matrix_2D<double>(A_eigen, M, P);
  initialize_eigen_matrix_2D<double>(B_eigen, P, N);

  // initializing std vectors
  std::vector<std::vector<double>> A_std(M, std::vector<double> (P, 0));
  std::vector<std::vector<double>> B_std(P, std::vector<double> (N, 0));
  std::vector<std::vector<double>> C_std(M, std::vector<double> (N, 0));

  // timings
  auto eigen_time_start = std::chrono::steady_clock::now();
  auto C_eigen = A_eigen*B_eigen;
  auto eigen_time_finish = std::chrono::steady_clock::now();

  auto eigen_duration = eigen_time_finish - eigen_time_start;

  std::cout << "Eigen Time: "
            << std::chrono::duration_cast<std::chrono::microseconds>(eigen_duration).count()
            << " microsseconds" << std::endl;

  auto std_time_start = std::chrono::steady_clock::now();
  matrix_multiplication(A_std, B_std, C_std, M, N, P, F);
  auto std_time_finish = std::chrono::steady_clock::now();

  auto std_duration = std_time_finish - std_time_start;

  std::cout << "STD Time: "
            << std::chrono::duration_cast<std::chrono::microseconds>(std_duration).count()
            << " microseconds" << std::endl;
}