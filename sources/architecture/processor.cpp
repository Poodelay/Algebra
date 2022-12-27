#include "processor.hpp"
#include "library.hpp"
#include <string>

Processor::Processor(lib::library_type &library) : library_{library},
  commands_
{ {"POW", &Processor::pow},
  {"SQRT", &Processor::sqrt},
  {"INC", &Processor::inc},
  {"SUM", &Processor::sum},
  {"SUB", &Processor::sub},
  {"MULT", &Processor::mult},
  {"DIV", &Processor::div}}
{}

void Processor::pow(lib::lines_type &lines)
{
  lib::floating_point_type *valuef = new lib::floating_point_type();
  lib::integer_number_type *valuei = new lib::integer_number_type();
  lib::line_type string, path = this->library_.get<lib::line_type>("path");

  try {
    lib::interpret(*valuef, lines.front(), this->library_);
    valuei = nullptr;
  } catch(...) {
    lib::interpret(*valuei, lines.front(), this->library_);
    valuef = nullptr;
  }

  if (valuef != nullptr) {
    string = term::display("result:", std::to_string(alg::pow(*valuef, std::stoi(lines.back()))));
  } else {
    string = term::display("result:", std::to_string(alg::pow(*valuei, std::stoi(lines.back()))));
  }
  file::write(path, string);
}

void Processor::sqrt(lib::lines_type &lines)
{
  lib::floating_point_type *valuef = new lib::floating_point_type();
  lib::integer_number_type *valuei = new lib::integer_number_type();
  lib::line_type string, path = this->library_.get<lib::line_type>("path");

  try {
    lib::interpret(*valuef, lines.front(), this->library_);
    valuei = nullptr;
  } catch(...) {
    lib::interpret(*valuei, lines.front(), this->library_);
    valuef = nullptr;
  }

  if (valuef != nullptr) {
    string = term::display("result:", std::to_string(alg::sqrt(*valuef)));
  } else {
    string = term::display("result:", std::to_string(alg::sqrt(*valuei)));
  }
  file::write(path, string);
}

void Processor::inc(lib::lines_type &lines)
{
  lib::floating_point_type *valuef = new lib::floating_point_type();
  lib::integer_number_type *valuei = new lib::integer_number_type();
  lib::line_type string, path = this->library_.get<lib::line_type>("path");

  try {
    lib::interpret(*valuef, lines.front(), this->library_);
    valuei = nullptr;
  } catch(...) {
    lib::interpret(*valuei, lines.front(), this->library_);
    valuef = nullptr;
  }

  if (valuef != nullptr) {
    string = term::display("result:", std::to_string(alg::inc(*valuef)));
  } else {
    string = term::display("result:", std::to_string(alg::inc(*valuei)));
  }
  file::write(path, string);
}

void Processor::sum(lib::lines_type &lines)
{
  lib::floating_point_type *valuef1 = new lib::floating_point_type(),
    *valuef2 = new lib::floating_point_type();
  lib::integer_number_type *valuei1 = new lib::integer_number_type(),
    *valuei2 = new lib::integer_number_type();
  lib::line_type string, path = this->library_.get<lib::line_type>("path");

  try {
    lib::interpret(*valuef1, lines.front(), this->library_);
    valuei1 = nullptr;
  } catch(...) {
    lib::interpret(*valuei1, lines.front(), this->library_);
    valuef1 = nullptr;
  }

  try {
    lib::interpret(*valuef2, lines.back(), this->library_);
    valuei2 = nullptr;
  } catch(...) {
    lib::interpret(*valuei2, lines.back(), this->library_);
    valuef2 = nullptr;
  }

  if (valuef1 != nullptr && valuef2 != nullptr) {
    string = term::display("result:", std::to_string(alg::sum(*valuef1, *valuef2)));
  } else if (valuef1 != nullptr && valuei2 != nullptr) {
    string = term::display("result:", std::to_string(alg::sum(*valuef1, *valuei2)));
  } else if (valuei1 != nullptr && valuef2 != nullptr) {
    string = term::display("result:", std::to_string(alg::sum(*valuei1, *valuef2)));
  } else {
    string = term::display("result:", std::to_string(alg::sum(*valuei1, *valuei2)));
  }
  file::write(path, string);
}

