#ifndef componentsH
#define componentsH

class InputComponent
{

public:
    bool right;
    bool left;
    bool up;
    bool down;
    InputComponent();
    InputComponent(bool right, bool left, bool up, bool down);
};

#endif
