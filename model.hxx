#pragma once

#include <ge211.hxx>
#include <piece.hxx>
#include <board.hxx>

class Model{
public:
    /// Model dimensions will use `int` coordinates, as board dimensions do.
    using Dimensions = Board::Dimensions;

    /// Model positions will use `int` coordinates, as board positions do.
    using Position = Board::Position;

    /// Model rectangles will use `int` coordinates, as board rectangles do.
    using Rectangle = Board::Rectangle;

    /// Constructs a model with `size` as its rows number.
    Model(int size);

    /// Constructs a model with the given width and height.
    Model();

    /// Returns a rectangle containing all the positions of the board.
    /// This can be used to iterate over the positions.
    Rectangle board() const;


    // create a random piece so the player can exchange the current piece
    void update_piece ();


    // return the active piece inside the board
    Piece active_piece ()
    {return active_piece_ ;}

    //rotate the current piece inside the board
    void rotate_piece();


    // check the top row of the board and actually determine if there a full
    // column of board full and return game over
    bool is_game_over () ;

    //gives a shadow of the current piece at the bottom of the screen, also
    // check the lowest positon that the piece can actually reach
    void create_ghost();


    // increase the speed of the current piece
    void move_piece_faster();


    //add a piece to the board and update that position of the board to true.
    void lock_piece (Piece) ;

    //exchange the current piece if the player doesn't want it to be there if
    //
    void exchange_piece();

    //place the current piece at the very bottom position of the the board.
    void place_at_the_bottom();


    // Responsible for updating the score and checking it
    std::size_t score() const
    {return score_;}

    // Moves a piece left on left arrow press
    void move_left(Piece piece);

    // Moves a piece right on right arrow press
    void move_right(Piece piece);

    // Moves a piece down if it will not collide.
    //void move_down(Piece piece);
    void move_down();

    Piece active_piece_ = create_piece(random_piece());

    Board board_;

    std::vector<Piece> past_pieces;


    //clear a whole line in the board and check if any other line needs to be
    // cleared and update the score accordingly
    void clear_line();

    //Initially the first piece is not moving and the game doesn't start
    // until you press S button
    bool game_active = false;


    int times_swapped = 0;

    //Assign the ghost Piece to the current active piece
    Piece ghost_piece = active_piece_;
private:

    std::size_t score_ = 0;

    std::size_t score_increment_ = 0;


#ifdef CS211_TESTING
    // When this class is compiled for testing, members of a struct named
    // Test_access will be allowed to access private members of this class.

    friend struct Test_access;
#endif

    //check the collisions of any of the pieces going on the board
    bool check_collision(Piece p);

    // check that the game piece is inside the board limits
    bool is_it_inside_board(Piece p);


};
