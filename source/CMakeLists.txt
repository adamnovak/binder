
#list(REMOVE_ITEM CMAKE_CXX_FLAGS "-fno-exceptions")
#set(CMAKE_CXX_FLAGS "-fexceptions ${CMAKE_CXX_FLAGS}")

set(LLVM_LINK_COMPONENTS support)
set(LLVM_USED_LIBS clangTooling clangBasic clangAST)

add_clang_executable(binder
  binder.cpp
  binder.hpp

  context.hpp
  context.cpp

  class.hpp
  class.cpp

  config.hpp
  config.cpp

  enum.hpp
  enum.cpp

  function.hpp
  function.cpp

  type.hpp
  type.cpp

  util.hpp
  util.cpp

  fmt/format.cc
  fmt/posix.cc
  )

target_link_libraries(binder
  PRIVATE
  clangTooling
  clangBasic
  clangASTMatchers
  clangAST
  clangFrontend
  )
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/binder 
PERMISSIONS WORLD_EXECUTE WORLD_READ OWNER_WRITE OWNER_READ OWNER_EXECUTE 
DESTINATION ${CMAKE_INSTALL_BINDIR})
