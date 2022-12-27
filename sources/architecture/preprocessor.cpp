#include "preprocessor.hpp"
#include "terminal.hpp"

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
  lib::line_type string = term::display("done!"),
    path = this->library_.get<lib::line_type>("path");
  file::write(path, string);
}

void Preprocessor::del(lib::lines_type &lines)
{
  lib::line_type Name = lines.front();
  library_.erase(Name);
  lib::line_type string = term::display("done!"),
    path = this->library_.get<lib::line_type>("path");
  file::write(path, string);
}

void Preprocessor::asg(lib::lines_type &lines)
{
  lib::line_type Value = lines.back(), Name = lines.front();
  library_.assign(Value, Name);
  lib::line_type string = term::display("done!"),
    path = this->library_.get<lib::line_type>("path");
  file::write(path, string);
}
