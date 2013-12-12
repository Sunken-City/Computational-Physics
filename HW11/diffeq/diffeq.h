int rk2(int order,void (*func)(int i,double x,double y[],double yp[]),double xstart,double xstop,double xinc,double y[]);
int rk4(int order,void (*func)(int i,double x,double y[],double yp[]),double xstart,double xstop,double xinc,double y[]);
int rk4_quiet(int order,void (*func)(int i,double x,double y[],double yp[]),double xstart,double xstop,double xinc,double y[]);
