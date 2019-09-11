#define MATRICKS_DEBUG 1


#include "matricks.h"

#include <iostream>
#include <string>

// used to demonstrate how to convert to C++ vectors
#include <vector>

#if CPP11 == 1
#include <initializer_list>
#endif


// ************************************************************
// The output screenshots are generated by examples/printing.cpp
// ************************************************************


int main()
{
  using namespace matricks;
  using namespace std;
  using namespace display;
  using namespace md;

  int Nex = 1;
  
  cr();
  mdtitle("\\*Formatted and styled printing");
  matricks_preamble();
  text("* The examples in this section can be found in file_ `examples/printing.cpp`\n");
  text("* All of the functions decribed in this section are in the namespace `display`");
  text("* Practically speaking, this functionality is one of the most useful aspects of mātricks.");


  // disp()
  
  header2("The function `disp(x)`");
  cr();cr();

  text("The function `disp(x)` displays both the variable name (or expression) as well as its value, formatted according to the user.   This is an incredibly useful function.");
  cr();cr();
  
  example(Nex++,"simple examples of `disp(x)` usage");
  cr();cr();
  text("Define and initialize some variables:");
  cr();cr();
  codestart("C++");
  codemulti(  int n = 45 );
  codemulti(  double x = 3.14 );
  codemulti(  double vals[] = {1.1,2.2,3.3} );
  codemulti(  bool done = true );
  codemulti( Vector<double> v = range<double>(1,10) );
  codemulti(  char str[] = "hello" );
  codemulti(  std::string s = "world"  );
  codemulti(  std::complex<double> z(1,-1)  );
  codeend();

  text("display each variable using `disp`:");
  cr();cr();

  codestart("C++");
  text("disp(n);");
  text("disp(x);");
  text("disp(vals);");
  text("disp(done);");
  text("disp(v);");
  text("disp(str);");
  text("disp(s);");
  text("disp(z);");
  codeend();

  cr();cr();
  text("The actual screen-shot of the output is shown below:");
  cr();cr();
  text("![disp example 1](disp_example1.png)");
  
  // tdisp()

  header2("The function `tdisp(x)`");
  cr();cr();

  text("The function `tdisp(x)` displays the variable type, in addition to the variable name and value");
  cr();cr();
  
  example(Nex++," `tdisp(x)` usage");

  cr();cr();

  codestart("C++");
  text("tdisp(n);");
  text("tdisp(x);");
  text("tdisp(vals);");
  text("tdisp(done);");
  text("tdisp(v);");
  text("tdisp(str);");
  text("tdisp(s);");
  text("tdisp(z);");
  codeend();

  cr();cr();
  text("The actual screen-shot of the output is shown below:");
  cr();cr();
  text("![disp example 2](disp_example2.png)");


  // mdisp()

  header2("The function `mdisp(x1,x2,...)`");
  cr();cr();

  text("* The function `mdisp(x1,x2,...)` displays multiple variables (from 1 to 10) on the same line.");
  text("* Very useful for displaying:");
  text("  * the arguments passed to a function");
  text("  * the variables inside a for loop");
  cr();cr();
  

  example(Nex++," `mdisp(x1,x2,...)` usage");
  cr();cr();

  codestart("C++");
  text("mdisp(n,x,vals,done,str,s,z);");
  codeend();

  cr();cr();
  text("The actual screen-shot of the output is shown below:");
  cr();cr();
  text("![disp example 3](disp_example3.png)");

  // tried this but doesn't help with displaying at the correct scale
  // the image are always blurred by github for some reason
  //text("<img src=\"disp_example3.png\" width=\"100%\" height=\"100%\">");



  // expressions

  header2("Displaying expressions");
  cr();cr();

  text("* The functions introduced above can also be used to display expressions.");
  text("* vector and matrix expressions can be displayed in this manner.");
  cr();cr();
  

  example(Nex++," displaying expressions");
  cr();cr();

  codestart("C++");
  text("disp(n+3);");
  text("disp(10*x-1);");
  text("disp(!done);");
  text("disp( round(10*sin(pi/10*v) + 10) );");
  text("disp(s+\" tour\");");
  codeend();

  cr();cr();
  text("The actual screen-shot of the output is shown below:");
  cr();cr();
  text("![disp example 4](disp_example4.png)");


  // expressions

  header2("Supported Types");
  cr();cr();

  text("The following types are currently supported by the display commands");
  text("* **Any class** with methods `.classname()` and `operator<<` is automatically supported");
  text("* `matricks::Vector<D>` vectors");
  text("* `matricks::Matrix<D>` matrices");
  text("* `bool`");
  text("* `short`, `int`, `long`, `long long`");
  text("* `unsigned short`, `unsigned int`, `unsigned long`, `unsigned long long`");
  text("* `float`, `double`, `long double`");
  text("* `char`, `unsigned char`");
  text("* `char[]` C-style strings");
  text("* `D[]` C-style arrays");
  text("* `std::string` C++ strings");
  text("* `std::complex<D>` complex numbers");
  text("* `std::vector` C++ vectors");
  text("* `std::valarray` C++ valarrays");
  text("* `std::vector` C++ vectors");
  text("* `std::list` C++ lists");
  text("* `std::queue` C++ queues");
  text("* `std::map` C++ maps");
  text("* `std::initializer_list` C++11 ");


  // debug-only printing

  header2("Debug-only printing");
  cr();cr();

  text("The display commands also have versions that only display when the code is compiled with the debug flag `MATRICKS_DEBUG` set.");
  text("* `disp1`, `tdisp1`, `mdisp1` will");
  text("  * when `MATRICKS_DEBUG >= 1`: behave like `disp`, `tdisp`, `mdisp`");
  text("  * when `MATRICKS_DEBUG == 0` or is undefined: compile to null statements (ie no output and no real-time hit)");

  text("* `disp2`, `tdisp2`, `mdisp2` will");
  text("  * when `MATRICKS_DEBUG >= 2`: behave like `disp`, `tdisp`, `mdisp`");
  text("  * when `MATRICKS_DEBUG < 2` or is undefined: compile to null statements (ie no output and no real-time hit)");


  text("* `disp3`, `tdisp3`, `mdisp3` will");
  text("  * when `MATRICKS_DEBUG >= 3`: behave like `disp`, `tdisp`, `mdisp`");
  text("  * when `MATRICKS_DEBUG < 3` or is undefined: compile to null statements (ie no output and no real-time hit)");

  header2("Controlling the output stream and color");
  text("* All output uses C++ streams (*no* `printf`)");
  text("* By default all output is sent to `std::cout`");
  text("* The output stream can be set using `Terminal::setmout(std::ostream&)`.");
  text("For example to set the output to stderr:");
  text("```C++\n");
  text("Terminal::setmout(std::cerr);");
  text("```\n");
  text("* You can use the matricks output stream via `Terminal::getmout()` or the macro `mout`");
  text("For example, you can output a string:");
  text("```C++\n");
  text("mout << \"Hello World\" << std::endl;\n");
  text("```\n");
  text("* By default, matricks uses color when it detects that the output stream is connected to a terminal.");
  text("* By default, matricks disables color when it detects that the output stream is piped to a file.");
  text("* However, the user can override this behavior as follows\n");
  text("To force matricks to use plain text, use the following settings:");
  text("```C++\n");
  text("Terminal::setColorOverride(true);");
  text("Terminal::setOverrideValue(false);");
  text("```\n");
  text("To force matricks to use color text, use the following settings:");
  text("```C++\n");
  text("Terminal::setColorOverride(true);");
  text("Terminal::setOverrideValue(true);");
  text("```\n");
  text("This latter setting can be used to print in colors to a file, which will display properly when the file is viewed via a terminal command like `more`,`less`, or `cat`.\n");
  
  cr();cr();
  header2("Customizing the format and colors");
  cr();cr();
  header3("Customizing number format");
  cr();cr();
  header3("Customizing complex number format");
  cr();cr();
  header3("Customizing Vector format");
  cr();cr();
  


  
  matricks_toc();

  return 0;
}
