# `uproot-custom` demo for PyHEP 2025

This project is a demonstration of how to use the [`uproot-custom`](https://github.com/mrzimu/uproot-custom) package to customize TTree reading in `Uproot`.

## Prerequisites

To run this demo, you need to have:

- Python >= 3.9, < 3.14
- C++ compiler supporting C++17
- CMake >= 3.20

If you want to generate the demo data file, you will need to have ROOT installed.

## Create virtual environment

```bash
python -m venv .venv
source .venv/bin/activate
```

## Install demo project

```bash
pip install -e .
```

This will compile the C++ codes and install the `my_reader` package in editable mode. Then you can run the demo script/notebook.
