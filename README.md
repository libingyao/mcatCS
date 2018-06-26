# mcatFS
This is the main source code of mcatFS, which provides a novel fusion scheme for multi-band astronomical catalogs.

mcatFS contains two parts, grouped spatial index file generation and min-conflict data layout strategy. In the program of grouped spatial index file generation, a KD-tree data structure for every file will be built and transfer them into binary format files by Protobuf, then save generated files into disks. Through the program of min-conflict data layout strategy, the index file would be distributed in multiple servers. A command line-based query interface is provided to users. The scheme will take the coordinates entered by users as inputs, and return all data that matched with target in multi-band astronomical catalogs as the result. We test the fusion time and min-conflict data layout strategy performance in our experiments。

This dependencies of mcatFS is contained in: Grouped Spatial Index File Generation/Match.depend
