//
// Created by Artemiy on 19.11.2026.
//

#ifndef OOP_MOONLANDER_LANDER_H
#define OOP_MOONLANDER_LANDER_H
#include <utility>

#include "Visible.h"

enum class LanderStatus {
    InFlight,
    Landed,
    Destroyed
};

class Lander:public Visible{
    float _x,_y;
    float _vx,_vy;
    float _angle;
    float _v_angle;
    float _fuel;
    float _size;
    LanderStatus _status;
    const float _gravity;
    const float _thrustPower;
    const float _rotationSpeed;
    const float _fuelConsumption;
    bool _isMainEngineActive;


    int _screen_width;
    int _screen_height;


public:
    Lander(int screen_width, int screen_height);

    void draw() override;

    ~Lander() override = default;

    void move(float dt);
    void workingMainEngine();
    void workingSecondaryEngine(int direction);

    std::pair<float, float> getLegPosL();
    std::pair<float, float> getLegPosR();

    void rLegOnSurface(float surfaceY);
    void lLegOnSurface(float surfaceY);

    float getVx() const {
        return _vx;
    }
    float getVy() const {
        return _vy;
    }
    float getAngle() const {
        return _angle;
    }
    float getFuel() const {
        return _fuel;
    }
    void setStatus( LanderStatus status ) {
        _status=status;
    }

    LanderStatus getStatus(){return _status;};
};


#endif //OOP_MOONLANDER_LANDER_H
