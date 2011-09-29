#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* to make pnm2png verbose so we can find problems (needs to be before png.h) */
#ifndef PNG_DEBUG
#define PNG_DEBUG 0
#endif

#include "png.h"
#include"displayplot.h"

void color2rgb(int color, unsigned* r, unsigned* g, unsigned* b);

// 绘制函数 func ，采用 colorfunction 做配色方案
// 输出为 png 格式
int displayplot(FILE *png_file,
				unsigned width, unsigned height,
				double (*func)(double,double),
				double xmin, double xmax,
				double ymin, double ymax,
				int (*colorfunction)(double))
{
  unsigned row,col;
  //  unsigned r,g,b;
  double x,y,z;
  double xstep,ystep;
  int color;

  png_struct    *png_ptr = NULL;
  png_info      *info_ptr = NULL;
  png_byte      *png_pixels = NULL;
  png_byte      **row_pointers = NULL;
  png_byte      *pix_ptr = NULL;
  png_uint_32   row_bytes;

  int           color_type;
  int           bit_depth = 0;
  int           channels = 3;  // RGB
  unsigned      i;

  if(width<1 || height<1 || xmax<xmin || ymax<ymin)
	return EOF;

  xstep=(xmax-xmin)/width;
  ystep=(ymax-ymin)/height;

  color_type = PNG_COLOR_TYPE_RGB;
  bit_depth = 8;

  /* row_bytes is the width x number of channels x (bit-depth / 8) */
  row_bytes = width * channels;

  if ((png_pixels = (png_byte *) malloc (row_bytes * height * sizeof (png_byte))) == NULL)
    return EOF;

  /* read data from PNM file */
  pix_ptr = png_pixels;

  for(row = 0, y = ymax-ystep; row < height; row++, y-=ystep){
	for(col = 0, x = xmin; col < width; col++, x+=xstep){
	  z=func(x,y);
	  color=colorfunction(z);
	  *pix_ptr++ = (color>>16)&0xff;  //R
	  *pix_ptr++ = (color>>8)&0xff;   //G
	  *pix_ptr++ = (color)&0xff;      //B
	}
  }

  /* prepare the standard PNG structures */
  png_ptr = png_create_write_struct (PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
  if (!png_ptr)
    return EOF;

  info_ptr = png_create_info_struct (png_ptr);
  if (!info_ptr){
    png_destroy_write_struct (&png_ptr, (png_infopp) NULL);
    return EOF;
  }

  /* setjmp() must be called in every function that calls a PNG-reading libpng function */
  if (setjmp (png_jmpbuf(png_ptr))){
    png_destroy_write_struct (&png_ptr, (png_infopp) NULL);
    return EOF;
  }

  /* initialize the png structure */
  png_init_io (png_ptr, png_file);

  /* we're going to write more or less the same PNG as the input file */
  png_set_IHDR (png_ptr, info_ptr, width, height, bit_depth, color_type,
    PNG_INTERLACE_ADAM7,
    PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);

  /* write the file header information */
  png_write_info (png_ptr, info_ptr);

  /* if needed we will allocate memory for an new array of row-pointers */
  if (row_pointers == (unsigned char**) NULL)
  {
    if ((row_pointers = (png_byte **) malloc (height * sizeof (png_bytep))) == NULL)
    {
      png_destroy_write_struct (&png_ptr, (png_infopp) NULL);
      return EOF;
    }
  }

  /* set the individual row_pointers to point at the correct offsets */
  for (i = 0; i < (height); i++)
    row_pointers[i] = png_pixels + i * row_bytes;

  /* write out the entire image data in one call */
  png_write_image (png_ptr, row_pointers);

  /* write the additional chuncks to the PNG file (not really needed) */
  png_write_end (png_ptr, info_ptr);

  /* clean up after the write, and free any memory allocated */
  png_destroy_write_struct (&png_ptr, (png_infopp) NULL);

  if (row_pointers != (unsigned char**) NULL)
    free (row_pointers);
  if (png_pixels != (unsigned char*) NULL)
    free (png_pixels);

  return 1;
}

// 凑出来的一个配色方案，效果还凑合

#define plk(x,t,xx) (tanh(((x)-(xx))*(t))+1.0)/2.0

int goldencolor(double z)
{
  int r,g,b;
  int color;

  r=(int)(255*plk(z,3,0.4));
  g=(int)(255*plk(z,2,1));
  b=(int)(255*plk(z,3,1.6));

  color=(r<<16)+(g<<8)+(b);

  return color&0xffffff;
}

//另一个配色方案
#define f(x,a,xx) (tanh((a)*((x)-(xx)))+1.0)/2.0

int hitcolor(double z){
  int color;
  int r,g,b;
  double rr,gg,bb;

  rr=(f(z,4.0,0.7)+f(-z,3.5,-1.8))-1;
  gg=(f(z,4.0,0.5)+f(-z,4.0,-1.5))-1;
  bb=(f(z,4.0,0.3)+f(-z,4.0,-1.3))-1;

  r=((int)(255*rr))&0xff;
  g=((int)(255*gg))&0xff;
  b=((int)(255*bb))&0xff;
  color=(r<<16)+(g<<8)+(b);
  return color&0xffffff;
}

int seacolor(double z)
{
  int r,g,b;
  int color;

  b=(int)(255*plk(z,3,0.4));
  g=(int)(255*plk(z,2,1));
  r=(int)(255*plk(z,3,1.6));

  color=(r<<16)+(g<<8)+(b);

  return color&0xffffff;
}

int foristcolor(double z)
{
  int r,g,b;
  int color;

  g=(int)(255*plk(z,3,0.4));
  b=(int)(255*plk(z,2,1));
  r=(int)(255*plk(z,3,1.6));

  color=(r<<16)+(g<<8)+(b);

  return color&0xffffff;
}

int grasscolor(double z)
{
  int r,g,b;
  int color;

  g=(int)(255*plk(z,3,0.4));
  b=(int)(255*plk(z,2,1));
  r=(int)(255*plk(z,3,1.6));

  color=(r<<16)+(g<<8)+(b);

  return color&0xffffff;
}

int pinkcolor(double z)
{
  int r,g,b;
  int color;

  r=(int)(255*plk(z,3,0.4));
  b=(int)(255*plk(z,2,1));
  g=(int)(255*plk(z,3,1.6));

  color=(r<<16)+(g<<8)+(b);

  return color&0xffffff;
}

int inkcolor(double z)
{
  int r,g,b;
  int color;

  b=(int)(255*plk(z,3,0.4));
  r=(int)(255*plk(z,2,1));
  g=(int)(255*plk(z,3,1.6));

  color=(r<<16)+(g<<8)+(b);

  return color&0xffffff;
}

int testcolor(double z)
{
  int r,g,b;
  int color;

  b=(int)(255*plk(z,3,0.4));
  r=(int)(255*plk(z,2,1));
  g=(int)(255*plk(z,3,1.6));

  color=(r<<16)+(g<<8)+(b);

  return color&0xffffff;
}
