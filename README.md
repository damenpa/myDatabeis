# myDatabeis

A simple key-value store database written in C++17.

## Overview

myDatabeis is a lightweight in-memory database that persists records to a binary file. Each record consists of a numeric ID and a string value, with an index for fast lookups.

## Features

- Insert, get, update, and remove records
- List all records
- Persistent storage to `data/records.bin`
- O(1) lookups via hash-based index

## Building

```bash
make
```

This compiles the project to `build/myDatabeis`.

## Usage

```bash
./build/myDatabeis
```

## Project Structure

```
include/    Header files (database.hpp, record.hpp)
src/        Source files (main.cpp, database.cpp, record.cpp)
build/      Compiled binary output
```
