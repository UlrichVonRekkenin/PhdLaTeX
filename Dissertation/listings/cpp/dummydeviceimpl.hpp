class DeviceImpl : public QModbusTcpServer, public IDeviceWriter {
    public:
    DeviceImpl() {
        // Создание подключения 127.0.0.1:502
        // И другие настройки...
    }
    ~DeviceImpl() {
        // Отключение устройства...
    }

    void write(const modbus::ModbusData& data) override {
        // Перевод в формат специфичный для библиотеки Qt.
        const QModbusDataUnit unit = transform(data);
        QModbusTcpServer::setData(unit);

        // Анализ результатов записи на устройство
        if (!error) {
            emit writed(data);
        }
    }
};