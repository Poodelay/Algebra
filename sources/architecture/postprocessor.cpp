#include "postprocessor.hpp"

Postprocessor::Postprocessor (lib::library_type &library) : library_{library}, commands_
{ {"SIZE", &Postprocessor::size},
  {"ANC",&Postprocessor::allNameConsol},
//{"ALF",&Postprocessor::allNameFile},
  {"CLC",&Postprocessor::clearPost},
  {"EXS",&Postprocessor::exs}
}
{}

void Postprocessor::size (lib::lines_type &lines)
{
  term::display(library_.size());
}

void Postprocessor::allNameConsol (lib::lines_type &lines)
{
  lines = library_.allNames();
  for (auto i = lines.cbegin(); i != lines.cend(); ++i)
  {std::cout << *i << ' ';}
  std::cout << std::endl;
}

// void Postprocessor::allNameFile (lib::lines_type &lines) {}

void Postprocessor::clearPost(lib::lines_type &lines)
{
  system("clear");
}

void Postprocessor::exs(lib::lines_type &lines)
{
  term::display(std::boolalpha, library_.exists(lines.front()));
}
