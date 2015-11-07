// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// Legend of the Great Unwashed (Working Title).
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file Assert.h
/// \brief Declares Assert macro class.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#pragma once

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

namespace USA { namespace AssertNS {

    static const bool CustomAssert( const bool exp,
                                const int line,
                                const char* file )
    {
        if ( !exp ) {
            bool ret = false;
#if defined ( WIN32 )
            std::string msg = "\r\nFILE: " + std::string( file ) +
                "\r\nLINE: " + "\r\nDo you wish to break?";
            if ( static_cast<int>( MessageBox( GetForegroundWindow(),
                                                msg.c_str(),
                                                "Assertion!",
                                                MB_YESNO | MB_ICONEXCLAMATION ) ) == IDYES ) {
                ret = true;
            }

            return ret;
#endif
        }

        return false;

    }
} // namespace AssertNS
using namespace AssertNS;

// Trigger debugger break if debug build, insert nop if release.
#if defined ( _DEBUG )
#define Assert( exp )\
if( CustomAssert( static_cast<const bool>( exp ), __LINE__, __FILE__ ) )\
{ _asm { int 3 } }
#else
#define Assert( exp ) ;
#endif

}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
