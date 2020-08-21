#include <SFML/Graphics.hpp>
#include <iostream>
#include <complex.h>
#include "hsvtorgb.h"

double mapInterval (double,double,double,double,double);

void setPixelColor (sf::Uint8*,sf::Vector2u,int,int,sf::Color);

void drawFractal (sf::Uint8*,sf::Vector2u,float,float);
sf::Color fractalClasifier (std::complex<double>*,std::complex<double>);

std::complex<double> f(std::complex<double>);
std::complex<double> f_p(std::complex<double>);
