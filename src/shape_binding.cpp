#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <sstream>

#include <ATen/core/tensor_shape.h>

namespace py = pybind11;

void bind_shape(py::module& m) {
    py::class_<container::TensorShape>(m, "Shape")
        .def(py::init<>())
        .def(py::init<std::initializer_list<int64_t>>())
        .def(py::init<std::vector<int64_t>>())
        .def(py::init<const container::TensorShape&>())
        .def("dim_size", &container::TensorShape::dim_size)
        .def("dims", &container::TensorShape::dims)
        .def("strides", &container::TensorShape::strides)
        .def("ndim", &container::TensorShape::ndim)
        .def("set_dim_size", &container::TensorShape::set_dim_size)
        .def("add_dim", &container::TensorShape::add_dim)
        .def("remove_dim", &container::TensorShape::remove_dim)
        .def("NumElements", &container::TensorShape::NumElements)
        .def("__eq__", &container::TensorShape::operator==)
        .def("__ne__", &container::TensorShape::operator!=)
        .def("__repr__",
             [](const container::TensorShape &shape) {
                 std::ostringstream oss;
                 oss << shape;
                 return oss.str();
             })
        .def("__str__",
             [](const container::TensorShape &shape) {
                 std::ostringstream oss;
                 oss << shape;
                 return oss.str();
             });
}

PYBIND11_MODULE(_libshape, m) {
    bind_shape(m);
}