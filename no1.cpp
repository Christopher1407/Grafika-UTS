#include<iostream.h>
#include<dos.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
void display (int xs1, int ys1, int x, int y);
void ellips1(int xs1,int ys1,int rx, int ry)
{
    int x,y;
    float d1,d2,dx,dy;
    x = 0;                  
    y = ry;                 
    d1 = pow(ry,2) - (pow(rx,2) * ry) + (0.25 * pow(rx,2));
    dx = 2 * pow(ry,2) * x;
    dy = 2 * pow(rx,2) * y;
    do
    {
        display(xs1,ys1,x,y);
        if(d1<0)
        {
            x++;
            dx = dx + (2 * (pow(ry,2)));
            d1 = d1 + dx +(pow(ry,2));
        }
        else
        {
            x++;
            y--;
            dx = dx + (2 * (pow(ry,2)));
            dy = dy - (2 * (pow(rx,2)));
            d1 = d1 + dx - dy + (pow(ry,2));
        }
    }while(dx<dy);
    do
    {
        display(xs1,ys1,x,y);
        if(d2>0)
        {
            x = x;
            y--;
            dy = dy - (2 * (pow(rx,2)));
            d2 = d2 - dy + pow(rx,2);
        }
        else
        {
            x++;
            y--;
            dy = dy - (2 * (pow(rx,2)));
            dx = dx + (2 * (pow(ry,2)));
            d2 = d2 +dx - dy + pow(rx,2);
  
        }
    }while(y>0);
}
void display(int xs,int ys,int x,int y)
{
    putpixel(xs+x,ys+y,WHITE);
    putpixel(xs-x,ys-y,WHITE);
    putpixel(xs+x,ys-y,WHITE);
    putpixel(xs-x,ys+y,WHITE);
}
int main(void)
{
    int xs1,ys1;
    float rx1,ry1;
    int gd = DETECT,gm;           
    initgraph(&gd,&gm,"c:\\tc\\bgi");

    cout<<"Masukan Koordinat\n";
    cout<<"xc = \t";
    cin>>xs1;
    cout<<"yc = \t";
    cin>>ys1;
    cout<<"Radius X\t";
    cin>>rx1;
    cout<<"Radius Y\t";
    cin>>ry1;
    ellips1(xs1,ys1,rx1,ry1);
    getch();
    closegraph();
}