int sys_newton_raphson(int n,void (*func)(int n,double *x,double *f),void (*jacobian)(int n,double *x,double **coeff),double *init,double *tol,int n_iters);
