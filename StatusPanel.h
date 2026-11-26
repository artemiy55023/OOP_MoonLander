//
// Created by Artemiy on 19.11.2026.
//

#ifndef OOP_MOONLANDER_STATUSPANEL_H
#define OOP_MOONLANDER_STATUSPANEL_H
#include "Lander.h"


class StatusPanel {
public:
    void showTelemetry(float height,float vx, float vy, float angle,float fuel);
    void showResult(LanderStatus status);

    StatusPanel();

    StatusPanel(int screen_width, int screen_height);
private:
    int _screen_width;
    int _screen_height;
};


#endif //OOP_MOONLANDER_STATUSPANEL_H
