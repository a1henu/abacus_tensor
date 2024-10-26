#include <sstream>
#include <pybind11/pybind11.h>

#include <ATen/core/tensor_types.h>

namespace py = pybind11;

void bind_type(py::module& m) {
    py::enum_<container::DataType>(m, "DataType")
        .value("DT_INVALID", container::DataType::DT_INVALID)
        .value("DT_FLOAT", container::DataType::DT_FLOAT)
        .value("DT_DOUBLE", container::DataType::DT_DOUBLE)
        .value("DT_INT", container::DataType::DT_INT)
        .value("DT_INT64", container::DataType::DT_INT64)
        .value("DT_COMPLEX", container::DataType::DT_COMPLEX)
        .value("DT_COMPLEX_DOUBLE", container::DataType::DT_COMPLEX_DOUBLE)
        .export_values()
        .def("__repr__",
             [](const container::DataType& data_type) {
                 std::ostringstream oss;
                 oss << data_type;
                 return oss.str();
             })
        .def("__str__",
             [](const container::DataType& data_type) {
                 std::ostringstream oss;
                 oss << data_type;
                 return oss.str();
             });

    py::enum_<container::DeviceType>(m, "DeviceType")
        .value("UnKnown", container::DeviceType::UnKnown)
        .value("CpuDevice", container::DeviceType::CpuDevice)
        .value("GpuDevice", container::DeviceType::GpuDevice)
        .export_values()
        .def("__repr__",
             [](const container::DeviceType& device_type) {
                 std::ostringstream oss;
                 oss << device_type;
                 return oss.str();
             })
        .def("__str__",
             [](const container::DeviceType& device_type) {
                 std::ostringstream oss;
                 oss << device_type;
                 return oss.str();
             });
}
