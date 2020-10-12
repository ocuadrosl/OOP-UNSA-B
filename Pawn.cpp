#include "Pawn.h"

uint16_t Pawn::Counter{1};

Pawn::Pawn(std::string color) : Piece(color)
{
    ID = Pawn::Counter++;
}

std::string Pawn::GetColor() const
{
    return Color;
}

uint16_t Pawn::GetID() const
{
    std::cout<<Pawn::Max(10,8)<<std::endl;
    return ID;
}
