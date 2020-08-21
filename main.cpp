#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include "isosurface.h"
#include "hsvtorgb.h"

#define WITDH 600*2
#define HEIGHT 600

#define _USE_MATH_DEFINES

using namespace std;
using namespace sf;

int main ()
{
    //Inicializacion de la ventana
    VideoMode mode(WITDH,HEIGHT,32);
    RenderWindow wnd;
    Event handler;
    wnd.create(mode,"Newton Fractal");

    //Set resources for Fractal
    Uint8 *fractalPixels;
    Vector2u fractalSize(WITDH/2,HEIGHT);
    fractalPixels=new Uint8 [fractalSize.x*fractalSize.y*4];

    Texture fractalTexture;
    fractalTexture.create(fractalSize.x,fractalSize.y);

    Sprite fractal;

    //Set resources for path


    while (wnd.isOpen())
    {
        while (wnd.pollEvent(handler))
        {
            if (handler.type==Event::Closed) wnd.close();
        }
        wnd.clear(Color::Black);

        drawFractal(fractalPixels,fractalSize,-2,2);
        fractalTexture.update(fractalPixels);
        fractal.setTexture(fractalTexture);

        wnd.draw(fractal);

        wnd.display();
    }

    delete []fractalPixels;

    return 0;
}
