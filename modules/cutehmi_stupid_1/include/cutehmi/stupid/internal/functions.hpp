#ifndef H_MODULES_CUTEHMI_u_STUPID_u_1_INCLUDE_CUTEHMI_STUPID_INTERNAL_FUNCTIONS_HPP
#define H_MODULES_CUTEHMI_u_STUPID_u_1_INCLUDE_CUTEHMI_STUPID_INTERNAL_FUNCTIONS_HPP

#include <cutehmi/ErrorInfo.hpp>

#include <QSqlError>

namespace cutehmi {
namespace stupid {
namespace internal {

ErrorInfo errorInfo(const QSqlError & error);

}
}
}

#endif

//(c)MP: Copyright © 2018, Michal Policht. All rights reserved.
//(c)MP: This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
