#include "includes.hpp"

void interfaces::impl::init( )
{
    // interfaces.
    m_globals       = utils::resolve_rip( signature::search( HASH( "client.dll" ), XOR( "48 8B 05 ? ? ? ? 4C 8D 0D ? ? ? ? F2 0F 11 74 24 ? 4C 8D 05 ? ? ? ? BA ? ? ? ? 8B" ) ).get( ), 3, 7 ).deref( ).get< sdk::c_global_vars_base * >( );
    m_render_system = utils::resolve_rip( signature::search( HASH( "rendersystemdx11.dll" ), XOR( "66 0F 7F 05 ? ? ? ? 66 0F 7F 0D ? ? ? ? 48 89 35 ? ? ? ?" ) ).get( ), 4, 8 ).deref( 2 ).get< sdk::c_render_system* >( );
    m_swap_chain    = m_render_system->m_swap_chain;
    m_client        = create_interface< sdk::c_client* >( HASH( "client.dll" ), HASH( "Source2Client002" ) );
}

using interface_fn = void * ( __cdecl * )( );

struct interface_reg_t
{
    interface_fn m_callback;
    const char * m_name;
    interface_reg_t * m_next;
};

template< typename T = void* >
T interfaces::impl::create_interface( const hash32_t& module_name, const hash32_t& interface_name )
{
    auto create_interface_fn = g_winapi.get_exported_function< __int64 ( __fastcall * ) ( const char *, DWORD * ) >( module_name, HASH( "CreateInterface" ) );

    if ( !create_interface_fn )
        return nullptr;

    auto interface_list = utils::resolve_rip( reinterpret_cast< std::uint8_t* >( create_interface_fn ), 3, 7 ).deref( ).get< interface_reg_t* >( );

    for ( auto it = interface_list; it; it = it->m_next ) {
        if ( HASH( it->m_name ) != interface_name )
            continue;

        auto callback = reinterpret_cast< T >( it->m_callback( ) );

        spdlog::info( "interface: Found interface: {} at [{}]", it->m_name, reinterpret_cast< void* >( callback ) );

        return callback;
    }

    return nullptr;
}