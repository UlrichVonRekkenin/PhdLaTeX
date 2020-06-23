class IModbusElementWriterImpl : public IModbusElementWriter {
// ...
public slots:
void IModbusElementWriterImpl::newModbusData(const modbus::ModbusData& data) override {
    if (_running && conditionsMet(data)) {
        write();
    }
}

protected:
void IModbusElementWriterImpl::write() override {
    if (_deviceWriter.get()) {
        _deviceWriter->write(static_cast<const modbus::ModbusData>(*this));
        emit writed(static_cast<const modbus::ModbusData>(*this));
        _running = false;
    }
}
};