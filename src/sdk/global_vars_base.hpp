#ifndef CS2_PROJECT_GLOBAL_VARS_BASE_HPP
#define CS2_PROJECT_GLOBAL_VARS_BASE_HPP

namespace sdk
{
    class c_global_vars_base {
    public:
        float m_realtime; //0x0000
        __int32 m_framecount; //0x0004
        PAD( 40 ); //0x0008
        float m_curtime; //0x0030
        PAD( 4100 ); //0x0034
    }; //Size: 0x1038

    static_assert( sizeof( c_global_vars_base ) == 0x1038, "class c_global_vars_base has wrong size." );
}

#endif //CS2_PROJECT_GLOBAL_VARS_BASE_HPP
