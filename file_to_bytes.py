""" This script reads a file and prints its contents as bytes and its size in bytes. """

import os

def print_file_size(file_path):
    with open(file_path, "rb") as f:
        content = f.read()
        print(f"File contents as bytes: {content}")

    try:
        file_size = os.path.getsize(file_path)
        print(f"The file size is {file_size} bytes.")

    except OSError as e:
        print(f"Error: {e.strerror}")

# Replace 'your_file.txt' with your file path
print_file_size('README.md')
