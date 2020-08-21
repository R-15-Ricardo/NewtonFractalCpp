#include "isosurface.h"

#define EPSILON 0.1
#define ITERATIONS 9

using namespace sf;
using namespace std;

double mapInterval (double var, double ins, double ine, double outs, double oute)
{
    double d1,d2,dor;
    d1=ine-ins;
    d2=oute-outs;
    dor=outs-ins*(d2/d1);
    return var*(d2/d1)+dor;
}

double invertInterval (double)
{

}

void setPixelColor (Uint8 *pix,Vector2u size,int x,int y,Color c)
{
    int pos=4*(y*size.x+x);
    pix[pos]=c.r;
    pix[pos+1]=c.g;
    pix[pos+2]=c.b;
    pix[pos+3]=c.a;
}


void drawFractal(Uint8* pixels,Vector2u size,float inf,float sup)
{
    complex<double> roots[3];
    for (int k=0;k<3;k++) roots[k]=exp((k*2*M_PI)/3*1i);

    for (int y=0;y<size.y;y++)
    {
        for (int x=0;x<size.x;x++)
        {
            double zx=mapInterval(x,0,size.x,-2,2);
            double zy=mapInterval(y,0,size.y,-2,2);
            complex<double> z=zx+zy*1i;
            setPixelColor(pixels,size,x,y,fractalClasifier(roots,z));
        }
    }

}

Color fractalClasifier (complex<double>* convergentPts, complex<double> z)
{
    int hue[] = {360,112,240};
    complex<double> n0,n1,df;
    n1=z;
    for (int i=0;i<ITERATIONS;i++)
    {
        n0=n1;

        df=f_p(n0);
        if (df!=0.+0.i)
        {
            n1=n0-f(n0)/df;
        }
    }
    for (int i=0;i<3;i++)
    {
        double dist=norm(n1-convergentPts[i]);
        if (dist<EPSILON)
        {
            Color spot;
            spot=hsv(hue[i],0.87,pow(mapInterval(dist,0,EPSILON,1,0.1),2));
            return spot;
        }
    }
    return Color::Black;
}

complex<double> f (complex<double> z)
{
    return pow(z,3)-1.0;
}

complex<double> f_p (complex<double> z)
{
    return 3.0*pow(z,2);
}
