class ModbusElementWriterImpl : public QObject, public IModbusElementWriter {
// ...
public slots:
void ModbusElementWriterImpl::newModbusData(const modbus::ModbusData& data) override {
    if (_running && conditionsMet(data)) {
        write();
    }
}

protected:
void ModbusElementWriterImpl::write() override {
    if (_deviceWriter.get()) {
        _deviceWriter->write(static_cast<const modbus::ModbusData>(*this));
        emit writed(static_cast<const modbus::ModbusData>(*this));
        _running = false;
    }
}
};