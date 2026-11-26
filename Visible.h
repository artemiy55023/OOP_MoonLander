//
// Created by Artemiy on 26.11.2026.
//

#ifndef OOP_MOONLANDER_VISIBLE_H
#define OOP_MOONLANDER_VISIBLE_H


class Visible {
public:
    virtual ~Visible() = default;

private:
    virtual void draw() = 0;
};


#endif //OOP_MOONLANDER_VISIBLE_H
