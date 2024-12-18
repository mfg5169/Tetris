#pragma once

#include "model.hxx"
#include "view.hxx"
#include <ge211.hxx>

class Controller : public ge211::Abstract_game
{
public:
    explicit Controller();

    Controller(int width, int height);

protected:
    void draw(ge211::Sprite_set& set) override;
    void on_key(ge211::Key) override;
    void on_key_up(ge211::Key key) override;
    void on_key_down(ge211::Key key) override;
    void on_frame(double) override;

    View::Dimensions initial_window_dimensions() const override;
    std::string initial_window_title() const override;

private:
    Model model_;
    View view_;
    double   max_frame = 20;
    double update_frame =0;
    double update_frame2 = 0;

};