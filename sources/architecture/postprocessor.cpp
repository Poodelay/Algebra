#include "postprocessor.hpp"
#include "library.hpp"
#include "terminal.hpp"
#include <list>
#include <string>

Postprocessor::Postprocessor (lib::library_type &library) : library_{library},
  commands_
{ {"SIZE", &Postprocessor::size},
  {"ANC",&Postprocessor::allNameConsol},
  {"CLC",&Postprocessor::clearPost},
  {"EXS",&Postprocessor::exs}
}
{}

void Postprocessor::size (lib::lines_type &lines)
{
  lib::line_type string =
    term::display
    ("in database", std::to_string(library_.size()), "variable(s)"),
    path = this->library_.get<lib::line_type>("path");
  file::write(path, string);
}

void Postprocessor::allNameConsol (lib::lines_type &lines)
{
  std::string line;
  lines = this->library_.allNames();
  auto it = lines.begin();
  for (std::size_t i = 0; i < lines.size(); ++i, ++it) {
    for (std::size_t j = 0; j < (*it).size(); ++j) {
      line.push_back((*it)[j]);
    }
    line.push_back(' ');
  }
  lib::line_type string = term::display("variable(s) in database: ", line),
    path = this->library_.get<lib::line_type>("path");
  file::write(path, string);
}

void Postprocessor::clearPost(lib::lines_type &lines)
{
  system("clear");
}

void Postprocessor::exs(lib::lines_type &lines)
{
  if (library_.exists(lines.front())) {
    lib::line_type string =
      term::display("variable ", lines.front(), " is exist"),
      path = this->library_.get<lib::line_type>("path");
    file::write(path, string);
  } else {
    lib::line_type string =
      term::display("variable ", lines.front(), " isn't exist"),
      path = this->library_.get<lib::line_type>("path");
    file::write(path, string);
  }
}
