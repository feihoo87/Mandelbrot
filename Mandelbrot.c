#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#include"displayplot.h"

int mm=0;

int Mandelbrot(double x, double y, int timeslimit)
{
  int i;
  double zx,zy,abs_z_2;
  double temp;

  abs_z_2=0.0;
  zx=0.0;
  zy=0.0;

  for(i=0; i<timeslimit && abs_z_2<4.0; ++i){
	temp = zx;
	zx = zx*zx-zy*zy+x;
	zy = 2.0*temp*zy+y;
    abs_z_2=zx*zx+zy*zy;
  }
  return i;
}

// 把上面的函数的大多数结果映射到(0,2)之间，因为我用的colorfunction在
// 这个区间变化迅速。

double mf(double x, double y)
{
  int max=100+mm;
  /*
  double cx;
  double cy;
  double r;
  for(r=0.0;r<=2.2;r+=0.2)
	if(x*x+y*y<=(r+0.001)*(r+0.001)&&x*x+y*y>=(r-0.001)*(r-0.001))
	  return 1.0;
  for(cx=-2.2;cx<=0.8;cx+=0.2)
	if(((x-cx)<=0.001&&(x-cx)>=-0.001))
	  return 1.0;
  for(cy=-1.4;cy<=1.4;cy+=0.2)
	if(((y-cy)<=0.001&&(y-cy)>=-0.001))
	  return 1.0;
  */
  int a=Mandelbrot(x,y,max);
  //if(a==max)
  //	return -10.0;
  return 1.7*2.0*log(a)/log(max)-1.1;
  //return 1.6*2.0*log(a)/log(max)-1.5;
  //return 1.25*2.0*log(a)/log(max)-1.39;
}

double colormap(double x, double y)
{
  x=0;
  return y;
}

int main(void)
{
  int width,height;
  double xrange[2];
  double yrange[2];
  double cx,cy,l;
  char filename[200]="default.png";
  FILE *ofp;
  int index=0;
  char selection;

#define setxrange(c,l) {xrange[0]=c-l/2.0;xrange[1]=c+l/2.0;}
#define setyrange(c,l) {yrange[0]=c-l/2.0;yrange[1]=c+l/2.0;}

  cx=-0.75;
  cy=0.0;
  l=2.7;

  setxrange(cx,l);
  setyrange(cy,l);

  do{
	width=800;
	height=(int)(((double)width)*(yrange[1]-yrange[0])/(xrange[1]-xrange[0])+0.5);

	sprintf(filename,"%d(%f,%f).png",index,cx,cy);
	if((ofp=fopen(filename,"wb"))==NULL)
	  exit(1);
	displayplot(ofp,
				width,height,     // img size
				mf,              // function to plot
				xrange[0],xrange[1],    // x range
				yrange[0],yrange[1],    // y range
				hitcolor);

	fclose(ofp);

	printf("Input a number or 'q' to quit [1~9]:");
	do{
	  selection=getchar();
	}while((selection<'1'||selection>'9')&&
		   selection!='q');
	/*
	switch(selection){
	case '1':cx+=l/4;cy+=l/4;l/=2;break;
	case '2':cx-=l/4;cy+=l/4;l/=2;break;
	case '3':cx-=l/4;cy-=l/4;l/=2;break;
	case '4':cx+=l/4;cy-=l/4;l/=2;break;
	}
	*/
	l=l*2.0/3.0;
	switch(selection){
	case '1':cx-=l/2;cy+=l/2;break;
	case '2':        cy+=l/2;break;
	case '3':cx+=l/2;cy+=l/2;break;
	case '4':cx-=l/2;        break;
	case '5':                break;
	case '6':cx+=l/2;        break;
	case '7':cx-=l/2;cy-=l/2;break;
	case '8':        cy-=l/2;break;
	case '9':cx+=l/2;cy-=l/2;break;
	}

	setxrange(cx,l);
	setyrange(cy,l);
	++index;
	mm+=50;
  }while(selection!='q');

  return 0;
}

