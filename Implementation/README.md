# Building on Windows #

### Requirements (For one-click build) ###
* Install Visual Studio 2015 - https://www.visualstudio.com/en-us/products/visual-studio-community-vs.aspx


### Running the Build ###
1. In the Implementation directory, run win-build.bat and wait for the build to complete.
2. This will generate Run-Debug and Run-Release shortcuts. Click these to run the game.

### Running the build from within Visual Studio ###
1. Go to the Implementation/src directory, and run win-make.bat. 
2. This will generate TeamUSA.sln, open this file using Visual Studio 2015.
3. You can browse the code and make changes here. Go to Build->Build Solution to build the project. 
4. Once it is built, below the top menu click the "Local Windows Debugger" button with the green play button to run the program within the debugger.


# Building on Linux #
1. Write a Linux kernel from scratch.
2. Implement a C++ compiler and linker.
3. Design and implement an IDE for use with your C++ compiler and linker.
4. Now create a project with all the TeamUSA source files in your custom IDE and build.


# Building on OS X #
1. Throw your Linux and/or Windows box out the window. (Especially Jordan)
2. Execute $cd /path/to/TeamUSA/Implementation
3. Then $make -f Makefile.mac 
4. Run the executable with $./convenienced


