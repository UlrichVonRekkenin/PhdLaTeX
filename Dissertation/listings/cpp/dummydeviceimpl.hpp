namespace modbusio {
class DeviceImpl : public QModbusTcpServer, public IDeviceWriter {
    public:
    DeviceImpl(){/*Создание подключения и другие настройки...*/}
    ~DeviceImpl() { /* Отключение устройства... */ }

    void write(const ModbusData& data) override {
        // Перевод в формат специфичный для библиотеки Qt.
        const QModbusDataUnit unit = transform(data);
        QModbusTcpServer::setData(unit);

        // Анализ результатов записи на устройство
        if (!error) {
            emit writed(data);
        }
    }
}; }