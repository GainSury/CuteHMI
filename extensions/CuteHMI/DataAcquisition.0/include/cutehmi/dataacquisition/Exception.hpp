#ifndef H_EXTENSIONS_CUTEHMI_DATAACQUISITION_0_INCLUDE_CUTEHMI_DATAACQUISITION_EXCEPTION_HPP
#define H_EXTENSIONS_CUTEHMI_DATAACQUISITION_0_INCLUDE_CUTEHMI_DATAACQUISITION_EXCEPTION_HPP

// This file has been initially autogenerated by 'cutehmi.skeleton.cpp' Qbs module.

#include "internal/platform.hpp"

#include <cutehmi/ExceptionMixin.hpp>

namespace cutehmi {
namespace dataacquisition {

class CUTEHMI_DATAACQUISITION_API Exception:
	public ExceptionMixin<Exception>
{
		typedef ExceptionMixin<Exception> Parent;

	public:
		using Parent::Parent;
};

}
}

#endif