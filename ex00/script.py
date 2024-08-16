import os
import re

def remove_comments(code):
    # Remove single-line comments
    code = re.sub(r'//.*', '', code)
    # Remove multi-line comments
    code = re.sub(r'/\*.*?\*/', '', code, flags=re.DOTALL)
    return code

def process_folder(folder_path, output_file, skip_file=None):
    for filename in os.listdir(folder_path):
        if filename.endswith('.hpp') or (filename.endswith('.cpp') and filename != skip_file):
            file_path = os.path.join(folder_path, filename)
            with open(file_path, 'r') as file:
                content = file.read()
                cleaned_content = remove_comments(content)
                output_file.write(cleaned_content)
                output_file.write("\n\n")

def combine_files(hpp_folder, cpp_folder, output_filename):
    with open(output_filename, 'w') as output_file:
        process_folder(hpp_folder, output_file)
        process_folder(cpp_folder, output_file, skip_file='main.cpp')

# Paths to the folders and output file
hpp_folder = 'includes'
cpp_folder = 'src'
output_filename = 'ex00'

combine_files(hpp_folder, cpp_folder, output_filename)
