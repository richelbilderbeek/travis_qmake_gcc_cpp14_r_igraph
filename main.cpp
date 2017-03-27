#include <fstream>
#include <iostream>

auto create_r_script_text() noexcept
{
  return
    R"(install.packages("DAISIE", repos = "http://cran.uk.r-project.org"))"
  ;
}

void create_r_script(const std::string& r_filename) noexcept
{
  std::ofstream f(r_filename);
  f << create_r_script_text();
}

int run_r_script(const std::string& r_filename)
{
  return std::system(("Rscript " + r_filename).c_str());
}

int main()
{
  const std::string r_filename{"travis_qmake_gcc_cpp14_r_igraph.R"};
  create_r_script(r_filename);
  return run_r_script(r_filename);
}
