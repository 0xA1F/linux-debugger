sources = ['debugger.cpp', 'breakpoint.cpp', 'utils.cpp', 'main.cpp']

utils = static_library('utils', ['utils.cpp'], include_directories: include)
ldb = executable('ldb', sources, include_directories: include, link_with: liblinenoise)
