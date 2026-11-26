//
// Created by Artemiy on 19.11.2026.
//

#ifndef OOP_MOONLANDER_GAME_H
#define OOP_MOONLANDER_GAME_H
#include "GameField.h"
#include "StatusPanel.h"


class Game {
public:
    Game();
    void run();
private:
    StatusPanel _sp;
    GameField _gf;
    int _screenWidth;
    int _screenHeight;
};


#endif //OOP_MOONLANDER_GAME_H
