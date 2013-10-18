int newton_raphson(double (*func)(double x),double (*deriv)(double x),double x,int nmax,double tol,double min);
int secant(double (*func)(double x),double a,double b,int nmax,double tol);
int regula_falsi(double (*func)(double x),double a,double b,int nmax,double tol);
int bisection(double (*func)(double x),double a,double b,int nmax,double tol);
