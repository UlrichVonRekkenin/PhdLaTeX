class DeviceImpl : public QModbusTcpServer, public IDeviceWriter {
    public:
    DeviceImpl() {
        // Создание подключения 127.0.0.1:502
        // И другие настройки...
    }
    ~DeviceImpl() {
        // Отключение устройства и другие завершающие процедуры...
    }

    void write(const modbus::ModbusData& data) override {
        const QModbusDataUnit unit = transform(data); // Перевод из одно формата в другой
        QModbusTcpServer::setData(unit);
        // Анализ результатов записи на устройство
        if (!error) {
            // emit writed(data);
        }
    }
};