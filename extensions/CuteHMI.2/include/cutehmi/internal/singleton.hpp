#ifndef H_EXTENSIONS_CUTEHMI_2_INCLUDE_CUTEHMI_INTERNAL_SINGLETON_HPP
#define H_EXTENSIONS_CUTEHMI_2_INCLUDE_CUTEHMI_INTERNAL_SINGLETON_HPP

#include "platform.hpp"


namespace cutehmi {
namespace internal {

typedef void(*singletonDestroyCallback)();

CUTEHMI_PRIVATE void destroySingletonInstances();

CUTEHMI_PRIVATE void storeSingletonDestroyCallback(singletonDestroyCallback callback);

CUTEHMI_PRIVATE void removeSingletonDestroyCallback(singletonDestroyCallback callback);

}
}

#endif

//(c)MP: Copyright © 2019, Michal Policht. All rights reserved.
//(c)MP: This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
