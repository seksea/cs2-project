#ifndef CS2_PROJECT_CSGOINPUT_HPP
#define CS2_PROJECT_CSGOINPUT_HPP

namespace sdk
{
    class c_csgo_input {
    public:
        // E8 ? ? ? ? 41 B1 01 44 8B C0 8B D3 49 8B CD E8 ? ? ? ? 48 8B F0 48
        void *get_user_cmd( int slot )
        {
            auto sequence_number = *reinterpret_cast< unsigned int* >( 0x4360 * slot + reinterpret_cast< uintptr_t >( this ) + 0x41E0 );
            auto cmd_split_screen = reinterpret_cast< uintptr_t >( this ) + 0x70 * ( 154 * slot + sequence_number % 150 );

            return reinterpret_cast< void* >( uintptr_t( cmd_split_screen ) + 0x10 );
        }
    };
}// namespace sdk

#endif//CS2_PROJECT_CSGOINPUT_HPP
