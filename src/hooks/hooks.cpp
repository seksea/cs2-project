#include "includes.hpp"

void hooks::impl::init( )
{
    MH_Initialize( );

    // init hooks.
    {
        hooks::frame_stage_notify::init( );
        hooks::present::init( );
        hooks::create_move::init( );
    }

    MH_EnableHook( MH_ALL_HOOKS );
}