#pragma once
#include <ge211.hxx>
#include <vector>
#include <piece.hxx>
#include <iostream>
#include <unordered_map>


class Board{
public:

    // Board dimensions will use `int` coordinates.
    using Dimensions = ge211::Dims<int>;

    /// Board positions will use `int` coordinates.
    using Position = ge211::Posn<int>;

    /// Board rectangles will use `int` coordinates.
    using Rectangle = ge211::Rect<int>;

    //function to check the occupied positions on the board
    int is_occupied(Position where) const;

    explicit Board(Dimensions dims);

    // board of integer to set up filled positions to 1
    int mboard[20][10];

    // board of type to help in deleting rows filled and draw the sprites
    Piece_type tboard[20][10];


#ifdef CS211_TESTING
    // When this class is compiled for testing, members of a struct named
    // Test_access will be allowed to access private members of this class.
    friend struct Test_access;
#endif

private:

    //
    // PRIVATE DATA MEMBERS

    Dimensions dims_;


public:

    // check if a row is full and delete it on the board
    void delete_line(int row);

    /// Returns the same `Dimensions` value passed to the
    /// constructor.
    Dimensions dimensions() const;

    /// Returns whether the given position is in bounds.
    bool good_position(Position) const;

    /// Returns a rectangle containing all the positions of the board. This
    /// can be used to iterate over the positions:
    Rectangle all_positions() const;

};