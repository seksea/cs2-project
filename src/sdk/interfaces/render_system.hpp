#ifndef CS2_PROJECT_RENDER_SYSTEM_HPP
#define CS2_PROJECT_RENDER_SYSTEM_HPP

namespace sdk
{
    class c_render_system {
    public:
        PAD( 0x178 );
        IDXGISwapChain* m_swap_chain;
    };
}

#endif //CS2_PROJECT_RENDER_SYSTEM_HPP
