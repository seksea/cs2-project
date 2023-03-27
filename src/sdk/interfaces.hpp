#ifndef CS2_PROJECT_INTERFACES_HPP
#define CS2_PROJECT_INTERFACES_HPP

namespace sdk
{
    class c_render {
    public:
        PAD( 0x178 );
        IDXGISwapChain* m_swap_chain;
    };
}

namespace interfaces
{
    class impl {
    public:
        void init( );

        template< typename T >
        T create_interface( const hash32_t &module_name, const hash32_t &interface_name );

        // ...
        HWND m_window = nullptr;
        ID3D11RenderTargetView *m_render_target_view = nullptr;
        ID3D11Device *m_device = nullptr;
        ID3D11DeviceContext *m_device_context = nullptr;
        IDXGISwapChain *m_swap_chain = nullptr;

        // interfaces.
        sdk::c_global_vars_base *m_globals = nullptr;
        sdk::c_client *m_client = nullptr;
        sdk::c_schema_system *m_schema_system = nullptr;
        sdk::c_render *m_render = nullptr;
    };
}// namespace interfaces

inline interfaces::impl g_interfaces{ };

#endif//CS2_PROJECT_INTERFACES_HPP
