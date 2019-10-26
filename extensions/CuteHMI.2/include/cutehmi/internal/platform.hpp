#ifndef H_EXTENSIONS_CUTEHMI_2_INCLUDE_CUTEHMI_INTERNAL_PLATFORM_HPP
#define H_EXTENSIONS_CUTEHMI_2_INCLUDE_CUTEHMI_INTERNAL_PLATFORM_HPP

#include <QtCore/QtGlobal>

#ifdef CUTEHMI_DYNAMIC
	#ifdef CUTEHMI_BUILD
		// Export symbols to dynamic library.
		#define CUTEHMI_API Q_DECL_EXPORT
		#ifdef CUTEHMI_TESTS
			// Export symbols to dynamic library.
			#define CUTEHMI_PRIVATE Q_DECL_EXPORT
		#else
			#define CUTEHMI_PRIVATE
		#endif
	#else
		// Using symbols from dynamic library.
		#define CUTEHMI_API Q_DECL_IMPORT
		#ifdef CUTEHMI_TESTS
			// Using symbols from dynamic library.
			#define CUTEHMI_PRIVATE Q_DECL_IMPORT
		#else
			#define CUTEHMI_PRIVATE
		#endif
	#endif
#else
	#define CUTEHMI_API
	#define CUTEHMI_PRIVATE
#endif

#endif

//(c)MP: Copyright © 2018-2019, Michal Policht <michpolicht@gmail.com>. All rights reserved.
//(c)MP: This file is a part of CuteHMI.
//(c)MP: CuteHMI is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
//(c)MP: CuteHMI is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.
//(c)MP: You should have received a copy of the GNU Lesser General Public License along with CuteHMI.  If not, see <https://www.gnu.org/licenses/>.
