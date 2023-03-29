#include "includes.hpp"

HRESULT __stdcall hooks::resizebuffers::hook( IDXGISwapChain *swap_chain, unsigned int buffer, unsigned int w, unsigned int h, DXGI_FORMAT format, unsigned int flags )
{
    auto result = m_hook.call_original< decltype( &hook ) >()( swap_chain, buffer, w, h, format, flags );

    g_render.m_screen_size.x = w;
    g_render.m_screen_size.y = h;

    g_interfaces.m_render_target_view->Release();

    ImGui_ImplDX11_InvalidateDeviceObjects();

    if ( SUCCEEDED( result ) ) {
        g_interfaces.m_swap_chain = swap_chain;

        ID3D11Texture2D *render_target_texture = nullptr;

        swap_chain->GetDevice( __uuidof( ID3D11Device ), reinterpret_cast< void ** >( &g_interfaces.m_device ) );
        g_interfaces.m_device->GetImmediateContext( &g_interfaces.m_device_context );
        swap_chain->GetBuffer( 0, __uuidof( ID3D11Texture2D ), reinterpret_cast< void ** >( &render_target_texture ) );

        D3D11_RENDER_TARGET_VIEW_DESC desc{};
        memset( &desc, 0, sizeof( desc ) );
        desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
        desc.ViewDimension = D3D11_RTV_DIMENSION_TEXTURE2DMS;

        g_interfaces.m_device->CreateRenderTargetView( render_target_texture, &desc, &g_interfaces.m_render_target_view );
        render_target_texture->Release();

        ImGui_ImplDX11_CreateDeviceObjects();
    }

    return result;
}

void hooks::resizebuffers::init()
{
    auto status = m_hook.create_hook( utils::get_method< void * >( g_interfaces.m_swap_chain, 13 ),
                                      reinterpret_cast< void * >( &hook ) );

    assert_hook( status );
}