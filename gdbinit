python
import sys,os
sys.path.insert(0, '/home/cedric/Documents/Dev/colorply/eigen-git-mirror/debug/gdb')
from printers import register_eigen_printers
register_eigen_printers (None)
print("ok !")
end