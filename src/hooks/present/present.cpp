#include "includes.hpp"

HRESULT __stdcall hooks::present::hook( IDXGISwapChain* swap_chain, unsigned int sync_interval, unsigned int flags )
{
    return m_hook.call_original< decltype( &hook ) >( )( swap_chain, sync_interval, flags );
}

void hooks::present::init( )
{
    m_hook.create_hook( utils::get_method< void* >( g_interfaces.m_swap_chain, 8 ),
            reinterpret_cast< void* >( &hook ) );
}