// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// LEGEND OF THE GREAT UNWASHED
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file main.cpp
/// \brief Entry point of program.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#include "Headers.h"

#include "Engine/Engine.h"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

namespace MainNS {

	///
	/// \brief Writes an error message to the log file.
	/// \param desc The string containing the error message.
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
        teamusa::Engine engine;

        engine.run();
    }
    catch ( std::exception& e ) {
        logError( e.what() );
#if defined( DEBUG ) || defined( _DEBUG )
        std::cout << "FATAL ERROR: " << e.what() << std::endl;
        getchar();
#endif
        return 1;
    }

    return 0;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
