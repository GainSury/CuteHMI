import qbs

/**
  Common product. Defines common properties for all CuteHMI product types.
  */
Product {
	targetName: qbs.buildVariant.contains("debug") ? name + "d" : name

	property string cutehmiType: "product"	///< CuteHMI product type.

	property string vendor					///< Product vendor.

	property string domain					///< Organization domain.

	property string friendlyName			///< Descriptive product name for ordinary humans.

	property string description				///< Product description.

	property string author					///< Author(s).

	property string copyright				///< Copyright holder(s).

	property string license					///< License(s).

	property string baseName				///< Base name of the product (without the major version suffix).

	property int major						///< Major version number.

	property int minor						///< Minor version number (deprecated).

	property int micro						///< Micro version number (deprecated).
}

//(c)C: Copyright © 2018-2019, Michal Policht <michpolicht@gmail.com>, CuteBOT <michpolicht@gmail.com>, Mr CuteBOT <michpolicht@gmail.com>, Michal Policht <michal@policht.pl>. All rights reserved.
//(c)C: This file is a part of CuteHMI.
//(c)C: CuteHMI is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
//(c)C: CuteHMI is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.
//(c)C: You should have received a copy of the GNU Lesser General Public License along with CuteHMI.  If not, see <https://www.gnu.org/licenses/>.
