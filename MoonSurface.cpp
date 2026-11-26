//
// Created by Artemiy on 19.11.2026.
//

#include "MoonSurface.h"
#include <algorithm>
#include <cmath>
#include <iostream>

#include "raylib.h"

MoonSurface::MoonSurface(int screen_width, int screen_height) {
    // std::cout << screen_width<<" "<< screen_height<<std::endl;
    float k1 = static_cast<float>(rand() % 1000);
    float k2 = static_cast<float>(rand() % 1000);
    _screen_width=screen_width;
    _screen_height=screen_height;
    _surface.resize(screen_width+2);
    for (int x=0; x<_screen_width;x++) {
        _surface[x]=_screen_height * 0.70f
                + std::sin(x * 0.005f + k1) * 80.0f
                + std::sin(x * 0.015f + k2) * 35.0f
                + std::cos(x * 0.030f) * 10.0f;;
    }
}

void MoonSurface::draw() {
    // BeginDrawing();
    for (int i=0; i<_screen_width;i++) {
        DrawPixel(i,getY(i),GREEN);
    }
    // EndDrawing();

}


float MoonSurface::getY(float x) {
    if (x>0 && x<_surface.size()) {
        return _surface[x];
    }
    return 0;
}


