#include <components.h>

InputComponent::InputComponent()
{
}

InputComponent::InputComponent(bool rightSignal, bool leftSignal, bool upSignal, bool downSignal) : right(rightSignal), left(leftSignal), up(upSignal), down(downSignal)
{
}
