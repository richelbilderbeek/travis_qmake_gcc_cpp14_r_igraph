#include <fstream>
#include <iostream>

auto create_r_script_text(const std::string& png_filename) noexcept
{
  return
    "png(filename = \"" + png_filename + "\")\n"
    "plot(sin, -pi, 2*pi, main = \"Sine\")\n"
    "dev.off()\n"
  ;
}

void create_r_script(
  const std::string& png_filename, const std::string& r_filename) noexcept
{
  std::ofstream f(r_filename);
  f << create_r_script_text(png_filename);
}

bool file_exists(const std::string& filename)
{
  std::fstream f;
  f.open(filename.c_str(),std::ios::in);
  return f.is_open();
}

int run_r_script(const std::string& r_filename)
{
  return std::system(("Rscript " + r_filename).c_str());
}

int main()
{
  const std::string png_filename{"travis_qmake_gcc_cpp14_r.png"};
  const std::string r_filename{"travis_qmake_gcc_cpp14_r.R"};
  create_r_script(png_filename, r_filename);
  run_r_script(r_filename);
  return file_exists(png_filename) ? 0 : 1;
}
