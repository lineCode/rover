#ifndef ROVER_PYTHON_BOX_HPP
#define ROVER_PYTHON_BOX_HPP
#include <string_view>
#include <pybind11/pybind11.h>
#include "Rover/Box.hpp"

namespace Rover {

  //! Exports an instantiation of the Box class.
  /*!
    \param module The module to export the class to.
    \param type_name The name of the type the Box generates.
  */
  template<typename T>
  void export_box(pybind11::module& module, std::string_view type_name);

  //! Exports a generic Box for Python objects.
  void export_box(pybind11::module& module);

  template<typename T>
  void export_box(pybind11::module& module, std::string_view type_name) {
    auto name = std::string("Box").append(type_name);
    pybind11::class_<Box<T>>(module, name.c_str())
      .def(pybind11::init<Constant<T>>())
      .def("generate", &Box<T>::generate);
  }
}

#endif
