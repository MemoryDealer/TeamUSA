// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// Legend of the Great Unwashed (Working Title).
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file main.cpp
/// \brief Entry point of program.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#include "Headers.h"

#include "Engine/Engine.h"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

namespace MainNS {

    static void logError( const std::string& desc )
    {
        std::ofstream log( "error.log" );

        log << "Legend of the Great Unwashed Log:\n\n";
        log << "FATAL ERROR: " << desc << std::endl;

        log.close();
    }

}
using namespace MainNS;

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

int main( int argc, char** argv )
{
    try {
        USA::Engine engine;

        engine.run();
    }
    catch ( std::exception& e ) {
        logError( e.what() );
        return 1;
    }

    return 0;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
