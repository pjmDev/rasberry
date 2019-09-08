#include <stdio.h>
#include <string>
#include "jpeglib.h"
 
 
int main(int argc, char** argv) {
	if (argc < 2) {
		printf("usage) ./cctv filename\n");
		return 0;
	}
 
std::string fn = argv[1];
if (fn.empty())
{
	printf("empty filename\n");
	return 0;
}
 
 
FILE* fp = fopen(fn.c_str(), "rb");
if (fp == NULL) {
	printf("Failed to open '%'s\n", fn.c_str());
	return 0;
}
 
struct jpeg_decompress_struct cinfo;
struct jpeg_error_mgr jerr;
 
cinfo.err = jpeg_std_error(&jerr);
jpeg_create_decompress(&cinfo);
jpeg_stdio_src(&cinfo, fp);
jpeg_read_header(&cinfo, true);
 
int w = cinfo.image_width;
int h = cinfo.image_height;
int d = cinfo.jpeg_color_space;
int out_h = cinfo.output_height;
 
printf("width:%d height:%d depth:%d out_height:%d\n", w, h ,d, out_h);
 
unsigned char *data = new unsigned char[w * h * d];
unsigned char *data0 = data;
int xx=0;

//printf("\nX%d, %d", cinfo.output_scanline,  cinfo.output_height);

//while (cinfo.output_scanline < cinfo.output_height) {
while (1) {
	printf("\nA");
	jpeg_read_scanlines(&cinfo, &data, 1);
	printf("\nA");

	printf("\nA%d %c %d", data[0], data[0]);
	printf("\nA%d %c %d", data[1], data[1]);
	printf("\nA%d %c %d", data[2], data[2]);
	printf("\nA");

break;

	data += d * cinfo.output_width;
}

unsigned char *pdata = data0;
int ii;
short ss;
for (int i=0 ; i<10 ; i++) {
	ii = (int)*pdata;
	ss = (short)*pdata;
	//printf("\n%d : %c %d", i, pdata, pdata);
	printf("\n%d : %d %d", i, ii, ss);
	pdata++;
}
 
fclose(fp);
jpeg_finish_decompress(&cinfo);
jpeg_destroy_decompress(&cinfo);
 
return 0;
 
}
