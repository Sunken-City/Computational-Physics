double lagrange(int n,struct point2d *sample,double x);
double lagrange_inverse(int n,struct point2d *sample,double x);
int find_newton_coeffs(int n,struct point2d *sample);
double newton(int n,struct point2d *sample,double x);
int find_newton_inverse_coeffs(int n,struct point2d *sample);
double newton_inverse(int n,struct point2d *sample,double x);
