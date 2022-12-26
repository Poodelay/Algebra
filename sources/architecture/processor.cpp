#include "processor.hpp"

Processor::Processor(lib::library_type &library) : library_{library},
  commands_
{ {"POW", &Processor::pow},
  {"SQRT", &Processor::sqrt},
  {"INC", &Processor::inc},
  {"SUM", &Processor::sum},
  {"SUB", &Processor::sub},
  {"MULT", &Processor::mult},
  {"DIV", &Processor::div}}
{
  this->flag_ = false;
}

Processor::Processor(lib::library_type &library, lib::line_type &path) : library_{library},
  commands_
{ {"POW", &Processor::pow},
  {"SQRT", &Processor::sqrt},
  {"INC", &Processor::inc},
  {"SUM", &Processor::sum},
  {"SUB", &Processor::sub},
  {"MULT", &Processor::mult},
  {"DIV", &Processor::div}},
  path_{path}
{
  this->flag_ = true;
}

// сейчас будут очень жесткие костыли

void Processor::pow(lib::lines_type &lines)
{
  lib::floating_point_type *valuef = new lib::floating_point_type();
  lib::integer_number_type *valuei = new lib::integer_number_type();

  try {
    lib::interpret(*valuef, lines.front(), this->library_);
    valuei = nullptr;
  } catch(...) {
    lib::interpret(*valuei, lines.front(), this->library_);
    valuef = nullptr;
  }

  if (this->flag_) {
    if (valuef != nullptr) {
      file::write(this->path_, "result:", alg::pow(*valuef, std::stoi(lines.back())));
    } else {
      file::write(this->path_, "result:", alg::pow(*valuei, std::stoi(lines.back())));
    }
  } else {
    if (valuef != nullptr) {
      term::display("result:", alg::pow(*valuef, std::stoi(lines.back())));
    } else {
      term::display("result:", alg::pow(*valuei, std::stoi(lines.back())));
    }
  }
}

void Processor::sqrt(lib::lines_type &lines)
{
  lib::floating_point_type *valuef = new lib::floating_point_type();
  lib::integer_number_type *valuei = new lib::integer_number_type();

  try {
    lib::interpret(*valuef, lines.front(), this->library_);
    valuei = nullptr;
  } catch(...) {
    lib::interpret(*valuei, lines.front(), this->library_);
    valuef = nullptr;
  }

  if (this->flag_) {
    if (valuef != nullptr) {
      file::write(this->path_, "result:", alg::sqrt(*valuef));
    } else {
      file::write(this->path_, "result:", alg::sqrt(*valuei));
    }
  } else {
    if (valuef != nullptr) {
      term::display("result:", alg::sqrt(*valuef));
    } else {
      term::display("result:", alg::sqrt(*valuei));
    }
  }
}

void Processor::inc(lib::lines_type &lines)
{
  lib::floating_point_type *valuef = new lib::floating_point_type();
  lib::integer_number_type *valuei = new lib::integer_number_type();

  try {
    lib::interpret(*valuef, lines.front(), this->library_);
    valuei = nullptr;
  } catch(...) {
    lib::interpret(*valuei, lines.front(), this->library_);
    valuef = nullptr;
  }

  if (this->flag_) {
    if (valuef != nullptr) {
      file::write(this->path_, "result:", alg::inc(*valuef));
    } else {
      file::write(this->path_, "result:", alg::inc(*valuei));
    }
  } else {
    if (valuef != nullptr) {
      term::display("result:", alg::inc(*valuef));
    } else {
      term::display("result:", alg::inc(*valuei));
    }
  }
}

void Processor::sum(lib::lines_type &lines)
{
  lib::floating_point_type *valuef1 = new lib::floating_point_type(),
    *valuef2 = new lib::floating_point_type();
  lib::integer_number_type *valuei1 = new lib::integer_number_type(),
    *valuei2 = new lib::integer_number_type();

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

  if (this->flag_) {
    if (valuef1 != nullptr && valuef2 != nullptr) {
      file::write(this->path_, "result:", alg::sum(*valuef1, *valuef2));
    } else if (valuef1 != nullptr && valuei2 != nullptr) {
      file::write(this->path_, "result:", alg::sum(*valuef1, *valuei2));
    } else if (valuei1 != nullptr && valuef2 != nullptr) {
      file::write(this->path_, "result:", alg::sum(*valuei1, *valuef2));
    } else {
      file::write(this->path_, "result:", alg::sum(*valuei1, *valuei2));
    }
  } else {
    if (valuef1 != nullptr && valuef2 != nullptr) {
      term::display("result:", alg::sum(*valuef1, *valuef2));
    } else if (valuef1 != nullptr && valuei2 != nullptr) {
      term::display("result:", alg::sum(*valuef1, *valuei2));
    } else if (valuei1 != nullptr && valuef2 != nullptr) {
      term::display("result:", alg::sum(*valuei1, *valuef2));
    } else {
      term::display("result:", alg::sum(*valuei1, *valuei2));
    }
  }
}

