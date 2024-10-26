from __future__ import annotations
from typing import List

from ._libtensor import Shape as _Shape

class Shape(_Shape):
    def  __init__(self, *args, **kwargs) -> None:
        super().__init__(*args, **kwargs)
    
    def __repr__(self) -> str:
        return super().__repr__()
    
    def __str__(self) -> str:
        return super().__str__()
    
    def __eq__(self, other) -> bool:
        return super().__eq__(other)
    
    def __ne__(self, other) -> bool:
        return super().__ne__(other)
    
    def dim_size(self, dim: int) -> int:
        return super().dim_size(dim)
    
    def dims(self) -> List[int]:
        return super().dims()
    
    def strides(self) -> List[int]:
        return super().strides()
    
    def ndim(self) -> int:
        return super().ndim()
    
    def set_dim_size(self, dim: int, size: int) -> None:
        super().set_dim_size(dim, size)
        
    def add_dim(self, size: int) -> None:
        super().add_dim(size)
        
    def remove_dim(self, dim: int) -> None:
        super().remove_dim(dim)
    
    def NumElements(self) -> int:
        return super().NumElements()