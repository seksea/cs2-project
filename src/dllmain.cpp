#include "includes.hpp"

void __stdcall cheat_thread( )
{
    g_console.init( );
    g_interfaces.init( );
    g_schema.init( );
    g_hooks.init( );

    while ( !GetAsyncKeyState( VK_END ) )
        std::this_thread::sleep_for( std::chrono::milliseconds( 500 ) );

    g_hooks.shutdown( );
    g_console.shutdown( );
    FreeLibraryAndExitThread( globals::dll, 0 );
}

int __stdcall DllMain( HMODULE mod, unsigned long reason, void *instance )
{
    globals::dll = mod;

    if ( reason == DLL_PROCESS_ATTACH ) {
        const auto h = CreateThread( nullptr, 0, LPTHREAD_START_ROUTINE( cheat_thread ), mod, 0, nullptr );

        if ( !h )
            return 0;

        CloseHandle( h );
    }

    return 1;
}