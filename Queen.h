#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen : public Piece
{
public:
    Queen() = delete;
    Queen(std::string color): Piece(color){}
    std::string GetColor() const override { return "Queen\n"; }
    uint16_t GetID() const override {}
    ~Queen(){std::cout<<"Queen destroyed\n";}
};

#endif // QUEEN_H
