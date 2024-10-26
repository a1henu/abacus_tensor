include_directories(module_container)
add_subdirectory(module_container)

add_subdirectory(pybind11)

# BINDING TENSOR::SHAPE
set(SHAPE_SOURCES
    shape_binding.cpp)

pybind11_add_module(_libshape MODULE ${SHAPE_SOURCES})
target_link_libraries(
    _libshape
    PRIVATE 
    pybind11::headers 
    container
    ${math_libs}
)

target_compile_definitions(_libshape PRIVATE VERSION_INFO=${PROJECT_VERSION})

set(TARGET_PACK abacus_tensor)
set(CMAKE_INSTALL_RPATH "${PYTHON_SITE_PACKAGES}/${TARGET_PACK}")
set_target_properties(_libshape PROPERTIES INSTALL_RPATH "$ORIGIN")

install(TARGETS _libshape DESTINATION ${TARGET_PACK})
install(TARGETS container DESTINATION ${TARGET_PACK})

# BINDING TENSOR::DATATYPE & TENSOR::DEVICETYPE