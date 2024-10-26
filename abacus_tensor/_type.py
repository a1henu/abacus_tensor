from __future__ import annotations
from typing import List

from ._libtensor import DataType as _DataType, DeviceType as _DeviceType

class DataType(_DataType):
    def __str__(self) -> str:
        return super().__str__()
    
    def __repr__(self) -> str:
        return super().__repr__()

class DeviceType(_DeviceType):
    def __str__(self) -> str:
        return super().__str__()
    
    def __repr__(self) -> str:
        return super().__repr__()