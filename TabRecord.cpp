#include "TabRecord.h"

//PDatValue _data;
//Key _key;

TabRecord::TabRecord(Key key, PDatValue data) : _key(key), _data(data) {}

void TabRecord::SetKey(Key key) { _key = key; }

Key TabRecord::GetKey()const { return _key; }

void TabRecord::SetData(PDatValue data) { _data = data; }

PDatValue TabRecord::GetData()const { return _data; }

PDatValue TabRecord::GetCopy() const{
	return _data->GetCopy();
}

TabRecord& TabRecord::operator=(const TabRecord& tr) {
	if (*this == tr) return *this;
	_key = tr.GetKey();
	delete _data;
	_data = tr.GetCopy();
	return *this;
}

bool TabRecord::operator==(const TabRecord& tr)const {
	return this->_key == tr._key;
}
bool TabRecord::operator>(const TabRecord& tr)const {
	return this->_key > tr._key;
}
bool TabRecord::operator<(const TabRecord& tr)const {
	return this->_key < tr._key;
}