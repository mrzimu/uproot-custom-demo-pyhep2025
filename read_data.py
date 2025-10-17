import awkward as ak
import uproot
import uproot_custom as uc

import my_reader

f = uproot.open("demo-data.root")
t = f["my_tree"]
t.show(name_width=40, typename_width=40)

t["obj_in_stl/m_objMap/m_objMap.second"].array()
