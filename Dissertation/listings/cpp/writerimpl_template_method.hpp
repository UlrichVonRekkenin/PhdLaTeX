class ModbusElementWriterImpl : public QObject, public IModbusElementWriter {
// ...
public slots:
void newModbusData(const modbus::ModbusData& data) override {
    if (_running && conditionsMet(data)) {
        write();
    }
}

protected:
void write() override {
    if (_deviceWriter.get()) {
        const auto md {static_cast<const modbus::ModbusData>(*this)};
        _deviceWriter->write(md);
        emit writed(md);
        _running = false;
    }
}
};