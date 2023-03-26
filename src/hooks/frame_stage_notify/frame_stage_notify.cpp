#include "includes.hpp"

void __fastcall hooks::frame_stage_notify::hook( void* ecx, int a1 )
{
    m_hook.call_original< decltype( &hook ) >( )( ecx, a1 );

    int stage = a1 - 1;
}

void hooks::frame_stage_notify::init( )
{
    m_hook.create_hook( signature::search( HASH( "client.dll" ),
                                           XOR( "48 89 5C 24 ? 56 48 83 EC 30 8B 05 ? ? ? ? 8D 5A FF 3B C2 48" ) ).get< void* >( ), reinterpret_cast< void* >( &hook ) );
}