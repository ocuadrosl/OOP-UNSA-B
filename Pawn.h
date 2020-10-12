#ifndef PAWN_H
#define PAWN_H

#include <cinttypes>
#include "Piece.h"

class Pawn : public Piece
{
public:
    Pawn() = delete;
    Pawn(std::string color);
    std::string GetColor() const override;
    uint16_t GetID() const override;

    ~Pawn(){/*std::cout<<"Pawn destroyed\n";*/}

private:

    static uint16_t Counter;

    static uint16_t Max(int a, int b )
    {
        return ( a > b ) ? a : b;
    };

};

#endif // PAWN_H
