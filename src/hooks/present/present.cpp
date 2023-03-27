#include "includes.hpp"

HRESULT __stdcall hooks::present::hook( IDXGISwapChain* swap_chain, unsigned int sync_interval, unsigned int flags )
{
    static bool init = false;

    if ( !init )
    {
        swap_chain->GetDevice( __uuidof( ID3D11Device ), reinterpret_cast< void** >( &g_interfaces.m_device ) );
        g_interfaces.m_device->GetImmediateContext( &g_interfaces.m_device_context );
        g_menu.init( );

        init = true;
    }

    ImGui_ImplDX11_NewFrame( );
    ImGui_ImplWin32_NewFrame( );
    ImGui::NewFrame( );

    g_menu.render( );

    ImGui::Render( );
    ImGui_ImplDX11_RenderDrawData( ImGui::GetDrawData( ) );

    return m_hook.call_original< decltype( &hook ) >( )( swap_chain, sync_interval, flags );
}

void hooks::present::init( )
{
    m_hook.create_hook( utils::get_method< void* >( g_interfaces.m_swap_chain, 8 ),
            reinterpret_cast< void* >( &hook ) );
}