#!/bin/bash
mpirun -np 5 ./forest 2 3 2
mpirun -np 2 ./forest 2 0 2