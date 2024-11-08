#include "model.hxx"
#include <catch.hxx>
#include "board.hxx"

using namespace ge211;

using namespace std;


TEST_CASE("example test (TODO: replace this)")
{
    CHECK(1 + 1 == 2);
}

// TODO: Write preliminary model tests.



//The Test case here check if there is a full row and delete the full row and
// then checks if there is multiple lines
TEST_CASE("Deleting a row and multiple rows and seeing the score")
{
    Model b = Model();

    int score = b.score();

    // score at initial game is equal to zero
    CHECK(score == 0);

    // creating multiple piece to fill a row and then delete it
   Piece new_piece = create_piece(Piece_type::line);

   new_piece.actual_pos_ = {{0,19}, {1,19}, {2,19}, {3, 19}};

   b.lock_piece(new_piece);
   Piece new_piece2 = create_piece(Piece_type::line);

   new_piece2.actual_pos_ = {{4,19}, {5,19}, {6,19}, {7, 19}};

    b.lock_piece(new_piece2);
    Piece new_piece3 = create_piece(Piece_type::square);

    new_piece3.actual_pos_ = {{8,19}, {9,19}, {8,18}, {9, 18}};

    b.lock_piece(new_piece3);

    b.clear_line();

    score = b.score();

    // CHECK that the score is now greater than one and it actually clear a
    // whole row
    CHECK(score > 0);

    //CHECK that the two left positions of the score has actually dropped and
    // now the previous position is not locked on the board
    CHECK_FALSE(b.board_.mboard[18][9] == 1);
    CHECK_FALSE(b.board_.mboard[18][8] == 1);

    /// CHECKING that two rows are deleted
    // The pieces maded in this test cases takes two rows (The two rows at
    // the bottom of the board and we then place a piece at the top of the
    // two rows. Then We check if the piece at the top of the two rows
    // actually moved to the new lowest position

    Piece new_piece5 = create_piece(Piece_type::line);
    new_piece5.actual_pos_ = {{0,19}, {1,19}, {2,19}, {3, 19}};
    b.lock_piece(new_piece5);

    Piece new_piece6 = create_piece(Piece_type::line);
    new_piece6.actual_pos_ = {{4,19}, {5,19}, {6,19}, {7, 19}};
    b.lock_piece(new_piece6);

    Piece new_piece7 = create_piece(Piece_type::line);
    new_piece7.actual_pos_ = {{0,18}, {1,18}, {2,18}, {3, 18}};
    b.lock_piece(new_piece7);

    Piece new_piece8 = create_piece(Piece_type::line);
    new_piece8.actual_pos_ = {{4,18}, {5,18}, {6,18}, {7, 18}};
    b.lock_piece(new_piece8);

    Piece new_piece_at_the_top = create_piece(Piece_type::L_shape);
    new_piece_at_the_top.actual_pos_ = {{0,17}, {1,17}, {2,17}, {2, 16}};
    b.lock_piece(new_piece_at_the_top);

    Piece new_piece9 = create_piece(Piece_type::square);
    new_piece9.actual_pos_ = {{8,19}, {9,19}, {8,18}, {9, 18}};
    b.lock_piece(new_piece9);

    //CHECK THAT THOSE POSITIONS ARE NOW not full after calling clear line
    CHECK(b.board_.mboard[17][0] == 1);
    CHECK(b.board_.mboard[17][1] == 1);

    b.clear_line();

    score = b.score();



    // CHECK that the score is now greater than one and it actually clear a
    // whole row
    CHECK(score == 20);

    //CHECK THAT THOSE POSITIONS ARE NOW not full after calling clear line
    CHECK_FALSE(b.board_.mboard[17][0] == 1);
    CHECK_FALSE(b.board_.mboard[17][1] == 1);

}


