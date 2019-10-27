#include <cutehmi/modbus/Register16.hpp>

namespace cutehmi {
namespace modbus {

Register16::Register16(quint16 value):
	m(new Members{value, 0})
{
}

quint16 Register16::value() const
{
	return m->value.loadAcquire();
}

void Register16::setValue(quint16 value)
{
	m->value.storeRelease(value);
}

void Register16::rest()
{
	m->awaken.fetchAndSubRelaxed(1);
}

void Register16::awake()
{
	m->awaken.fetchAndAddRelaxed(1);
}

bool Register16::wakeful() const
{
	return m->awaken.load();
}

}
}

//(c)C: Copyright © 2019, Michal Policht <michpolicht@gmail.com>, Mr CuteBOT <michpolicht@gmail.com>. All rights reserved.
//(c)C: This file is a part of CuteHMI.
//(c)C: CuteHMI is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
//(c)C: CuteHMI is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.
//(c)C: You should have received a copy of the GNU Lesser General Public License along with CuteHMI.  If not, see <https://www.gnu.org/licenses/>.
