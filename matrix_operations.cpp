//[[Rcpp::depends(RcppEigen)]]
//[[Rcpp::depends(RcppArmadillo)]]
#include <Rcpp.h>
#include <RcppEigen.h>
#include <RcppArmadillo.h>
#include "matrix_types.h"

using namespace Rcpp;

// Sum of squared of the row elements  for sparse matrices

// [[Rcpp::export]]
NumericVector rowSumsSquared(MappedSpMat sparse_matrix) {
	int nrow = sparse_matrix.rows(), ncol = sparse_matrix.cols();
	NumericVector out(nrow);

	for(int col_index = 0; col_index < ncol; ++col_index) {
		for(InnerIter sparse_row_index(sparse_matrix, col_index); sparse_row_index; ++sparse_row_index) {
			out[sparse_row_index.index()] += std::pow(sparse_row_index.value(), 2);
		}
	}

	return(out);
}

// [[Rcpp::export]]
NumericVector rowMax()