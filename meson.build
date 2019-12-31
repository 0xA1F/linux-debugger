project('ldb', 
        ['c', 'cpp'],
        version: '0.0.1',
        default_options: ['cpp_std=c++14', 'c_std=gnu89', 'warning_level=3'])

liblinenoise_include = include_directories('external/linenoise')
liblinenoise = static_library('liblinenoise', 
                              sources: ['external/linenoise/linenoise.c'],
                              include_directories: liblinenoise_include)

include = include_directories('include',
                              'external/linenoise',
                              'external/libelfin/elf',
                              'external/libelfin/dwarf')
tests_include = include_directories('external/doctest/doctest')

subdir('src')
subdir('tests')
