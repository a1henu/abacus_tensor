from __future__ import annotations
from typing import List

import pytest
from abacus_tensor import Shape

def test_constructor():
    # Test default constructor
    shape1 = Shape()
    assert shape1.ndim() == 0

    # Test initializer_list constructor
    shape2 = Shape([2, 3, 4])
    assert shape2.ndim() == 3
    assert shape2.dim_size(0) == 2
    assert shape2.dim_size(1) == 3
    assert shape2.dim_size(2) == 4

    # Test vector constructor
    dims = [5, 6]
    shape3 = Shape(dims)
    assert shape3.ndim() == 2
    assert shape3.dim_size(0) == 5
    assert shape3.dim_size(1) == 6

def test_size_manipulation():
    # Test add_dim and dim_size
    shape = Shape([2, 3])
    shape.add_dim(4)
    assert shape.ndim() == 3
    assert shape.dim_size(0) == 2
    assert shape.dim_size(1) == 3
    assert shape.dim_size(2) == 4

    # Test remove_dim
    shape.remove_dim(1)
    assert shape.ndim() == 2
    assert shape.dim_size(0) == 2
    assert shape.dim_size(1) == 4

    # Test set_dim_size
    shape.set_dim_size(1, 5)
    assert shape.dim_size(1) == 5

    # Test NumElements
    assert shape.NumElements() == 10

def test_comparison():
    shape1 = Shape([2, 3, 4])
    shape2 = Shape([2, 3, 4])
    shape3 = Shape([3, 3, 4])

    # Test == operator
    assert shape1 == shape2
    assert shape1 != shape3

    # Test != operator
    assert shape1 != shape3
    assert shape2 != shape3

def test_output():
    shape = Shape([2, 3, 4])
    assert str(shape) == "[2,3,4]"

if __name__ == "__main__":
    pytest.main()