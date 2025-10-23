import uproot
from uproot_custom import AsCustom, registered_factories

from my_reader import OverrideStreamerFactory

# Register custom factory
registered_factories.add(OverrideStreamerFactory)

# Specify target branches
AsCustom.target_branches |= {
    "/my_tree:standalone_obj",
    "/my_tree:my_obj/m_objVec",
    "/my_tree:my_obj/m_objMap/m_objMap.second",
}

f = uproot.open("demo-data.root")
b = f["my_tree/my_obj"]
b.show(name_width=40, typename_width=40)

print()
print("-" * 50)
print()

b.arrays(filter_name="m_obj*").show()
