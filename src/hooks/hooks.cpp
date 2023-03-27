#include "includes.hpp"

void hooks::impl::init( )
{
    g_interfaces.m_window = FindWindowA( XOR( "SDL_app" ), nullptr );

    MH_Initialize( );
    {
        hooks::present::init( );
        hooks::wndproc::init( );
        hooks::frame_stage_notify::init( );
        hooks::create_move::init( );
    }
    MH_EnableHook( MH_ALL_HOOKS );
}