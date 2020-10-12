#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <cinttypes>

class Piece
{

protected:

    std::string Color{};
    uint16_t ID{};

public:
    Piece() = delete;
    Piece(std::string color): Color{color} {};
    virtual std::string GetColor() const = 0;
    virtual uint16_t GetID() const = 0;
    virtual ~Piece(){/*std::cout<<"Piece destroyed\n";*/}

};

#endif // PIECE_H
