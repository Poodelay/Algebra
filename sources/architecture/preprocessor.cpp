#include "preprocessor.hpp"

Preprocessor::Preprocessor(lib::library_type &library) : library_{library},
  commands_
{
  {"SET", &Preprocessor::set},
  {"DEL", &Preprocessor::del},
  {"ASG", &Preprocessor::asg}
}
{}

void Preprocessor::set(lib::lines_type &lines)
{
  lib::line_type Value = lines.back(), Name = lines.front();
  library_.flag = false;
  library_.set(Name,Value);
}

void Preprocessor::del(lib::lines_type &lines)
{
  lib::line_type Name = lines.front();
  library_.erase(Name);
}

void Preprocessor::asg(lib::lines_type &lines)
{
  lib::line_type Value = lines.back(), Name = lines.front();
  library_.assign(Value, Name);
}
