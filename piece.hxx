#pragma once
#include <ge211.hxx>
#include <vector>
#include <iostream>

enum class Piece_type
{
    square, //good
    t_flipped, //good
    z,
    line, //good
    L_shape,
    neither
};

class Piece{

public:

    //declaring position as ge211::posn<int>
    using Position = ge211::Posn<int>;


    Piece(
            Piece_type type,
            std::vector<Piece::Position>& pos,
            std::vector<Piece::Position>& actual_pos);

    //return the piece type
    Piece_type get_name() const;

    //explicit Piece (Piece& p);

    //velocity for the falling piece
    double velocity;

    // a vector of the current positions of piece blocks used for rotations only
    std::vector<Position> get_body() const;

    // a vector of Piece Positions to return the initial positions of each
    // block at the top of the screen
    std::vector<Position> get_actual_body() const;


    // vector of positions to rotate Piece
    std::vector<Position> pos_;

    //vector of position to draw piece and move it
    std::vector<Position> actual_pos_;


private:
    enum Piece_type type_;


};

Piece_type random_piece();

Piece create_piece(Piece_type type);


