# mcatFS
This is the main source code of mcatCS, which provides a novel cross-matching scheme for multi-band astronomical catalogs.

mcatCS contains two parts, grouped spatial index file generation and min-conflict data layout strategy. In the program of grouped spatial index file generation, a KD-tree data structure for every file will be built and transfer them into binary format files by Protobuf, then save generated files into disks. Through the program of min-conflict data layout strategy, the index file would be distributed in multiple servers. A command line-based query interface is provided to users. The scheme will take the coordinates entered by users as inputs, and return all data that matched with target in multi-band astronomical catalogs as the result. 


Prerequisites
This program has the following dependencies:
  - cfitsio 3.3
  - Healpix_3.20
  - protobuf_2.6.1
  
 All of these dependencies can be found in main directory.

After install all these software, you can run the program in /
