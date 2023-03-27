#ifndef CS2_PROJECT_WNDPROC_HPP
#define CS2_PROJECT_WNDPROC_HPP

namespace hooks
{
    namespace wndproc
    {
        inline WNDPROC m_hook_original = nullptr;

        LRESULT __stdcall hook( HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam );
        void init( );
    }
}

#endif //CS2_PROJECT_WNDPROC_HPP
