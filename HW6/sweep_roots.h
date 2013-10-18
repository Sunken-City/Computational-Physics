int sweep_newton_raphson(double (*func)(double x),double (*deriv)(double x),double xstart,double xstop,double xinc,int nmax,double tol,double min);
int sweep_secant(double (*func)(double x),double xstart,double xstop,double xinc,int nmax,double tol);
int sweep_regula_falsi(double (*func)(double x),double xstart,double xstop,double xinc,int nmax,double tol);
int sweep_bisection(double (*func)(double x),double xstart,double xstop,double xinc,int nmax,double tol);
