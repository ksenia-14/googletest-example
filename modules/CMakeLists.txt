add_library(
  modules 
  module_a/test_fun_a.c 
  module_b/test_fun_b.c
)

target_include_directories(
  modules 
  PUBLIC 
  module_a 
  module_b
)


