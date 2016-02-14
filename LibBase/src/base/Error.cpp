#include "Error.hpp"

namespace cutehmi {
namespace base {

Error::Error():
	m_code(UNINITIALIZED)
{
}

  Error::Error(int code):
	m_code(code)
{
}

bool Error::operator ==(const Error & other) const
{
	return m_code == other.m_code;
}

bool Error::operator !=(const Error & other) const
{
	return m_code != other.m_code;
}

Error::operator bool() const
{
	return m_code == Error::OK;
}

int Error::code() const
{
	return m_code;
}

QString Error::str() const
{
	switch (code()) {
		case Error::OK:
			return tr("No error.");
		case Error::FAIL:
			return tr("Undescribed error.");
		case Error::UNINITIALIZED:
			return tr("Uninitialized error code.");
		default:
			return tr("Unrecognized error code.");
	}
}

void Error::setCode(int code)
{
	m_code = code;
}

}
}

bool operator ==(const cutehmi::base::Error & error, int code)
{
	return error.code() == code;
}

bool operator ==(int code, const cutehmi::base::Error & error)
{
	return error.code() == code;
}

bool operator !=(const cutehmi::base::Error & error, int code)
{
	return error.code() != code;
}

bool operator !=(int code, const cutehmi::base::Error & error)
{
	return error.code() != code;
}
