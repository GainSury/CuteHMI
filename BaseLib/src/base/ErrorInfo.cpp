#include "../../include/base/ErrorInfo.hpp"

namespace cutehmi {
namespace base {

QString ErrorInfo::toString() const
{
	QString result = str;
	result += "\n[error class: ";
	result += errClass;
	result += " code: ";
	result += QString::number(code);
	result += "]";
	return result;
}

}
}

//(c)MP: Copyright © 2017, Michal Policht. All rights reserved.
//(c)MP: This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
