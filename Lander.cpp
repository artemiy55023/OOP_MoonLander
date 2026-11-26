//
// Created by Artemiy on 19.11.2026.
//

#include "Lander.h"

#include <cmath>
#include <complex>
#include <vector>

#include "raylib.h"

Lander::Lander(int screen_width, int screen_height) : _gravity(40), _thrustPower(200), _rotationSpeed(90), _fuelConsumption(5) {
    _x = screen_width/2;
    _y = screen_height / 10;
    _vx,_vy,_v_angle=0,0,0;
    _size=std::sqrt(screen_width*screen_height/70);
    _angle=0;
    _fuel=100;
    _isMainEngineActive=false;
    _status=LanderStatus::InFlight;


    _screen_width = screen_width;
    _screen_height = screen_height;
}



void Lander::draw() {
    // BeginDrawing();
    float rad = (_angle) * (PI / 180.0f);
    float cosA = cosf(rad);
    float sinA = sinf(rad);

    float posHx = _x ;
    float posHy = _y - _size;
    float dx = posHx - _x;
    float dy = posHy - _y;
    posHx = _x + (dx * cosA - dy * sinA);
    posHy = _y + (dx * sinA + dy * cosA);

    float posLx = _x-_size/2;
    float posLy = _y + _size/2;
    dx = posLx - _x;
    dy = posLy - _y;
    posLx = _x + (dx * cosA - dy * sinA);
    posLy = _y + (dx * sinA + dy * cosA);

    float posFx = _x ;
    float posFy =(_y+_size/4);
    dx = posFx - _x;
    dy = posFy - _y;
    posFx = _x + (dx * cosA - dy * sinA);
    posFy = _y + (dx * sinA + dy * cosA);

    float posRx = (_x + _size/2);
    float posRy = (_y + _size/2);
    dx = posRx - _x;
    dy = posRy - _y;
    posRx = _x + (dx * cosA - dy * sinA);
    posRy = _y + (dx * sinA + dy * cosA);

    DrawLine(posHx,posHy,posLx,posLy,BLUE);
    DrawLine(posHx,posHy,posRx,posRy,BLUE);
    DrawLine(posFx,posFy,posLx,posLy,BLUE);
    DrawLine(posFx,posFy,posRx,posRy,BLUE);
    // EndDrawing();

    DrawCircle(_x,_y,5,RED);
}

void Lander::move(float dt) {
    if (_status == LanderStatus::InFlight) {
        float ax = 0.0f;
        float ay = _gravity;
        if (_isMainEngineActive && _fuel > 0.0f) {
            float radians = _angle * (3.14159265f / 180.0f);
            ax += _thrustPower * std::sin(radians);
            ay -= _thrustPower * std::cos(radians);

            _fuel = std::max(0.0f, _fuel - _fuelConsumption * dt);
        }

        _vx += ax * dt;
        _vy += ay * dt;

         _x += _vx * dt;
         _y += _vy * dt;

        // Вращение ракеты
        _angle += _v_angle * dt;
        _v_angle *= 0.95f;

        _isMainEngineActive=false;
    }
}

void Lander::workingMainEngine() {
    _isMainEngineActive=true;
}

void Lander::workingSecondaryEngine(int direction) {
    if (_status == LanderStatus::InFlight) {
        _v_angle += direction * _rotationSpeed * 0.1f;
    }
}


std::pair<float, float> Lander::getLegPosL() {
    float rad = (_angle) * (PI / 180.0f);
    float cosA = cosf(rad);
    float sinA = sinf(rad);

    float posLx = _x-_size/2;
    float posLy = _y + _size/2;
    float dx = posLx - _x;
    float dy = posLy - _y;
    posLx = _x + (dx * cosA - dy * sinA);
    posLy = _y + (dx * sinA + dy * cosA);

    return {posLx,posLy};
}

std::pair<float, float> Lander::getLegPosR() {
    float rad = (_angle) * (PI / 180.0f);
    float cosA = cosf(rad);
    float sinA = sinf(rad);


    float posRx = (_x + _size/2);
    float posRy = (_y + _size/2);
    float dx = posRx - _x;
    float dy = posRy - _y;
    posRx = _x + (dx * cosA - dy * sinA);
    posRy = _y + (dx * sinA + dy * cosA);

    return {posRx,posRy};
}

void Lander::lLegOnSurface(float surfaceY) {
    float depth = getLegPosL().second - surfaceY;
    _y -= depth;
    _v_angle += 15.0f + std::abs(_vy) * 0.2f;
    _vy *= 0.2f;
    _vx *= 0.7f;
}

void Lander::rLegOnSurface(float surfaceY) {
    float depth = getLegPosR().second - surfaceY;
    _y -= depth;
    _v_angle -= (15.0f + std::abs(_vy) * 0.2f);
    _vy *= 0.2f;
    _vx *= 0.7f;
}


