#ifndef __DISPLAYPLOT_H__
#define __DISPLAYPLOT_H__

#define tanh(x) (exp(x)-exp(-(x)))/(exp(x)+exp(-(x)))
#define gauss(x,a,xx) exp(-(a)*((x)-(xx))*((x)-(xx)))

int displayplot(FILE *img,                        // output file
				unsigned width, unsigned hight,            // img size
				double (*func)(double,double),   // the function to plot
				double xmin, double xmax,        // x range
				double ymin, double ymax,        // y range
				int (*colorfunction)(double));   // colorfunction


int goldencolor(double z);                       // 一种配色方案
int hitcolor(double z);
int seacolor(double z);
int foristcolor(double z);
int grasscolor(double z);
int pinkcolor(double z);
int inkcolor(double z);
int testcolor(double z);

#endif
