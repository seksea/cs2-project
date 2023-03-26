#ifndef CS2_PROJECT_VMT_HPP
#define CS2_PROJECT_VMT_HPP

namespace hook
{
    class detour {
    public:
        __forceinline void create_hook( void * address, void * function )
        {
            auto status = MH_CreateHook( address, function, &this->m_original );

            if ( status != MH_OK )
                spdlog::error( "detour: failed to create hook at address {} ({})", address, MH_StatusToString( status ) );

            spdlog::info( "detour: hooked function {} at address {}", function, address );
        }

        template< typename T >
        __forceinline T call_original( )
        {
            return reinterpret_cast< T >( this->m_original );
        }
    private:
        void* m_original = nullptr;
    };
}

#endif //CS2_PROJECT_VMT_HPP