void Processor::sub(lib::lines_type &lines)
{
  lib::floating_point_type *valuef1 = new lib::floating_point_type(),
    *valuef2 = new lib::floating_point_type();
  lib::integer_number_type *valuei1 = new lib::integer_number_type(),
    *valuei2 = new lib::integer_number_type();

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

  if (this->flag_) {
    if (valuef1 != nullptr && valuef2 != nullptr) {
      file::write(this->path_, "result:", alg::sub(*valuef1, *valuef2));
    } else if (valuef1 != nullptr && valuei2 != nullptr) {
      file::write(this->path_, "result:", alg::sub(*valuef1, *valuei2));
    } else if (valuei1 != nullptr && valuef2 != nullptr) {
      file::write(this->path_, "result:", alg::sub(*valuei1, *valuef2));
    } else {
      file::write(this->path_, "result:", alg::sub(*valuei1, *valuei2));
    }
  } else {
    if (valuef1 != nullptr && valuef2 != nullptr) {
      term::display("result:", alg::sub(*valuef1, *valuef2));
    } else if (valuef1 != nullptr && valuei2 != nullptr) {
      term::display("result:", alg::sub(*valuef1, *valuei2));
    } else if (valuei1 != nullptr && valuef2 != nullptr) {
      term::display("result:", alg::sub(*valuei1, *valuef2));
    } else {
      term::display("result:", alg::sub(*valuei1, *valuei2));
    }
  }
}

void Processor::mult(lib::lines_type &lines)
{
  lib::floating_point_type *valuef1 = new lib::floating_point_type(),
    *valuef2 = new lib::floating_point_type();
  lib::integer_number_type *valuei1 = new lib::integer_number_type(),
    *valuei2 = new lib::integer_number_type();

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

  if (this->flag_) {
    if (valuef1 != nullptr && valuef2 != nullptr) {
      file::write(this->path_, "result:", alg::mult(*valuef1, *valuef2));
    } else if (valuef1 != nullptr && valuei2 != nullptr) {
      file::write(this->path_, "result:", alg::mult(*valuef1, *valuei2));
    } else if (valuei1 != nullptr && valuef2 != nullptr) {
      file::write(this->path_, "result:", alg::mult(*valuei1, *valuef2));
    } else {
      file::write(this->path_, "result:", alg::mult(*valuei1, *valuei2));
    }
  } else {
    if (valuef1 != nullptr && valuef2 != nullptr) {
      term::display("result:", alg::mult(*valuef1, *valuef2));
    } else if (valuef1 != nullptr && valuei2 != nullptr) {
      term::display("result:", alg::mult(*valuef1, *valuei2));
    } else if (valuei1 != nullptr && valuef2 != nullptr) {
      term::display("result:", alg::mult(*valuei1, *valuef2));
    } else {
      term::display("result:", alg::mult(*valuei1, *valuei2));
    }
  }
}

void Processor::div(lib::lines_type &lines)
{
  lib::floating_point_type *valuef1 = new lib::floating_point_type(),
    *valuef2 = new lib::floating_point_type();
  lib::integer_number_type *valuei1 = new lib::integer_number_type(),
    *valuei2 = new lib::integer_number_type();

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

  if (this->flag_) {
    if (valuef1 != nullptr && valuef2 != nullptr) {
      file::write(this->path_, "result:", alg::div(*valuef1, *valuef2));
    } else if (valuef1 != nullptr && valuei2 != nullptr) {
      file::write(this->path_, "result:", alg::div(*valuef1, *valuei2));
    } else if (valuei1 != nullptr && valuef2 != nullptr) {
      file::write(this->path_, "result:", alg::div(*valuei1, *valuef2));
    } else {
      file::write(this->path_, "result:", alg::div(*valuei1, *valuei2));
    }
  } else {
    if (valuef1 != nullptr && valuef2 != nullptr) {
      term::display("result:", alg::div(*valuef1, *valuef2));
    } else if (valuef1 != nullptr && valuei2 != nullptr) {
      term::display("result:", alg::div(*valuef1, *valuei2));
    } else if (valuei1 != nullptr && valuef2 != nullptr) {
      term::display("result:", alg::div(*valuei1, *valuef2));
    } else {
      term::display("result:", alg::div(*valuei1, *valuei2));
    }
  }
}
