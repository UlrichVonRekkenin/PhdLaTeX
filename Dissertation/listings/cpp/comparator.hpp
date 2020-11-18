namespace modbusio {
[[nodiscard]] inline bool 
compare(const ModbusDataRelationed& cond, 
        const ModbusData& data)
{
    switch (cond.relation()) {
        case Relation::Eq: return data.value()==cond.value();
        case Relation::Ne: return data.value()!=cond.value();
        case Relation::Gt: return data.value()>cond.value();
        case Relation::Lt: return data.value()<cond.value();
        case Relation::Ge: return data.value()>=cond.value();
        case Relation::Le: return data.value()<=cond.value();
    }
    return false;
}}