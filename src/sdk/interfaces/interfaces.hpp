#ifndef CS2_PROJECT_INTERFACES_HPP
#define CS2_PROJECT_INTERFACES_HPP

namespace interfaces
{
    class impl {
    public:
        void init( );

        template< typename T >
        T create_interface( const hash32_t& module_name, const hash32_t& interface_name );

        // ...
        IDXGISwapChain* m_swap_chain = nullptr;
        sdk::c_render_system* m_render_system = nullptr;
        sdk::c_client* m_client = nullptr;
        sdk::c_global_vars_base* m_globals = nullptr;
    };
}

inline interfaces::impl g_interfaces{ };

#endif //CS2_PROJECT_INTERFACES_HPP
