#ifndef CS2_PROJECT_SCHEMA_SYSTEM_HPP
#define CS2_PROJECT_SCHEMA_SYSTEM_HPP

namespace sdk
{
    struct schema_class_field_data_t {
        const char* m_name; // 0x0000
        PAD( 0x8 ); // 0x0008
        short m_offset; // 0x0010
        PAD( 0xE ); // 0x0012
    };

    struct schema_class_info_data_t {
        PAD( 0x8 ); // 0x0000
        const char* m_name; // 0x0008
        char* m_module; // 0x0010
        int m_size; // 0x0018
        __int16 m_field_size; // 0x001C
        __int16 m_static_size; // 0x001E
        __int16 m_metadata_size; // 0x0020
        __int16 m_i_unk1; // 0x0022
        __int16 m_i_unk2; // 0x0024
        __int16 m_i_unk3; // 0x0026
        schema_class_field_data_t* m_fields; // 0x0028
    };

    class c_schema_system_type_scope {
    public:
        schema_class_info_data_t* find_type_declared_class( const char* name )
        {
            using find_type_declared_class_t = schema_class_info_data_t* ( __thiscall* )( void*, const char* );
            return utils::get_method< find_type_declared_class_t >( this, 2 )( this, name );
        }
    };

    class c_schema_system {
    public:
        __forceinline c_schema_system_type_scope* global_type_scope( )
        {
            using global_type_scope_t = c_schema_system_type_scope* ( __thiscall* )( void* );
            return utils::get_method< global_type_scope_t >( this, 13 )( this );
        }

        __forceinline c_schema_system_type_scope* find_type_scope_for_module( const char* module )
        {
            using find_type_scope_for_module_t = c_schema_system_type_scope* ( __thiscall* )( void*, const char* );
            return utils::get_method< find_type_scope_for_module_t >( this, 13 )( this, module );
        }
    };
}

#endif //CS2_PROJECT_SCHEMA_SYSTEM_HPP