TEST_CASE("Check Rotate and Check Move Down")
{
    Model b = Model();
    //Check that function moves the active piece down the screen
    b.active_piece_ = create_piece(Piece_type::square);
    Piece intial_p = b.active_piece_;
    //checking move down function
    b.move_down();
    b.move_down();
    b.move_down();
    CHECK_FALSE(b.active_piece_.actual_pos_ == intial_p.actual_pos_);
    //checks that the rotation function does nothing to a square
    //square shouldn't rotate
    Piece p_square = b.active_piece_;
    b.rotate_piece();
    CHECK(b.active_piece_.actual_pos_ == p_square.actual_pos_);
    //line cant rotate on the when its all the way against the way
    //in this case the line is against the top wall
    b.active_piece_ = create_piece(Piece_type::line);
    //cant flip at top or sides
    Piece p_line = b.active_piece_;
    b.rotate_piece();
    CHECK(b.active_piece_.actual_pos_ == p_line.actual_pos_);
    b.move_down();
    b.move_down();
    b.move_down();
    b.move_down();
    b.move_down();
    b.move_down();
    //test the whole cw loop of rotation for line
    CHECK_FALSE(b.active_piece_.actual_pos_ == p_line.actual_pos_);
    p_line.actual_pos_ = {{5,5},{5,6},{5,7},{5,8}};
    b.rotate_piece();
    CHECK(b.active_piece_.actual_pos_ == p_line.actual_pos_);
    p_line.actual_pos_ = {{4,6},{5,6},{6,6},{7,6}};
    b.rotate_piece();
    CHECK(b.active_piece_.actual_pos_ == p_line.actual_pos_);
    p_line.actual_pos_ = {{5,5},{5,6},{5,7},{5,8}};
    b.rotate_piece();
    CHECK(b.active_piece_.actual_pos_ == p_line.actual_pos_);
    p_line.actual_pos_ = {{4,6},{5,6},{6,6},{7,6}};
    b.rotate_piece();



    //check t flipped rotation
    b.active_piece_ = create_piece(Piece_type::t_flipped);
    Piece p_t = b.active_piece_;
    b.move_down();
    b.move_down();
    b.move_down();
    CHECK_FALSE(b.active_piece_.actual_pos_ == p_t.actual_pos_);
    p_t.actual_pos_ = {{6,4},{5,3},{5,4},{5,5}};
    b.rotate_piece();
    CHECK(b.active_piece_.actual_pos_ == p_t.actual_pos_);
    p_t.actual_pos_ = {{5,5},{6,4},{5,4},{4,4}};
    b.rotate_piece();
    CHECK(b.active_piece_.actual_pos_ == p_t.actual_pos_);
    p_t.actual_pos_ = {{4,4},{5,5},{5,4},{5,3}};
    b.rotate_piece();
    CHECK(b.active_piece_.actual_pos_ == p_t.actual_pos_);
    p_t.actual_pos_ = {{5,3},{4,4},{5,4},{6,4}};
    b.rotate_piece();
    CHECK(b.active_piece_.actual_pos_ == p_t.actual_pos_);


}

TEST_CASE("Check Game Over")
{
    //testing when a position in the top row is occupied then the game is over
    //aka pos.y of a piece = 0
    Model b = Model();
    bool gg = b.is_game_over();
    CHECK(gg == false);
    CHECK(b.board_.mboard[19][2] == 0);
    b.active_piece_ = create_piece(Piece_type::line);
    b.active_piece_.actual_pos_ = {{5,19},{5,18},{5,17},{5,16}};
    b.lock_piece(b.active_piece_);
    bool gg2 = b.is_game_over();
    CHECK(gg2 == false);
    CHECK(b.board_.mboard[19][5] == 1);
    b.active_piece_ = create_piece(Piece_type::line);
    b.active_piece_.actual_pos_ = {{5,15},{5,14},{5,13},{5,12}};
    b.lock_piece(b.active_piece_);
    bool gg3 = b.is_game_over();
    CHECK(gg3 == false);
    b.active_piece_ = create_piece(Piece_type::line);
    b.active_piece_.actual_pos_ = {{5,11},{5,10},{5,9},{5,8}};
    b.lock_piece(b.active_piece_);
    b.active_piece_ = create_piece(Piece_type::line);
    b.active_piece_.actual_pos_ = {{5,7},{5,6},{5,5},{5,4}};
    b.lock_piece(b.active_piece_);
    b.active_piece_ = create_piece(Piece_type::line);
    b.active_piece_.actual_pos_ = {{5,3},{5,2},{5,1},{5,0}};
    b.lock_piece(b.active_piece_);
    bool gg4 = b.is_game_over();
    CHECK(gg4 == true);
}

TEST_CASE("Piece Move")
{
    Model b = Model();
    //testing that the piece can move left fine by comparing it to its
    // initial position
    b.active_piece_ = create_piece(Piece_type::line);
    Piece copy_p = b.active_piece_;
    b.move_left(b.active_piece_);
    CHECK_FALSE(b.active_piece_.actual_pos_ == copy_p.actual_pos_);
    b.move_left(b.active_piece_);
    b.move_left(b.active_piece_);
    b.move_left(b.active_piece_);
    //continue to move piece left
    CHECK_FALSE(b.active_piece_.actual_pos_ == copy_p.actual_pos_);
    copy_p.actual_pos_ = b.active_piece_.actual_pos_;
    b.move_left(b.active_piece_);
    //active piece shouldn't be able to move left anymore
    CHECK(b.active_piece_.actual_pos_ == copy_p.actual_pos_);
    //checking that the piece can move right
    b.move_right(b.active_piece_);
    CHECK_FALSE(b.active_piece_.actual_pos_ == copy_p.actual_pos_);
}

TEST_CASE("Ghost piece")
{
    Model b = Model();
    //ghost piece should be initialized to the same positions and piece type
    // as the active piece
    CHECK(b.ghost_piece.actual_pos_ == b.active_piece_.actual_pos_);
    CHECK(b.ghost_piece.get_name() == b.active_piece_.get_name());
    //this function should move the ghost piece all the waay down
    //thus the ghost piece and actual piece shoudln't have the same pos
    b.create_ghost();
    CHECK_FALSE(b.ghost_piece.actual_pos_ == b.active_piece_.actual_pos_);
    //function sets the position of the piece equal to the position of the
    // ghost piece
    b.place_at_the_bottom();
    CHECK(b.ghost_piece.actual_pos_ == b.active_piece_.actual_pos_);

}
