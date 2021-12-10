#ifndef SFMLPROJECT_EFFECT_H
#define SFMLPROJECT_EFFECT_H

class Effect {
protected:
    int time;
    int type;
    int value;
public:
    Effect();
    Effect(int _time, int _type, int _value);
    virtual void applyEffect() = 0;
};

#endif
