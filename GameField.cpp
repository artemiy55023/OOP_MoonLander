//
// Created by Artemiy on 19.11.2026.
//

#include "GameField.h"

#include <iostream>



GameField::GameField(StatusPanel *sp, int screen_width, int screen_height) :
    _moon_surface(screen_width, screen_height),
    _lander(screen_width,screen_height) {
    // std::cout << screen_width<<"-"<< screen_height<<std::endl;
    _sp = sp;
    _screen_height=screen_height;
    _screen_width=screen_width;

}

GameField GameField::operator=(const GameField &gf) {
    return *this;
}

void GameField::show() {
    _moon_surface.draw();
    _lander.draw();
    showTelemetry();
}

void GameField::controller(bool w_presed, bool s_presed, bool a_presed, bool d_presed,float dt) {
    if (w_presed) {
        _lander.workingMainEngine();
        // std::cout<<"w presed"<< std::endl;
    }
    if (a_presed) _lander.workingSecondaryEngine(-1);
    if (d_presed) _lander.workingSecondaryEngine(1);
    _lander.move(dt);
    bool safeVy = std::abs(_lander.getVy()) <= 40.0f;
    bool safeVx = std::abs(_lander.getVx()) <= 20.0f;
    int res= checkContact();
    if (res>0) {
        std::cout<<"colision ";

        if (!safeVy || !safeVx) {
            _lander.setStatus(LanderStatus::Destroyed);
        }else {
            if (res==2) {
                bool safeAngle = abs(_lander.getAngle()) <= 30.0f;
                if (safeVy && safeVx && safeAngle) {
                   _lander.setStatus(LanderStatus::Landed);
                } else {
                    _lander.setStatus(LanderStatus::Destroyed);
                }
            }
        }
    }
}

int GameField::checkContact() {
    auto [LLegX,LLegY] = _lander.getLegPosL();
    auto [RLegX,RLegY] = _lander.getLegPosR();


    if (abs(LLegY-_moon_surface.getY(LLegX))<1 && abs(RLegY-_moon_surface.getY(RLegX))<1) {
        return 2;
    }
    if (abs(LLegY>_moon_surface.getY(LLegX))) {
        // std::cout<<"lLegOnSurface"<< std::endl;
        _lander.lLegOnSurface(_moon_surface.getY(LLegX));
        return 1;
    }

    if (abs(RLegY>_moon_surface.getY(RLegX))) {
        _lander.rLegOnSurface(_moon_surface.getY(RLegX));
        return 1;
    }
    return 0;

}

void GameField::showTelemetry() {
    _sp->showTelemetry(_screen_height-_lander.getVy(),_lander.getVx(),_lander.getVy(),_lander.getAngle(),_lander.getFuel());
}

LanderStatus GameField::getLanderStatus() {
    return _lander.getStatus();
}
