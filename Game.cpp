//
// Created by Artemiy on 19.11.2026.
//

#include "Game.h"

#include <iostream>

#include "raylib.h"
#include "GameField.h"
#include "StatusPanel.h"

Game::Game() :
    _screenWidth(800),
    _screenHeight(450),
    _sp(800, 450),
    _gf(&_sp, 800, 450) {
}


void Game::run() {

    InitWindow(_screenWidth, _screenHeight, "MoonLander");
    SetTargetFPS(60);

    //_sp=StatusPanel(_screenWidth,_screenHeight);
    //_gf=GameField(&_sp,_screenWidth,_screenHeight);
    _gf.show();

   while (!WindowShouldClose()) {
       ClearBackground(BLACK);
        _gf.controller(
            IsKeyDown(KEY_W),
            IsKeyDown(KEY_S),
            IsKeyDown(KEY_A),
            IsKeyDown(KEY_D),
            1.0/60
            );
       BeginDrawing();
        _gf.show();
       EndDrawing();
       if (_gf.getLanderStatus()!=LanderStatus::InFlight) {
           _sp.showResult(_gf.getLanderStatus());
           WaitTime(5);
           break;
       }
   }
    CloseWindow();

}
