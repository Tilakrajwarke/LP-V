# LP-V Practicals

## Deep Learning Libraries Installation

pip install numpy pandas matplotlib scikit-learn seaborn tensorflow notebook

---

# HPC Ubuntu Commands

## Install g++ and OpenMP Support

sudo apt update
sudo apt install build-essential
sudo apt install libomp-dev

---

## Compile Command

g++ filename.cpp -fopenmp -o compiled_filename

Example:
g++ bfs_openmp.cpp -fopenmp -o bfs

---

## Run Command

./compiled_filename

Example:
./bfs

---

# CUDA Commands

## Compile CUDA File

nvcc filename.cu -o output

Example:
nvcc vectorAdd.cu -o vectorAdd

---

## Run CUDA Program

./vectorAdd
