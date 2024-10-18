#include <calc/calc.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/dom/elements.hpp>
#include <iostream>
#include <string>
#include <tui/tui.hpp>

using namespace ftxui;
using namespace std;

string a{"12"}, b{"90"};

auto input_a = Input(&a, "Enter value for A");
auto input_b = Input(&b, "Enter value for B");

Component getTui() {
  return Renderer(Container::Vertical({input_a, input_b}), [&] {
    int sum = Calc::Sum(stoi(a), stoi(b));

    return vbox({
               input_a->Render(),
               input_b->Render(),
               separator(),
               text("Sum: " + to_string(sum)),
           }) |
           border;
  });
}
