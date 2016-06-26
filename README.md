## Molecular Magnet
Monte Carlo magnetization of molecular magnets

### Setup (Optional)
Setup a working c++ environment, including:
- A compiler (e.g. g++)
- Standard libraries.

On Windows, one recommendation is [MinGW](http://www.mingw.org). Follow their HOWTO, or look up one of numerous youtube videos available. In particular, it will be useful to setup the PATH variable to include **C:\MinGW\bin** (assuming a standard install)

NOTE: there is an issue when compiling with on windows with MinGW, involving their **math.h** (the bug is detailed [here](http://stackoverflow.com/questions/29450016/o1-2-3-with-std-c1y-11-98-if-cmath-is-included-im-getting-error-hypo)). If, in the course of compiling one receives an error involving something about "hypot", then this could be one potential reason. In this case the fix is to do the following:
  1. navigate to the culprit file (located at **C:\MinGW\include\math.h** assuming a standard installation of MinGW)
  2. create a backup of it just in case. We will be modifying the file.
  3. navigate to the line **635** in the file (or whichever line that the compiler is complaining about)
  4. change **_hypot** to **hypot**; that is, remove the leading underscore.

#### Compiling
When compiling, be sure to enable **c++11** as well as **optimizations**. (For g++, enabling c++11 is achieved with the **--std=c++11** or **--std=c++0x** flag; and optimizations is achieved with the **-O2** or **-O3** flag).

As an easier alternative, a [makefile](https://en.wikipedia.org/wiki/Makefile) has been included with the repo, to assist in compilation. One can then invoke **make {target}** to quickly build the specified targets, e.g. **make Tests**. 
- To build tests, invoke **make Tests** (or with MinGW, invoke **mingw32-make Tests**. This will require that the path variable be setup correctly)

