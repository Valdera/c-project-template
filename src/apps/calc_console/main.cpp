#include <ftxui/component/screen_interactive.hpp>
#include <tui/tui.hpp>

int main(int argc, char** argv) {
  ftxui::ScreenInteractive::FitComponent().Loop(getTui());
  return 0;
}
