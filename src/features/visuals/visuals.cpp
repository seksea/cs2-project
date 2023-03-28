#include "includes.hpp"

void visuals::impl::run( )
{
    if ( !g_interfaces.m_engine_client->is_connected( ) || !g_interfaces.m_engine_client->is_in_game( ) )
        return;

    for ( int i = 1; i < g_interfaces.m_global_vars->m_max_clients; i++ ) {
        auto entity = game::get_entity_index< sdk::c_base_entity* >( i );

        if ( !entity )
            continue;

        auto pawn = game::get_player_pawn< sdk::c_base_player_pawn* >( entity );

        if ( !pawn || !pawn->alive( ) )
            continue;
    }
}