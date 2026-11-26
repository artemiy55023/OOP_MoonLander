//
// Created by Artemiy on 19.11.2026.
//

#include "StatusPanel.h"

#include <iostream>

#include "raylib.h"

void StatusPanel::showTelemetry(float height, float vx, float vy, float angle, float fuel) {
    DrawText(TextFormat("Height: %.02f",height),10,10,15,LIGHTGRAY);
    DrawText(TextFormat("VX    : %.02f",vx),10,25,15,LIGHTGRAY);
    DrawText(TextFormat("VY    : %.02f",vy),10,40,15,LIGHTGRAY);
    DrawText(TextFormat("Angle : %.02f",angle),10,55,15,LIGHTGRAY);
    DrawText(TextFormat("Fuel  : %.02f",fuel),10,70,15,LIGHTGRAY);
}

void StatusPanel::showResult(LanderStatus status) {
    std::cout<<"res";
    BeginDrawing();
    if (status==LanderStatus::Destroyed) {
        std::cout<<"fail";

        DrawText("You faild",_screen_width/3,_screen_height/5*2,50,RED);

    }else {
        std::cout<<"win";

        DrawText("You WIN",_screen_width/3,_screen_height/5*2,50,LIGHTGRAY);
    }
    EndDrawing();
}

StatusPanel::StatusPanel(int screen_width, int screen_height) {
    _screen_height=screen_height;
    _screen_width=screen_width;
}

StatusPanel::StatusPanel() {
}
