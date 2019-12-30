sources = ['debugger.cpp', 'utils.cpp', 'main.cpp']

libutils = static_library('libutils', ['utils.cpp'], include_directories: include)
ldb = executable('ldb', sources, include_directories: include, link_with: liblinenoise)
