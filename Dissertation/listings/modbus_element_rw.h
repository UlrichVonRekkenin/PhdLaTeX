namespace modbus
{
    class ModbusElementWriter : public ModbusElement {

    public:
        // ...
        template <typename Value> void write(const Value &value);
    };

    class ModbusElementReader : public ModbusElement {

    public:
        // ...
        template <typename Value> Value read();
    };

    
} // namespace modbus
