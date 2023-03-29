#ifndef CS2_PROJECT_RESIZEBUFFERS_HPP
#define CS2_PROJECT_RESIZEBUFFERS_HPP

namespace hooks
{
    namespace resizebuffers
    {
        inline hook::detour m_hook;

        HRESULT __stdcall hook( IDXGISwapChain *swap_chain, unsigned int buffer, unsigned int w, unsigned int h, DXGI_FORMAT format, unsigned int flags );

        void init( );
    }// namespace resizebuffers
}// namespace hooks

#endif//CS2_PROJECT_PRESENT_HPP