void Processor::sub(lib::lines_type &lines)
{
  lib::floating_point_type *valuef1 = new lib::floating_point_type(),
    *valuef2 = new lib::floating_point_type();
  lib::integer_number_type *valuei1 = new lib::integer_number_type(),
    *valuei2 = new lib::integer_number_type();
  lib::line_type string, path = this->library_.get<lib::line_type>("path");

  try {
    lib::interpret(*valuef1, lines.front(), this->library_);
    valuei1 = nullptr;
  } catch(...) {
    lib::interpret(*valuei1, lines.front(), this->library_);
    valuef1 = nullptr;
  }

  try {
    lib::interpret(*valuef2, lines.back(), this->library_);
    valuei2 = nullptr;
  } catch(...) {
    lib::interpret(*valuei2, lines.back(), this->library_);
    valuef2 = nullptr;
  }

  if (valuef1 != nullptr && valuef2 != nullptr) {
    string = term::display("result:", std::to_string(alg::sub(*valuef1, *valuef2)));
  } else if (valuef1 != nullptr && valuei2 != nullptr) {
    string = term::display("result:", std::to_string(alg::sub(*valuef1, *valuei2)));
  } else if (valuei1 != nullptr && valuef2 != nullptr) {
    string = term::display("result:", std::to_string(alg::sub(*valuei1, *valuef2)));
  } else {
    string = term::display("result:", std::to_string(alg::sub(*valuei1, *valuei2)));
  }
  file::write(path, string);
}

void Processor::mult(lib::lines_type &lines)
{
  lib::floating_point_type *valuef1 = new lib::floating_point_type(),
    *valuef2 = new lib::floating_point_type();
  lib::integer_number_type *valuei1 = new lib::integer_number_type(),
    *valuei2 = new lib::integer_number_type();
  lib::line_type string, path = this->library_.get<lib::line_type>("path");

  try {
    lib::interpret(*valuef1, lines.front(), this->library_);
    valuei1 = nullptr;
  } catch(...) {
    lib::interpret(*valuei1, lines.front(), this->library_);
    valuef1 = nullptr;
  }

  try {
    lib::interpret(*valuef2, lines.back(), this->library_);
    valuei2 = nullptr;
  } catch(...) {
    lib::interpret(*valuei2, lines.back(), this->library_);
    valuef2 = nullptr;
  }

  if (valuef1 != nullptr && valuef2 != nullptr) {
    string = term::display("result:", std::to_string(alg::mult(*valuef1, *valuef2)));
  } else if (valuef1 != nullptr && valuei2 != nullptr) {
    string = term::display("result:", std::to_string(alg::mult(*valuef1, *valuei2)));
  } else if (valuei1 != nullptr && valuef2 != nullptr) {
    string = term::display("result:", std::to_string(alg::mult(*valuei1, *valuef2)));
  } else {
    string = term::display("result:", std::to_string(alg::mult(*valuei1, *valuei2)));
  }
  file::write(path, string);
}

void Processor::div(lib::lines_type &lines)
{
  lib::floating_point_type *valuef1 = new lib::floating_point_type(),
    *valuef2 = new lib::floating_point_type();
  lib::integer_number_type *valuei1 = new lib::integer_number_type(),
    *valuei2 = new lib::integer_number_type();
  lib::line_type string, path = this->library_.get<lib::line_type>("path");

  try {
    lib::interpret(*valuef1, lines.front(), this->library_);
    valuei1 = nullptr;
  } catch(...) {
    lib::interpret(*valuei1, lines.front(), this->library_);
    valuef1 = nullptr;
  }

  try {
    lib::interpret(*valuef2, lines.back(), this->library_);
    valuei2 = nullptr;
  } catch(...) {
    lib::interpret(*valuei2, lines.back(), this->library_);
    valuef2 = nullptr;
  }

  if (valuef1 != nullptr && valuef2 != nullptr) {
    string = term::display("result:", std::to_string(alg::div(*valuef1, *valuef2)));
  } else if (valuef1 != nullptr && valuei2 != nullptr) {
    string = term::display("result:", std::to_string(alg::div(*valuef1, *valuei2)));
  } else if (valuei1 != nullptr && valuef2 != nullptr) {
    string = term::display("result:", std::to_string(alg::div(*valuei1, *valuef2)));
  } else {
    string = term::display("result:", std::to_string(alg::div(*valuei1, *valuei2)));
  }
  file::write(path, string);
}
