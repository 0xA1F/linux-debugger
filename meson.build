project('ldb', 'cpp',
        default_options: ['cpp_std=c++14', 'warning_level=3'])

include = include_directories('include', 
                              'external/linenoise',
                              'external/libelfin/elf',
                              'external/libelfin/dwarf')

subdir('src')
subdir('tests')
