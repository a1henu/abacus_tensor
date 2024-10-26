#include <pybind11/pybind11.h>

void bind_shape(py::module& m);
void bind_type(py::module& m);

PYBIND11_MODULE(_libtensor, m) {
    bind_shape(m);
    bind_type(m);
}