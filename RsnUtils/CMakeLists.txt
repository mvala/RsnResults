
set(PACKAGE RsnUtils)

set(SRCS
    TRsnUtils.cxx
)

set(INCLUDE_DIRECTORIES
    ${CMAKE_SOURCE_DIR}/RsnUtils
  ${ROOT_INCLUDE_DIR}
)
include_directories( ${INCLUDE_DIRECTORIES})


set(LINK_DIRECTORIES
  ${ROOT_LIBRARY_DIR}
)
link_directories( ${LINK_DIRECTORIES})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")


String(REPLACE ".cxx" ".h" HDRS "${SRCS}")
ROOT_GENERATE_DICTIONARY( G__${PACKAGE} ${HDRS} LINKDEF ${PACKAGE}LinkDef.h)
list(APPEND SRCS G__${PACKAGE}.cxx)

add_library(${PACKAGE} SHARED ${SRCS} ${HDRS})
target_link_libraries(${PACKAGE} ${ROOT_LIBRARIES} ${ALIEN_LIB} ${APPMON_LIB})

install(TARGETS ${PACKAGE}
RUNTIME DESTINATION bin COMPONENT RUNTIME
LIBRARY DESTINATION lib64 COMPONENT RUNTIME
ARCHIVE DESTINATION lib64 COMPONENT DEVELOPMENT)

add_par(${PACKAGE})

