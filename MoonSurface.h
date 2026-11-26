//
// Created by Artemiy on 19.11.2026.
//

#ifndef OOP_MOONLANDER_MOONSURFACE_H
#define OOP_MOONLANDER_MOONSURFACE_H
#include <vector>

#include "Visible.h"


class MoonSurface:public Visible{
public:
    void draw() override;

    ~MoonSurface() override = default;

    float getY(float x);

    MoonSurface(int screen_width, int screen_height);


private:
    int _screen_width;
    int _screen_height;
    std::vector<float> _surface;
};


#endif //OOP_MOONLANDER_MOONSURFACE_H
