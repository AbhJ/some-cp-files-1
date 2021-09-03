#include <stdio.h>
#define g 25

  FILE *fp;
int get_int(float x){
	float y = (int)x;
	if(x - y >= 0.5)return (int)y + 1;
	return (int)y;
}
int main(){
  float i, j, sl = 2.5;
  fp = fopen("ex.svg", "w");
  fprintf(fp, "<?xml version=\"1.0\" standalone=\"no\" ?>\n");
  fprintf(fp, "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\" \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n\n");
  fprintf(fp, "<svg width=\"200px\" height=\"200px\" xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">\n");
  fprintf(fp, "<line x1=\"0\" y1=\"0\" x2=\"50\" y2=\"125\" style=\"stroke:rgb(255,0,0);stroke-width:2\" />");
  for(float x = 0; x <= 2; x += 1){
	  float y = sl * x;
		fprintf(fp, "<circle cx=\"%d\" cy=\"%d\" r=\"3\" stroke=\"black\" stroke-width=\"1\"/>\n", get_int(x)*g, get_int(y)*g);
  }

  fprintf(fp, "\n<text x=\"20\" y=\"410\" text-anchor=\"left\" font-size=\"15px\" fill=\"#aaaaaa\">PB (29-Oct-2020)</text>\n\n");

  fprintf(fp, "</svg>\n");
  fclose(fp);

  return 0;
}
