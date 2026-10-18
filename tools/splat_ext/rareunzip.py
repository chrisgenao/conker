import importlib.util
import os

# Load rareunzip from the parent tools directory by path (avoids circular import
# where this module is registered as 'rareunzip' in sys.modules before loading)
_tools_dir = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
_rareunzip_path = os.path.join(_tools_dir, "rareunzip.py")
_spec = importlib.util.spec_from_file_location("_rareunzip_parent", _rareunzip_path)
_rareunzip_mod = importlib.util.module_from_spec(_spec)
_spec.loader.exec_module(_rareunzip_mod)

runzip_with_leftovers = _rareunzip_mod.runzip_with_leftovers
runzip = _rareunzip_mod.runzip