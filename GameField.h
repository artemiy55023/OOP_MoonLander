//
// Created by Artemiy on 19.11.2026.
//

#ifndef OOP_MOONLANDER_GAMEFIELD_H
#define OOP_MOONLANDER_GAMEFIELD_H
#include "Lander.h"
#include "MoonSurface.h"
#include "StatusPanel.h"


class GameField {
public:
    GameField(StatusPanel *st,int screen_width, int screen_height);

    GameField operator=(const GameField &gf);


    void show();
    void controller(bool w_presed,bool s_presed,bool a_presed,bool d_presed,float dt);
    void create(int screen_width, int screen_height);
    LanderStatus getLanderStatus();

private:
    StatusPanel *_sp;

    int checkContact();
    void showTelemetry();



    MoonSurface _moon_surface;
    Lander _lander;
    int _screen_width;
    int _screen_height;


};


#endif //OOP_MOONLANDER_GAMEFIELD_H
