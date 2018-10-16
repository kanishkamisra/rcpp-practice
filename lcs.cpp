#include <Rcpp.h>

//[[Rcpp::export]]
int lcs(std::string s, std::string t) {
	int n = s.size();
	int m = t.size();

	Rcpp::IntegerMatrix lcs(n + 1, m + 1);

	for(int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if(i == 0 || j == 0) {
				lcs(i, j) = 0;
			} else if (s[i - 1] == t[j - 1]) {
				lcs(i, j) = lcs(i - 1, j - 1) + 1;
			} else {
				lcs(i, j) = std::max(lcs(i - 1, j), lcs(i, j - 1));
			}
		}
	}

	return(lcs(n, m));
}

//[[Rcpp::export]]
double lcsr(std::string s, std::string t) {
  int denom = std::max(s.size(), t.size());
  
  return((double)lcs(s, t)/denom);
}

//[[Rcpp::export]]
Rcpp::NumericVector lcs_vec(std::vector<std::string> s, std::string t) {
  unsigned int size = s.size();
  
  Rcpp::NumericVector d(size);
  
  for(unsigned int i = 0; i < size; i++) {
    d(i) = lcs(s[i], t);
  }
  
  return(d);
}