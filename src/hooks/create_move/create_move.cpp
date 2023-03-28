#include "includes.hpp"

bool __fastcall hooks::create_move::hook( void* ecx, int a2, unsigned __int8 a3 )
{
    return m_hook.call_original< decltype( &hook ) >( )( ecx, a2, a3 );
}

void hooks::create_move::init( )
{
    auto status = m_hook.create_hook( signature::search( HASH( "client.dll" ),
                                                         XOR( "48 8B C4 48 89 58 10 48 89 48 08 55 56 57 41 54 41 55" ) ).get< void * >( ), reinterpret_cast< void * >( &hook ) );

    assert_hook( status );
}