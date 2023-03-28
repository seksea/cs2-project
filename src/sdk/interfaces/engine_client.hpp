#ifndef CS2_PROJECT_ENGINE_CLIENT_HPP
#define CS2_PROJECT_ENGINE_CLIENT_HPP

namespace sdk
{
    class c_engine_client {
    public:
        __forceinline bool is_connected( )
        {
            using is_connected_t = bool( __thiscall* )( void* );
            return utils::get_method< is_connected_t >( this, 31 )( this );
        }

        __forceinline bool is_in_game( )
        {
            using is_in_game_t = bool( __thiscall* )( void* );
            return utils::get_method< is_in_game_t >( this, 30 )( this );
        }
    };
}// namespace sdk

#endif//CS2_PROJECT_ENGINE_CLIENT_HPP
