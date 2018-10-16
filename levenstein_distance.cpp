#include <Rcpp.h>

//[[Rcpp::export]]
int string_dist(std::string s, std::string t) {
	int n = s.size();
	int m = t.size();
	Rcpp::IntegerMatrix d(n + 1, m + 1);
	Rcpp::Rcout << "n:" << n << ", m:" << m << std::endl;

	if(n == 0) {
		return n;
	}

	if(m == 0) {
		return m;
	}

	for (int i = 0; i <= n; i++) {
		d(i, 0) = i;
	}

	for (int j = 0; j <= m; j++) {
		d(0, j) = j;
	}

	for (int j = 1; j <= m; j++) {
		for (int i = 1; i <= n; i++) {
			if(s[i - 1] == t[j - 1]) {
				d(i, j) = d(i - 1, j - 1); //no operation
			} else {
				d(i, j) = std::min(d(i - 1, j) + 1, std::min(d(i, j - 1) + 1, d(i - 1, j - 1) + 1));
			}
		}
	}

	return d(n, m);
}

// [[Rcpp::export]]
Rcpp::IntegerVector lev_dist(std::vector<std::string> c, std::string s) {
	unsigned int size = c.size();

	Rcpp::IntegerVector d(size);

	for(unsigned int i = 0; i < size; i++) {
		d(i) = string_dist(c[i], s);
	}

	return(d);
}